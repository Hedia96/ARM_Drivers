/*
 * STD_TYPE.H
 *
 *  Created on: Feb 24, 2019
 *      Author: AyetAllah
 */

#ifndef STD_TYPE_H_
#define STD_TYPE_H_



#define ERROR_NOK                 1
#define ERROR_NO                  0
#define NULL                    ((void *)0)
#define MIN_U8                  (u8) 0
#define MIN_U32                 (u32)0



typedef unsigned char          u8;
typedef unsigned short int     u16;
typedef unsigned long int      u32;
typedef unsigned long long int u64;

typedef signed char            s8;
typedef signed short int       s16;
typedef signed long int        s32;
typedef signed long long int   s64;

typedef float                  f32;
typedef double                 f64;

typedef union
{
	struct
	{
		u32 bit0  :1;
		u32 bit1  :1;
		u32 bit2  :1;
		u32 bit3  :1;
		u32 bit4  :1;
		u32 bit5  :1;
		u32 bit6  :1;
		u32 bit7  :1;
		u32 bit8  :1;
		u32 bit9  :1;
		u32 bit10 :1;
		u32 bit11 :1;
		u32 bit12 :1;
		u32 bit13 :1;
		u32 bit14 :1;
		u32 bit15 :1;
		u32 bit16 :1;
		u32 bit17 :1;
		u32 bit18 :1;
		u32 bit19 :1;
		u32 bit20 :1;
		u32 bit21 :1;
		u32 bit22 :1;
		u32 bit23 :1;
		u32 bit24 :1;
		u32 bit25 :1;
		u32 bit26 :1;
		u32 bit27 :1;
		u32 bit28 :1;
		u32 bit29 :1;
		u32 bit30 :1;
		u32 bit31 :1;


	}BitAccess;

	u32 WordAccess;

}Register_32bit;

/*
 * #define GPIOC_CRL_ADDRESS   0x40011000
#define GPIOC_CRH_ADDRESS   0x40011004
#define GPIOC_IDR_ADDRESS   0x40011008
#define GPIOC_ODR_ADDRESS   0x4001100C
#define GPIOC_BSRR_ADDRESS  0x40011010
#define GPIOC_BRR_ADDRESS   0x40011014
#define GPIOC_LCKR_ADDRESS  0x40011018
 *
 */


typedef union
{
	struct
	{
		u16 bit0  :1;
		u16 bit1  :1;
		u16 bit2  :1;
		u16 bit3  :1;
		u16 bit4  :1;
		u16 bit5  :1;
		u16 bit6  :1;
		u16 bit7  :1;
		u16 bit8  :1;
		u16 bit9  :1;
		u16 bit10 :1;
		u16 bit11 :1;
		u16 bit12 :1;
		u16 bit13 :1;
		u16 bit14 :1;
		u16 bit15 :1;
	}BitAccess;
		u16 WordAccess;

	}Register_16bit;


#endif /* STD_TYPE_H_ */
