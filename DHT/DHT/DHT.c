/*
 * DHT.c
 *
 * Created: 23/10/2020 01:08:07
 *  Author: ADHM
 */ 
#include "DHT.h"
#include "LCD.h"
typedef  struct  DHT
{uint8_t humidity_low;
	uint8_t humidity_high;
	uint8_t temp_low;
	uint8_t temp_high;
	uint8_t check;
}  DHT_DATA;
void dht_ini()
{//To make sure of reaching stable state.
	_delay_ms(1000);
	//make pin as output
	SET_BIT(dht_pin,dht_addr);
	//low output to let dht detect the signal (atleast 18ms)
	CLR_BIT(dht_pin,dht_port);
	_delay_ms(20);
	//optional :
	//SET_BIT(dht_pin,dht_port);
	//********************************************************************
	//Release the line to recieve resopnse  (make it as input ) for [20-40 us]
	CLR_BIT(dht_pin,dht_addr);
	while(READ_BIT(dht_pin,dht_read));
	while(READ_BIT(dht_pin,dht_read)==0);
	while(READ_BIT(dht_pin,dht_read));
}
uint8_t dht_read_byte()
{uint8_t data=0;
	//recieve mode 
	CLR_BIT(dht_pin,dht_addr);
	//receiving
	for(uint8_t i=0;i<8;i++)
	{while(READ_BIT(dht_pin,dht_read)==0);	
	_delay_us(27);
	data=(data<<1)|((READ_BIT(dht_pin,dht_read)!=0) ? 1:0);
	while(READ_BIT(dht_pin,dht_read));
	}
	return data;
	}
void view_data ()
{dht_ini();
char temp_int[5];
char temp_float[5];
char humidity_int[5];
char humidity_float[5];
DHT_DATA Read={dht_read_byte(),dht_read_byte(),dht_read_byte(),dht_read_byte(),dht_read_byte()};
	itoa(Read.temp_low,temp_int,10);
	itoa(Read.temp_high,temp_float,10);
	itoa(Read.humidity_low,humidity_int,10);
	itoa(Read.humidity_high,humidity_float,10);
	if(Read.check==Read.humidity_low+Read.humidity_high+Read.temp_low+Read.temp_high)
	{   lcd_clear();
		//Viewing Temperature
		lcd_send_string("Temp: ");
		lcd_send_string(temp_int);
		lcd_send_data('.');
		lcd_send_string(temp_float);
		lcd_send_data(0xDF);
		lcd_send_string("C");
		//viewing humidity
		lcd_send_command(C_SECOND_LINE);
		lcd_send_string("humid: ");
		lcd_send_string(humidity_int);
		lcd_send_data('.');
		lcd_send_string(humidity_float);
		lcd_send_data('%');
		
	}
	_delay_ms(10);
	
	
	
}