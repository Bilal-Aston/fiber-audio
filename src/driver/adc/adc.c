#include "adc.h"
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
