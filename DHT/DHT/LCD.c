/*
 * LCD.c
 *
 * Created: 20/09/2020 06:01:02
 *  Author: ADHM
 */ 
#include "LCD.h"
#include <string.h>
void lcd_ini(void)
{hardware_ini();
	_delay_ms(15);
lcd_send_command(MODE);
lcd_send_command(DISPLY_ON_CURSOR_ON);
lcd_send_command(CLEAR);
lcd_send_command(HOME);
}
  void lcd_send_command(unsigned char command)
{	LCD_PORT=command;
	//TO send commands 
	CLR_BIT(R_S,PORTD);
	//To write to LCD
	CLR_BIT(R_W,PORTD);
	SET_BIT(ENBLE,PORTD);
	_delay_ms(1);
	CLR_BIT(ENBLE,PORTD);
	_delay_ms(2);
}

 void lcd_send_data(unsigned char data)
{LCD_PORT=data;
	//TO send DATA
	SET_BIT(R_S,PORTD);
	//To write to LCD
	CLR_BIT(R_W,PORTD);
	
	SET_BIT(ENBLE,PORTD);
	_delay_ms(1);
	CLR_BIT(ENBLE,PORTD);
	_delay_ms(2);
}
void lcd_send_string(const char * word)
{
	for (uint16_t i=0;i<strlen(word);i++)
	{
		lcd_send_data(word[i]);
	}
	
}
void lcd_clear()
{
	lcd_send_command(CLEAR);
	lcd_send_command(HOME);
	
}
void lcd_place_write(const char * word,uint8_t row,uint8_t col)
{switch(row)
	{case (0):	lcd_send_command(C_FIRST_LINE);break;
     case (1): 	lcd_send_command(C_SECOND_LINE);break;
	default:lcd_send_command(C_FIRST_LINE);break;
	}
	for(uint8_t i=0;i<col;i++)
	{
	lcd_send_command(C_RIGHT);
	}
	lcd_send_string(word);
}


