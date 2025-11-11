/*
 * fsm_manual.c
 *
 *  Created on: Nov 10, 2025
 *      Author: LENOVO
 */

#include "fsm_manual.h"

void fsm_manual_run()
{
	if (mode != 5) return;
    switch (manual_status)
    {
        case MANUAL_IDLE:
            // When enter manual, turn off all
            turnOffAll();
            display_7SEG_manual();

            // Button 2: Red 1 on
            if (isButtonPressed(1) == 1)
            {
                manual_status = MANUAL_RED;
                turnOnRed1();
                turnOffGreen1();
                turnOffYellow1();

                turnOffRed2();
                turnOnGreen2();
                turnOffYellow2();
            }

            // Button 3: Green 1 on
            if (isButtonPressed(2) == 1)
            {
                manual_status = MANUAL_GREEN;
                turnOffRed1();
                turnOnGreen1();
                turnOffYellow1();

                turnOnRed2();
                turnOffGreen2();
                turnOffYellow2();
            }

            break;

        case MANUAL_RED:
            display_7SEG_manual();

            if (isButtonPressed(2) == 1)
            {
                manual_status = MANUAL_GREEN;

                turnOffRed1();
                turnOnGreen1();
                turnOffYellow1();

                turnOnRed2();
                turnOffGreen2();
                turnOffYellow2();
            }
            break;

        case MANUAL_GREEN:
            display_7SEG_manual();

            if (isButtonPressed(1) == 1)
            {
                manual_status = MANUAL_RED;

                turnOnRed1();
                turnOffGreen1();
                turnOffYellow1();

                turnOffRed2();
                turnOnGreen2();
                turnOffYellow2();
            }
            break;

        default:
            manual_status = MANUAL_IDLE;
            break;
    }
}
