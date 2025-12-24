#include "controller.h"
#include "../pwm/timer0.h"
#include "../trigger/timer1.h"
#include "../adc/adc.h"
#include <avr/interrupt.h>

int controller_init(void)
{
	if(timer0_init() || adc_init ||  timer0_init()) 
	{
		return 1;
	} else {
		sei();
		return 0;
	}
}

ISR(TIMER1_COMPA_vect)
{
    // Start ADC Conversion
    adc_start();
}

ISR(ADC_vect)
{
    // Map Latest ADC Value and update duty cycle 
    adc_last = ADC;
    set_duty(adc_map(adc_last));

}
