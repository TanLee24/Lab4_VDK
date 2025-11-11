/*
 * scheduler.h
 *
 *  Created on: Nov 9, 2025
 *      Author: LENOVO
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include "global.h"

#define SCH_MAX_TASKS 20
#define NO_TASK_ID    0

typedef struct
{
	void (*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t  RunMe;
	uint32_t TaskID;
} sTask;

// Core functions
void SCH_Init(void);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
uint8_t SCH_Delete_Task(uint32_t taskID);

#endif /* INC_SCHEDULER_H_ */
