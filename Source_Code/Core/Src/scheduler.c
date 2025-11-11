/*
 * scheduler.c
 *
 *  Created on: Nov 9, 2025
 *      Author: LENOVO
 */
#include "scheduler.h"

sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint32_t currentIndexTask = 0;

static sTasks heap[SCH_MAX_TASKS];
static uint32_t heap_size = 0;
static uint32_t current_tick = 0;

// Hoán đổi hai phần tử heap
static void swap(sTasks *a, sTasks *b)
{
    sTasks temp = *a;
    *a = *b;
    *b = temp;
}

// Duy trì heap sau khi thêm
static void heapify_up(int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (heap[parent].next_run_time <= heap[index].next_run_time) break;
        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

// Duy trì heap sau khi xóa
static void heapify_down(int index)
{
    int smallest = index;
    while (1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if (left < heap_size && heap[left].next_run_time < heap[smallest].next_run_time)
            smallest = left;
        if (right < heap_size && heap[right].next_run_time < heap[smallest].next_run_time)
            smallest = right;
        if (smallest == index) break;
        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

void SCH_Init(void)
{
    heap_size = 0;
    current_tick = 0;
}

void SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD)
{
    if (heap_size >= SCH_MAX_TASKS) return;
    sTasks newTask;
    newTask.pTask = pFunction;
    newTask.Delay = DELAY / TICK;
    newTask.Period = PERIOD / TICK;
    newTask.RunMe = 0;
    newTask.TaskID = heap_size;
    newTask.next_run_time = current_tick + newTask.Delay;

    heap[heap_size] = newTask;
    heapify_up(heap_size);
    heap_size++;
}

static void SCH_Remove_Head(void)
{
    if (heap_size == 0) return;
    heap[0] = heap[heap_size - 1];
    heap_size--;
    heapify_down(0);
}

void SCH_Update(void)
{
    current_tick++; // Mỗi tick tăng 1

    if (heap_size == 0) return;

    // Nếu đến lúc chạy task đầu tiên
    if (heap[0].next_run_time <= current_tick)
    {
        heap[0].RunMe++;

        // Nếu task có period -> cập nhật next_run_time
        if (heap[0].Period > 0)
        {
            heap[0].next_run_time = current_tick + heap[0].Period;
            // Sau khi thay đổi next_run_time, cần duy trì heap
            // Đưa phần tử này xuống đúng vị trí
            heapify_down(0);
        }
        else
        {
            // Task 1 lần -> xóa khỏi heap
            SCH_Remove_Head();
        }
    }
}


void SCH_Dispatch_Tasks(void)
{
    if (heap_size == 0) return;
    if (heap[0].RunMe > 0)
    {
        (*heap[0].pTask)();
        heap[0].RunMe--;
    }
}

void SCH_Delete_Task(const unsigned char TASK_INDEX)
{
	if (TASK_INDEX < SCH_MAX_TASKS)
	{
		SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
		SCH_tasks_G[TASK_INDEX].Delay = 0;
		SCH_tasks_G[TASK_INDEX].Period = 0;
		SCH_tasks_G[TASK_INDEX].RunMe = 0;
		SCH_tasks_G[TASK_INDEX].TaskID = 0;
	}
}

void SCH_Delete_Short_Task(void)
{
	unsigned char i;
	for (i = 0; i < SCH_MAX_TASKS; i++)
	{
		if (SCH_tasks_G[i].Period == 0 && SCH_tasks_G[i].Delay != 0)
		{
			SCH_Delete_Task(i);
		}
	}
}
