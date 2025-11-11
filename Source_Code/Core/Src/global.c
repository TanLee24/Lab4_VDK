/*
 * global.c
 *
 *  Created on: Nov 10, 2025
 *      Author: LENOVO
 */
#include "global.h"

int status1 = INIT;
int status2 = INIT;
int mode = 1;
int timer_red = 5000;
int timer_yellow = 2000;
int timer_green = 3000;
int count = 0; // Variable to count the time in mode 2 3 4
int countdown1 = 0;
int countdown2 = 0;
int manual_status = MANUAL_IDLE;
