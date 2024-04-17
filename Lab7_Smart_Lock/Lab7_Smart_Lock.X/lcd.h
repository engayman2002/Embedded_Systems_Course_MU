#ifndef _LCD_H_
#define _LCD_H_

#include "common.h"
#ifndef LCD_RS
    #error "LCD_RS pin definition is missing"
#endif
#ifndef LCD_EN
    #error "LCD_EN pin definition is missing"
#endif
#ifndef LCD_D4
    #error "LCD_D4 pin definition is missing"
#endif
#ifndef LCD_D5
    #error "LCD_D5 pin definition is missing"
#endif
#ifndef LCD_D6
    #error "LCD_D6 pin definition is missing"
#endif
#ifndef LCD_D7
    #error "LCD_D7 pin definition is missing"
#endif
#ifndef LCD_RS_Direction
    #error "LCD_RS_Direction bit register definition is missing"
#endif
#ifndef LCD_EN_Direction
    #error "LCD_EN_Direction bit register definition is missing"
#endif
#ifndef LCD_D4_Direction
    #error "LCD_D4_Direction bit register definition is missing"
#endif
#ifndef LCD_D5_Direction
    #error "LCD_D5_Direction bit register definition is missing"
#endif
#ifndef LCD_D6_Direction
    #error "LCD_D6_Direction bit register definition is missing"
#endif
#ifndef LCD_D7_Direction
    #error "LCD_D7_Direction bit register definition is missing"
#endif

#define LCD_EN_Delay 1800
#define RS LCD_RS
#define EN LCD_EN
#define D4 LCD_D4
#define D5 LCD_D5
#define D6 LCD_D6
#define D7 LCD_D7
//============================================
// =========== LCD Commands ==================
//============================================
#define _LCD_CLEAR                  (0x01)
#define _LCD_RETURN_HOME            (0x02)
#define _LCD_TURN_ON                (0x0C)
#define _LCD_TURN_OFF               (0x08)
#define _LCD_CURSOR_OFF             (0x0C)
#define _LCD_CURSOR_ON              (0x0E)
#define _LCD_BLINK_CURSOR_ON        (0x0F)
#define _LCD_BLINK_CURSOR_OFF       (_LCD_CURSOR_ON)
#define _LCD_SHIFT_RIGHT            (0x1C)
#define _LCD_SHIFT_LEFT             (0x18)

//==============================================
//-----[ Prototypes For All LCD Functions ]-----
// Initialize The LCD For 4-Bit Interface 
void lcd_init(void); 
// Send Command To LCD
void lcd_cmd(unsigned char);
// Set Cursor Position
void lcd_set_cursor(unsigned char, unsigned char);
// Write string To LCD At the given Position (row, columns)
void lcd_out(unsigned char row,unsigned char col,char* str); 
// Write string To LCD At the cursor Position
void lcd_out_cp(char *str); 
// Write A character To LCD at give position
void lcd_chr(unsigned char row,unsigned char col,unsigned char chr);
// Write character To LCD At the cursor Position
void lcd_chr_cp(unsigned char chr);

#endif