/*
 * File:   main.c
 * Author: engay
 *
 * Created on April 17, 2024, 2:22 AM
 */

#define _XTAL_FREQ (8000000)

#include <xc.h>

#define random_number(min,max) (rand() % ((max)-(min)+1)+(min))
#define LED_RED PORTDbits.RD6
#define LED_Green PORTDbits.RD7
#define LED_Yellow0 PORTDbits.RD0
#define LED_Yellow1 PORTDbits.RD1
#define LED_Yellow2 PORTDbits.RD2



void keypad_init(void)
{
    OPTION_REGbits.nRBPU = 0;
    TRISB = 0x38; // 0011 1000 (0,1,2)-O/P (3,4,5)-I/P
    PORTB =0x07;  // 0000 0111 (0,1,2) are initially high to make rows the provider of volt
    TRISD = 0; // Make LEDs Output
    PORTD = 0; // Put Low on all pins
    return;
}

char keypad_get_key(void)
{
    char num='\0';
    while(num=='\0')
    {
        // First Row
        PORTB=0x07;
        PORTBbits.RB0=0;
        if(PORTBbits.RB3==0)
        {
            num=1;
        }
        else if(PORTBbits.RB4==0)
        {
            num=2;
        }
        else if(PORTBbits.RB5==0)
        {
            num=3;
        }
        
        // Second Row
        PORTB=0x07;
        PORTBbits.RB1=0;
        if(PORTBbits.RB3==0)
        {
            num=4;
        }
        else if(PORTBbits.RB4==0)
        {
            num=5;
        }
        else if(PORTBbits.RB5==0)
        {
            num=6;
        }
        
        // Third Row
        PORTB=0x07;
        PORTBbits.RB2=0;
        if(PORTBbits.RB3==0)
        {
            num=7;
        }
        else if(PORTBbits.RB4==0)
        {
            num=8;
        }
        else if(PORTBbits.RB5==0)
        {
            num=9;
        }
    }
    PORTB=0x07;
    return num;
}


void main(void) {
    keypad_init();
    
    int actual_num;
    int guess_num;
    
    int i;
    for(i=0;i<3;i++)
    {
        actual_num=random_number(1,9);
        guess_num=keypad_get_key();
        
        __delay_ms(1000);
        

        
        if(actual_num==guess_num)
        {
            PORTD=0;
            LED_Green=1;
            while(1);
        }
        else
        {
            LED_Yellow0= ((actual_num & 1<<2)!=0);
            LED_Yellow1= ((actual_num & 1<<1)!=0);
            LED_Yellow2= ((actual_num & 1<<0)!=0);
        }
    }
    
    PORTD=0x07;
    LED_RED=1;
    while(1);
    
    
    return;
}

 