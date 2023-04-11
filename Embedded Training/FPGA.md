
[Learning FPGA and Verilig - a beginners guide Part 1: Introduction](https://numato.com/kb/learning-fpga-verilog-beginners-guide-part-1-introduction/)

## [HDL](https://en.wikipedia.org/wiki/Hardware_description_language)
Hardware Description Language.
+ Specialised computer language used to describe the structure and behaviour of electronic circuits and digital logic circuits.
+ Enables precise, formal description of a circuit which can be used in automated analysis and simulation of a circuit.
+ Looks similar to a typical programming language and includes similar concepts, though HDLs explicitly include time.
+ HDLs are integral to electronic design automation systems especially for complex circuits such as application-specific ICs, microprocessors and programmable logic devices.

2 main HDLs
1. VHDL
2. Verilog

Verilog is syntactically similar to C.
Can be used to design, simulate and then implement a circuit.

Tutorial uses Xilinx ISE for simulation and synthesis.

# What is FPGA?
Stands for Field Programmable Gate Array. Is essentially a large array of gates which can be programmed and reconifugred any time anywhere. 

Though FPGAs are more complex than the previous definition, some have built-in hard blocks including Memory controllers, high-speed comm. interfaces, PCIe endpoints and so on. With this, there are a lot of gates which can be connected together to make a circuit of choice. Kind of like connecting separate logic gate ICs together.

Manufactured by Xilinx, Altera, Microsemi. Fundamentally similar to CPLDs but CPLDs are much smaller in size and capability.

## [CPLD](https://uk.rs-online.com/web/c/semiconductors/programmable-logic-ics/cplds/)
Complex Programmable Logic Devices, used to implement complex combinational or sequential circuits. They typically consist of logic array blocks, programmable interconnects and I/O blocks.

LAB - Consist of macrocells, inward/non-inward metrics and support for flip flop ICs to allow for implementation of sequential circuits.
Programmable Interconnects - used to disperse signals for one logic array block to another.
I/O Blocks - pins that can be programmed as an input pin, output pin or both.

## FPGA Applications

"... gates that can be reconfigured to build almost any digital circuit that one can imagine." thus has great flexibility as well as the ability to reconfigure the device with different designs at will.

They are typically a better choice when compared to ASICs for many applications including deep learning, AI or application acceleration. Its possible to reprogram a single FPGA with different algos at different times in order to achieve the best performance. An ASIC is less flexible in such situations. Generally the FPGA is often cost-effective and robust. 

It also makes it easy to implement applications without the need of end-product designers to handle power supplies, DDR3 routing and so on. Further applications include:
+ Cryptography
+ ASIC prototyping
+ Industrial, medical, scientific instruments
+ Audio/Video, image processing and broadcasting
+ High-performance computing, AI and Deep Learning
+ Military and space applications
+ Networking, packet processing and other communications

## [ASIC](https://embeddedartistry.com/fieldmanual-terms/application-specific-integrated-circuit/)
Application-Specific Integrated Circuit

IC customised for a particular use rather than general purpose. Example could be a digital voice recorder or a high-efficiency bitcoin miner.