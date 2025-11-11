/*
 * display7seg.c
 *
 *  Created on: Nov 10, 2025
 *      Author: LENOVO
 */

#include "display7seg.h"

int enable7SEG = EN0;

void display7SEG1(int num)
{
    switch (num)
    {
        case 0:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET); // a on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET); // b on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET); // c on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET); // d on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET); // e on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET); // f on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, SET);   // g off
            break;
        case 1:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, SET);   // a off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET); // b on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET); // c on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);   // d off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);   // e off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);   // f off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, SET);   // g off
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET); // a on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET); // b on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, SET);   // c off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET); // d on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET); // e on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);   // f off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET); // g on
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET); // a on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET); // b on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET); // c on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET); // d on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);   // e off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);   // f off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET); // g on
            break;
        case 4:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, SET);   // a off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET); // b on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET); // c on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);   // d off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);   // e off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET); // f on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET); // g on
            break;
        case 5:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET); // a on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, SET);   // b off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET); // c on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET); // d on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);   // e off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET); // f on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET); // g on
            break;
        case 6:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET); // a on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, SET);   // b off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET); // c on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET); // d on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET); // e on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET); // f on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET); // g on
            break;
        case 7:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET); // a on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET); // b on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET); // c on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);   // d off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);   // e off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);   // f off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, SET);   // g off
            break;
        case 8:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET); // a on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET); // b on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET); // c on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET); // d on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET); // e on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET); // f on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET); // g on
            break;
        case 9:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET); // a on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET); // b on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET); // c on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET); // d on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);   // e off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET); // f on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET); // g on
            break;
        default:
            // Do nothing or invalid paramters
            break;
    }
}

void display7SEG2(int num)
{
    switch (num)
    {
        case 0:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET); // a on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET); // b on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET); // c on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET); // d on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET); // e on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET); // f on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);   // g off
            break;
        case 1:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, SET);   // a off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET); // b on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET); // c on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);   // d off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, SET);   // e off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);   // f off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);   // g off
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET); // a on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET); // b on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, SET);   // c off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET); // d on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET); // e on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);   // f off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET); // g on
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET); // a on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET); // b on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET); // c on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET); // d on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, SET);   // e off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);   // f off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET); // g on
            break;
        case 4:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, SET);   // a off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET); // b on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET); // c on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);   // d off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, SET);   // e off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET); // f on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET); // g on
            break;
        case 5:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET); // a on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, SET);   // b off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET); // c on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET); // d on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, SET);   // e off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET); // f on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET); // g on
            break;
        case 6:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET); // a on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, SET);   // b off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET); // c on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET); // d on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET); // e on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET); // f on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET); // g on
            break;
        case 7:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET); // a on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET); // b on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET); // c on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);   // d off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, SET);   // e off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);   // f off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);   // g off
            break;
        case 8:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET); // a on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET); // b on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET); // c on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET); // d on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET); // e on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET); // f on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET); // g on
            break;
        case 9:
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET); // a on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET); // b on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET); // c on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET); // d on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, SET);   // e off
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET); // f on
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET); // g on
            break;
        default:
            // Do nothing or invalid paramters
            break;
    }
}

void display_7SEG_automatic()
{
	switch(enable7SEG)
	{
		case EN0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			display7SEG1(countdown1 / 10);
			display7SEG2(countdown1 % 10);
			if(isTimeExpired(3) == 1)
			{
				setTimer(3, 50);
				enable7SEG = EN1;
			}
			break;
		case EN1:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			display7SEG1(countdown2 / 10);
			display7SEG2(countdown2 % 10);
			if(isTimeExpired(3) == 1)
			{
				setTimer(3, 50);
				enable7SEG = EN0;
			}
			break;
		default:
			break;
	}
}

void display_7SEG_manual()
{
	if (mode == 5)
	{
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		display7SEG1(0);
		display7SEG2(5);
		return;
	}
	switch(enable7SEG)
	{
		case EN0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			display7SEG1(0);
			display7SEG2(mode);
			if(isTimeExpired(3) == 1)
			{
				setTimer(3, 50);
				enable7SEG = EN1;
			}
			break;
		case EN1:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			display7SEG1(count / 10);
			display7SEG2(count % 10);
			if(isTimeExpired(3) == 1)
			{
				setTimer(3, 50);
				enable7SEG = EN0;
			}
			break;
		default:
			break;
	}
}
