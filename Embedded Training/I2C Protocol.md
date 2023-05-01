
# [Texas Instruments: Understanding the I2C Bus](https://www.ti.com/lit/an/slva704/slva704.pdf)

## Core points/abstract
+ I2C bus is popular and powerful
+ Used for comms between a master(s) and slave(s) devices (may be single or many)
+ Can be used by many peripherals and connected by only 2 wires (thus is simple to configure/set-up yet works with many other systems)

## Electrical characteristics
Uses an open-drain/open-collector with input buffer on the same line. Allows one data line to be used for bi-directional data flow.

### Open-drain
Output which can either pull the bus down to a voltage or 'release' the bus and let it be pulled by a pull-up resistor.

If the bus were released by the master or slave, the pull-up resistor is then responsible for pulling the bus voltage up to the power rail. As no device may force a high on a line, the bus will never have communication issues such as a short where 2 different devices transmits high and low at the same time. 

I2C requires a multi-environment master to halt communications if the line is low and pulled down by another device as another device is clearly using the bus. This type of freedom is not allowed in push-pull interfaces, thus this makes I2C beneficial.

A device can only pull the bus line low (provide a short to ground) or release the bus line (high impedance to ground), allowing the pull-up resistor to raise the voltage. This is important as no device may hold the bus high which allows for the bidirectional communication.

## General i2c operation
This bus is a standard bi-directional interface which uses a controller (aka master) to communicate with slave devices. A slave may not transmit data unless it has been addressed by the master.

Each device on the bus has a specific device address to differentiate from others on the same bus. Many slave devices will require startup configuration to denote device behaviour which is typically achieved when the master accesses the slaves internal register maps, which have unique register addresses. A device can have one or many registers which may store, write or read data.

The physical i2c interface consists of the serial clock (SCL) and serial data (SDA) lines. Both lines must be connected to ground through a pull-up resistor. Pull-up resistor size is determined by capacitance amount on the i2c lines. 

Data transfer can only start when the bus is idle, which is when both SDA and SCL lines are high after a STOP condition.

General procedure for a master accessing a slave:

**Master wants to send data to slave**
1. Master transmitter sends START condition and addresses slave receiver
2. Master transmitter sends data to slave-receiver
3. Master transmitter terminates transfer with a STOP condition

**Master wants to read/recv data from slave**
1. Master receiver sends START condition and addresses slave transmitter
2. Master receiver sends requested register which should be read to slave transmitter
3. Master receiver receives data from slave transmitter
4. Master receiver terminates transfer with STOP condition

### START & STOP conditions
Communication with a device is initiated after a Master sends a START condition and is terminated after the Master sends a STOP condition.

A high-to-low transition on the SDA line while SCL is high represents a START condition.

A low-to-high transition on SDA while SCL is high represents a STOP condition.

A repeated START is similar to the typical START and is used instead of a repeating STOP then START. It looks almost identical to the START but differes as it occurs before a STOP when the bus isn't idle. 

This is useful for when the master wishes to start a new communication without letting the bus go idle with the next STOP condition. In multi master environments, this means the master has a chance of losing control of the bus to another master.

## Data validity/formatting
