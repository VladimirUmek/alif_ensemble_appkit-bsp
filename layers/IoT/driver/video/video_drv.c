/*
 * Copyright (c) 2024 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdint.h>
#include <stddef.h>
#include "video_drv.h"
#include "RTE_Components.h"
#include CMSIS_device_header

// Camera
#include "Driver_CPI.h"
// LCD
#include "Driver_CDC200.h"

// Video channel definitions
#ifndef VIDEO_INPUT_CHANNELS
#define VIDEO_INPUT_CHANNELS    1
#endif
#if    (VIDEO_INPUT_CHANNELS >  1)
#error "Maximum 1 Video Input channel is supported!"
#endif
#ifndef VIDEO_OUTPUT_CHANNELS
#define VIDEO_OUTPUT_CHANNELS   1
#endif
#if    (VIDEO_OUTPUT_CHANNELS > 1)
#error "Maximum 1 Video Output channel is supported!"
#endif

// Video STATUS definitions
#define Reg_STATUS_ACTIVE_Pos           0U
#define Reg_STATUS_ACTIVE_Msk           (1UL << Reg_STATUS_ACTIVE_Pos)
#define Reg_STATUS_BUF_EMPTY_Pos        1U
#define Reg_STATUS_BUF_EMPTY_Msk        (1UL << Reg_STATUS_BUF_EMPTY_Pos)
#define Reg_STATUS_BUF_FULL_Pos         2U
#define Reg_STATUS_BUF_FULL_Msk         (1UL << Reg_STATUS_BUF_FULL_Pos)

// Camera Resolution and frames per second
#if RTE_Drivers_CAMERA_SENSOR_MT9M114
#define CAMERA_FRAME_WIDTH  RTE_MT9M114_CAMERA_SENSOR_MIPI_FRAME_WIDTH
#define CAMERA_FRAME_HEIGHT RTE_MT9M114_CAMERA_SENSOR_MIPI_FRAME_HEIGHT
#define CAMERA_FRAME_RATE   60
#elif RTE_Drivers_CAMERA_SENSOR_HM0360
#define CAMERA_FRAME_WIDTH  RTE_HM0360_CAMERA_SENSOR_FRAME_WIDTH
#define CAMERA_FRAME_HEIGHT RTE_HM0360_CAMERA_SENSOR_FRAME_HEIGHT
#define CAMERA_FRAME_RATE   RTE_HM0360_CAMERA_SENSOR_CSI_CFG_FPS
#elif RTE_Drivers_CAMERA_SENSOR_ARX3A0
#define CAMERA_FRAME_WIDTH  RTE_ARX3A0_CAMERA_SENSOR_FRAME_WIDTH
#define CAMERA_FRAME_HEIGHT RTE_ARX3A0_CAMERA_SENSOR_FRAME_HEIGHT
#define CAMERA_FRAME_RATE   RTE_ARX3A0_CAMERA_SENSOR_CSI_CFG_FPS
#elif RTE_Drivers_CAMERA_SENSOR_AR0144
#define CAMERA_FRAME_WIDTH  RTE_AR0144_CAMERA_SENSOR_FRAME_WIDTH
#define CAMERA_FRAME_HEIGHT RTE_AR0144_CAMERA_SENSOR_FRAME_HEIGHT
#define CAMERA_FRAME_RATE   60
#else
#define CAMERA_FRAME_WIDTH  0
#define CAMERA_FRAME_HEIGHT 0
#define CAMERA_FRAME_RATE   60
#endif

// LCD Resolution and frames per second
#if RTE_Drivers_MIPI_DSI_ILI9806E_PANEL || RTE_Drivers_CDC_ILI6122_PANEL
#define DISPLAY_FRAME_WIDTH  RTE_PANEL_HACTIVE_TIME
#define DISPLAY_FRAME_HEIGHT RTE_PANEL_VACTIVE_LINE
#define DISPLAY_FRAME_RATE   RTE_CDC200_DPI_FPS
#else
#define DISPLAY_FRAME_WIDTH  0
#define DISPLAY_FRAME_HEIGHT 0
#define DISPLAY_FRAME_RATE   60
#endif

// Camera Driver instance
extern ARM_DRIVER_CPI Driver_CPI;
static ARM_DRIVER_CPI *VideoI0 = &Driver_CPI;

// LCD Driver instance
extern ARM_DRIVER_CDC200 Driver_CDC200;
static ARM_DRIVER_CDC200 *VideoO0 = &Driver_CDC200;

// Driver State
static uint8_t Initialized = 0U;

// Video Driver Configuration Parameters
static struct _video_config {
  void    *buf;
  uint32_t frame_width;
  uint32_t frame_height;
  uint8_t  pixel_size;
  uint8_t  configured;
  uint8_t  active;
  uint16_t status;
} video_config[2];

// Event Callback
static VideoDrv_Event_t CB_Event = NULL;

// Camera Event
static void VideoI0_Event(uint32_t camera_event) {
  uint32_t event;

  event = 0U;
  if (camera_event & ARM_CPI_EVENT_CAMERA_CAPTURE_STOPPED) {
    event |= VIDEO_DRV_EVENT_FRAME;
    video_config[0].active = 0U;
    video_config[0].status &= ~Reg_STATUS_BUF_EMPTY_Msk;
  }

  if (camera_event & ARM_CPI_EVENT_ERR_CAMERA_INPUT_FIFO_OVERRUN |
                     ARM_CPI_EVENT_ERR_CAMERA_OUTPUT_FIFO_OVERRUN |
                     ARM_CPI_EVENT_ERR_HARDWARE) {
    event |= VIDEO_DRV_EVENT_ERROR;
  }

  if (CB_Event != NULL) {
    CB_Event(0U, event);
  }
}

// Display Event
static void VideoO0_Event(uint32_t display_event) {
  uint32_t event;

  event = 0U;
  if (display_event & ARM_CDC_DSI_ERROR_EVENT) {
    event |= VIDEO_DRV_EVENT_ERROR;
  }

  if (CB_Event != NULL) {
    CB_Event(1U, event);
  }
}

// Initialize Video Interface
int32_t VideoDrv_Initialize (VideoDrv_Event_t cb_event) {

  #if (VIDEO_INPUT_CHANNELS == 1)
    VideoI0->Initialize(VideoI0_Event);
    VideoI0->PowerControl(ARM_POWER_FULL);
    VideoI0->Control(CPI_CONFIGURE, 0U);
    VideoI0->Control(CPI_CAMERA_SENSOR_CONFIGURE, 0U);
    VideoI0->Control(CPI_EVENTS_CONFIGURE, ARM_CPI_EVENT_CAMERA_CAPTURE_STOPPED |
                                           ARM_CPI_EVENT_ERR_CAMERA_INPUT_FIFO_OVERRUN |
                                           ARM_CPI_EVENT_ERR_CAMERA_OUTPUT_FIFO_OVERRUN |
                                           ARM_CPI_EVENT_ERR_HARDWARE);
    video_config[0].configured = 0U;
  #endif

  #if (VIDEO_OUTPUT_CHANNELS == 1)
    VideoO0->Initialize(VideoO0_Event);
    VideoO0->PowerControl(ARM_POWER_FULL);
    video_config[1].configured = 0U;
  #endif

  CB_Event = cb_event;

  Initialized = 1U;

  return VIDEO_DRV_OK;
}

// De-initialize Video Interface
int32_t VideoDrv_Uninitialize (void) {

  #if (VIDEO_INPUT_CHANNELS == 1)
    VideoI0->Uninitialize();
  #endif
  #if (VIDEO_OUTPUT_CHANNELS == 1)
    VideoO0->Uninitialize();
  #endif

  Initialized = 0U;

  return VIDEO_DRV_OK;
}

// Set Video Interface file
int32_t VideoDrv_SetFile (uint32_t channel, const char *name) {

  // Unsupported function

  return VIDEO_DRV_ERROR;
}

// Configure Video Interface
int32_t VideoDrv_Configure (uint32_t channel, uint32_t frame_width, uint32_t frame_height, uint32_t color_format, uint32_t frame_rate) {
  uint32_t pixel_size;

  if ((((channel & 1U) == 0U) && ((channel >> 1) >= VIDEO_INPUT_CHANNELS))  ||
      (((channel & 1U) != 0U) && ((channel >> 1) >= VIDEO_OUTPUT_CHANNELS)) ||
      (frame_width  == 0U) ||
      (frame_height == 0U) ||
      (frame_rate   == 0U) ||
      (color_format <= VIDEO_DRV_COLOR_FORMAT_BEGIN) ||
      (color_format >= VIDEO_DRV_COLOR_FORMAT_END)) {
    return VIDEO_DRV_ERROR_PARAMETER;
  }

  if (channel == VIDEO_DRV_IN0) {
    if((frame_width  != CAMERA_FRAME_WIDTH)  ||
       (frame_height != CAMERA_FRAME_HEIGHT) ||
       (frame_rate   != CAMERA_FRAME_RATE)) {
      return VIDEO_DRV_ERROR_PARAMETER;
    }
  }

  if (channel == VIDEO_DRV_OUT0) {
    if((frame_width  != DISPLAY_FRAME_WIDTH)  ||
       (frame_height != DISPLAY_FRAME_HEIGHT) ||
       (frame_rate   != DISPLAY_FRAME_RATE)) {
      return VIDEO_DRV_ERROR_PARAMETER;
    }
  }

  switch (color_format) {
    case VIDEO_DRV_COLOR_RGB888:
      pixel_size = 24U;
      break;
    case VIDEO_DRV_COLOR_BGR565:
      pixel_size = 16U;
      break;
    // Unsupported
    case VIDEO_DRV_COLOR_GRAYSCALE8:
    case VIDEO_DRV_COLOR_YUV420:
    case VIDEO_DRV_COLOR_NV12:
    case VIDEO_DRV_COLOR_NV21:
    default:
      return VIDEO_DRV_ERROR;
  }

  if (Initialized == 0U) {
    return VIDEO_DRV_ERROR;
  }

  if (video_config[channel].active != 0U) {
    return VIDEO_DRV_ERROR;
  }

  video_config[channel].frame_width  = frame_width;
  video_config[channel].frame_height = frame_height;
  video_config[channel].pixel_size   = pixel_size;
  video_config[channel].configured   = 1U;

  return VIDEO_DRV_OK;
}

// Set Video Interface buffer
int32_t VideoDrv_SetBuf (uint32_t channel, void *buf, uint32_t buf_size) {
  uint32_t block_size, block_num;

  if ((((channel & 1U) == 0U) && ((channel >> 1) >= VIDEO_INPUT_CHANNELS))  ||
      (((channel & 1U) != 0U) && ((channel >> 1) >= VIDEO_OUTPUT_CHANNELS)) ||
      (buf      == NULL) ||
      (buf_size == 0U)) {
    return VIDEO_DRV_ERROR_PARAMETER;
  }

  if ((Initialized == 0U) ||
      (video_config[channel].configured == 0U)) {
    return VIDEO_DRV_ERROR;
  }

  if (video_config[channel].active != 0U) {
    return VIDEO_DRV_ERROR;
  }

  block_size = (((video_config[channel].frame_width * video_config[channel].frame_height) *
                  video_config[channel].pixel_size) + 7U) / 8U;
  block_num = buf_size / block_size;

  if (block_num == 0U) {
    return VIDEO_DRV_ERROR;
  }

  if (channel & VIDEO_DRV_OUT0) {
    VideoO0->Control(CDC200_CONFIGURE_DISPLAY, (uint32_t)buf);
  }

  video_config[channel].buf = buf;
  video_config[channel].configured = 2U;

  return VIDEO_DRV_OK;
}

// Flush Video Interface buffer
int32_t VideoDrv_FlushBuf (uint32_t channel) {

  if ((((channel & 1U) == 0U) && ((channel >> 1) >= VIDEO_INPUT_CHANNELS))  ||
      (((channel & 1U) != 0U) && ((channel >> 1) >= VIDEO_OUTPUT_CHANNELS))) {
    return VIDEO_DRV_ERROR_PARAMETER;
  }

  if (Initialized == 0U) {
    return VIDEO_DRV_ERROR;
  }

  if (video_config[channel].active != 0U) {
    return VIDEO_DRV_ERROR;
  }

  video_config[channel].status |=  Reg_STATUS_BUF_EMPTY_Msk;
  video_config[channel].status &= ~Reg_STATUS_BUF_FULL_Msk;

  return VIDEO_DRV_OK;
}

// Start Stream on Video Interface
int32_t VideoDrv_StreamStart (uint32_t channel, uint32_t mode) {
  uint32_t ret;

  if ((((channel & 1U) == 0U) && ((channel >> 1) >= VIDEO_INPUT_CHANNELS))  ||
      (((channel & 1U) != 0U) && ((channel >> 1) >= VIDEO_OUTPUT_CHANNELS)) ||
      (mode > VIDEO_DRV_MODE_CONTINUOS)) {
    return VIDEO_DRV_ERROR_PARAMETER;
  }

  if ((Initialized == 0U) ||
      (video_config[channel].configured <  2U)) {
    return VIDEO_DRV_ERROR;
  }

  if (video_config[channel].active != 0U) {
    return VIDEO_DRV_OK;
  }

  if (channel == VIDEO_DRV_IN0) {
    if (mode == VIDEO_DRV_MODE_SINGLE) {
      ret = VideoI0->CaptureFrame(video_config[channel].buf);
      if (ret != ARM_DRIVER_OK) {
        return VIDEO_DRV_ERROR;
      }
    } else {
      return VIDEO_DRV_ERROR;
    }
  }

  if (channel == VIDEO_DRV_OUT0) {
    if (mode == VIDEO_DRV_MODE_SINGLE) {
      return VIDEO_DRV_ERROR;
    } else {
      ret = VideoO0->Start();
      if (ret != ARM_DRIVER_OK) {
        return VIDEO_DRV_ERROR;
      }
    }
  }

  video_config[channel].active = 1U;

  return VIDEO_DRV_OK;
}

// Stop Stream on Video Interface
int32_t VideoDrv_StreamStop (uint32_t channel) {

  if ((((channel & 1U) == 0U) && ((channel >> 1) >= VIDEO_INPUT_CHANNELS))  ||
      (((channel & 1U) != 0U) && ((channel >> 1) >= VIDEO_OUTPUT_CHANNELS))) {
    return VIDEO_DRV_ERROR_PARAMETER;
  }

  if ((Initialized == 0U) ||
      (video_config[channel].configured <  2U)) {
    return VIDEO_DRV_ERROR;
  }

  if (channel == VIDEO_DRV_IN0) {
    VideoI0->Stop();
  }

  if (channel == VIDEO_DRV_OUT0) {
    VideoO0->Stop();
  }

  video_config[channel].active = 0U;

  return VIDEO_DRV_OK;
}

// Get Video Frame buffer
void *VideoDrv_GetFrameBuf (uint32_t channel) {
  void *frame;

  if ((((channel & 1U) == 0U) && ((channel >> 1) >= VIDEO_INPUT_CHANNELS))  ||
      (((channel & 1U) != 0U) && ((channel >> 1) >= VIDEO_OUTPUT_CHANNELS))) {
    return NULL;
  }

  if ((Initialized == 0U) ||
      (video_config[channel].configured < 2U)) {
    return NULL;
  }

  if (channel == VIDEO_DRV_IN0) {
    if ((video_config[channel].status & Reg_STATUS_BUF_EMPTY_Msk) != 0U) {
      return NULL;
    }
  }

  if (channel == VIDEO_DRV_OUT0) {
    if ((video_config[channel].status & Reg_STATUS_BUF_FULL_Msk) != 0U) {
      return NULL;
    }
  }

  frame = video_config[channel].buf;

  return frame;
}

// Release Video Frame
int32_t VideoDrv_ReleaseFrame (uint32_t channel) {

  if ((((channel & 1U) == 0U) && ((channel >> 1) >= VIDEO_INPUT_CHANNELS))  ||
      (((channel & 1U) != 0U) && ((channel >> 1) >= VIDEO_OUTPUT_CHANNELS))) {
    return VIDEO_DRV_ERROR_PARAMETER;
  }

  if ((Initialized == 0U) ||
      (video_config[channel].configured < 2U)) {
    return VIDEO_DRV_ERROR;
  }

  if (channel == VIDEO_DRV_IN0) {
    if ((video_config[channel].status & Reg_STATUS_BUF_EMPTY_Msk) != 0U) {
      return VIDEO_DRV_ERROR;
    }
  }

  if (channel == VIDEO_DRV_OUT0) {
    if ((video_config[channel].status & Reg_STATUS_BUF_FULL_Msk) != 0U) {
      return VIDEO_DRV_ERROR;
    }
  }

  return VIDEO_DRV_OK;
}


// Get Video Interface status
VideoDrv_Status_t VideoDrv_GetStatus (uint32_t channel) {
  VideoDrv_Status_t status = { 0U, 0U, 0U, 0U, 0U, 0U, 0U };

  status.active    = video_config[channel].active;
  status.buf_empty = (video_config[channel].status & Reg_STATUS_BUF_EMPTY_Msk) >> Reg_STATUS_BUF_EMPTY_Pos;
  status.buf_full  = (video_config[channel].status & Reg_STATUS_BUF_FULL_Msk)  >> Reg_STATUS_BUF_FULL_Pos;

  return status;
}
