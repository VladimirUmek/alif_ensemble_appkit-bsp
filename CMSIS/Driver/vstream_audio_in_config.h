/*---------------------------------------------------------------------------
 * Copyright (c) 2025 Arm Limited (or its affiliates).
 * All rights reserved.
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

#ifdef   CMSIS_target_header
#include CMSIS_target_header
#else
#define CMSIS_DRIVER_VSTREAM_AUDIO_IN  0
#define CMSIS_DRIVER_SAI               0
#endif

//------------------- Open Preview for Configuration Wizard --------------------

//  <y>Export Driver Number (Driver_vStream#)
//  <i> Define the number of the exported driver (Driver_vStream#).
//  <i> Default: 0
#ifndef AUDIO_CFG_VSTREAM_INSTANCE
#define AUDIO_CFG_VSTREAM_INSTANCE  CMSIS_DRIVER_VSTREAM_AUDIO_IN
#endif

//  <y>Connect to hardware via Driver_SAI#
//  <i>Select driver control block for hardware interface
#ifndef AUDIO_CFG_SAI_INSTANCE
#define AUDIO_CFG_SAI_INSTANCE      CMSIS_DRIVER_SAI
#endif

//  <o>Number of bits per sample <0=>8 <1=>16 <2=>24 <3=>32
//  <i>Defines number of bits of information in each sample.
#ifndef AUDIO_CFG_BIT_DEPTH
#define AUDIO_CFG_BIT_DEPTH         16
#endif

//  <o>Number of samples per second
//  <i>Defines audio sampling rate.
#ifndef AUDIO_CFG_SAMPLE_RATE
#define AUDIO_CFG_SAMPLE_RATE       16000U
#endif
