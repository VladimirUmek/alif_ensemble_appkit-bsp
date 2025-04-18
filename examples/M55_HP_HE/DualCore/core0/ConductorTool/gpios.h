/* 
*   Copyright (C) 2025 Alif Semiconductor - All Rights Reserved.
*   Use, distribution and modification of this code is permitted under the
*   terms stated in the Alif Semiconductor Software License Agreement
*
*   You should have received a copy of the Alif Semiconductor Software
*   License Agreement with this file. If not, please write to:
*   https://alifsemi.com/contact/, or visit: https://alifsemi.com/license/
*/
/******************************************************************************
* @file    	gpios.h
* @author  	Auto generated by Conductor Tool https://conductor.alifsemi.com/
* @version  v1.0.0
* @date     2025-4-11
* @brief   	Pseudo-static GPIO pin settings for "AI/ML AppKit Gen 2 (AK-E7-AIML)"
*           project with AE722F80F55D5LS.
* @bug      None.
* @note     None.
******************************************************************************/

#ifndef __GPIOS_H__
#define __GPIOS_H__

#include <stdint.h>
#include "pinconf.h"

struct gpioconf {
    uint8_t	port_num;
    uint8_t	hardware_mode_lptimer_on_lpgpio;
    uint8_t initial_state_high;
    uint8_t direction_output;
    uint8_t debounce_enable;
    uint8_t interrupt_enable;
    uint8_t interrupt_edge;
    uint8_t interrupt_polarity_high_edge_rising;
    uint8_t interrupt_both_edge;
};

/* GPIO pseudo-static settings generated by Conductor Tool */

const struct gpioconf board_gpioconf[] = {

	/* Pin settings (8-bit, 1 bit per pin) for GPIO4
		1 - Reserved for LPGPIO
		2 - Output pins that will drive logic '1' after startup. Other output pins will drive '0'
		3 - Output pins. Other pins are inputs
		4 - Pins with debounce function enabled
		5 - Pins that will generate interrupts
		6 - Interrupts that are edge sensitive. Other interrupts are level sensitive
		7 - Interrupts generated on high level or on rising edge - depending on previous setting. Other pins are low level/falling edge sensitive
		8 - Interrupts generated on both edges. Other pins behavior is based on previous 2 settings */
	{
		PORT_4,
		0,
		(1<<PIN_0),
		(1<<PIN_0),
		0,
		0,
		0,
		0,
		0,
	}, 

	/* Pin settings (8-bit, 1 bit per pin) for GPIO6
		1 - Reserved for LPGPIO
		2 - Output pins that will drive logic '1' after startup. Other output pins will drive '0'
		3 - Output pins. Other pins are inputs
		4 - Pins with debounce function enabled
		5 - Pins that will generate interrupts
		6 - Interrupts that are edge sensitive. Other interrupts are level sensitive
		7 - Interrupts generated on high level or on rising edge - depending on previous setting. Other pins are low level/falling edge sensitive
		8 - Interrupts generated on both edges. Other pins behavior is based on previous 2 settings */
	{
		PORT_6,
		0,
		0,
		(1<<PIN_6) | (1<<PIN_2) | (1<<PIN_1),
		0,
		0,
		0,
		0,
		0,
	}, 

	/* Pin settings (8-bit, 1 bit per pin) for GPIO7
		1 - Reserved for LPGPIO
		2 - Output pins that will drive logic '1' after startup. Other output pins will drive '0'
		3 - Output pins. Other pins are inputs
		4 - Pins with debounce function enabled
		5 - Pins that will generate interrupts
		6 - Interrupts that are edge sensitive. Other interrupts are level sensitive
		7 - Interrupts generated on high level or on rising edge - depending on previous setting. Other pins are low level/falling edge sensitive
		8 - Interrupts generated on both edges. Other pins behavior is based on previous 2 settings */
	{
		PORT_7,
		0,
		0,
		(1<<PIN_5) | (1<<PIN_4),
		0,
		0,
		0,
		0,
		0,
	}, 

	/* Pin settings (8-bit, 1 bit per pin) for GPIO8
		1 - Reserved for LPGPIO
		2 - Output pins that will drive logic '1' after startup. Other output pins will drive '0'
		3 - Output pins. Other pins are inputs
		4 - Pins with debounce function enabled
		5 - Pins that will generate interrupts
		6 - Interrupts that are edge sensitive. Other interrupts are level sensitive
		7 - Interrupts generated on high level or on rising edge - depending on previous setting. Other pins are low level/falling edge sensitive
		8 - Interrupts generated on both edges. Other pins behavior is based on previous 2 settings */
	{
		PORT_8,
		0,
		0,
		0,
		0,
		(1<<PIN_5) | (1<<PIN_4),
		(1<<PIN_5) | (1<<PIN_4),
		0,
		0,
	}, 

	/* Pin settings (8-bit, 1 bit per pin) for GPIO9
		1 - Reserved for LPGPIO
		2 - Output pins that will drive logic '1' after startup. Other output pins will drive '0'
		3 - Output pins. Other pins are inputs
		4 - Pins with debounce function enabled
		5 - Pins that will generate interrupts
		6 - Interrupts that are edge sensitive. Other interrupts are level sensitive
		7 - Interrupts generated on high level or on rising edge - depending on previous setting. Other pins are low level/falling edge sensitive
		8 - Interrupts generated on both edges. Other pins behavior is based on previous 2 settings */
	{
		PORT_9,
		0,
		(1<<PIN_1),
		(1<<PIN_3) | (1<<PIN_2) | (1<<PIN_1),
		0,
		(1<<PIN_4),
		(1<<PIN_4),
		0,
		0,
	}, 

	/* Pin settings (8-bit, 1 bit per pin) for GPIO12
		1 - Reserved for LPGPIO
		2 - Output pins that will drive logic '1' after startup. Other output pins will drive '0'
		3 - Output pins. Other pins are inputs
		4 - Pins with debounce function enabled
		5 - Pins that will generate interrupts
		6 - Interrupts that are edge sensitive. Other interrupts are level sensitive
		7 - Interrupts generated on high level or on rising edge - depending on previous setting. Other pins are low level/falling edge sensitive
		8 - Interrupts generated on both edges. Other pins behavior is based on previous 2 settings */
	{
		PORT_12,
		0,
		0,
		(1<<PIN_3) | (1<<PIN_0),
		0,
		0,
		0,
		0,
		0,
	}, 

	/* Pin settings (8-bit, 1 bit per pin) for GPIO13
		1 - Reserved for LPGPIO
		2 - Output pins that will drive logic '1' after startup. Other output pins will drive '0'
		3 - Output pins. Other pins are inputs
		4 - Pins with debounce function enabled
		5 - Pins that will generate interrupts
		6 - Interrupts that are edge sensitive. Other interrupts are level sensitive
		7 - Interrupts generated on high level or on rising edge - depending on previous setting. Other pins are low level/falling edge sensitive
		8 - Interrupts generated on both edges. Other pins behavior is based on previous 2 settings */
	{
		PORT_13,
		0,
		(1<<PIN_2),
		(1<<PIN_2) | (1<<PIN_1) | (1<<PIN_0),
		0,
		(1<<PIN_3),
		(1<<PIN_3),
		0,
		0,
	}, 

	/* Pin settings (8-bit, 1 bit per pin) for GPIO14
		1 - Reserved for LPGPIO
		2 - Output pins that will drive logic '1' after startup. Other output pins will drive '0'
		3 - Output pins. Other pins are inputs
		4 - Pins with debounce function enabled
		5 - Pins that will generate interrupts
		6 - Interrupts that are edge sensitive. Other interrupts are level sensitive
		7 - Interrupts generated on high level or on rising edge - depending on previous setting. Other pins are low level/falling edge sensitive
		8 - Interrupts generated on both edges. Other pins behavior is based on previous 2 settings */
	{
		PORT_14,
		0,
		0,
		0,
		0,
		(1<<PIN_2),
		(1<<PIN_2),
		0,
		0,
	}, 

	/* Pin settings (8-bit, 1 bit per pin) for GPIO15
		1 - LPGPIO pins driven by LPTIMER
		2 - Output pins that will drive logic '1' after startup. Other output pins will drive '0'
		3 - Output pins. Other pins are inputs
		4 - Pins with debounce function enabled
		5 - Pins that will generate interrupts
		6 - Interrupts that are edge sensitive. Other interrupts are level sensitive
		7 - Interrupts generated on high level or on rising edge - depending on previous setting. Other pins are low level/falling edge sensitive
		8 - Interrupts generated on both edges. Other pins behavior is based on previous 2 settings */
	{
		PORT_15,
		0,
		(1<<PIN_7) | (1<<PIN_6) | (1<<PIN_5),
		(1<<PIN_7) | (1<<PIN_6) | (1<<PIN_5),
		(1<<PIN_4) | (1<<PIN_3) | (1<<PIN_2) | (1<<PIN_1) | (1<<PIN_0),
		(1<<PIN_4) | (1<<PIN_3) | (1<<PIN_2) | (1<<PIN_1) | (1<<PIN_0),
		(1<<PIN_4) | (1<<PIN_3) | (1<<PIN_1) | (1<<PIN_0),
		0,
		(1<<PIN_2),
	}
};

#endif /* __GPIOS_H__ */
