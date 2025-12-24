#ifndef adc_h
#define adc_h
#include <stdint.h>
extern volatile uint16_t adc_last;

void adc_start(void);
int adc_init(void);
uint8_t adc_map(uint16_t adc);

#endif
