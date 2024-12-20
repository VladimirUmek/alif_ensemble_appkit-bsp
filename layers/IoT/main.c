/*---------------------------------------------------------------------------
 * Copyright (c) 2024 Arm Limited (or its affiliates). All rights reserved.
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
 *---------------------------------------------------------------------------*/

#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_vio.h"
#ifdef    CMSIS_shield_header
#include  CMSIS_shield_header
#endif

#include "conductor_board_config.h"
#include "ethosu_driver.h"
#include "main.h"
#include "power.h"

#include "se_services_port.h"


#ifdef CMSIS_shield_header
__WEAK int32_t shield_setup (void) {
  return 0;
}
#endif

static struct ethosu_driver npuDriver;

static void npu_irq_handler(void) {
  ethosu_irq_handler(&npuDriver);
}

int NpuInit() {
  void * const npuBaseAddr = (void *) LOCAL_NPU_BASE;

  /*  Initialize Ethos-U NPU driver. */
  if (ethosu_init(&npuDriver, /* Arm Ethos-U device driver pointer  */
                  npuBaseAddr, /* Base address for the Arm Ethos-U device */
                  0, /* Cache memory pointer (not applicable for U55) */
                  0, /* Cache memory size */
                  1, /* Secure */
                  1) /* Privileged */ ) {
    return 1;
  }

  NVIC_SetVector(LOCAL_NPU_IRQ_IRQn, (uint32_t) &npu_irq_handler);
  NVIC_EnableIRQ(LOCAL_NPU_IRQ_IRQn);

  return 0;
}

void clock_init(void) {
  uint32_t service_error_code = 0;
  /* Enable Clocks */
  uint32_t error_code = SERVICES_clocks_enable_clock(se_services_s_handle, CLKEN_CLK_100M, true, &service_error_code);
  if(error_code || service_error_code) {
    // printf("SE: 100MHz clock enable error_code=%u se_error_code=%u\n", error_code, service_error_code);
    return;
  }

  error_code = SERVICES_clocks_enable_clock(se_services_s_handle, CLKEN_HFOSC, true, &service_error_code);
  if(error_code || service_error_code) {
    // printf("SE: HFOSC enable error_code=%u se_error_code=%u\n", error_code, service_error_code);
    return;
  }
}

#ifdef COPY_VECTORS
#include <string.h> // memcpy
static VECTOR_TABLE_Type MyVectorTable[496] __attribute__((aligned (2048))) __attribute__((section (".bss.noinit.ram_vectors")));
static void copy_vtor_table_to_ram()
{
  if (SCB->VTOR == (uint32_t) MyVectorTable) {
    return;
  }
  memcpy(MyVectorTable, (const void *) SCB->VTOR, sizeof MyVectorTable);
  __DMB();
  // Set the new vector table into use.
  SCB->VTOR = (uint32_t) MyVectorTable;
  __DSB();
}
#endif

static void CpuCacheEnable(void) {
  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}

int main (void) {
#ifdef COPY_VECTORS
  copy_vtor_table_to_ram();
#endif
  /* Apply pin configuration */
  conductor_pins_config();

  se_services_port_init();

  enable_mipi_dphy_power();
  disable_mipi_dphy_isolation();

  clock_init();

  NpuInit();

  /* Initialize STDIO */
  stdio_init();

  /* Initialize Virtual I/O */
  vioInit();

#ifdef CMSIS_shield_header
  shield_setup();
#endif

  /* Enable the CPU Cache */
  CpuCacheEnable();

  return (app_main());
}
