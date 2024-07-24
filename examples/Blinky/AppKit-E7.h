/*---------------------------------------------------------------------------
 * Copyright (c) 2024 Arm Limited (or its affiliates).
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

#ifndef APPKIT_E7_H_
#define APPKIT_E7_H_

#include "Driver_GPIO_Private.h"
#include "Driver_ETH_MAC.h"
#include "Driver_USART.h"

// CMSIS Driver instances of Board peripherals
#define CMSIS_DRIVER_USART  4     // CMSIS Driver USART instance number

// Retarget stdio to CMSIS UART
#define RETARGET_STDIO_UART 4

// CMSIS Drivers
extern ARM_DRIVER_USART   Driver_USART4;   /* PRG USB */

#ifdef CMSIS_shield_header
#include CMSIS_shield_header
#endif

#endif /* APPKIT_E7_H_ */
