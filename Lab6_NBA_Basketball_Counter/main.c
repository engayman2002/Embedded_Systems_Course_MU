/*
 * File:   main.c
 * Author: engay
 *
 * Created on April 17, 2024, 5:38 AM
 */



#include <xc.h>
#define _XTAL_FREQ (8000000)

#define Team1_2 PORTBbits.RB0
#define Team1_3 PORTBbits.RB1

#define Team2_2 PORTBbits.RB6
#define Team2_3 PORTBbits.RB7

#define Team1_Seg PORTC
#define Team1_D1 PORTCbits.RC7
#define Team1_D2 PORTCbits.RC6
#define Team1_D3 PORTCbits.RC5

#define Team2_Seg PORTD
#define Team2_D1 PORTDbits.RD7
#define Team2_D2 PORTDbits.RD6
#define Team2_D3 PORTDbits.RD5

#define ON 1
#define OFF 0

#define Sev_delay_time 10
#define delay __delay_ms

void Team1_Display(unsigned char num)
{
	// First Digit num%10
	Team1_Seg=num%10;
    
	Team1_D1=ON;
    Team1_D2=OFF;
    Team1_D3=OFF;
    
	delay(Sev_delay_time);
	
	// Second Digit (num/10)%10
	Team1_Seg=(num/10)%10;
    
    Team1_D1=OFF;
    Team1_D2=ON;
    Team1_D3=OFF;
	
	delay(Sev_delay_time);
	
	// Third Digit (num/100)%10
	Team1_Seg=(num/100)%10;
    
	Team1_D1=OFF;
    Team1_D2=OFF;
    Team1_D3=ON;
	delay(Sev_delay_time);
}

void Team2_Display(unsigned char num)
{
	// First Digit num%10
	Team2_Seg=num%10;
    
	Team2_D1=ON;
    Team2_D2=OFF;
    Team2_D3=OFF;
	delay(Sev_delay_time);
	
	// Second Digit (num/10)%10
	Team2_Seg=(num/10)%10;
    
	Team2_D1=OFF;
    Team2_D2=ON;
    Team2_D3=OFF;
	delay(Sev_delay_time);
	
	// Third Digit (num/100)%10
	Team2_Seg=(num/100)%10;
    
	Team2_D1=OFF;
    Team2_D2=OFF;
    Team2_D3=ON;
	delay(Sev_delay_time);
}

void initial_condition(void)
{
	unsigned char num = 3000/(Sev_delay_time*6);
    
	while(num)
	{
		Team1_Display(101);
		Team2_Display(103);
		num--;
	}
	
	Team1_Display(0);
	Team2_Display(0);

    return;
}



void main(void) {
    
    TRISB=0xff;
    OPTION_REGbits.nRBPU = 0;
    
    TRISC=0x00;
    TRISD=0x00;
    
    
    
	initial_condition();
    
	
    unsigned char team1=0,team2=0;
    
    while(1)
    {
        if(Team1_2==0)
        {
            team1+=2;
            while(Team1_2==0);
        }
        if(Team1_3==0)
        {
            team1+=3;
            while(Team1_3==0);
        }
        if(Team2_2==0)
        {
            team2+=2;
            while(Team2_2==0);
        }
        if(Team2_3==0)
        {
            team2+=3;
            while(Team2_3==0);
        }
        
		Team1_Display(team1);
		Team2_Display(team2);
    }
    
    return;
}
