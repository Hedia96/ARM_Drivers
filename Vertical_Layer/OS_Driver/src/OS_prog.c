/*
 * OS_prog.c
 *
 *  Created on: Apr 22, 2019
 *      Author: AyetAllah
 */
#include "SYSTICK_interface.h"
#include "OS_interface.h"
#include "STD_TYPE.h"
void OS_VInit(void)
{
/*set the time tick what is confiured in configuration file*/
SYSTICK_Init();
SYSTICK_SetTickTime(1000);
SYSTICK_SetCallBack(OS_VScheduler);
}

void OS_VEnable(void)
{
	SYSTICK_Enable();

}
/*
 * Name: OS_VScheduler
 * description: this is a function , responsible for loop on all tasks in a certain data structure (here is array from
 * 					from pointer to structure this structure is a task)
 * 					make all tasks run for multiple of ticks according to the periodicity which is a member in that struct
 * 					there are Two approaches first make a flag for every task because every task need to zero after certain time
 * 					is different than others  Hence make another array of flags  for every task but
 * 					second one is  better use the modules to get the step
 * 					(NOtee: what is difference increment the counter in beginning or  in the last )
 * Parameters:
 * Return:
 */

void OS_VScheduler(void)
{

	u8 index=0;
	static u32  counter=0;
	for (index=0;index<MAX_NUMBER_OF_TASKS;index++)
	{
		if(counter%Array_Tasks[index]->Periodicity==0)
		{
			Array_Tasks[index]->Runnable();
		}
		counter++;
	}

}

u8 OS_CreateTask(u8 Copy_u8Priority, Task_t * Copy_PNewTask)
{
	u8 Local_u8ErrorState=ERROR_NOK;
	if(Copy_u8Priority<MAX_NUMBER_OF_TASKS && Copy_PNewTask!=NULL )
	{
		Array_Tasks[Copy_u8Priority]=Copy_PNewTask;
		Local_u8ErrorState=ERROR_NO;
	}
	return Local_u8ErrorState;
}



