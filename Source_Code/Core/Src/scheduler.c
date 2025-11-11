///*
// * scheduler.c
// *
// *  Created on: Nov 9, 2025
// *      Author: LENOVO
// */
//#include "scheduler.h"
//
//sTasks SCH_tasks_G[SCH_MAX_TASKS];
//uint32_t currentIndexTask = 0;
//
//static sTasks heap[SCH_MAX_TASKS];
//static uint32_t heap_size = 0;
//static uint32_t current_tick = 0;
//
//// Hoán đổi hai phần tử heap
//static void swap(sTasks *a, sTasks *b)
//{
//    sTasks temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//// Duy trì heap sau khi thêm
//static void heapify_up(int index)
//{
//    while (index > 0)
//    {
//        int parent = (index - 1) / 2;
//        if (heap[parent].next_run_time <= heap[index].next_run_time) break;
//        swap(&heap[parent], &heap[index]);
//        index = parent;
//    }
//}
//
//// Duy trì heap sau khi xóa
//static void heapify_down(int index)
//{
//    int smallest = index;
//    while (1)
//    {
//        int left = 2 * index + 1;
//        int right = 2 * index + 2;
//        if (left < heap_size && heap[left].next_run_time < heap[smallest].next_run_time)
//            smallest = left;
//        if (right < heap_size && heap[right].next_run_time < heap[smallest].next_run_time)
//            smallest = right;
//        if (smallest == index) break;
//        swap(&heap[index], &heap[smallest]);
//        index = smallest;
//    }
//}
//
//void SCH_Init(void)
//{
//    heap_size = 0;
//    current_tick = 0;
//}
//
//void SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD)
//{
//    if (heap_size >= SCH_MAX_TASKS) return;
//    sTasks newTask;
//    newTask.pTask = pFunction;
//    newTask.Delay = DELAY / TICK;
//    newTask.Period = PERIOD / TICK;
//    newTask.RunMe = 0;
//    newTask.TaskID = heap_size;
//    newTask.next_run_time = current_tick + newTask.Delay;
//
//    heap[heap_size] = newTask;
//    heapify_up(heap_size);
//    heap_size++;
//}
//
//static void SCH_Remove_Head(void)
//{
//    if (heap_size == 0) return;
//    heap[0] = heap[heap_size - 1];
//    heap_size--;
//    heapify_down(0);
//}
//
//void SCH_Update(void)
//{
//    current_tick++; // Mỗi tick tăng 1
//
//    if (heap_size == 0) return;
//
//    // Nếu đến lúc chạy task đầu tiên
//    if (heap[0].next_run_time <= current_tick)
//    {
//        heap[0].RunMe++;
//
//        // Nếu task có period -> cập nhật next_run_time
//        if (heap[0].Period > 0)
//        {
//            heap[0].next_run_time = current_tick + heap[0].Period;
//            // Sau khi thay đổi next_run_time, cần duy trì heap
//            // Đưa phần tử này xuống đúng vị trí
//            heapify_down(0);
//        }
//        else
//        {
//            // Task 1 lần -> xóa khỏi heap
//            SCH_Remove_Head();
//        }
//    }
//}
//
//
//void SCH_Dispatch_Tasks(void)
//{
//    if (heap_size == 0) return;
//    if (heap[0].RunMe > 0)
//    {
//        (*heap[0].pTask)();
//        heap[0].RunMe--;
//    }
//}
//
//void SCH_Delete_Task(const unsigned char TASK_INDEX)
//{
//	if (TASK_INDEX < SCH_MAX_TASKS)
//	{
//		SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
//		SCH_tasks_G[TASK_INDEX].Delay = 0;
//		SCH_tasks_G[TASK_INDEX].Period = 0;
//		SCH_tasks_G[TASK_INDEX].RunMe = 0;
//		SCH_tasks_G[TASK_INDEX].TaskID = 0;
//	}
//}
//
//void SCH_Delete_Short_Task(void)
//{
//	unsigned char i;
//	for (i = 0; i < SCH_MAX_TASKS; i++)
//	{
//		if (SCH_tasks_G[i].Period == 0 && SCH_tasks_G[i].Delay != 0)
//		{
//			SCH_Delete_Task(i);
//		}
//	}
//}

/*
 * scheduler.c
 *
 *  Created on: Nov 3, 2025
 *      Author: DoDo
 */

#include "scheduler.h"

sTasks SCH_tasks_G[SCH_MAX_TASKS];

static uint32_t task_counter = 0;

static uint32_t next_task_id = 1;

void SCH_Init (void) {
	task_counter = 0;
	next_task_id = 1;
	// Reset từng phần tử
	for (uint32_t i = 0; i < SCH_MAX_TASKS; i++) {
		SCH_tasks_G[i].pTask = 0;
		SCH_tasks_G[i].Delay = 0;
		SCH_tasks_G[i].Period = 0;
		SCH_tasks_G[i].RunMe = 0;
		SCH_tasks_G[i].TaskID = 0;
	}
}

uint32_t SCH_Add_Task (void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
	if (task_counter >= SCH_MAX_TASKS) return 0;

	uint32_t index = 0;
	uint32_t delay_sum = 0;
	// Tìm chỗ trống
	while (index < task_counter) {
		// Kiểm tra delay
		if (DELAY < (delay_sum + SCH_tasks_G[index].Delay)) {
			break; // Found
		}
		delay_sum += SCH_tasks_G[index].Delay;
		index++;
	}

	// Shift left các phần tử
	for (uint32_t i = task_counter; i > index; i++) {
		SCH_tasks_G[i] = SCH_tasks_G[i - 1];
	}

	uint32_t new_task_id = next_task_id++;
	SCH_tasks_G[index].pTask = pFunction;
	SCH_tasks_G[index].Delay = DELAY/TICK;
	SCH_tasks_G[index].Period = PERIOD/TICK;
	SCH_tasks_G[index].RunMe = 0; // Chờ SCH_Update

	// Tính toán delay task mới
	SCH_tasks_G[index].Delay = DELAY - delay_sum;

	// Cập nhật delay task sau
	if (index < task_counter) {
		SCH_tasks_G[index + 1].Delay -= SCH_tasks_G[index].Delay;
	}

	task_counter++;

	return new_task_id;
}

void SCH_Update (void) {
	// Kiểm tra hàng đợi
	if (task_counter > 0 && SCH_tasks_G[0].pTask != 0) {
		// Giảm delay task đầu tiên
		SCH_tasks_G[0].Delay--;
	}
}

void SCH_Dispatch_Tasks (void) {
	// Kiểm tra task đầu
	if (task_counter > 0 && SCH_tasks_G[0].Delay == 0) {
		sTasks task_run = SCH_tasks_G[0];

		(*task_run.pTask)();

		// Xóa task đầu
		task_counter--;
		for (uint32_t i = 0; i < task_counter; i++) {
			SCH_tasks_G[i] = SCH_tasks_G[i + 1];
		}

		// Xóa rác ở cuối sau khi shift left
		SCH_tasks_G[task_counter].pTask = 0;
		SCH_tasks_G[task_counter].TaskID = 0;

		// Thêm lại task nếu là peiodic task
		if (task_run.Period > 0) {
			SCH_Add_Task(task_run.pTask,
						 task_run.Period,
						 task_run.Period);
		}
	}
}

uint32_t SCH_Delete (uint32_t taskID) {
	if (taskID == 0) return 0;
			;
	uint32_t task_index = 0;

	// Tìm task để xóa thông qua taskID
	while (task_index < task_counter) {
		if (SCH_tasks_G[task_index].TaskID == taskID) {
			break;
		}
		task_index++;
	}

	// Nếu không tìm thấy
	if (task_index == task_counter) return 0;

	// Cộng delay cho task sau
	if ((task_index + 1) < task_counter) {
		SCH_tasks_G[task_index + 1].Delay += SCH_tasks_G[task_index].Delay;
	}

	// Shift left mảng
	task_counter--;
	for (uint32_t i = task_index; i < task_counter; i++) {
		SCH_tasks_G[i] = SCH_tasks_G[i + 1];
	}

	// Xóa rác ở cuối sau khi shift left
	SCH_tasks_G[task_counter].pTask = 0;
	SCH_tasks_G[task_counter].TaskID = 0;

	return 1;
}



