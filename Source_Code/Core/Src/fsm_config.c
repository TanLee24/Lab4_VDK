/*
 * fsm_config.c
 *
 *  Created on: Nov 10, 2025
 *      Author: LENOVO
 */

#include "fsm_config.h"

void fsm_config()
{
	switch(mode)
	{
	  case 1:  // Autorun
		  display_7SEG_automatic();
		  if(isButtonPressed(0) == 1) // Button 1 pressed
		  {
			setTimer(4, 50);
			mode = 2;
			count = 1;
			turnOffAll();
			setTimer(3, 50);
		  }
		  if (isButtonPressed(3) == 1) // Button4 -> manual
		  {
		      mode = 5;
		      manual_status = MANUAL_IDLE;
		      turnOffAll();
		  }
		  break;
	  case 2:  // Red light
		  if(isTimeExpired(4) == 1)
		  {
			  setTimer(4, 50);
			  toggleRed1();
			  toggleRed2();
		  }
		  if(isButtonPressed(1) == 1) // Button 2 pressed
		  {
			  count++;
			  if (count > 99) count = 0;
		  }
		  if(isButtonPressed(2) == 1) // Button 3 pressed
		  {
			  timer_red = count * 1000;
			  count = 1;
		  }
		  display_7SEG_manual();
		  if(isButtonPressed(0) == 1) // Button 1 pressed
		  {
			  setTimer(4, 50);
			  mode = 3;
			  count = 1;
			  turnOffRed1();
			  turnOffRed2();
		  }
		  if (isButtonPressed(3) == 1) // Button4 -> manual
		  {
		      mode = 5;
		      manual_status = MANUAL_IDLE;
		      turnOffAll();
		  }
		  break;
	  case 3:  // Yellow light
		 if(isTimeExpired(4) == 1)
		 {
			 setTimer(4, 50);
			 toggleYellow1();
			 toggleYellow2();
		 }
		 if(isButtonPressed(1) == 1) // Button 2 pressed
		 {
			 count++;
			 if (count > 99) { count = 0; }
		 }
		 if(isButtonPressed(2) == 1) // Button 3 pressed
		 {
			 timer_yellow = count*1000;
			 count = 1;
		 }
		 display_7SEG_manual();
		 if(isButtonPressed(0) == 1) // Button 1 pressed
		 {
			 setTimer(4, 50);
			 mode = 4;
			 count = 1;
			 turnOffYellow1();
			 turnOffYellow2();
		 }
		 if (isButtonPressed(3) == 1) // Button4 -> manual
		 {
		     mode = 5;
		     manual_status = MANUAL_IDLE;
		     turnOffAll();
		 }
		 break;
	  case 4:  // Green light
		  if(isTimeExpired(4) == 1)
		  {
			  setTimer(4, 50);
			  toggleGreen1();
			  toggleGreen2();
		  }
		  if(isButtonPressed(1) == 1) // Button 2 pressed
		  {
			  count++;
			  if (count > 99) { count = 0; }
		  }
		  if(isButtonPressed(2) == 1) // Button 3 pressed
		  {
			  timer_green = count*1000;
			  count = 1;
		  }
		  display_7SEG_manual();
		  if(isButtonPressed(0) == 1) // Button 1 pressed
		  {
			  mode = 1;
			  count = 1;
			  status1 = INIT;
			  status2 = INIT;
			  turnOffGreen1();
			  turnOffGreen2();
		  }
		  if (isButtonPressed(3) == 1) // Button4 -> manual
		  {
		      mode = 5;
		      manual_status = MANUAL_IDLE;
		      turnOffAll();
		  }
		  break;
	  case 5:
		  //fsm_manual_run();
		  if (isButtonPressed(3) == 1)
		  {
			  mode = 1;
			  manual_status = MANUAL_IDLE;
			  status1 = INIT;
			  status2 = INIT;
			  turnOffAll();
		  }
		  break;
	  default:
		  mode = 1;
		  break;
	}
}
