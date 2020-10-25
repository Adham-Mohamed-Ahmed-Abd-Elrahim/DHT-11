/*
 * Hardware.h
 *
 * Created: 23/10/2020 01:21:28
 *  Author: ADHM
 */ 


#ifndef HARDWARE_H_
#define HARDWARE_H_
// pin configuration for DHT 
#define dht_pin 4
#define dht_port PORTD
#define dht_read PIND
#define dht_addr DDRD
//pins for lcd
#define R_S 5
#define R_W 6
#define ENBLE 7
//port of lcd data cable
#define LCD_PORT PORTA
#define USED_PORT DDRA




#endif /* HARDWARE_H_ */