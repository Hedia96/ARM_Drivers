/*
 * RCC_private.h
 *
 *  Created on: Feb 28, 2019
 *      Author: AyetAllah
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_



typedef struct
{
	Register_32bit RCC_CR;
	Register_32bit RCC_CFGR;
	Register_32bit RCC_CIR;
	Register_32bit RCC_APB2RSTR;
	Register_32bit RCC_APB1RSTR;
	Register_32bit RCC_APHBENR;
	Register_32bit RCC_APB2ENR;
	Register_32bit RCC_APB1ENR;
	Register_32bit RCC_BDCR;
	Register_32bit RCC_CSR;



}RCCstype;

#define  RCC  ((RCCstype *)(0x40021000))

/*====================INDECIES IN REGISTER=======================*/

#define RCC_INDEX_BIT_HSION_CR           0
#define RCC_INDEX_BIT_HSIRDY_CR          1
#define RCC_INDEX_BIT_HSEON_CR           16
#define RCC_INDEX_BIT_HSEON_RDY          17
#define RCC_INDEX_BIT_PLLON_CR           24
#define RCC_INDEX_BIT_PLLRDY_CR          25

#define RCC_INDEX_BIT_IOPAEN_APB2ENR       2
#define RCC_INDEX_BIT_IOPBEN_APB2ENR       3
#define RCC_INDEX_BIT_IOPCEN_APB2ENR       4
#define RCC_INDEX_BIT_IOPDEN_APB2ENR       5




/*===============Clock Source System (is dominant)===========*/

#define SW_HSI  0b00
#define SW_HSE  0b01
#define SW_PLL  0b10


/*===============States Clock in System============*/

#define  ON  1
#define  OFF 0


/*================PLL Multiplication============*/
#define PLL_INPUT_CLOCK_X4          0b0010
#define PLL_INPUT_CLOCK_X5          0b0011
#define PLL_INPUT_CLOCK_X6          0b0100
#define PLL_INPUT_CLOCK_X7          0b0101
#define PLL_INPUT_CLOCK_X8          0b0110
#define PLL_INPUT_CLOCK_X9          0b0111
#define PLL_INPUT_CLOCK_XSIX_HALF   0b1101



/*=================PLL Source======================*/

#define HSI_OSCILLATOR_DIVIED_TWO     0
#define HSE_CLOCK_PREDIV1             1




/*=====================PRESCALLER BUSES================*/

/******************AHB BUS********************/
/*add HCLK to name*/
#define AHB_DIV_1                           0b0000
#define AHB_DIV_2						  	0b1000
#define AHB_DIV_4							0b1001
#define AHB_DIV_8							0b1010
#define AHB_DIV_16							0b1011
#define AHB_DIV_64							0b1100
#define AHB_DIV_128							0b1101
#define AHB_DIV_256							0b1110
#define AHB_DIV_512							0b1111


/***************APB BUS**********************/
#define APB_DIV_1							0b000
#define APB_DIV_2							0b100
#define APB_DIV_4							0b101
#define APB_DIV_8							0b110
#define APB_DIV_16						    0b111



#endif /* RCC_PRIVATE_H_ */
