/*
 * App2.c
 *
 *  Created on: Apr 23, 2019
 *      Author: AyetAllah
 */


#include "GPIO_interface.h"
#include "OS_interface.h"
#include "App2.h"

/*create the task */

const Task_t Task_tApp2={App2_VFunction,1,5,0};/*runnable, priority, periodicity, offset*/

void App2_VInit(void)
{
	OS_CreateTask(Task_tApp2.Priority,&Task_tApp2);
}
void App2_VFunction(void)
{
	static u8 value = 0;
	if(value == 0)
	{
	GPIO_u8SetPinValue(PORTA_PIN1,GPIO_PIN_HIGH);
		value = 1;
	}
	else
	{
		GPIO_u8SetPinValue(PORTA_PIN1,GPIO_PIN_LOW);
		value = 0;
	}


}
