/*
 * File:   main.c
 * Author: engay
 *
 * Created on May 10, 2024, 1:15 AM
 */


#include <xc.h>
#include "common.h"
#include "lcd.h"
#include "timer.h"

extern unsigned long timer0_time_passed_ms;
extern unsigned short overflow_cnt;

#define WakeUp_Button   PORTBbits.RB0
#define Up_Button       PORTBbits.RB5
#define Down_Button     PORTBbits.RB6
#define Reset_Button    PORTBbits.RB7

#define ON 0
#define OFF 1

#define Sleep_Mode_Time 4000

void My_init_Function()
{
    lcd_init();
    timer0_init(_TIMER_PRESCALER_2);
    lcd_cmd(_LCD_CLEAR);
    OPTION_REGbits.nRBPU = 0;
    INTE = 1;
    INTF = 0;
    INTEDG= 1;
    TRISB=0xff;
    GIE=1;
}

void Print(int mynum)
{
    char My_Buffer[9];
    sprintf(My_Buffer,"%d",mynum);
    lcd_out_cp(My_Buffer);
}

void __interrupt() ISR()
{
    GIE = 0;
    if(INTE == 1 && INTF == 1)
    {
        // My_Implementaion here
        timer0_time_passed_ms = 0 ; // Reset My Timer To start calcualte from zero.
        INTF = 0;
        GIE = 1;
        return;
    }
    if(TMR0IF==1 && TMR0IE==1)
    {
        overflow_cnt++;
        if(overflow_cnt==4)
        {
            timer0_time_passed_ms++;
            overflow_cnt = 0;
        }
        TMR0IF=0;
    }
    TMR0= 6+40;
    GIE=1;
}

void my_delay(unsigned long mytime)
{
    unsigned long start_time=0,end_time=0;
    end_time = timer_get_time_since_init();
    while(end_time-start_time<=mytime)
    {
        end_time = timer_get_time_since_init();
    }
    timer0_time_passed_ms=0;
}

void main(void) {
    My_init_Function();
    int count = 0;
    
    lcd_out(1,1,"  WELCOME USER");
    my_delay(3000);
    lcd_cmd(_LCD_CLEAR);
    unsigned long start_time=0,end_time=0;
    while(1)
    {
        if(end_time-start_time<=Sleep_Mode_Time)
        {
            lcd_out(1,1,"Count = ");
            //lcd_chr_cp(count+48); // Make it good. 
            Print(count);
            if(Up_Button == ON)
            {
                count++;
                timer0_time_passed_ms=0;
                while(Up_Button == ON);
                lcd_cmd(_LCD_CLEAR);
            }
            if(Down_Button == ON)
            {
                if(count!=0)
                {
                    count--;
                }
                timer0_time_passed_ms=0;
                while(Down_Button == ON);
                lcd_cmd(_LCD_CLEAR);
            }
            if(Reset_Button == ON)
            {
                count = 0;
                timer0_time_passed_ms=0;
                while(Reset_Button == ON);
                lcd_cmd(_LCD_CLEAR);
            }
        }
        else
        {
            lcd_cmd(_LCD_CLEAR);
            while(end_time-start_time>Sleep_Mode_Time)
            {
                end_time = timer0_time_passed_ms ;
            }
            lcd_out(1,1,"Wake up Ayman");
            my_delay(2000);
            timer0_time_passed_ms = 0 ;
            lcd_cmd(_LCD_CLEAR);
        }
        end_time = timer_get_time_since_init();
    }
    
    
    
    return;
}
