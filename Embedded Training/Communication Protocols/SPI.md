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

# [SPI Basics](https://microcontrollerslab.com/introduction-to-spi-communication-protocol/)

Used to transfer data serially, 1 bit at a time, between several digital devices. Many analog devices (analog sensors, temp sensors, data converters) also provide an interfacing mode based on SPI comms. 

Examples of common SPI devices:
+ SD Cards
+ RFID Modules
+ WIFI transmitter/receiver modules

## SPI
+ Serial and synchronous interface. Requires a clock signal in order to transfer/receive data, this clock signal is synced between the master and slave.
+ Is unlike UART (as UART is async).
+ Clock controls when data should be sent to slave and when it should be ready to read.
+ Only master device can control the clock and provide this signal to all slave devices.
+ Clock signal is critical; It is not possible to transfer data without a clock signal.
+ Both the master and the slave can exchange data between each other.
+ No address decoding is performed.

## SPI between 2 devices
Full duplex synced comms. Both the master and slave can exchange data on the rising and falling edge of the clock signal.

+ SCLK/SCK (Clock): Clock for Slave devices which only the Master can control. This pin remains in an idle state when no operation is being carried out.
+ SS/CS (Chip select): Selects which device the Master wants to target with data
+ MOSI (Master Out, Slave In): Unidirectional, used to send data from master to slave
+ MISO (Master In,  Slave Out): Opposite of MOSI, used to send data from slave to master

Devices exchange data in a master/slave setup with the master being responsible for the initiation of the data frame as well as selecting the target slave device. The chip select line is usually used to identify/select a particular device. When a master wants to transmit to or read from the slave device, it activates the clock signal.

## Data Transmission

+ Master outputs clock signal.
+ To activate the slave, the master sets the chip select to low.
+ Data is sent to the slave on the MOSI line, serially, 1 bit at a time. The slave reads the bits as they are received.
+ If master requires a response, the slave sends data 1 bit a time via MISO. With the Master reading these bits as they're received.

While transferring from the Master to the Slave, the data is MSB first. While transferring from the Slave device to the Master, the data is LSB first. 

## SPI configuration modes
I




