/*
 *  SYSTICK_prog.c
 *  Created on: Apr. 22, 2019
 *  Author: AyetAllah
 */

#include "STD_TYPE.h"
#include "SYSTICK_private.h"
#include "SYSTICK_confg.h"
#include "SYSTICK_interface.h"

#define MASK_STK_CTRL_ENABLE             0X01
#define MASK_STK_CTRL_TICKINT            0X02
#define MASK_STK_CTRL_CLKSOURCE          0X04
#define STK_ENABLE_BIT                   0


enum Boolen_enum{False=0,True=1};
typedef enum Boolen_enum Boolen_t;

 Boolen_t GetBit(u32 Register,u8 index)
{
	Boolen_t Flag=False;
	if(Register & (1<<index))
	{
		Flag=True;
	}
	return Flag;
}

PvFunction_t CallBack;

/*
 * NAME       : SYSTICK_Init
 * DESCRIPTION: SELECT THE SOURCE OF TIMER IS PRESCALED BY 8 AHB/8 OR TAKE CLIOCK SOURCE FROM PROCESSOR DIRECTLY
 * PARAMETERS : VOID
 * RETURN     : VOID
 */
extern void SYSTICK_Init(void)
{
    /* set configuration like : source of timer which source AHB or AHB/8 */
	switch(SOURCE_SYSTICK)
	{
	case SOURCE_SYSTICK_AHB_8:
		STK_CTRL&=~MASK_STK_CTRL_CLKSOURCE;  /*clear the bit clock source for SYSTICK timer*/
		break;
	case SOURCE_SYSTICK_AHB:
		STK_CTRL|=MASK_STK_CTRL_CLKSOURCE;   /*set the bit clock source for SYSTICK timer*/
		break;

	}
	/*enable the interrupt when the timer counts down to zero */
	switch (SYSTICK_EXCEPTION_REQUEST)
	{
		case ENABLE_EXCEPTION:
			STK_CTRL|=MASK_STK_CTRL_TICKINT;
			break;
		case DISABLE_EXCEPTION:
			STK_CTRL&=~MASK_STK_CTRL_TICKINT;
			break;
	}



}

/*
 * NAME       : SYSTICK_Enable
 * DESCRIPTION: Enable the counter itself by connect  a appropriate  clock as it exists in configuration
 * PARAMETERS : VOID
 * RETURN     : VOID
 */
extern void SYSTICK_Enable(void)

{
	STK_CTRL|=MASK_STK_CTRL_ENABLE;
}

/*
 * NAME       : SYSTICK_Disable
 * DESCRIPTION: DISABLE THE COUNTER NOT INTERPUT
 * PARAMETERS : VOID
 * RETURN     : VOID
 */
extern void SYSTICK_Disable(void)

{
	STK_CTRL&=~MASK_STK_CTRL_ENABLE;
}

/*
 * NAME       : SYSTICK_SetCallBack
 * DESCRIPTION: POINTER TO VOID FUNCTION TAKES VOID TOO ,SET THIS FUNCTION
 * 			 TO CALLBACK in ISR of systick handler
 * PARAMETERS :
 * RETURN     :
 */
extern void SYSTICK_SetCallBack(PvFunction_t Copy_PvFunction)
{
		/*there is a check to make sure the timer isn't enabled before
		 the setting calling back to make sure the function in handler be called after the whole exact time outs
		    */
	/*get the enable counter and see if it 0 or 1*/
//	if(!GetBit(STK_CTRL,STK_ENABLE_BIT))
	//{
		/*another check if the pointer is null or no because if it was null ,an exception will be fired */
			if(Copy_PvFunction!=NULL)
			{
				CallBack=Copy_PvFunction;
			}
	//}

}
extern void SYSTICK_SetTickTime(u16 Copy_u16Time_ms)
{
	/*get number to count in  load register*/
f64 Local_f64TickTime=0.0;
u32 Local_u32NumberOfTicks=0;
if(SOURCE_SYSTICK==SOURCE_SYSTICK_AHB)
{
	Local_f64TickTime=1/AHB_CLOCK; /*NOTE: Time in Seconds*/
}else if(SOURCE_SYSTICK==SOURCE_SYSTICK_AHB_8)
{
	Local_f64TickTime=1/(AHB_CLOCK/8); /*NOTE: Time in Seconds*/
}
Local_u32NumberOfTicks=((Copy_u16Time_ms )* .001)/Local_f64TickTime;

STK_LOAD=Local_u32NumberOfTicks;

}
void SysTick_Handler(void)
{

	CallBack();
}
