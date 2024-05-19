/* 
 * File:   timer.h
 * Author: Omar Wahba
 *
 * Created on 28 April 2024, 17:03
 */

#ifndef TIMER_H_
#define	TIMER_H_

#include "common.h"
/**** Timer *******/
#define TIMER0_MAX_VAL       (256)
/*Timer prescaler values */
#define _TIMER_PRESCALER_2   (0)
#define _TIMER_PRESCALER_4   (1)
#define _TIMER_PRESCALER_8   (2)
#define _TIMER_PRESCALER_16  (3)
#define _TIMER_PRESCALER_32  (4)
#define _TIMER_PRESCALER_64  (5)
#define _TIMER_PRESCALER_128 (6)
#define _TIMER_PRESCALER_256 (7)

/************ Timer APIs **********************/

/*
 * This function initialize the timer-0 module
 * @param[in] prescaler is the requied prescaler value defined in timer.h
 */
void timer0_init(char prescaler);

void counter0_init(void);
/*
 * This function gets the time passed in ms after system initialization is done
 */
unsigned long timer_get_time_since_init();

unsigned long counter0_get_val();
#endif	/* TIMER_H_ */

