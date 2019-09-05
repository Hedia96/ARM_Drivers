/*
 * App1.c
 *
 *  Created on: Apr 23, 2019
 *      Author: AyetAllah
 */

#ifndef APP1_C_
#define APP1_C_
/*
typedef struct

{
	PvFunction_t Runnable;
	u8  Priority;//the order of tasks if we put them in an array
	u32 Periodicity;//multiple of time tick
	u32 Offset;//in beginning only to make offset after 0 only in timer


}Task_t;
*/

#include "GPIO_interface.h"
#include "OS_interface.h"
#include "App1.h"
/*create the task */

 Task_t Task_tApp1={App1_VFunction,0,10,0};/*runnable, priority, periodicity, offset*/

void App1_VInit(void) /*Add this task in  array */
{
	OS_CreateTask(Task_tApp1.Priority,&Task_tApp1);
}
void App1_VFunction(void)
{
	static u8 value = 0;
	if(value == 0)
	{
	GPIO_u8SetPinValue(PORTA_PIN0,GPIO_PIN_HIGH);
		value = 1;
	}
	else
	{
		GPIO_u8SetPinValue(PORTA_PIN0,GPIO_PIN_LOW);
		value = 0;
	}

}




#endif /* APP1_C_ */
