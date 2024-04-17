/*
 * File:   main.c
 * Author: engay
 *
 * Created on March 31, 2024, 2:22 AM
 */


#include <xc.h>
#define _XTAL_FREQ (8000000)
#define Mini_Delay 30


void main(void) {
    
    int num=0;
    
    TRISC=0x00;
    TRISD=0x00;
    
    PORTC=0x00;
    PORTD=0x00;
    __delay_ms(1000);
    
    
    while(num<=9999)
    {
        PORTC=num%10;
        PORTD=~(0x08);
        __delay_ms(Mini_Delay);
        
        PORTC=(num/10)%10;
        PORTD=~(0x04);
        __delay_ms(Mini_Delay);
        
        PORTC=(num/100)%10;
        PORTD=~(0x02);
        __delay_ms(Mini_Delay);
        
        PORTC=(num/1000)%10;
        PORTD=~(0x01);
        __delay_ms(Mini_Delay);
        
        num++;
    }
    
    return;
}
