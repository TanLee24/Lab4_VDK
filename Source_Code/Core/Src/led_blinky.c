/*
 * led_blinky.c
 *
 *  Created on: Nov 10, 2025
 *      Author: LENOVO
 */

#include "led_blinky.h"

void ledBlinky()
{
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}
