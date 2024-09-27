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
#include "main.h"
#include "power.h"

#include "se_services_port.h"


#ifdef CMSIS_shield_header
__WEAK int32_t shield_setup (void) {
  return 0;
}
#endif

void clock_init(void)
{
  uint32_t service_error_code = 0;
  /* Enable Clocks */
  uint32_t error_code = SERVICES_clocks_enable_clock(se_services_s_handle, CLKEN_CLK_100M, true, &service_error_code);
  if(error_code || service_error_code){
    // printf("SE: 100MHz clock enable error_code=%u se_error_code=%u\n", error_code, service_error_code);
    return;
  }

  error_code = SERVICES_clocks_enable_clock(se_services_s_handle, CLKEN_HFOSC, true, &service_error_code);
  if(error_code || service_error_code){
    // printf("SE: HFOSC enable error_code=%u se_error_code=%u\n", error_code, service_error_code);
    return;
  }
}

int main (void) {

  /* Apply pin configuration */
  conductor_pins_config();

  se_services_port_init();
  
  enable_mipi_dphy_power();
  disable_mipi_dphy_isolation();

  clock_init();

  /* Initialize STDIO */
  stdio_init();

  /* Initialize Virtual I/O */
  vioInit();

#ifdef CMSIS_shield_header
  shield_setup();
#endif

  return (app_main());
}
