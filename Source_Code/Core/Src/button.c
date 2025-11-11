/*
 * button.c
 *
 *  Created on: Nov 10, 2025
 *      Author: LENOVO
 */

#include "button.h"

int Timer_For_Key_Press[NUM_OF_BUTTONS] = {200};
int KeyReg0[NUM_OF_BUTTONS] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[NUM_OF_BUTTONS] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[NUM_OF_BUTTONS] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg3[NUM_OF_BUTTONS] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};

int buttonFlag[NUM_OF_BUTTONS] = {0, 0, 0, 0};

GPIO_TypeDef* buttonPort[NUM_OF_BUTTONS] = {Button1_GPIO_Port, Button2_GPIO_Port, Button3_GPIO_Port, Button4_GPIO_Port};
uint16_t buttonPin[NUM_OF_BUTTONS] = {Button1_Pin, Button2_Pin, Button3_Pin, Button4_Pin};

int isButtonPressed(int index)
{
	if (buttonFlag[index] == 1)
	{
		buttonFlag[index] = 0;
		return 1;
	}
	return 0;
}

void readButton()
{
    for (int i = 0; i < NUM_OF_BUTTONS; i++)
    {
        KeyReg0[i] = KeyReg1[i];
        KeyReg1[i] = KeyReg2[i];
        KeyReg2[i] = HAL_GPIO_ReadPin(buttonPort[i], buttonPin[i]);
        if (KeyReg0[i] == KeyReg1[i] && KeyReg1[i] == KeyReg2[i])
        {
        	if (KeyReg3[i] != KeyReg2[i])
        	{
        		KeyReg3[i] = KeyReg2[i];
        		if (KeyReg2[i] == PRESSED_STATE)
        		{
        			buttonFlag[i] = 1;
        			Timer_For_Key_Press[i] = 200;
        		}
        	}
        	else
        	{
        		if (KeyReg2[i] == PRESSED_STATE)
        		{
        			Timer_For_Key_Press[i]--;
        			if (Timer_For_Key_Press[i] == 0)
        			{
        				buttonFlag[i] = 1;
        				Timer_For_Key_Press[i] = 200;
        			}
        		}
        	}
        }
    }
}
