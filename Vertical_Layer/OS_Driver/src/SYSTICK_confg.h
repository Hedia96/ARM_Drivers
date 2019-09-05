/*
 * SYSTICK_confg.h
 *
 *  Created on: April 22, 2019
 *  Author: AyetAllah
 */

#ifndef SYSTICK_CONFG_H_
#define SYSTICK_CONFG_H_
#include "SYSTICK_private.h"

#define AHB_CLOCK                         (f64)8000000.0

/*CHOOSE THE SOURCE OF SYSTICK*/

#define SOURCE_SYSTICK_AHB                    1
#define SOURCE_SYSTICK_AHB_8                  0
/*CHOOSE THE SYSTICK EXCEPTION REQUEST ENABLE/DISABLE*/
#define ENABLE_EXCEPTION                      1
#define DISABLE_EXCEPTION                     0


/************************CONFIGURATION SYSTICK***********************/
#define SOURCE_SYSTICK                        SOURCE_SYSTICK_AHB_8
#define SYSTICK_EXCEPTION_REQUEST             ENABLE_EXCEPTION


/******************************************************************/



#endif /* SYSTICK_CONFG_H_ */
