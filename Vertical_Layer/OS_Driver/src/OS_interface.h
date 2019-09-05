/*
 * OS_interface.h
 *
 *  Created on: Apr 22, 2019
 *      Author: AyetAllah
 */

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_
#include "STD_TYPE.h"
/*
typedef struct LinkedList * Node;
struct LinkedList
{

	Node next;
};
*/
#define MAX_NUMBER_OF_TASKS  2

typedef void (*PvFunction_t)(void);
typedef struct
{
	PvFunction_t Runnable;
	u8  Priority;/*the order of tasks if we put them in an array */
	u32 Periodicity;/*multiple of time tick*/
	u32 Offset;/*in beginning only to make offset after 0 only in timer*/


}Task_t;

/*****************API******************/
/*how make the */

Task_t* Array_Tasks[MAX_NUMBER_OF_TASKS];

void OS_VInit(void);
void OS_VEnable(void);
void OS_VScheduler(void);
u8 OS_CreateTask(u8 Copy_u8Priority,Task_t * Copy_PNewTask);

#endif /* OS_INTERFACE_H_ */
