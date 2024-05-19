#include "timer.h"


unsigned long timer0_time_passed_ms =0;
unsigned short overflow_cnt =0;

/*
 * This function initialize the timer-0 module
 * @param[in] prescaler is the requied prescaler value defined in timer.h
 */
void timer0_init(char prescaler)
{
    OPTION_REG = (OPTION_REG & 0xF8) | (prescaler & 0x7); //set pre-scaler to 1/2
    OPTION_REGbits.T0CS =0;
    OPTION_REGbits.T0SE =0;
    OPTION_REGbits.PSA =0;
    //enable timer-0 overflow interrupt
    TMR0IE = 1;
    TMR0IF = 0;
    GIE =1;
}

void counter0_init(void)
{
    //configure Timer0 as counter
    OPTION_REGbits.T0CS =1;
    OPTION_REGbits.T0SE =1;
    OPTION_REGbits.PSA  =1; //no prescaler 
    //make RA4 input
    ADCON1 = 6;
    TRISA4 = 1;
    //enable timer-0 overflow interrupt
    TMR0IE = 1;
    TMR0IF = 0;
    GIE =1;
}

/*
 * This function gets the time passed in ms after system initialization is done
 */
unsigned long timer_get_time_since_init()
{
    return timer0_time_passed_ms;
}
/*
 * This function gets the counter zero value from the last call
 */
unsigned long counter0_get_val()
{
    GIE  =0;
    unsigned char curr_cnt_val = TMR0;
    unsigned short curr_ov_cnt = overflow_cnt;
    TMR0 =0;
    overflow_cnt=0;
    GIE =1;
    return ( (curr_ov_cnt* TIMER0_MAX_VAL) + curr_cnt_val);
}
