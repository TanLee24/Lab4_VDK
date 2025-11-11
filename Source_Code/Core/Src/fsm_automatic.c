/*
 * fsm_automatic.c
 *
 *  Created on: Nov 10, 2025
 *      Author: LENOVO
 */

#include "fsm_automatic.h"

void fsm_automatic_run()
{
	if (mode != 1) return;
	switch (status1)
	{
		case INIT:
			turnOffRed1();
			turnOffGreen1();
			turnOffYellow1();
			status1 = AUTO_RED;
			countdown1 = timer_red/1000;
			setTimer(1, 100);
			break;
		case AUTO_RED:
			turnOnRed1();
			turnOffGreen1();
			turnOffYellow1();
			if (isTimeExpired(1) == 1)
			{
				countdown1--;
				setTimer(1, 100);
				if (countdown1 <= 0)
				{
					status1 = AUTO_GREEN;
					countdown1 = timer_green/1000;
				}
			}
			break;
		case AUTO_GREEN:
			turnOffRed1();
			turnOnGreen1();
			turnOffYellow1();
			if (isTimeExpired(1) == 1)
			{
				countdown1--;
				setTimer(1, 100);
				if (countdown1 <= 0)
				{
					status1 = AUTO_YELLOW;
					countdown1 = timer_yellow/1000;
				}
			}
			break;
		case AUTO_YELLOW:
			turnOffRed1();
			turnOffGreen1();
			turnOnYellow1();
			if (isTimeExpired(1) == 1)
			{
				countdown1--;
				setTimer(1, 100);
				if (countdown1 <= 0)
				{
					status1 = AUTO_RED;
					countdown1 = timer_red/1000;
				}
			}
			break;
		default:
			break;
	}

	switch (status2)
		{
			case INIT:
				turnOffRed2();
				turnOffGreen2();
				turnOffYellow2();
				status2 = AUTO_GREEN;
				countdown2 = timer_green/1000;
				setTimer(2, 100);
				break;
			case AUTO_RED:
				turnOnRed2();
				turnOffGreen2();
				turnOffYellow2();
				if (isTimeExpired(2) == 1)
				{
					countdown2--;
					setTimer(2, 100);
					if (countdown2 == 0)
					{
						status2 = AUTO_GREEN;
						countdown2 = timer_green/1000;
					}
				}
				break;
			case AUTO_GREEN:
				turnOffRed2();
				turnOnGreen2();
				turnOffYellow2();
				if (isTimeExpired(2) == 1)
				{
					countdown2--;
					setTimer(2, 100);
					if (countdown2 == 0)
					{
						status2 = AUTO_YELLOW;
						countdown2 = timer_yellow/1000;
					}
				}
				break;
			case AUTO_YELLOW:
				turnOffRed2();
				turnOffGreen2();
				turnOnYellow2();
				if (isTimeExpired(2) == 1)
				{
					countdown2--;
					setTimer(2, 100);
					if (countdown2 == 0)
					{
						status2 = AUTO_RED;
						countdown2 = timer_red/1000;
					}
				}
				break;
			default:
				break;
		}
}
