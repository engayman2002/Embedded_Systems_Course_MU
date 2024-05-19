#ifndef COMMON_H_
#define	COMMON_H_

#define _XTAL_FREQ (8000000)
#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdio.h>

// bit masking macros
#define SET_BIT(reg,bit)        (reg = reg | 1<<bit)
#define CLEAR_BIT(reg,bit)      (reg = reg & (~(1<<bit)))
#define GET_BIT_STATUS(reg,bit) (reg & (1<<bit)?1:0)

/* declaring variables used with the LCD screen (write the bit and its
direction on the same line ) 
--- This must be defined before any include to "lcd.h"   */
#define LCD_RS             RD0
#define LCD_RS_Direction   TRISD0    
#define LCD_EN             RD1
#define LCD_EN_Direction   TRISD1    
// declaring the data bits and their direction
#define LCD_D4             RD2
#define LCD_D4_Direction   TRISD2   
#define LCD_D5             RD3
#define LCD_D5_Direction   TRISD3    
#define LCD_D6             RD4
#define LCD_D6_Direction   TRISD4    
#define LCD_D7             RD5
#define LCD_D7_Direction   TRISD5
#endif	//COMMON_H_

