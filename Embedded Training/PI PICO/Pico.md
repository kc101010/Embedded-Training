https://www.raspberrypi.com/documentation/microcontrollers/raspberry-pi-pico.html

![[Pico-R3-A4-Pinout.pdf]]

![[pico-datasheet.pdf]]

[Pico cmd line tool](https://github.com/raspberrypi/picotool)

https://github.com/raspberrypi/pico-sdk

https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf?_gl=1*yfnd6r*_ga*MTM1NTAyODUwMy4xNzA4MTA2ODI5*_ga_22FD70LWDS*MTcwODEwNjgyOS4xLjEuMTcwODEwNjg2Mi4wLjAuMA..

https://www.raspberrypi.com/documentation/microcontrollers/raspberry-pi-pico.html

## PICO notes

Uses .uf2 files rather than .hex files
Uses cmake/make build chain

## [Blink LED in C/C++ on the Raspberry Pi Pico [Linux SDK Setup] ](https://youtu.be/JhajoAyP8e4?si=5wLyBeELpPLbR-td)
+ Copy pico sdk to machine from git
+ Setup cmakefiles and code
+ From pico sdk copy `/external/pico_sdk_import.cmake` into source code dir
+ Create build dir
+ In build dir run `cmake ..`
+ Run `make`
+ Copy `{PROJECT}.uf2` to raspberry pi pico in media folder

To program the pico again, connect it to the PC while holding the bootloader select button. 


