/*
 * SYSTICK_private.h
 *
 *  Created on: Apr 7, 2019
 *      Author: AyetAllah
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_




#define STK_CTRL                                       (*(u32 *)0XE000E010)
#define STK_LOAD                                      (*(u32 *)0XE000E014)
#define STK_VAL                                         (*(u32 *)0XE000E018)


#endif /* SYSTICK_PRIVATE_H_ */
