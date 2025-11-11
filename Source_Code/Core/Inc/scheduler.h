///*
// * scheduler.h
// *
// *  Created on: Nov 9, 2025
// *      Author: LENOVO
// */
//
//#ifndef INC_SCHEDULER_H_
//#define INC_SCHEDULER_H_
//
//#include "global.h"
//#include <stdint.h>
//
//typedef struct
//{
//	void(*pTask)(void);
//	uint32_t Delay;
//	uint32_t Period;
//	uint32_t RunMe;
//
//	uint32_t TaskID;
//	uint32_t next_run_time;
//} sTasks;
//
//#define SCH_MAX_TASKS 20
//
//void SCH_Init(void);
//void SCH_Update(void);
//void SCH_Dispatch_Tasks(void);
//void SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
//void SCH_Delete_Task(const unsigned char TASK_INDEX);
//void SCH_Delete_Short_Task(void);
//
//#endif /* INC_SCHEDULER_H_ */

/*
 * scheduler.h
 *
 *  Created on: Nov 3, 2025
 *      Author: DoDo
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>

#include "global.h"

typedef struct {
	void (*pTask)(void);
	uint32_t 	Delay;
	uint32_t 	Period;
	uint8_t  	RunMe;

	uint32_t 	TaskID;
} sTasks;

#define SCH_MAX_TASKS 20

void SCH_Init(void);

uint32_t SCH_Add_Task (void (*pFunction)(),
					uint32_t DELAY,
					uint32_t PERIOD);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

uint32_t SCH_Delete (uint32_t taskID);

#endif /* INC_SCHEDULER_H_ */
