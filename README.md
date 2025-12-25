DEPENDANCIES:

gcc

avr-gcc

avr-libc

avrdude

make 

can be installed with : sudo apt install gcc-avr binutils-avr avr-libc avrdude build-essential

or use whatever toolchain you want

BUILD INSTRUCTIONS:

1.) Make clean - cleanup

2.) Make all - build hex binary

3.) Make flash - flash via uart OR Make flashISP - flash via ISP
