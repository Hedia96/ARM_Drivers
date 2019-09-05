/*
 * RCC_interface.h
 *
 *  Created on: Feb 28, 2019
 *      Author: AyetAllah
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


#include "GPIO_config.h"

/*********************************************************************
 * AUTHOR: AYA ABDELMAGIED                                           *
 *                                                                   *
 * VERSION: V2                                                       *
 *                                                                   *
 * DATE  : 28 FEBURARY 2019                                          *
 *                                                                   *
 *********************************************************************/



/*
 * Name       : RCC_VInit
 * Description: it initialzes internal clock
 * Arguments  :
 * Return     :
 */

void RCC_VInit (void);
/*
 * Name       : RCC_u8EnablePerphieral
 * Description: to  choose which peripherals  from
 * Arguments  :
 * Return     :
 */


/*******************************PERIPHERALS****************************/
#define PERIPHERAL_GPIO_PORTA  0
#define PERIPHERAL_GPIO_PORTB  1
#define PERIPHERAL_GPIO_PORTC  2
#define PERIPHERAL_GPIO_PORTD  3


/*******************************PERIPHERALS****************************/

/*
  PERIPHERAL_GPIO_PORTA
  PERIPHERAL_GPIO_PORTB
  PERIPHERAL_GPIO_PORTC
  PERIPHERAL_GPIO_PORTD */

u8 RCC_u8EnablePerphieral(u8 Copy_u8SelectPerpherial);
/*
 * Name       : RCC_
 * Description:
 * Arguments  :
 * Return     :
 */
u8 RCC_u8DisablePerphieral(u8 Copy_u8SelectPerpherial);

#endif /* RCC_INTERFACE_H_ */
