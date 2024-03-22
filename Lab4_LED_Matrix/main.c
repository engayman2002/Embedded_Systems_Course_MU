/*
* File: main.c
* Author: engay
*
* Created on March 22, 2024, 2:16 AM
*/
#include <xc.h>
#define _XTAL_FREQ (8000000)
#define Mini_Delay 10
void main(void) {
TRISB=0;
PORTB=1;char Matrix[3][3]=
{
0xf1,0xf2,0xf4,
0xe9,0xea,0xec,
0xd9,0xda,0xdc
};
while(1)
{
int i,j;
// Each Turn on after 500ms
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
PORTB=Matrix[i][j];
__delay_ms(500);
}
}
// Sqaure
for(i=0;i<500;i++)
{
PORTB=Matrix[0][0];
__delay_ms(Mini_Delay);
PORTB=Matrix[0][1];
__delay_ms(Mini_Delay);
PORTB=Matrix[0][2];
__delay_ms(Mini_Delay);PORTB=Matrix[1][2];
__delay_ms(Mini_Delay);
PORTB=Matrix[2][2];
__delay_ms(Mini_Delay);
PORTB=Matrix[2][1];
__delay_ms(Mini_Delay);
PORTB=Matrix[2][0];
__delay_ms(Mini_Delay);
PORTB=Matrix[1][0];
__delay_ms(Mini_Delay);
}
}
return;
}