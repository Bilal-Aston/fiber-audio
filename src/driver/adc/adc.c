#include "adc.h"

int adc_init(void)
{
	//set ADC0 as input
	DDRA |= (1 << PA0);

	//Enable interrupts and set Prescale 32
	ADCSRA |= (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS0);
}
