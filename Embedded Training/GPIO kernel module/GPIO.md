https://en.wikipedia.org/wiki/General-purpose_input/output

General purpose input/output.
Uncommitted digital signal pin on an IC or electronic circuit board.
May be used as input, output or both, controllable by software.

Only limited by eletrical and timing specs of GPIO interface and the ability of software to interact with GPO in a timely manner. 
![[pi4j-rpi-400-pinout.png]]

# GPIOs

## [Can a Raspberry Pi be used as an Arduino? || RPi GPIO Programming Guide 101](https://youtu.be/tQEmtbaO2GY)

`man gpio` for in-depth info

'WiringPi' - Pin-based GPIO access library written in C.


# GPIOs and Linux kernel modules

## [ Let's code a Linux Driver - 4: GPIO driver](https://youtu.be/P3Judr4i7QI)

LED and button. Driver to control circuit via GPIO.

Dev simply modifies source code from the previous episode.

`gpio_request()`
`gpio_direction_output()`
`gpio_free()`
