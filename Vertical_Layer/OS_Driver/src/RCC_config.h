/*
 * RCC_config.h
 *
 *  Created on: Feb 28, 2019
 *      Author: AyetAllah
 */

/***********************************************PRIVATE CONFIGURATION************************************************/
/*
#ifdef RCC_PRIVATE_H_
#ifndef RCC_CONFIG_H_PRIVATE
#define RCC_CONFIG_H_PRIVATE




#endif //RCC_CONFIG_H_PRIVATE
//#endif //RCC_PRIVATE_H_

/**************************************PUBLIC CONFIGURATION**********************************************************************************************/

//#ifdef RCC_INTERFACE_H_
//#ifndef RCC_CONFIG_PUBLIC
//#define RCC_CONFIG_PUBLIC


#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H
/*==============================================PLL Source====================================================*/
/****************************************************************
* range to choose between   HSI_OSCILLATOR_DIVIED_TWO           *
*                           HSE_CLOCK_PREDIV1                   *
*****************************************************************/
#define  PLL_SRC       HSI_OSCILLATOR_DIVIED_TWO



/*================================Clock Source System (is dominant)====================================*/
/***********************************************************************
 *  choose the source of the clock systemSW  from three choices        *
 *     SW_HSI                                                          *
 *     SW_HSE                                                          *
 *     SW_PLL                                                          *
 * *********************************************************************/
#define SW  SW_HSI


/*=====================================States Clock in System========================*/
/*************************************************
 * choose the state of each clock is on or off   *
 *   					ON                       *
 *   					OFF                      *
 *************************************************/

#define  HSION   ON
#define  HSEON   OFF
#define  PLLON   OFF




/*======================================PLL Multiplication==============================*/

/**********************************************************************
 * choose pll_mul from                                                *
 *               PLL_INPUT_CLOCK_X4                                   *
 * 				 PLL_INPUT_CLOCK_X5                                   *
 * 				 PLL_INPUT_CLOCK_X6                                   *
 * 				 PLL_INPUT_CLOCK_X7                                   *
 * 				 PLL_INPUT_CLOCK_X8                                   *
 * 				 PLL_INPUT_CLOCK_X9                                   *
 * 				 PLL_INPUT_CLOCK_XSIX_HALF                            *
 * 				                                                      *
 * 				                                                      *
 **********************************************************************/

#define  PLL_MUL    PLL_INPUT_CLOCK_X4


/*====================PRESCALAR BUS=============================*/

/**********************************************************************
 * PPRE2 is 11:13 bits in configuration register to APB high speed    *
 * APB2                                                               *
 *********************************************************************/
#define  PPRE2             APB_DIV_1
/**********************************************************************
 * PPRE1 is 8:10 bits in configuration register to APB low speed      *
 * APB1                                                               *
 *********************************************************************/
#define  PPRE1  		   APB_DIV_1
#define  HPRE			   AHB_DIV_1


#endif /*RCC_CONFIG_H*/
//#endif /*RCC_CONFIG_PUBLIC*/
//#endif /*RCC_INTERFACE_H_*/
