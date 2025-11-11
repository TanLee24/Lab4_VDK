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

//void readButton()
//{
//    for (int i = 0; i < NUM_OF_BUTTONS; i++)
//    {
//        KeyReg0[i] = KeyReg1[i];
//        KeyReg1[i] = KeyReg2[i];
//        KeyReg2[i] = HAL_GPIO_ReadPin(buttonPort[i], buttonPin[i]);
//        if (KeyReg0[i] == KeyReg1[i] && KeyReg1[i] == KeyReg2[i])
//        {
//        	if (KeyReg3[i] != KeyReg2[i])
//        	{
//        		KeyReg3[i] = KeyReg2[i];
//        		if (KeyReg2[i] == PRESSED_STATE)
//        		{
//        			buttonFlag[i] = 1;
//        			Timer_For_Key_Press[i] = 200;
//        		}
//        	}
//        	else
//        	{
//        		if (KeyReg2[i] == PRESSED_STATE)
//        		{
//        			Timer_For_Key_Press[i]--;
//        			if (Timer_For_Key_Press[i] == 0)
//        			{
//        				buttonFlag[i] = 1;
//        				Timer_For_Key_Press[i] = 200;
//        			}
//        		}
//        	}
//        }
//    }
//}

void readButton(void)
{
    for (int i = 0; i < NUM_OF_BUTTONS; i++)
    {
        uint8_t current = HAL_GPIO_ReadPin(buttonPort[i], buttonPin[i]);

        // Nếu khác lần trước → reset đếm
        if (current != KeyReg2[i])
        {
            KeyReg0[i] = KeyReg1[i] = KeyReg2[i] = current;
            Timer_For_Key_Press[i] = 5;     // chờ ổn định ~5*10ms = 50ms
            continue;
        }

        // Debounce: giảm đếm khi ổn định
        if (Timer_For_Key_Press[i] > 0)
            Timer_For_Key_Press[i]--;

        // Khi ổn định đủ lâu
        if (Timer_For_Key_Press[i] == 0)
        {
            if (KeyReg3[i] != current)
            {
                KeyReg3[i] = current;
                if (current == PRESSED_STATE)
                    buttonFlag[i] = 1;  // nhận 1 lần khi nhấn
            }
        }
    }
}
