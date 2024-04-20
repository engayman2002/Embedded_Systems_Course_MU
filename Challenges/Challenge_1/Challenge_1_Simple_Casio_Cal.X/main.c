/*
 * File:   main.c
 * Author: engay
 *
 * Created on April 17, 2024, 8:53 PM
 */


#include <xc.h>
#define _XTAL_FREQ (8000000)

#include "common.h"
#include "keypad.h"
#include "lcd.h"

#define delay __delay_ms

void Get_Expression(char *equ)
{
    lcd_cmd(_LCD_CLEAR);
    lcd_cmd(_LCD_RETURN_HOME);
    lcd_cmd(_LCD_CURSOR_OFF);
    
    char expr[17]={0};
    int i;
    lcd_set_cursor(1,1);
    for(i=0;i<16;i++)
    {
        expr[i]='\0';
        while(expr[i]=='\0')
        {
            expr[i]=keypad_get_key();
        }
        while(expr[i]==keypad_get_key());
        lcd_chr_cp(expr[i]);
        
        *(equ+i)=expr[i];
        if(expr[i]=='=')
        {
            break;
        }
        if(expr[i]=='c')
        {
            i=0;
            lcd_cmd(_LCD_CLEAR);
            lcd_cmd(_LCD_RETURN_HOME);
            lcd_cmd(_LCD_CURSOR_OFF);
            continue;
        }
    }
}

void Delete_Pre_Num(char *expr,char i)
{
    char j=i;
    while(i!=0 && expr[i]!='+' && expr[i]!='-' && expr[i]!='*' && expr[i]!='/')
    {
        i--;
    }
    
    while(i!=j)
    {
        expr[i]='r';
        i++;
    }
    
}

int Get_Pre_Num(char *expr,char i)
{
    while(i!=0 && expr[i]!='+' && expr[i]!='-' && expr[i]!='*' && expr[i]!='/')
    {
        i--;
    }
    if(expr[i]=='-')
    {
        return -1*atoi(expr+i+1);
    }
    else
    {
        return atoi(expr+i+1);
    }
}

int Solve_Mul_Div(char *expr)
{
    int result=0;
    int i=0;
    while(i<17)
    {
        if(expr[i]=='*' || expr[i]=='/')
        {
            i++;
            if(expr[i-1]=='*')
                result+=(atoi(expr+i)*Get_Pre_Num(expr,i-2));
            else
                result+=(atoi(expr+i)/Get_Pre_Num(expr,i-2));
            
            Delete_Pre_Num(expr,i-2);
            
            while( (expr[i]>='0' && expr[i]<='9') && i<17)
            {
                i++;
            }
            i--;
            continue;
        }
        i++;
    }
    return result;
}

int Solve_Add_Sub(char *expr)
{
    int result=0;
    int i=0;
    while(i<17)
    {
        
        if(expr[i]=='+' || expr[i]=='-')
        {
            i++;
            if(expr[i-1]=='+')
                result+=(atoi(expr+i));
            else
                result-=(atoi(expr+i));
            
            while( (expr[i]>='0' && expr[i]<='9') && i<17)
            {
                i++;
            }
            i--;
            continue;
        }
        
        i++;
    }
    return result;
}

int Solve_expr(char *expr)
{
    int result=0;
    result+=Solve_Mul_Div(expr);
    result+=Solve_Add_Sub(expr);
    return result;
}

void Print_Result(int result)
{
    char row=2,col=16,flag=0;
    if(result<0)
    {
        result*=-1;
        flag=1;
    }
    while(result!=0)
    {
        lcd_chr(row,col,((result%10)+48));
        col--;
        result/=10;
    }
    if(flag==1)
    {
        lcd_chr(row,col,'-');
    }
}

void main(void) {
    
    // Initialize LCD and Keypad
    lcd_init();
    lcd_cmd(_LCD_CLEAR);
    lcd_cmd(_LCD_RETURN_HOME);
    lcd_cmd(_LCD_CURSOR_OFF);
    keypad_init();
    int result;
    
    char expr[18]={0};
    int i;
    
    while(1)
    {
        for(i=0;i<17;i++)
        {
            expr[i]=0;
        }
        expr[0]='+';
        
        Get_Expression(expr+1);
        result=Solve_expr(expr);
        Print_Result(result);        
        while(keypad_get_key()=='\0');  
    }
    return;
}
