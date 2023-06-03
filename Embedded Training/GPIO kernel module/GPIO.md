#generalconcepts 

https://en.wikipedia.org/wiki/General-purpose_input/output

General purpose input/output.
Uncommitted digital signal pin on an IC or electronic circuit board.
May be used as input, output or both, controllable by software.

Only limited by eletrical and timing specs of GPIO interface and the ability of software to interact with GPO in a timely manner. 

![[Raspberry-Pi-GPIO-Layout-Model-B-Plus-2700x900.png]]



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

# [Sagar Kanjariya: Features of GPIO (Linkedin)](https://www.linkedin.com/posts/sagar-kanjariya_embedded-hardware-embeddedsystems-activity-7070227854701002752-h_VO?utm_source=share&utm_medium=member_desktop)

Features:
+ Output states support push-pull or open-drain (alongside pull up and pull downs)
+ Able to select a certain speed for each port
+ Input states can have several configurations including; floating, pull-up/down and analog.
+ A locking mechanism (GPIOx_LCKR) is available in order to freeze I/O port.

GPIOs are very flexible with their ability to switch between alternative functionalities.
High, flexible pin multiplexing allows I/O pins to be used as GPIOs or to facilitate peripheral functions.

[Multiplexing:](https://en.wikipedia.org/wiki/Multiplexing) Method where many analog or digital signals are combined into 1 signal across a shared medium in order to share a physical transmission medium. 

## How does a GPIO work internally?
Consists of an input buffer, an output buffer and an enable pin, with the value of the enable pin used to determine whether the GPIO should be set as input or output. The buffer circuitry is a simple CMOS logic circuit with a PMOS transistor connected to +Vcc and NMOS transistor connected to ground.

A value of 0 on the enable pin means the output buffer is enabled, a 1 means the input buffer is enabled. 

### Terms
CMOS: Complementary metal-oxide-semiconductor. [Commonly used to hold the BIOS.](https://www.intel.co.uk/content/www/uk/en/support/articles/000025368/processors.html) [Also used to build ICs such as microprocessors, micro-controllers, memory chips and so on. Other uses in image sensors, data converters, RF circuits and highly integrated transceivers.](https://en.wikipedia.org/wiki/CMOS)
[PMOS](https://en.wikipedia.org/wiki/PMOS_logic): P-channel metal-oxide-semiconductor. Family of digital circuits based on the p-channel, enhancement mode metal-oxide-semiconductor field-effect transistors (MOSFETs) which are used to implement logic gates etc.

[NMOS](https://en.wikipedia.org/wiki/NMOS_logic): N-type metal-oxide-semiconductor logic. Uses n-type MOSFETs to implement logic gates and digital circuits.

[MOSFET](https://en.wikipedia.org/wiki/MOSFET): Metal-oxide-semiconductor field-effect transistor. Type of field effect transistor (FET). Used to amplify or switch electronic signals. Digital ICs and memory devices contain a high volume of integrated MOSFETs in order to provide basic switching functions which are required for logic gates and data storage.

[FET](https://en.wikipedia.org/wiki/Field-effect_transistor#Basic_information): Type of transistor which uses an electric field to control the flow of current within a semiconductor. 


### Technical info
When setting the pin as output, enable is set to 0. This results in the PMOS being disabled and the NMOS becoming enabled which pulls the pin to GND (A low state).

With input, the logic is swapped. So enable is set to 1 which disables the NMOS transistor, enables the PMOS transistor which pulls the pin to +Vcc (A high state).

By default, GPIO pins are set to Input state. This keeps them in a high impedance state and keeps the overall system safe.

Impedance: [Measure of opposition to electrical flow. In DC systems, impedance and resistance are the same.](https://www.analog.com/en/design-center/glossary/impedance.html)[Opposition to alternating current presented by the combined effect of resistance and reactance in a circuit.](https://en.wikipedia.org/wiki/Electrical_impedance)

GPIO will typically be used to send data from the CPU to an output device or receive data from an input device and send it to the CPU. Though most GPIOs support additional functionalities such as having the ability to act as the I/O pin of other peripherals or facilitating communication (some pins may have the ability to be used for I2C, UART etc).