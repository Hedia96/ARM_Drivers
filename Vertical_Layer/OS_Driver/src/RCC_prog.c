/*
 * RCC_prog.c
 *
 *  Created on: Feb 28, 2019
 *      Author: AyetAllah
 */
#include "STD_TYPE.h"
#include "BIT_CALC.h"

#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"
/*********************************************************************
 * AUTHOR: AYA ABDELMAGIED                                           *
 *                                                                   *
 * VERSION: V2                                                       *
 *                                                                   *
 * DATE  : 28 FEBURARY 2019                                          *
 *                                                                   *
 *********************************************************************/


/*
 * NAME       :
 * DESCRPITION:
 * ARGUMENTS  :
 * RETURN     :
 *
 */


#define FIIRSTBIT   0
#define SECONDBIT   1


void RCC_VInit(void)
{
	/*Select clock system and should make sure it is on and ready*/


	//RCC->RCC_CR.WordAccess = 0x00000001;

			if(HSION == ON)
			{
			SET_BIT(RCC->RCC_CR.WordAccess,RCC_INDEX_BIT_HSION_CR);
			//wait till activeRDY
			while(!GET_BIT(RCC->RCC_CR.WordAccess,RCC_INDEX_BIT_HSIRDY_CR));
			}
/*
			if(HSEON == ON)
			{
			ASSIGN_BIT(RCC->RCC_CR.WordAccess,RCC_INDEX_BIT_HSEON_CR,HSEON);
			while(!GET_BIT(RCC->RCC_CR.WordAccess,RCC_INDEX_BIT_HSIRDY_CR));
			}
*/

			//if(PLLON == ON)
		//	{

			/* configuration then enable
			 *
			 * 1-configure the source of pll is external or internal
			 * 2-if ready of both or one is already high don't enable it again
			 * 3-Multiplication of pll
			 * 4- turn on the pll
			 * 5-wait till ready
			 * */
			//ASSIGN_BIT(RCC->RCC_CR.WordAccess,RCC_INDEX_BIT_PLLON_CR,PLLON);
			//while(! (GET_BIT( RCC->RCC_CR.WordAccess , RCC_INDEX_BIT_PLLRDY_CR )));
			//}

			//select status clock for system


	//RCC->RCC_CFGR.WordAccess = 0x00000000;
     		RCC->RCC_CFGR.BitAccess.bit0=GET_BIT(SW,FIIRSTBIT);
			RCC->RCC_CFGR.BitAccess.bit1=GET_BIT(SW,SECONDBIT);
			/****Choosing prescalar for buses****/


			/*reset the port A,B,C,D*/
			//RCC ->RCC_APB2RSTR.BitAccess.bit2=1;
			//RCC ->RCC_APB2RSTR.BitAccess.bit3=1;
			//RCC ->RCC_APB2RSTR.BitAccess.bit4=1;
			//RCC ->RCC_APB2RSTR.BitAccess.bit5=1;



	}






/*
 * NAME       : RCC_u8EnablePerphieral
 * DESCRPITION:
 * ARGUMENTS  :
 * RETURN     :
 *
 */


//RCC_INDEX_BIT_HSION_CR






u8 RCC_u8EnablePerphieral(u8 Copy_u8SelectPerpherial)
{
	u8 local_u8ErrorState=ERROR_NO;

	//RCC->RCC_APB2ENR.WordAccess = 0x00000004;

	switch(Copy_u8SelectPerpherial)
	{
	case PERIPHERAL_GPIO_PORTA:
		SET_BIT(RCC->RCC_APB2ENR.WordAccess,RCC_INDEX_BIT_IOPAEN_APB2ENR);

		break;
	case PERIPHERAL_GPIO_PORTB:
		SET_BIT(RCC->RCC_APB2ENR.WordAccess,RCC_INDEX_BIT_IOPBEN_APB2ENR);
		break;
	case PERIPHERAL_GPIO_PORTC:
		SET_BIT(RCC->RCC_APB2ENR.WordAccess,RCC_INDEX_BIT_IOPCEN_APB2ENR);
			break;
	case PERIPHERAL_GPIO_PORTD:
		SET_BIT(RCC->RCC_APB2ENR.WordAccess,RCC_INDEX_BIT_IOPDEN_APB2ENR);
		break;
	default: local_u8ErrorState=ERROR_NOK  ;


		}
	return local_u8ErrorState;

}


/*
 * NAME       :
 * DESCRPITION:
 * ARGUMENTS  :
 * RETURN     :
 *
 */
