/* 
 * File:   keypad.h
 * Author: Omar Wahba
 *
 * Created on 24 March 2024, 00:00
 */

#ifndef KEYPAD_H
#define	KEYPAD_H
#include "common.h"

void keypad_init(void);
unsigned char keypad_get_key(void);
#endif	/* KEYPAD_H */

