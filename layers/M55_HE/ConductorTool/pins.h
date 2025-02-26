/* 
*   Copyright (C) 2024 Alif Semiconductor - All Rights Reserved.
*   Use, distribution and modification of this code is permitted under the
*   terms stated in the Alif Semiconductor Software License Agreement
*
*   You should have received a copy of the Alif Semiconductor Software
*   License Agreement with this file. If not, please write to:
*   https://alifsemi.com/contact/, or visit: https://alifsemi.com/license/
*/
/******************************************************************************
* @file    	pins.h
* @author  	Auto generated by Conductor Tool https://conductor.alifsemi.com/
* @version  v1.0.0
* @date     2024-10-29
* @brief   	Pin MUX and Pin Config settings for "AI/ML AppKit Gen 2 (AK-E7-AIML)"
*           project with AE722F80F55D5LS.
* @bug      None.
* @note     None.
******************************************************************************/

#ifndef __PINS_H__
#define __PINS_H__

#include <stdint.h>
#include "pinconf.h"

struct pinconf {
    uint8_t port;
    uint8_t pin;
    uint8_t alternate_function;
    uint8_t pad_control;
};

/* Pin Mux and Config Values generated by Conductor Tool */

const struct pinconf board_pinconf[] = {
	/* P0_3 on pin R11. Functions: [0]: GPIO0_3, [1]: OSPI0_D3_A, [2]: UART0_RTS_A, [3]: I2C0_SCL_A, [4]: UT1_T1_A, [5]: LPCAM_XVCLK_B, [6]: >>>CAM_XVCLK_A<<<, [7]: ANA_S3 */
	/* Selected: CAM_XVCLK_A for "My CPI" */
	{PORT_0, PIN_3, PINMUX_ALTERNATE_FUNCTION_6, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P0_4 on pin R10. Functions: [0]: GPIO0_4, [1]: OSPI0_D4_A, [2]: >>>UART1_RX_A<<<, [3]: PDM_D0_A, [4]: I2C1_SDA_A, [5]: UT2_T0_A, [6]: CAN_RXD_B, [7]: ANA_S4 */
	/* Selected: UART1_RX_A for "WE310F5 WIFI BLE" */
	{PORT_0, PIN_4, PINMUX_ALTERNATE_FUNCTION_2, PADCTRL_READ_ENABLE | PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P0_5 on pin N15. Functions: [0]: GPIO0_5, [1]: OSPI0_D5_A, [2]: >>>UART1_TX_A<<<, [3]: PDM_C0_A, [4]: I2C1_SCL_A, [5]: UT2_T1_A, [6]: CAN_TXD_B, [7]: ANA_S5 */
	/* Selected: UART1_TX_A for "WE310F5 WIFI BLE" */
	{PORT_0, PIN_5, PINMUX_ALTERNATE_FUNCTION_2, PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P0_6 on pin P15. Functions: [0]: GPIO0_6, [1]: OSPI0_D6_A, [2]: >>>UART1_CTS_A<<<, [3]: PDM_D1_A, [4]: I2C2_SCL_A, [5]: UT3_T0_A, [6]: CAN_STBY_B, [7]: ANA_S6 */
	/* Selected: UART1_CTS_A for "WE310F5 WIFI BLE" */
	{PORT_0, PIN_6, PINMUX_ALTERNATE_FUNCTION_2, PADCTRL_READ_ENABLE | PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P0_7 on pin R15. Functions: [0]: GPIO0_7, [1]: OSPI0_D7_A, [2]: >>>UART1_RTS_A<<<, [3]: PDM_C1_A, [4]: I2C2_SDA_A, [5]: UT3_T1_A, [6]: CDC_DE_B, [7]: ANA_S7 */
	/* Selected: UART1_RTS_A for "WE310F5 WIFI BLE" */
	{PORT_0, PIN_7, PINMUX_ALTERNATE_FUNCTION_2, PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P1_0 on pin R14. Functions: [0]: GPIO1_0, [1]: >>>UART2_RX_A<<<, [2]: SPI0_MISO_A, [3]: I2C3_SDA_A, [4]: UT4_T0_A, [5]: LPCAM_HSYNC_C, [6]: ETH_RXD0_C, [7]: ANA_S8 */
	/* Selected: UART2_RX_A for "UARTA" */
	{PORT_1, PIN_0, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P1_1 on pin M15. Functions: [0]: GPIO1_1, [1]: >>>UART2_TX_A<<<, [2]: SPI0_MOSI_A, [3]: I2C3_SCL_A, [4]: UT4_T1_A, [5]: LPCAM_VSYNC_C, [6]: ETH_RXD1_C, [7]: ANA_S9 */
	/* Selected: UART2_TX_A for "UARTA" */
	{PORT_1, PIN_1, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P1_6 on pin L19. Functions: [0]: GPIO1_6, [1]: >>>OSPI0_RXDS_B<<<, [2]: UART1_RX_B, [3]: I2S0_SDI_A, [4]: UT7_T0_A, [5]: LPCAM_D2_C, [6]: ETH_IRQ_C, [7]: ANA_S14 */
	/* Selected: OSPI0_RXDS_B for "ISSI RAM" */
	{PORT_1, PIN_6, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P2_0 on pin K19. Functions: [0]: GPIO2_0, [1]: >>>OSPI0_D0_B<<<, [2]: UART2_RX_B, [3]: LPPDM_D0_A, [4]: UT8_T0_A, [5]: LPCAM_D4_C, [6]: ETH_MDIO_C, [7]: ANA_S16 */
	/* Selected: OSPI0_D0_B for "ISSI RAM" */
	{PORT_2, PIN_0, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P2_1 on pin K18. Functions: [0]: GPIO2_1, [1]: >>>OSPI0_D1_B<<<, [2]: UART2_TX_B, [3]: LPPDM_C0_A, [4]: UT8_T1_A, [5]: LPCAM_D5_C, [6]: ETH_MDC_C, [7]: ANA_S17 */
	/* Selected: OSPI0_D1_B for "ISSI RAM" */
	{PORT_2, PIN_1, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P2_2 on pin J15. Functions: [0]: GPIO2_2, [1]: >>>OSPI0_D2_B<<<, [2]: UART3_RX_B, [3]: LPPDM_D1_A, [4]: UT9_T0_A, [5]: LPCAM_D6_C, [6]: ETH_CRS_DV_C, [7]: ANA_S18 */
	/* Selected: OSPI0_D2_B for "ISSI RAM" */
	{PORT_2, PIN_2, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P2_3 on pin H15. Functions: [0]: GPIO2_3, [1]: >>>OSPI0_D3_B<<<, [2]: UART3_TX_B, [3]: LPPDM_C1_A, [4]: UT9_T1_A, [5]: LPCAM_D7_C, [6]: CDC_PCLK_B, [7]: ANA_S19 */
	/* Selected: OSPI0_D3_B for "ISSI RAM" */
	{PORT_2, PIN_3, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P2_4 on pin G19. Functions: [0]: GPIO2_4, [1]: >>>OSPI0_D4_B<<<, [2]: LPI2S_SDI_A, [3]: SPI1_MISO_A, [4]: UT10_T0_A, [5]: LPCAM_D0_B, [6]: CAM_D0_A, [7]: ANA_S20 */
	/* Selected: OSPI0_D4_B for "ISSI RAM" */
	{PORT_2, PIN_4, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P2_5 on pin H19. Functions: [0]: GPIO2_5, [1]: >>>OSPI0_D5_B<<<, [2]: LPI2S_SDO_A, [3]: SPI1_MOSI_A, [4]: UT10_T1_A, [5]: LPCAM_D1_B, [6]: CAM_D1_A, [7]: ANA_S21 */
	/* Selected: OSPI0_D5_B for "ISSI RAM" */
	{PORT_2, PIN_5, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P2_6 on pin H18. Functions: [0]: GPIO2_6, [1]: >>>OSPI0_D6_B<<<, [2]: LPI2S_SCLK_A, [3]: SPI1_SCLK_A, [4]: UT11_T0_A, [5]: LPCAM_D2_B, [6]: CAM_D2_A, [7]: ANA_S22 */
	/* Selected: OSPI0_D6_B for "ISSI RAM" */
	{PORT_2, PIN_6, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P2_7 on pin J19. Functions: [0]: GPIO2_7, [1]: >>>OSPI0_D7_B<<<, [2]: LPI2S_WS_A, [3]: SPI1_SS0_A, [4]: UT11_T1_A, [5]: LPCAM_D3_B, [6]: CAM_D3_A, [7]: ANA_S23 */
	/* Selected: OSPI0_D7_B for "ISSI RAM" */
	{PORT_2, PIN_7, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P3_0 on pin B6. Functions: [0]: GPIO3_0, [1]: >>>OSPI0_SCLK_B<<<, [2]: UART4_RX_A, [3]: PDM_D0_B, [4]: I2S0_SCLK_A, [5]: QEC0_X_A, [6]: LPCAM_D4_B, [7]: CAM_D4_A */
	/* Selected: OSPI0_SCLK_B for "ISSI RAM" */
	{PORT_3, PIN_0, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P3_1 on pin A6. Functions: [0]: GPIO3_1, [1]: >>>OSPI0_SCLKN_B<<<, [2]: UART4_TX_A, [3]: PDM_C0_B, [4]: I2S0_WS_A, [5]: QEC0_Y_A, [6]: LPCAM_D5_B, [7]: CAM_D5_A */
	/* Selected: OSPI0_SCLKN_B for "ISSI RAM" */
	{PORT_3, PIN_1, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P3_2 on pin E2. Functions: [0]: GPIO3_2, [1]: >>>OSPI0_SS0_B<<<, [2]: PDM_D1_B, [3]: I2S1_SDI_A, [4]: I3C_SDA_C, [5]: QEC0_Z_A, [6]: LPCAM_D6_B, [7]: CAM_D6_A */
	/* Selected: OSPI0_SS0_B for "ISSI RAM" */
	{PORT_3, PIN_2, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P3_4 on pin F2. Functions: [0]: GPIO3_4, [1]: OSPI0_RXDS_A, [2]: UART5_RX_A, [3]: LPPDM_C0_B, [4]: I2S1_SCLK_A, [5]: >>>I2C0_SCL_B<<<, [6]: QEC1_Y_A, [7]: CAM_D8_A */
	/* Selected: I2C0_SCL_B for "WM8904 CODEC" */
	{PORT_3, PIN_4, PINMUX_ALTERNATE_FUNCTION_5, PADCTRL_READ_ENABLE | PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P3_5 on pin F1. Functions: [0]: GPIO3_5, [1]: OSPI0_SCLKN_A, [2]: UART5_TX_A, [3]: LPPDM_D0_B, [4]: SPI0_SS1_B, [5]: >>>I2C0_SDA_B<<<, [6]: QEC1_Z_A, [7]: CAM_D9_A */
	/* Selected: I2C0_SDA_B for "WM8904 CODEC" */
	{PORT_3, PIN_5, PINMUX_ALTERNATE_FUNCTION_5, PADCTRL_READ_ENABLE | PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P4_0 on pin F18. Functions: [0]: >>>GPIO4_0<<<, [1]: Reserved, [2]: Reserved, [3]: I2S1_WS_A, [4]: SPI1_SS2_A, [5]: QEC2_Z_A, [6]: CDC_VSYNC_B, [7]: CAM_D12_A */
	/* Selected: GPIO4_0 for "TOUCH_RESET" */
	{PORT_4, PIN_0, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P4_4 on pin B17. Functions: [0]: GPIO4_4, [1]: >>>JTAG_TCK<<<, [2]: I2S0_WS_B, [3]: SPI2_SCLK_A, [4]: FAULT0_A */
	/* Selected: JTAG_TCK for "My JTAG" */
	{PORT_4, PIN_4, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SCHMITT_TRIGGER_ENABLE | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P4_5 on pin A19. Functions: [0]: GPIO4_5, [1]: >>>JTAG_TMS<<<, [2]: SPI2_SS0_A, [3]: FAULT1_A */
	/* Selected: JTAG_TMS for "My JTAG" */
	{PORT_4, PIN_5, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SCHMITT_TRIGGER_ENABLE | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P4_6 on pin A18. Functions: [0]: GPIO4_6, [1]: >>>JTAG_TDI<<<, [2]: SPI2_SS1_A, [3]: FAULT2_A */
	/* Selected: JTAG_TDI for "My JTAG" */
	{PORT_4, PIN_6, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SCHMITT_TRIGGER_ENABLE | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P4_7 on pin B16. Functions: [0]: GPIO4_7, [1]: >>>JTAG_TDO<<<, [2]: SPI2_SS2_A, [3]: FAULT3_A */
	/* Selected: JTAG_TDO for "My JTAG" */
	{PORT_4, PIN_7, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P5_4 on pin E11. Functions: [0]: GPIO5_4, [1]: OSPI1_SS1_A, [2]: UART3_CTS_A, [3]: >>>PDM_D2_B<<<, [4]: SPI0_SS3_A, [5]: UT2_T0_B, [6]: SD_D4_A, [7]: CDC_DE_A */
	/* Selected: PDM_D2_B for "PDM MIC" */
	{PORT_5, PIN_4, PINMUX_ALTERNATE_FUNCTION_3, PADCTRL_READ_ENABLE | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P5_5 on pin E10. Functions: [0]: GPIO5_5, [1]: >>>OSPI1_SCLK_C<<<, [2]: UART3_RTS_A, [3]: PDM_D3_B, [4]: UT2_T1_B, [5]: SD_D5_A, [6]: ETH_RXD0_A, [7]: CDC_HSYNC_A */
	/* Selected: OSPI1_SCLK_C for "ISSI FLASH" */
	{PORT_5, PIN_5, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P5_7 on pin B11. Functions: [0]: GPIO5_7, [1]: >>>OSPI1_SS0_C<<<, [2]: UART1_RTS_B, [3]: I2C2_SDA_C, [4]: UT3_T1_B, [5]: SD_D7_A, [6]: ETH_RST_A */
	/* Selected: OSPI1_SS0_C for "ISSI FLASH" */
	{PORT_5, PIN_7, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P6_1 on pin E9. Functions: [0]: >>>GPIO6_1<<<, [1]: OSPI0_D1_C, [2]: UART5_DE_A, [3]: PDM_C0_C, [4]: UT4_T1_B, [5]: SD_D1_D, [6]: ETH_TXD1_A */
	/* Selected: GPIO6_1 for "LCD_BACKLIGHT" */
	{PORT_6, PIN_1, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P6_2 on pin A11. Functions: [0]: >>>GPIO6_2<<<, [1]: OSPI0_D2_C, [2]: UART2_CTS_A, [3]: Reserved, [4]: PDM_D1_C, [5]: UT5_T0_B, [6]: SD_D2_D, [7]: ETH_TXEN_A */
	/* Selected: GPIO6_2 for "LEDRGB1_R" */
	{PORT_6, PIN_2, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P6_5 on pin E7. Functions: [0]: >>>GPIO6_5<<<, [1]: OSPI0_D5_C, [2]: UART2_RTS_B, [3]: Reserved, [4]: SPI1_SS1_B, [5]: UT6_T1_B, [6]: SD_D5_D, [7]: ETH_MDIO_A */
	/* Selected: GPIO6_5 for "LEDRGB1_G" */
	{PORT_6, PIN_5, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P6_6 on pin E6. Functions: [0]: >>>GPIO6_6<<<, [1]: OSPI0_D6_C, [2]: UART0_CTS_B, [3]: Reserved, [4]: SPI1_SS2_B, [5]: UT7_T0_B, [6]: SD_D6_D, [7]: ETH_MDC_A */
	/* Selected: GPIO6_6 for "LEDRGB1_B" */
	{PORT_6, PIN_6, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P6_7 on pin A9. Functions: [0]: GPIO6_7, [1]: OSPI0_D7_C, [2]: UART0_RTS_B, [3]: >>>PDM_C2_A<<<, [4]: SPI1_SS3_B, [5]: UT7_T1_B, [6]: SD_D7_D, [7]: ETH_CRS_DV_A */
	/* Selected: PDM_C2_A for "PDM MIC" */
	{PORT_6, PIN_7, PINMUX_ALTERNATE_FUNCTION_3, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P7_2 on pin D1. Functions: [0]: GPIO7_2, [1]: Reserved, [2]: UART3_CTS_B, [3]: CMP1_OUT_A, [4]: SPI0_SCLK_C, [5]: >>>I2C1_SDA_C<<<, [6]: UT9_T0_B, [7]: SD_RST_A */
	/* Selected: I2C1_SDA_C for "Camera,GT911 Touchscreen" */
	{PORT_7, PIN_2, PINMUX_ALTERNATE_FUNCTION_5, PADCTRL_READ_ENABLE | PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P7_3 on pin A8. Functions: [0]: GPIO7_3, [1]: Reserved, [2]: UART3_RTS_B, [3]: CMP0_OUT_A, [4]: SPI0_SS0_C, [5]: >>>I2C1_SCL_C<<<, [6]: UT9_T1_B, [7]: CAN_STBY_A */
	/* Selected: I2C1_SCL_C for "Camera,GT911 Touchscreen" */
	{PORT_7, PIN_3, PINMUX_ALTERNATE_FUNCTION_5, PADCTRL_READ_ENABLE | PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P7_4 on pin T1 {FLEX IO}. Functions: [0]: >>>GPIO7_4<<<, [1]: Reserved, [2]: LPUART_CTS_A, [3]: LPPDM_C2_A, [4]: LPSPI_MISO_A, [5]: LPI2C_SCL_A, [6]: UT10_T0_B */
	/* Selected: GPIO7_4 for "LEDRGB0_G" */
	{PORT_7, PIN_4, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P7_5 on pin T2 {FLEX IO}. Functions: [0]: >>>GPIO7_5<<<, [1]: Reserved, [2]: LPUART_RTS_A, [3]: Reserved, [4]: LPPDM_D2_A, [5]: LPSPI_MOSI_A, [6]: LPI2C_SDA_A, [7]: UT10_T1_B */
	/* Selected: GPIO7_5 for "CAMERA_POWER" */
	{PORT_7, PIN_5, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P7_6 on pin U3 {FLEX IO}. Functions: [0]: GPIO7_6, [1]: Reserved, [2]: LPUART_RX_A, [3]: Reserved, [4]: LPPDM_C3_A, [5]: LPSPI_SCLK_A, [6]: >>>I3C_SDA_D<<<, [7]: UT11_T0_B */
	/* Selected: I3C_SDA_D for "ICM42670 IMU,BMI323 IMU" */
	{PORT_7, PIN_6, PINMUX_ALTERNATE_FUNCTION_6, PADCTRL_READ_ENABLE | PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P7_7 on pin U1 {FLEX IO}. Functions: [0]: GPIO7_7, [1]: Reserved, [2]: LPUART_TX_A, [3]: Reserved, [4]: LPPDM_D3_A, [5]: LPSPI_SS_A, [6]: >>>I3C_SCL_D<<<, [7]: UT11_T1_B */
	/* Selected: I3C_SCL_D for "ICM42670 IMU,BMI323 IMU" */
	{PORT_7, PIN_7, PINMUX_ALTERNATE_FUNCTION_6, PADCTRL_READ_ENABLE | PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P8_0 on pin B7. Functions: [0]: GPIO8_0, [1]: >>>OSPI1_SCLKN_C<<<, [2]: AUDIO_CLK_A, [3]: FAULT0_B, [4]: LPCAM_D0_A, [5]: SD_D0_C, [6]: CDC_D0_A, [7]: CAM_D0_B */
	/* Selected: OSPI1_SCLKN_C for "ISSI FLASH" */
	{PORT_8, PIN_0, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P8_1 on pin C2. Functions: [0]: GPIO8_1, [1]: >>>I2S2_SDI_A<<<, [2]: FAULT1_B, [3]: LPCAM_D1_A, [4]: SD_D1_C, [5]: CDC_D1_A, [6]: CAM_D1_B */
	/* Selected: I2S2_SDI_A for "WM8904 Output" */
	{PORT_8, PIN_1, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P8_2 on pin C3. Functions: [0]: GPIO8_2, [1]: >>>I2S2_SDO_A<<<, [2]: SPI0_SS3_B, [3]: FAULT2_B, [4]: LPCAM_D2_A, [5]: SD_D2_C, [6]: CDC_D2_A, [7]: CAM_D2_B */
	/* Selected: I2S2_SDO_A for "WM8904 Output" */
	{PORT_8, PIN_2, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P8_3 on pin A7. Functions: [0]: GPIO8_3, [1]: >>>I2S2_SCLK_A<<<, [2]: SPI1_MISO_B, [3]: FAULT3_B, [4]: LPCAM_D3_A, [5]: SD_D3_C, [6]: CDC_D3_A, [7]: CAM_D3_B */
	/* Selected: I2S2_SCLK_A for "WM8904 Output" */
	{PORT_8, PIN_3, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P8_4 on pin B4. Functions: [0]: >>>GPIO8_4<<<, [1]: I2S2_WS_A, [2]: SPI1_MOSI_B, [3]: QEC0_X_B, [4]: LPCAM_D4_A, [5]: SD_D4_C, [6]: CDC_D4_A, [7]: CAM_D4_B */
	/* Selected: GPIO8_4 for "ICM_IMU_IRQ" */
	{PORT_8, PIN_4, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_READ_ENABLE | PADCTRL_SCHMITT_TRIGGER_ENABLE | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P8_5 on pin H1. Functions: [0]: >>>GPIO8_5<<<, [1]: Reserved, [2]: SPI1_SCLK_B, [3]: QEC0_Y_B, [4]: LPCAM_D5_A, [5]: SD_D5_C, [6]: CDC_D5_A, [7]: CAM_D5_B */
	/* Selected: GPIO8_5 for "BMI_IMU_IRQ" */
	{PORT_8, PIN_5, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_READ_ENABLE | PADCTRL_SCHMITT_TRIGGER_ENABLE | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P8_6 on pin J2. Functions: [0]: GPIO8_6, [1]: Reserved, [2]: >>>I2S3_SCLK_B<<<, [3]: QEC0_Z_B, [4]: LPCAM_D6_A, [5]: SD_D6_C, [6]: CDC_D6_A, [7]: CAM_D6_B */
	/* Selected: I2S3_SCLK_B for "MIC Input" */
	{PORT_8, PIN_6, PINMUX_ALTERNATE_FUNCTION_2, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P8_7 on pin J1. Functions: [0]: GPIO8_7, [1]: Reserved, [2]: >>>I2S3_WS_B<<<, [3]: QEC1_X_B, [4]: LPCAM_D7_A, [5]: SD_D7_C, [6]: CDC_D7_A, [7]: CAM_D7_B */
	/* Selected: I2S3_WS_B for "MIC Input" */
	{PORT_8, PIN_7, PINMUX_ALTERNATE_FUNCTION_2, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P9_0 on pin K2. Functions: [0]: GPIO9_0, [1]: Reserved, [2]: >>>I2S3_SDI_B<<<, [3]: QEC1_Y_B, [4]: SD_CMD_C, [5]: CDC_D8_A, [6]: CAM_D8_B */
	/* Selected: I2S3_SDI_B for "MIC Input" */
	{PORT_9, PIN_0, PINMUX_ALTERNATE_FUNCTION_2, PADCTRL_READ_ENABLE | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P9_1 on pin K1. Functions: [0]: >>>GPIO9_1<<<, [1]: LPUART_RX_B, [2]: I2S3_SDO_B, [3]: QEC1_Z_B, [4]: SD_CLK_C, [5]: CDC_D9_A, [6]: CAM_D9_B */
	/* Selected: GPIO9_1 for "CAMERA_RESET" */
	{PORT_9, PIN_1, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P9_2 on pin G5. Functions: [0]: >>>GPIO9_2<<<, [1]: LPUART_TX_B, [2]: I2S3_SDI_A, [3]: SPI2_MISO_B, [4]: QEC2_X_B, [5]: SD_RST_C, [6]: CDC_D10_A, [7]: CAM_D10_B */
	/* Selected: GPIO9_2 for "CAMERA_FLASH" */
	{PORT_9, PIN_2, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P9_3 on pin H5. Functions: [0]: >>>GPIO9_3<<<, [1]: Reserved, [2]: UART7_RX_B, [3]: I2S3_SDO_A, [4]: SPI2_MOSI_B, [5]: QEC2_Y_B, [6]: CDC_D11_A, [7]: CAM_D11_B */
	/* Selected: GPIO9_3 for "CAMERA_TRIGGER" */
	{PORT_9, PIN_3, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P9_4 on pin J5. Functions: [0]: >>>GPIO9_4<<<, [1]: UART7_TX_B, [2]: I2S3_SCLK_A, [3]: SPI2_SCLK_B, [4]: I2C3_SDA_C, [5]: QEC2_Z_B, [6]: CDC_D12_A, [7]: CAM_D12_B */
	/* Selected: GPIO9_4 for "TOUCH_INT" */
	{PORT_9, PIN_4, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_READ_ENABLE | PADCTRL_SCHMITT_TRIGGER_ENABLE | PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P9_5 on pin L1. Functions: [0]: GPIO9_5, [1]: >>>OSPI1_D0_C<<<, [2]: I2S3_WS_A, [3]: SPI2_SS0_B, [4]: I2C3_SCL_C, [5]: QEC3_X_B, [6]: CDC_D13_A, [7]: CAM_D13_B */
	/* Selected: OSPI1_D0_C for "ISSI FLASH" */
	{PORT_9, PIN_5, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P9_6 on pin K5. Functions: [0]: GPIO9_6, [1]: >>>OSPI1_D1_C<<<, [2]: AUDIO_CLK_B, [3]: SPI2_SS1_B, [4]: I2C3_SDA_B, [5]: QEC3_Y_B, [6]: CDC_D14_A, [7]: CAM_D14_B */
	/* Selected: OSPI1_D1_C for "ISSI FLASH" */
	{PORT_9, PIN_6, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P9_7 on pin L5. Functions: [0]: GPIO9_7, [1]: >>>OSPI1_D2_C<<<, [2]: UART7_DE_B, [3]: SPI2_SS2_B, [4]: I2C3_SCL_B, [5]: QEC3_Z_B, [6]: CDC_D15_A, [7]: CAM_D15_B */
	/* Selected: OSPI1_D2_C for "ISSI FLASH" */
	{PORT_9, PIN_7, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P10_0 on pin M2. Functions: [0]: GPIO10_0, [1]: >>>OSPI1_D3_C<<<, [2]: UART6_DE_B, [3]: SPI2_SS3_B, [4]: UT0_T0_C, [5]: LPCAM_HSYNC_A, [6]: CDC_D16_A, [7]: CAM_HSYNC_B */
	/* Selected: OSPI1_D3_C for "ISSI FLASH" */
	{PORT_10, PIN_0, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P10_1 on pin M1. Functions: [0]: GPIO10_1, [1]: >>>OSPI1_D4_C<<<, [2]: Reserved, [3]: LPI2S_SDI_B, [4]: UT0_T1_C, [5]: LPCAM_VSYNC_A, [6]: CDC_D17_A, [7]: CAM_VSYNC_B */
	/* Selected: OSPI1_D4_C for "ISSI FLASH" */
	{PORT_10, PIN_1, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P10_2 on pin N1. Functions: [0]: GPIO10_2, [1]: >>>OSPI1_D5_C<<<, [2]: Reserved, [3]: LPI2S_SDO_B, [4]: UT1_T0_C, [5]: LPCAM_PCLK_A, [6]: CDC_D18_A, [7]: CAM_PCLK_B */
	/* Selected: OSPI1_D5_C for "ISSI FLASH" */
	{PORT_10, PIN_2, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P10_3 on pin N2. Functions: [0]: GPIO10_3, [1]: >>>OSPI1_D6_C<<<, [2]: Reserved, [3]: LPI2S_SCLK_B, [4]: UT1_T1_C, [5]: LPCAM_XVCLK_A, [6]: CDC_D19_A, [7]: CAM_XVCLK_B */
	/* Selected: OSPI1_D6_C for "ISSI FLASH" */
	{PORT_10, PIN_3, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P10_4 on pin M5. Functions: [0]: GPIO10_4, [1]: >>>OSPI1_D7_C<<<, [2]: Reserved, [3]: LPI2S_WS_B, [4]: I2C0_SDA_D, [5]: UT2_T0_C, [6]: ETH_TXD0_B, [7]: CDC_D20_A */
	/* Selected: OSPI1_D7_C for "ISSI FLASH" */
	{PORT_10, PIN_4, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P10_7 on pin P1. Functions: [0]: GPIO10_7, [1]: UART7_RX_A, [2]: I2S2_SCLK_B, [3]: SPI3_SCLK_B, [4]: I2C1_SCL_D, [5]: UT3_T1_C, [6]: CDC_D23_A, [7]: >>>OSPI1_RXDS_C<<< */
	/* Selected: OSPI1_RXDS_C for "ISSI FLASH" */
	{PORT_10, PIN_7, PINMUX_ALTERNATE_FUNCTION_7, PADCTRL_READ_ENABLE | PADCTRL_SLEW_RATE_FAST | PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA},

	/* P11_0 on pin P2. Functions: [0]: GPIO11_0, [1]: OSPI1_D0_A, [2]: UART7_TX_A, [3]: >>>I2S2_WS_B<<<, [4]: SPI3_SS0_B, [5]: UT4_T0_C, [6]: ETH_REFCLK_B, [7]: CDC_D0_B */
	/* Selected: I2S2_WS_B for "WM8904 Output" */
	{PORT_11, PIN_0, PINMUX_ALTERNATE_FUNCTION_3, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P12_0 on pin F19. Functions: [0]: >>>GPIO12_0<<<, [1]: OSPI0_SCLK_C, [2]: AUDIO_CLK_C, [3]: I2S1_SDI_B, [4]: UT8_T0_C, [5]: CDC_D8_B */
	/* Selected: GPIO12_0 for "LEDRGB0_B" */
	{PORT_12, PIN_0, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P12_1 on pin E18. Functions: [0]: GPIO12_1, [1]: OSPI0_SCLKN_C, [2]: >>>UART4_RX_B<<<, [3]: I2S1_SDO_B, [4]: UT8_T1_C, [5]: CDC_D9_B */
	/* Selected: UART4_RX_B for "UARTB" */
	{PORT_12, PIN_1, PINMUX_ALTERNATE_FUNCTION_2, PADCTRL_READ_ENABLE | PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P12_2 on pin E15. Functions: [0]: GPIO12_2, [1]: OSPI0_RXDS_C, [2]: >>>UART4_TX_B<<<, [3]: I2S1_SCLK_B, [4]: UT9_T0_C, [5]: CDC_D10_B */
	/* Selected: UART4_TX_B for "UARTB" */
	{PORT_12, PIN_2, PINMUX_ALTERNATE_FUNCTION_2, PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P12_3 on pin D18. Functions: [0]: >>>GPIO12_3<<<, [1]: OSPI0_SS0_C, [2]: UART4_DE_B, [3]: I2S1_WS_B, [4]: UT9_T1_C, [5]: CDC_D11_B */
	/* Selected: GPIO12_3 for "LEDRGB0_R" */
	{PORT_12, PIN_3, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P12_4 on pin F5. Functions: [0]: GPIO12_4, [1]: OSPI0_SS1_C, [2]: >>>SPI3_MISO_A<<<, [3]: UT10_T0_C, [4]: CAN_RXD_C, [5]: CDC_D12_B */
	/* Selected: SPI3_MISO_A for "WE310F5 WIFI BLE" */
	{PORT_12, PIN_4, PINMUX_ALTERNATE_FUNCTION_2, PADCTRL_READ_ENABLE | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P12_5 on pin A10. Functions: [0]: GPIO12_5, [1]: Reserved, [2]: >>>SPI3_MOSI_A<<<, [3]: UT10_T1_C, [4]: CAN_TXD_C, [5]: CDC_D13_B */
	/* Selected: SPI3_MOSI_A for "WE310F5 WIFI BLE" */
	{PORT_12, PIN_5, PINMUX_ALTERNATE_FUNCTION_2, PADCTRL_READ_ENABLE | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P12_6 on pin E5. Functions: [0]: GPIO12_6, [1]: Reserved, [2]: >>>SPI3_SCLK_A<<<, [3]: UT11_T0_C, [4]: CAN_STBY_C, [5]: CDC_D14_B */
	/* Selected: SPI3_SCLK_A for "WE310F5 WIFI BLE" */
	{PORT_12, PIN_6, PINMUX_ALTERNATE_FUNCTION_2, PADCTRL_READ_ENABLE | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P12_7 on pin D2. Functions: [0]: GPIO12_7, [1]: OSPI1_RXDS_B, [2]: Reserved, [3]: >>>SPI3_SS0_A<<<, [4]: UT11_T1_C, [5]: CDC_D15_B */
	/* Selected: SPI3_SS0_A for "WE310F5 WIFI BLE" */
	{PORT_12, PIN_7, PINMUX_ALTERNATE_FUNCTION_3, PADCTRL_READ_ENABLE | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P13_0 on pin G18. Functions: [0]: >>>GPIO13_0<<<, [1]: OSPI1_D0_B, [2]: Reserved, [3]: SPI3_SS1_A, [4]: QEC0_X_C, [5]: SD_D0_B, [6]: CDC_D16_B */
	/* Selected: GPIO13_0 for "WIFI_ENABLE" */
	{PORT_13, PIN_0, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P13_1 on pin G15. Functions: [0]: >>>GPIO13_1<<<, [1]: OSPI1_D1_B, [2]: SPI3_SS2_A, [3]: QEC0_Y_C, [4]: SD_D1_B, [5]: CDC_D17_B */
	/* Selected: GPIO13_1 for "WIFI_WAKE" */
	{PORT_13, PIN_1, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P13_2 on pin F15. Functions: [0]: >>>GPIO13_2<<<, [1]: OSPI1_D2_B, [2]: SPI3_SS3_A, [3]: QEC0_Z_C, [4]: SD_D2_B, [5]: CDC_D18_B */
	/* Selected: GPIO13_2 for "WIFI_RESET" */
	{PORT_13, PIN_2, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P13_3 on pin E13. Functions: [0]: >>>GPIO13_3<<<, [1]: OSPI1_D3_B, [2]: SPI2_SS3_A, [3]: QEC1_X_C, [4]: SD_D3_B, [5]: CDC_D19_B */
	/* Selected: GPIO13_3 for "WIFI_IRQ" */
	{PORT_13, PIN_3, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_READ_ENABLE | PADCTRL_SCHMITT_TRIGGER_ENABLE | PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P14_2 on pin G1. Functions: [0]: >>>GPIO14_2<<<, [1]: OSPI1_SS0_B, [2]: UART7_RX_C, [3]: Reserved, [4]: QEC3_Y_C, [5]: SD_RST_B */
	/* Selected: GPIO14_2 for "CODEC_IRQ" */
	{PORT_14, PIN_2, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_READ_ENABLE | PADCTRL_SCHMITT_TRIGGER_ENABLE | PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P15_0 on pin V2 {FLEX IO}. Functions: [0]: >>>GPIOV_0<<<, [1]: LPTMR0_CLK_IO. Note that LPGPIO_CTRL_n register has a different layout! */
	/* Selected: GPIOV_0 for "JOY_SW_A" */
	{PORT_15, PIN_0, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_READ_ENABLE | PADCTRL_SCHMITT_TRIGGER_ENABLE | PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P15_1 on pin W2 {FLEX IO}. Functions: [0]: >>>GPIOV_1<<<, [1]: LPTMR1_CLK_IO. Note that LPGPIO_CTRL_n register has a different layout! */
	/* Selected: GPIOV_1 for "JOY_SW_B" */
	{PORT_15, PIN_1, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_READ_ENABLE | PADCTRL_SCHMITT_TRIGGER_ENABLE | PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P15_2 on pin U2 {FLEX IO}. Functions: [0]: >>>GPIOV_2<<<, [1]: LPTMR2_CLK_IO. Note that LPGPIO_CTRL_n register has a different layout! */
	/* Selected: GPIOV_2 for "JOY_SW_C" */
	{PORT_15, PIN_2, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_READ_ENABLE | PADCTRL_SCHMITT_TRIGGER_ENABLE | PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P15_3 on pin V1 {FLEX IO}. Functions: [0]: >>>GPIOV_3<<<, [1]: LPTMR3_CLK_IO. Note that LPGPIO_CTRL_n register has a different layout! */
	/* Selected: GPIOV_3 for "JOY_SW_D" */
	{PORT_15, PIN_3, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_READ_ENABLE | PADCTRL_SCHMITT_TRIGGER_ENABLE | PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P15_4 on pin V3. Functions: [0]: >>>GPIOV_4<<<. Note that LPGPIO_CTRL_n register has a different layout! */
	/* Selected: GPIOV_4 for "JOY_SW_CENTER" */
	{PORT_15, PIN_4, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_READ_ENABLE | PADCTRL_SCHMITT_TRIGGER_ENABLE | PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P15_5 on pin W4. Functions: [0]: >>>GPIOV_5<<<. Note that LPGPIO_CTRL_n register has a different layout! */
	/* Selected: GPIOV_5 for "LCD_RESET" */
	{PORT_15, PIN_5, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P15_6 on pin V4. Functions: [0]: >>>GPIOV_6<<<. Note that LPGPIO_CTRL_n register has a different layout! */
	/* Selected: GPIOV_6 for "OSPI0_RESET" */
	{PORT_15, PIN_6, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA},

	/* P15_7 on pin W5. Functions: [0]: >>>GPIOV_7<<<. Note that LPGPIO_CTRL_n register has a different layout! */
	/* Selected: GPIOV_7 for "OSPI1_RESET" */
	{PORT_15, PIN_7, PINMUX_ALTERNATE_FUNCTION_0, PADCTRL_DRIVER_DISABLED_PULL_UP | PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA} 

};

#endif /* __PINS_H__ */
