/*
 * BIT_CALC.h
 *
 *  Created on: Feb 24, 2019
 *      Author: AyetAllah
 */

#ifndef BIT_CALC_H_
#define BIT_CALC_H_


#define  SET_BIT(var,bit_index)                    ((var) |= (1 << (bit_index)))
#define  CLR_BIT(var,bit_index)                    ((var) &= (~ (1 << (bit_index))))
#define  ASSIGN_BIT(var,bit_index,value)           ((value==1)?SET_BIT(var,bit_index):CLR_BIT(var,bit_index))
#define  GET_BIT(var,bit_index)		               ((var&(1<<bit_index))>>bit_index)
/*
Here if directive has both function like macro and obj like macro so funlike has more prority than object
so we do this ,because the problem is aroused when fun-lke concatenate before replace the value should obj-like do
so we make two stages by CONC_HELP
*/
#define  CONC_8BITS(b7,b6,b5,b4,b3,b2,b1,b0)     (CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0))
#define  CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)       0b##b7##b6##b5##b4##b3##b2##b1##b0
#define  WIDTH_NIBBLE 4
//#define ASSIGN_NIBBLE(NibbleIndex,Value,Register)
#define ASSIGN_NIBBLE( Register, NibbleIndex , Value )	  (Register) = ( ( (Register)&(~(0xf << (WIDTH_NIBBLE*NibbleIndex))) ) | (Value << (WIDTH_NIBBLE*NibbleIndex)) )
/*to assign clear the bits firstly then put the values by or
 * and 000F because it is 32 bit register and the value too
 *
 */
#define WIDTH_HALFWORD 16
#define ASSIGN_HALFWORD(HALFWORDINDEX,Value,Register)  (Register)=( ((u32)(Register)&(u32)(~(0xffff << WIDTH_HALFWORD*HALFWORDINDEX)))|((u16)(Value << WIDTH_HALFWORD*HALFWORDINDEX)) )
#endif /* BIT_CALC_H_ */
