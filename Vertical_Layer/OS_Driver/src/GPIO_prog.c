/*
 * GPIO_prog.c
 *
 *  Created on: Feb 27, 2019
 *      Author: AyetAllah
 */

#include "STD_TYPE.h"
#include "BIT_CALC.h"

#include"GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"





static u8 u8SetPin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8Result = ERROR_NO;
	switch (Copy_u8Port)
	{
		case GPIO_PORTA:  GPIOA->BSRR.WordAccess = (1<<Copy_u8Pin); break;
		case GPIO_PORTB:  GPIOB->BSRR.WordAccess = (1<<Copy_u8Pin); break;
		case GPIO_PORTC:  GPIOC->BSRR.WordAccess = (1<<Copy_u8Pin); break;
		case GPIO_PORTD:  GPIOD->BSRR.WordAccess = (1<<Copy_u8Pin); break;
		default          :  Local_u8Result = ERROR_NOK;
	}

	return Local_u8Result;
}


static u8 u8RstPin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8Result = ERROR_NO;
	switch (Copy_u8Port)
	{
		case GPIO_PORTA:  GPIOA->BRR.WordAccess = (1<<Copy_u8Pin); break;
		case GPIO_PORTB:  GPIOB->BRR.WordAccess = (1<<Copy_u8Pin); break;
		case GPIO_PORTC:  GPIOC->BRR.WordAccess = (1<<Copy_u8Pin); break;
		case GPIO_PORTD:  GPIOD->BRR.WordAccess = (1<<Copy_u8Pin); break;
		default          :  Local_u8Result = ERROR_NOK;
	}

	return Local_u8Result;
}

void GPIO_VInit(void)
{

	GPIO_u8SetPinDirectionType(PORTA_PIN0,GPIO_PORTA_PIN0_DIR );
	GPIO_u8SetPinDirectionType(PORTA_PIN1,GPIO_PORTA_PIN1_DIR );
	GPIO_u8SetPinDirectionType(PORTA_PIN2,GPIO_PORTA_PIN2_DIR );
	GPIO_u8SetPinDirectionType(PORTA_PIN3,GPIO_PORTA_PIN3_DIR );
	GPIO_u8SetPinDirectionType(PORTA_PIN4,GPIO_PORTA_PIN4_DIR );
	GPIO_u8SetPinDirectionType(PORTA_PIN5,GPIO_PORTA_PIN5_DIR );
	GPIO_u8SetPinDirectionType(PORTA_PIN6,GPIO_PORTA_PIN6_DIR );
	GPIO_u8SetPinDirectionType(PORTA_PIN7,GPIO_PORTA_PIN7_DIR );
	GPIO_u8SetPinDirectionType(PORTA_PIN8,GPIO_PORTA_PIN8_DIR );
	GPIO_u8SetPinDirectionType(PORTA_PIN9,GPIO_PORTA_PIN9_DIR );
	GPIO_u8SetPinDirectionType(PORTA_PIN10,GPIO_PORTA_PIN10_DIR);
	GPIO_u8SetPinDirectionType(PORTA_PIN11,GPIO_PORTA_PIN11_DIR);
	GPIO_u8SetPinDirectionType(PORTA_PIN12,GPIO_PORTA_PIN12_DIR);
	GPIO_u8SetPinDirectionType(PORTA_PIN13,GPIO_PORTA_PIN13_DIR);
	GPIO_u8SetPinDirectionType(PORTA_PIN14,GPIO_PORTA_PIN14_DIR);
	GPIO_u8SetPinDirectionType(PORTA_PIN15,GPIO_PORTA_PIN15_DIR);


	GPIO_u8SetPinDirectionType(PORTB_PIN0,GPIO_PORTB_PIN0_DIR);
    GPIO_u8SetPinDirectionType(PORTB_PIN1,GPIO_PORTB_PIN1_DIR);
    GPIO_u8SetPinDirectionType(PORTB_PIN2,GPIO_PORTB_PIN2_DIR);
	GPIO_u8SetPinDirectionType(PORTB_PIN3,GPIO_PORTB_PIN3_DIR);
	GPIO_u8SetPinDirectionType(PORTB_PIN4,GPIO_PORTB_PIN4_DIR);
	GPIO_u8SetPinDirectionType(PORTB_PIN5,GPIO_PORTB_PIN5_DIR);
	GPIO_u8SetPinDirectionType(PORTB_PIN6,GPIO_PORTB_PIN6_DIR);
	GPIO_u8SetPinDirectionType(PORTB_PIN7,GPIO_PORTB_PIN7_DIR);
	GPIO_u8SetPinDirectionType(PORTB_PIN8,GPIO_PORTB_PIN8_DIR);
	GPIO_u8SetPinDirectionType(PORTB_PIN9,GPIO_PORTB_PIN9_DIR);
	GPIO_u8SetPinDirectionType(PORTB_PIN10,GPIO_PORTB_PIN10_DIR);
	GPIO_u8SetPinDirectionType(PORTB_PIN11,GPIO_PORTB_PIN11_DIR);
	GPIO_u8SetPinDirectionType(PORTB_PIN12,GPIO_PORTB_PIN12_DIR);
	GPIO_u8SetPinDirectionType(PORTB_PIN13,GPIO_PORTB_PIN13_DIR);
	GPIO_u8SetPinDirectionType(PORTB_PIN14,GPIO_PORTB_PIN14_DIR);
	GPIO_u8SetPinDirectionType(PORTB_PIN15,GPIO_PORTB_PIN15_DIR);


	GPIO_u8SetPinDirectionType(PORTC_PIN13,GPIO_PORTC_PIN13_DIR);
	GPIO_u8SetPinDirectionType(PORTC_PIN14,GPIO_PORTC_PIN14_DIR);
	GPIO_u8SetPinDirectionType(PORTC_PIN15,GPIO_PORTC_PIN15_DIR);


	GPIO_u8SetPinDirectionType(PORTD_PIN0,GPIO_PORTD_PIN0_DIR);
	GPIO_u8SetPinDirectionType(PORTD_PIN1,GPIO_PORTD_PIN1_DIR);
	/***********************************************
	 * set pin values                              *
	 **********************************************/

/*

	GPIO_u8SetPinValue(PORTA_PIN0,GPIO_PORTA_PIN0_VALUE);
	GPIO_u8SetPinValue(PORTA_PIN1,GPIO_PORTA_PIN1_VALUE);
	GPIO_u8SetPinValue(PORTA_PIN2,GPIO_PORTA_PIN2_VALUE);
	GPIO_u8SetPinValue(PORTA_PIN3,GPIO_PORTA_PIN3_VALUE);
	GPIO_u8SetPinValue(PORTA_PIN4,GPIO_PORTA_PIN4_VALUE);
	GPIO_u8SetPinValue(PORTA_PIN5,GPIO_PORTA_PIN5_VALUE);
	GPIO_u8SetPinValue(PORTA_PIN6,GPIO_PORTA_PIN6_VALUE);
	GPIO_u8SetPinValue(PORTA_PIN7,GPIO_PORTA_PIN7_VALUE);
	GPIO_u8SetPinValue(PORTA_PIN8,GPIO_PORTA_PIN8_VALUE);
	GPIO_u8SetPinValue(PORTA_PIN9,GPIO_PORTA_PIN9_VALUE);
	GPIO_u8SetPinValue(PORTA_PIN10,GPIO_PORTA_PIN10_VALUE);
	GPIO_u8SetPinValue(PORTA_PIN11,GPIO_PORTA_PIN11_VALUE);
	GPIO_u8SetPinValue(PORTA_PIN12,GPIO_PORTA_PIN12_VALUE);
	GPIO_u8SetPinValue(PORTA_PIN13,GPIO_PORTA_PIN13_VALUE);
	GPIO_u8SetPinValue(PORTA_PIN14,GPIO_PORTA_PIN14_VALUE);
	GPIO_u8SetPinValue(PORTA_PIN15,GPIO_PORTA_PIN15_VALUE);



	GPIO_u8SetPinValue(PORTB_PIN0,GPIO_PORTB_PIN0_VALUE );
	GPIO_u8SetPinValue(PORTB_PIN1,GPIO_PORTB_PIN1_VALUE );
	GPIO_u8SetPinValue(PORTB_PIN2,GPIO_PORTB_PIN2_VALUE );
	GPIO_u8SetPinValue(PORTB_PIN3,GPIO_PORTB_PIN3_VALUE );
	GPIO_u8SetPinValue(PORTB_PIN4,GPIO_PORTB_PIN4_VALUE );
	GPIO_u8SetPinValue(PORTB_PIN5,GPIO_PORTB_PIN5_VALUE );
	GPIO_u8SetPinValue(PORTB_PIN6,GPIO_PORTB_PIN6_VALUE );
	GPIO_u8SetPinValue(PORTB_PIN7,GPIO_PORTB_PIN7_VALUE );
	GPIO_u8SetPinValue(PORTB_PIN8,GPIO_PORTB_PIN8_VALUE );
	GPIO_u8SetPinValue(PORTB_PIN9,GPIO_PORTB_PIN9_VALUE );
	GPIO_u8SetPinValue(PORTB_PIN10,GPIO_PORTB_PIN10_VALUE);
	GPIO_u8SetPinValue(PORTB_PIN11,GPIO_PORTB_PIN11_VALUE);
	GPIO_u8SetPinValue(PORTB_PIN12,GPIO_PORTB_PIN12_VALUE);
	GPIO_u8SetPinValue(PORTB_PIN13,GPIO_PORTB_PIN13_VALUE);
	GPIO_u8SetPinValue(PORTB_PIN14,GPIO_PORTB_PIN14_VALUE);
	GPIO_u8SetPinValue(PORTB_PIN15,GPIO_PORTB_PIN15_VALUE);


	GPIO_u8SetPinValue(PORTC_PIN13,GPIO_PORTC_PIN13_VALUE);
	GPIO_u8SetPinValue(PORTC_PIN14,GPIO_PORTC_PIN14_VALUE);
	GPIO_u8SetPinValue(PORTC_PIN15,GPIO_PORTC_PIN15_VALUE);

	GPIO_u8SetPinValue(PORTD_PIN0,GPIO_PORTD_PIN0_VALUE);
	GPIO_u8SetPinValue(PORTD_PIN1,GPIO_PORTD_PIN1_VALUE);
	*/

}


u8   GPIO_u8SetPinValue (u8 Copy_u8PinNb, u8  Copy_u8Value )
{
	u8 Local_u8Result    = ERROR_NO;
	u8 Local_u8ActualPrt = Copy_u8PinNb / 16;
	u8 Local_u8ActualPin = Copy_u8PinNb % 16;

	switch (Copy_u8Value)
	{
		case GPIO_PIN_HIGH: Local_u8Result = u8SetPin(Local_u8ActualPrt,Local_u8ActualPin); break;
		case GPIO_PIN_LOW : Local_u8Result = u8RstPin(Local_u8ActualPrt,Local_u8ActualPin); break;
		default           : Local_u8Result = ERROR_NOK;                                     break;
	}

	return Local_u8Result;
}


u8   GPIO_u8SetPinDirectionType   (u8 Copy_u8PinNb, u8 Copy_u8Mode   )
{
	u8 Local_u8Result    = ERROR_NO;
	u8 Local_u8ActualPrt = Copy_u8PinNb / 16;
	u8 Local_u8ActualPin = Copy_u8PinNb % 16;
	/*
	 * VALIDATION FOR MODES
	 */
	/*
	if((Copy_u8Mode == (INPUT_FLOATING) |(INPUT_PULLUP )|(INPUT_PULLDOWN )| INPUT_ANALOG |OUTPUT_10MHZ_GP_PUSHPULL \
				 |OUTPUT_10MHZ_GP_OPENDRAIN | OUTPUT_10MHZ_AF_PUSHPULL|OUTPUT_10MHZ_AF_OPENDRAIN| OUTPUT_2MHZ_GP_PUSHPULL|\
				 OUTPUT_2MHZ_GP_OPENDRAIN| OUTPUT_2MHZ_AF_PUSHPULL| OUTPUT_2MHZ_AF_OPENDRAIN|\
				 OUTPUT_50MHZ_GP_PUSHPULL |OUTPUT_50MHZ_GP_OPENDRAIN  |OUTPUT_50MHZ_AF_PUSHPULL | OUTPUT_50MHZ_AF_OPENDRAIN   ) )
	*/
    //set odr-> pull up
	/*if (Copy_u8Mode == INPUT_PULLUP)
	{
		// Set ODR -> 1
		switch (Local_u8ActualPrt)
		{
			case GPIO_PORTA: SET_BIT(GPIOA->ODR.WordAccess, Local_u8ActualPin); break;
			case GPIO_PORTB: SET_BIT(GPIOB->ODR.WordAccess, Local_u8ActualPin); break;
			case GPIO_PORTC: SET_BIT(GPIOC->ODR.WordAccess, Local_u8ActualPin); break;
			case GPIO_PORTD: SET_BIT(GPIOC->ODR.WordAccess, Local_u8ActualPin); break;
		}
	}

	else if (Copy_u8Mode == INPUT_PULLDOWN)
	{
		switch (Local_u8ActualPrt)
		{	//clear odr ->pull down
			case GPIO_PORTA: CLR_BIT(GPIOA->ODR.WordAccess, Local_u8ActualPin);break;
			case GPIO_PORTB: CLR_BIT(GPIOB->ODR.WordAccess, Local_u8ActualPin);break;
			case GPIO_PORTC: CLR_BIT(GPIOC->ODR.WordAccess, Local_u8ActualPin);break;
			case GPIO_PORTD: CLR_BIT(GPIOC->ODR.WordAccess, Local_u8ActualPin);break;
		}
		Copy_u8Mode = INPUT_PULLUP;
	}
*/
	if(Local_u8ActualPin <= 7)
	{
		switch (Local_u8ActualPrt)
		{
			case GPIO_PORTA: ASSIGN_NIBBLE(GPIOA->CRL.WordAccess,Local_u8ActualPin, Copy_u8Mode); break;
			case GPIO_PORTB: ASSIGN_NIBBLE(GPIOB->CRL.WordAccess,Local_u8ActualPin, Copy_u8Mode); break;
			case GPIO_PORTC: ASSIGN_NIBBLE(GPIOC->CRL.WordAccess,Local_u8ActualPin, Copy_u8Mode); break;
			case GPIO_PORTD: ASSIGN_NIBBLE(GPIOD->CRL.WordAccess,Local_u8ActualPin, Copy_u8Mode); break;
			default          : Local_u8Result = ERROR_NOK;                                        break;
		}
	}

	else
	{
		Local_u8ActualPin -=  8;
		switch (Local_u8ActualPrt)
		{
			case GPIO_PORTA: ASSIGN_NIBBLE(GPIOA->CRH.WordAccess,Local_u8ActualPin, Copy_u8Mode); break;
			case GPIO_PORTB: ASSIGN_NIBBLE(GPIOB->CRH.WordAccess,Local_u8ActualPin, Copy_u8Mode); break;
			case GPIO_PORTC: ASSIGN_NIBBLE(GPIOC->CRH.WordAccess,Local_u8ActualPin, Copy_u8Mode); break;
			case GPIO_PORTD: ASSIGN_NIBBLE(GPIOD->CRH.WordAccess,Local_u8ActualPin, Copy_u8Mode); break;
			default        : Local_u8Result = ERROR_NOK;                                          break;
		}
	}

	return Local_u8Result;
}


u8 GPIO_u8GetPinValue(u8 Copy_u8PinNb, u8*  Copy_Pu8Value )
{
	u8 Local_u8Result    = ERROR_NO;
	u8 Local_u8ActualPrt = Copy_u8PinNb / 16;
	u8 Local_u8ActualPin = Copy_u8PinNb % 16;

	switch (Local_u8ActualPrt)
	{
		case GPIO_PORTA: *Copy_Pu8Value = GET_BIT(GPIOA->IDR.WordAccess,Local_u8ActualPin); break;
		case GPIO_PORTB: *Copy_Pu8Value = GET_BIT(GPIOB->IDR.WordAccess,Local_u8ActualPin); break;
		case GPIO_PORTC: *Copy_Pu8Value = GET_BIT(GPIOC->IDR.WordAccess,Local_u8ActualPin); break;
		case GPIO_PORTD: *Copy_Pu8Value = GET_BIT(GPIOD->IDR.WordAccess,Local_u8ActualPin); break;
		default          :  Local_u8Result = ERROR_NOK;
	}


	return Local_u8Result;
}


u8 GPIO_GetPortValue(u8 Copy_u8PortNb, u8* Copy_Pu32Value)
{


	u8 Local_u8Result    = ERROR_NO;

	switch (Copy_u8PortNb)
	{
		case GPIO_PORTA: *Copy_Pu32Value = GPIOA->IDR.WordAccess; break;
		case GPIO_PORTB: *Copy_Pu32Value = GPIOB->IDR.WordAccess; break;
		case GPIO_PORTC: *Copy_Pu32Value = GPIOC->IDR.WordAccess; break;
		case GPIO_PORTD: *Copy_Pu32Value = GPIOD->IDR.WordAccess; break;
		default        :  Local_u8Result = ERROR_NOK;
	}


	return Local_u8Result;
}
u8 GPIO_u8SetPortValue(u8 Copy_u8PortNb,u16 Copy_u16Value)
{
	u8 local_u8ErrorState=ERROR_NO;

	switch(Copy_u8PortNb)
	{
	/*WORD1 IS FOR RESERVED BITS CANT WRITE ON THEM*/
	case GPIO_PORTA: ASSIGN_HALFWORD(WORD0,Copy_u16Value,GPIOA->ODR.WordAccess); break;
	case GPIO_PORTB: ASSIGN_HALFWORD(WORD0,Copy_u16Value,GPIOA->ODR.WordAccess); break;
	case GPIO_PORTC: ASSIGN_HALFWORD(WORD0,Copy_u16Value,GPIOA->ODR.WordAccess); break;
	case GPIO_PORTD: ASSIGN_HALFWORD(WORD0,Copy_u16Value,GPIOA->ODR.WordAccess); break;
	default :         local_u8ErrorState=ERROR_NOK;
	}


return local_u8ErrorState;
}
