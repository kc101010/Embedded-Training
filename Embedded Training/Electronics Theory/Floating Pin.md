# Floating pin

[Floating Pins, Pull-Up Resistors and Arduino (programmingelectronics.com)](https://www.programmingelectronics.com/floating-pins-pull-up-resistors-and-arduino/)

Is detrimental and affects reliability of circuits.

Example, Arduino with button connected. Reading pin as input through Serial while the button isn't being pressed. When button is idle, serial comms send a mix of 1s and 0s. Also demos with an LED, when the LED is sitting idle it pulses/flashes erratically and then is solid and brighter when the button is pressed, LED set high.

When the component is sitting idle, and no signal supplied, noise is allowed to interfere with the pin and causing an indeterminate value which causes incorrect behaviour.

This issue can be resolved by using a pull-up resistor which ties the floating pin to a known voltage (5V on the Arduino UNO). When this resistor is used, it ensures that when a component is idle, the necessary pin will read a stable high signal.

[Don’t Leave Your Pins Floating | Bench Talk (mouser.com)](https://www.mouser.com/blog/dont-leave-your-pins-floating)

Pin's not connected to GND, just left floating. Will register both highs and lows while the pin floats because the pin is now susceptible to electrical noise that causes random signal fluctuations. This can be caused by thermal noise and EMI (electromagnetic interference) this is because the leads of the chip act like tiny antennas when floating.

A bad solution is simply connecting the input to Vcc. In the example, if the button is pressed, a short circuit will be created between Vcc and GND. This short circuit may generate enough heat to damage the circuit. It may also cause the power supply voltage to drop to ground potential which kill the device. The solution connecting Vcc to the input pin is generally a bad idea. 

Better solution is to have a pull-up resistor which then connects out to Vcc. Or a pull-down resistor between ground and I/O. A pull-up will give a logic high and if the button is pressed, it will give a logic low ('active low' logic). With a pull-down resistor, the I/O pin will see a logic low and pressing the button will give a logic high (known as 'active high' logic) 

Either can be used, software/firmware just needs to be modified to make use of the correct logic. Pull-up/down resistors can also be applied in 
