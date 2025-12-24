#include "controller.h"
#include "../pwm/timer0.h"
#include "../trigger/timer1.h"
#include "../adc/adc.h"
#include <avr/interrupt.h>

int controller_init(void)
{
	if(timer0_init() || timer1_init ||  adc_init()) 
	{
		return 1;
	} else {
		sei();
		return 0;
	}
}

ISR(TIMER1_COMPA_vect)
{
    // Timer1 compare-match A ISR body
    // something like adc_start_sample();
}

ISR(ADC_vect)
{
    // ADC conversion complete ISR body
    // something like adc_map();
}
