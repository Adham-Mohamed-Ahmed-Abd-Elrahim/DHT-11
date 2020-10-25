/*
 * Hardware.c
 *
 * Created: 23/10/2020 01:21:52
 *  Author: ADHM
 */ 
#include "micro.h"
void hardware_ini()
{ USED_PORT=0xff;
	DDRD|=0xE0;
}