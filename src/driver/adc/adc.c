#include "adc.h"
#include "lut.h"
#include <avr/io.h>

int adc_init(void)
{
	//set ADC0 as input
	DDRA |= (1 << PA0);

	//Enable interrupts and set Prescale 32
	ADCSRA |= (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS0);
	
	return 0;

}

void adc_start(void)
{
	//start an adc conversion
	ADCSRA |= (1 << ADSC);
}

uint8_t adc_map(uint16_t adc)
{
	//take an adc value and map it to a pwm value - return the value
	return pgm_read_byte(&adc_to_pwm[a]);
}

//fill up LUT here