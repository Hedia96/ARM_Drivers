/*
 * SYSTICK_interface.h
 *
 *  Created on: Apr 7, 2019
 *      Author: AyetAllah
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_
#include "STD_TYPE.h"
#define MASK_STK_CTRL_COUNTFLAG			 0X10
typedef void (*PvFunction_t)(void);


extern void SYSTICK_Init(void);

extern void SYSTICK_Enable(void);


extern void SYSTICK_Disable(void);


extern void SYSTICK_SetTickTime(u16 Copy_u16Time_ms);
extern void SYSTICK_SetCallBack(PvFunction_t Copy_PvFunction);


extern void SysTick_Handler (void);



#endif /* SYSTICK_INTERFACE_H_ */
