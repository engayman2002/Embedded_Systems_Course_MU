#include "lcd.h"

static void SET_LCD_DATA_PINS(unsigned char Data)
{
  if(Data & 1)
    D4 = 1;
  else
    D4 = 0;
  if(Data & 2)
    D5 = 1;
  else
    D5 = 0;
  if(Data & 4)
    D6 = 1;
  else
    D6 = 0;
  if(Data & 8)
    D7 = 1;
  else
    D7 = 0;
}
static void  LCD_SEND_4BIT_CMD(unsigned char CMD)
{
  // Select Command Register
  RS = 0;
  // Move The Command Data To LCD
  SET_LCD_DATA_PINS(CMD);
  // Send The EN Clock Signal
  EN = 1;
  __delay_us(LCD_EN_Delay);
  EN = 0;
}

static void LCD_Write_Char(char Data)
{
  char Low4,High4;
  Low4 = Data & 0x0F;
  High4 = Data & 0xF0;
  RS = 1;
  SET_LCD_DATA_PINS(High4>>4);
  EN = 1;
  __delay_us(LCD_EN_Delay);
  EN = 0;
  __delay_us(LCD_EN_Delay);
  SET_LCD_DATA_PINS(Low4);
  EN = 1;
  __delay_us(LCD_EN_Delay);
  EN = 0;
  __delay_us(LCD_EN_Delay);
}
//=============================================================================
//=============================== APIs definition =============================
//=============================================================================
void lcd_init()
{
  // IO Pin Configurations -- all output --
  LCD_RS_Direction = 0;
  LCD_EN_Direction = 0;
  LCD_D4_Direction = 0;
  LCD_D5_Direction = 0;
  LCD_D6_Direction = 0;
  LCD_D7_Direction = 0;
  // The Init. Procedure As Described In The Datasheet
  SET_LCD_DATA_PINS(0x00);
  __delay_ms(30);
  __delay_us(LCD_EN_Delay);
   LCD_SEND_4BIT_CMD(0x03);
  __delay_ms(5);
   LCD_SEND_4BIT_CMD(0x03);
  __delay_us(150);
   LCD_SEND_4BIT_CMD(0x03);
   LCD_SEND_4BIT_CMD(0x02);
   LCD_SEND_4BIT_CMD(0x02);
   LCD_SEND_4BIT_CMD(0x08);
   LCD_SEND_4BIT_CMD(0x00);
   LCD_SEND_4BIT_CMD(0x0C);
   LCD_SEND_4BIT_CMD(0x00);
   LCD_SEND_4BIT_CMD(0x06);
}
void lcd_cmd(unsigned char command)
{
  //send higher 4-bits of the command
  LCD_SEND_4BIT_CMD( (command & 0xF0) >> 4 );
  //send lower 4-bits of the command
  LCD_SEND_4BIT_CMD( command &  0x0F );
}
void lcd_set_cursor(unsigned char r, unsigned char c)
{
  unsigned char Temp,Low4,High4;
  if(r == 1)
  {
    Temp = 0x80 + c - 1; //0x80 is used to move the cursor
    High4 = Temp >> 4;
    Low4 = Temp & 0x0F;
    LCD_SEND_4BIT_CMD(High4);
    LCD_SEND_4BIT_CMD(Low4);
  }
  if(r == 2)
  {
    Temp = 0xC0 + c - 1;
    High4 = Temp >> 4;
    Low4 = Temp & 0x0F;
    LCD_SEND_4BIT_CMD(High4);
    LCD_SEND_4BIT_CMD(Low4);
  }
}
void lcd_chr(unsigned char row,unsigned char col, unsigned char chr)
{
  lcd_set_cursor(row,col);
  LCD_Write_Char(chr);
}
void lcd_chr_cp(unsigned char chr)
{
  LCD_Write_Char(chr);
}
void lcd_out(unsigned char row, unsigned char col,char *str)
{
  int i;
  lcd_set_cursor(row,col);
  for(i=0;str[i]!='\0';i++)
    LCD_Write_Char(str[i]);
}
void lcd_out_cp(char *str)
{
  int i;
  for(i=0;str[i]!='\0';i++)
    LCD_Write_Char(str[i]);
}