/*
 * traffic.c
 *
 *  Created on: Nov 10, 2025
 *      Author: LENOVO
 */

#include "traffic.h"

// ======= LED SET 1 =======
void turnOnRed1(void) {
    HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
}
void turnOffRed1(void) {
    HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
}
void toggleRed1(void) {
    HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
}

void turnOnYellow1(void) {
    HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_RESET);
}
void turnOffYellow1(void) {
    HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);
}
void toggleYellow1(void) {
    HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
}

void turnOnGreen1(void) {
    HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_RESET);
}
void turnOffGreen1(void) {
    HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
}
void toggleGreen1(void) {
    HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
}


// ======= LED SET 2 =======
void turnOnRed2(void) {
    HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
}
void turnOffRed2(void) {
    HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_SET);
}
void toggleRed2(void) {
    HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
}

void turnOnYellow2(void) {
    HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_RESET);
}
void turnOffYellow2(void) {
    HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_SET);
}
void toggleYellow2(void) {
    HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
}

void turnOnGreen2(void) {
    HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_RESET);
}
void turnOffGreen2(void) {
    HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);
}
void toggleGreen2(void) {
    HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
}

void turnOffAll(void)
{
	turnOffGreen1();
	turnOffRed1();
	turnOffYellow1();

	turnOffGreen2();
	turnOffRed2();
	turnOffYellow2();
}
