#communicationprot 

# [SPI: The serial peripheral interface](https://youtu.be/MCi7dCBhVpQ)

Used for communicating between a peripheral device (such as an SD card or temperature sensor etc) and a microcontroller/microprocessor.

Another master-slave configuration, typically a 4 wire interface consisting of:
+ Clock (SCK)
+ Data to device (MOSI)
+ Data to controller (MISO)
+ Chip select (CSB)
Some devices don't have an output as they are only expected to use input from the MC.

Communication typically occurs 1 bit at a time in any direction.

More devices can be introduced into the configuration by connecting the clock and data lines to the new devices however these new devices need separate connections to the chip select of the master. 