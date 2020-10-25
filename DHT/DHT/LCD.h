/*AUTHOR:ADHAM MOHAMED AHMED 
 * LCD.h
 * Driver : LCD 16*2 DRIVER 
 * Created: 20/09/2020 05:58:45
 *  
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "micro.h"
//--------------------------------------------------
//LCD commands 
#define CLEAR 0x01
#define HOME 0x02
//cursor 
#define C_SHIFT_LEFT 0x04
#define C_SHIFT_RIGHT 0x06
#define C_LEFT 0x10
#define C_RIGHT 0x14
#define C_FIRST_LINE 0x80
#define C_SECOND_LINE 0xC0
//disply
#define D_SHIFT_LEFT 0x05
#define D_SHIFT_RIGHT 0x07
#define D_ALL_SHIFT_LEFT 0x18
#define D_ALL_SHIFT_RIGHT 0x1C
#define DISPLY_OFF_CURSOR_OFF 0x08
#define DISPLY_OFF_CURSOR_ON 0x0A
#define DISPLY_ON_CURSOR_OFF 0x0C
#define DISPLY_ON_CURSOR_ON 0x0E
//mode of used pins 
#define EIGHT_PINS 0x38
#define FOUR_PINS 0x28
//-----------------------------------------------------
//LCD SETTING 
#define MODE EIGHT_PINS
void lcd_ini(void);
void lcd_send_command(unsigned char command);
void lcd_send_data(unsigned char data);
void lcd_send_string(const char * word);
void lcd_clear();
void lcd_place_write(const char * word,uint8_t row,uint8_t col);

#endif /* LCD_H_ */