MCU = atmega164p
F_CPU = 20000000UL

CC = avr-gcc

OBJCPY = avr-objcopy

OBJS = controller/controller.o \
       controller/main.o \
       driver/adc/adc.o \
       driver/mapping/mapping.o \
       driver/pwm/timer0.o \
       driver/trigger/timer1.o


CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall

PORT = /dev/serial/by-id/usb-1a86_USB_Serial-if00-port0

BAUD = 115200

all: main.hex

main.hex: main.elf
	$(OBJCPY) -O ihex -R .eeprom $< $@

main.elf: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

flashISP: main.hex 
	sudo avrdude -c usbasp -p m164p -U flash:w:$<

flash: main.hex
	sudo avrdude -c arduino -p m164p -P $(PORT) -b $(BAUD) -U flash:w:$<

clean:
	rm -f *.elf *.hex $(OBJS)

.PHONY: all clean flash flashISP
