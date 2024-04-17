/*
 * File:   main.c
 * Author: engay
 *
 * Created on April 17, 2024, 5:36 PM
 */


#include <xc.h>
#define _XTAL_FREQ (8000000)

#include "common.h"
#include "keypad.h"
#include "lcd.h"

#define delay __delay_ms

char Get_Password(void)
{
    int i;
    int state=0;
    lcd_cmd(_LCD_CLEAR);
    lcd_cmd(_LCD_RETURN_HOME);
    lcd_cmd(_LCD_CURSOR_OFF);
    lcd_out(1,1,"Enter the password");
    char pass;
    
    lcd_set_cursor(2,1);
    for(i=0;i<4;i++)
    {
        pass='\0';
        while(pass=='\0')
        {
            pass=keypad_get_key();
        }
        lcd_chr_cp(pass);
        
       if(pass!=i+1+48)
       {
           state++;
       }
    }
    delay(200); // for seeing the last num
    return state==0?1:0;
}

void main(void) {
    lcd_init();
    keypad_init();
    
    lcd_cmd(_LCD_CLEAR);
    lcd_cmd(_LCD_RETURN_HOME);
    lcd_cmd(_LCD_CURSOR_OFF);
    
    lcd_out(1,1,"WELCOME USER");
    delay(2000);
    
    int i;
    char flag=0;
    while(1)
    {
        flag=Get_Password();
        if(flag==1)
        {
            break;
        }
        lcd_cmd(_LCD_CLEAR);
        lcd_cmd(_LCD_RETURN_HOME);
        lcd_cmd(_LCD_CURSOR_OFF);
        lcd_out(1,1,"WRONG PASSWORD");
        delay(1500);
        
    }
    
    lcd_cmd(_LCD_CLEAR);
    lcd_cmd(_LCD_RETURN_HOME);
    lcd_cmd(_LCD_CURSOR_OFF);
    lcd_out(1,1,"Ayman");
    lcd_out(2,1,"Mohamed");
    
    while(1)
    {
        
    for(i=0;i<8;i++)
    {
        lcd_cmd(_LCD_SHIFT_RIGHT);
        delay(300);
    }
    
    for(i=0;i<8;i++)
    {
        lcd_cmd(_LCD_SHIFT_LEFT);
        delay(300);
    }
    
    }
    
    
    
    
    return;
}
