/*
 * GPIO_private.h
 *
 *  Created on: Feb 20, 2019
 *      Author: AyetAllah
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_



#include "STD_TYPE.h"



/**************************************GPIO_REGISTERS AS WORDACCESS(32 BITS)****************************************/


typedef struct
{
Register_32bit CRL;
Register_32bit CRH;
Register_32bit IDR;
Register_32bit ODR;
Register_32bit BSRR;
Register_32bit BRR;
Register_32bit LCKR;

}GPIO;

#define GPIOA  ((GPIO *)0x40010800)
#define GPIOB  ((GPIO *)0x40010C00)
#define GPIOC  ((GPIO *)0x40011000)
#define GPIOD  ((GPIO *)0x40011400)


#define RST_VALUE_PORTX   0X0000
/*private functions */
static u8 u8SetPin(u8 Copy_u8Port, u8 Copy_u8Pin);
static u8 u8RstPin(u8 Copy_u8Port, u8 Copy_u8Pin);

#endif /* GPIO_PRIVATE_H_ */
