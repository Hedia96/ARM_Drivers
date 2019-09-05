/*
 * GPIO_interface.h
 *
 *  Created on: Feb 27, 2019
 *      Author: AyetAllah
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*
 * GPIO_interface.h
 *
 *  Created on: Feb 20, 2019
 *      Author: AyetAllah
 */


#include "STD_TYPE.h"

#define GPIO_PIN_HIGH       1
#define GPIO_PIN_LOW        0

#define GPIO_PORTA   0
#define GPIO_PORTB   1
#define GPIO_PORTC   2
#define GPIO_PORTD   3
/********************INDEX WORD***********************************/
#define WORD0 0
#define WORD1 1


/******************************Macros to initialize the word or a byte in register*******************************/
  /* in Register configuration register low ((((CRL)))CNF1 CNF0 MODE1 MODE0*/

#define INPUT_FLOATING             0b0100
//#define INPUT_PULLUP_PULLDOWN    0b1000
#define INPUT_PULLUP               0b1000
#define INPUT_PULLDOWN             0b1100 //something reserved for give only the application layer different meaning
/*select pull up or pull down from another Register ODR*/
#define INPUT_ANALOG               0b0000

#define OUTPUT_10MHZ_GP_PUSHPULL   0b0001
#define OUTPUT_10MHZ_GP_OPENDRAIN  0b0101
#define OUTPUT_10MHZ_AF_PUSHPULL   0b1001
#define OUTPUT_10MHZ_AF_OPENDRAIN  0b1101

#define OUTPUT_2MHZ_GP_PUSHPULL    0b0010
#define OUTPUT_2MHZ_GP_OPENDRAIN   0b0110
#define OUTPUT_2MHZ_AF_PUSHPULL    0b1010
#define OUTPUT_2MHZ_AF_OPENDRAIN   0b1110


#define OUTPUT_50MHZ_GP_PUSHPULL    0b0011
#define OUTPUT_50MHZ_GP_OPENDRAIN   0b0111
#define OUTPUT_50MHZ_AF_PUSHPULL    0b1011
#define OUTPUT_50MHZ_AF_OPENDRAIN   0b1111


/********************************APIs******************************/


/*
 * Name       : GPIO_VInit
 * Description:
 * Arguments  :
 * Return     :
 */
void GPIO_VInit(void);
/*
 * Name       : GPIO_u8SetPinDirectionType
 * Description:
 * Arguments  :
 * Return     :
 */
u8 GPIO_u8SetPinDirectionType(u8 Copy_u8PinNb, u8 Copy_u8Mode  );
/*
 * Name       : GPIO_u8GetPinValue
 * Description:
 * Arguments  :
 * Return     :
 */
u8 GPIO_u8GetPinValue(u8 Copy_u8PinNb, u8*  Copy_Pu8Value );
/*
 * Name       : GPIO_u8SetPortValue
 * Description: this function set the port ODR sixteen bits are reserved and others are  actually mapped to 16 pins in port
 * Arguments  : port is about macro defined in the interface file from 0 to 3 mapped to A,B,C,D and value for allowed bits only to write in them
 * Return     : Error State
 */
u8 GPIO_u8SetPortValue(u8 Copy_u8PortNb,u16 Copy_u16Value);
/*
 * Name       : GPIO_u8GetPortValue
 * Description:
 * Arguments  :
 * Return     :
 */
u8 GPIO_u8GetPortValue(u8 Copy_u8PortNb, u32* Copy_Pu32Value);
/*
 * Name       : GPIO_u8SetPinValue
 * Description:
 * Arguments  :
 * Return     :
 */

u8   GPIO_u8SetPinValue (u8 Copy_u8PinNb, u8  Copy_u8Value )  ;

/*******************************Names of Pins*********************/

#define PORTA_PIN0  0
#define PORTA_PIN1  1
#define PORTA_PIN2  2
#define PORTA_PIN3  3
#define PORTA_PIN4  4
#define PORTA_PIN5  5
#define PORTA_PIN6  6
#define PORTA_PIN7  7
#define PORTA_PIN8  8
#define PORTA_PIN9  9
#define PORTA_PIN10  10
#define PORTA_PIN11  11
#define PORTA_PIN12  12
#define PORTA_PIN13  13
#define PORTA_PIN14  14
#define PORTA_PIN15  15


#define PORTB_PIN0 16
#define PORTB_PIN1 17
#define PORTB_PIN2 18
#define PORTB_PIN3 19
#define PORTB_PIN4 20
#define PORTB_PIN5 21
#define PORTB_PIN6 22
#define PORTB_PIN7 23
#define PORTB_PIN8 24
#define PORTB_PIN9 25
#define PORTB_PIN10 26
#define PORTB_PIN11 27
#define PORTB_PIN12 28
#define PORTB_PIN13 29
#define PORTB_PIN14 30
#define PORTB_PIN15 31
/* this number to give me the right  value for pin number and port number
  15 -> 15/16=0 port number
  15%16->15 pin number
  45/16=2.-> port C
  45%16=13 ->pin number

*/
#define PORTC_PIN13 45
#define PORTC_PIN14 46
#define PORTC_PIN15 47

#define PORTD_PIN0 48
#define PORTD_PIN1 49
#define PORTD_PIN2 50
#define PORTD_PIN3 51










#endif /* GPIO_INTERFACE_H_ */
