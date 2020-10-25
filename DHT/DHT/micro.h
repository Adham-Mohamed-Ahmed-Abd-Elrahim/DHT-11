/*
 * micro.h
 *
 * Created: 23/10/2020 01:17:48
 *  Author: ADHM
 */ 


#ifndef MICRO_H_
#define MICRO_H_
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#ifndef UTIL_DELAY_H
#include <util/delay.h>
#endif
#ifndef AVR_IO_H
#include <avr/io.h>
#endif
#ifndef HARDWARE_H_
#include "Hardware.h"
#endif 

#define SET_BIT(INDX,REG) ((REG)|=(1<<INDX))
#define CLR_BIT(INDX,REG) ((REG)&=~(1<<INDX))
#define READ_BIT(INDX,REG) ((REG>>INDX)&0x01)
#define TOGGLE_BIT(INDX,REG) ((REG)^=(1<<INDX))




#endif /* MICRO_H_ */