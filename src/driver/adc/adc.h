#ifndef adc_h
#define adc_h

volatile uint16_t adc_last;

int adc_init(void);
uint8_t adc_map(uint16_t);

#endif
