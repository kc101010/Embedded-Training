
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

---
# [What's an FPGA?](https://youtu.be/iHg0mmIg0UU)

----
# [Driving a VGA Display?! Getting started with an FPGA! (TinyFPGA)](https://youtu.be/ZNunxg7o8l0)

Several register devices - programming logic blocks (PLBs) consisting of logic gates and LUTs are used within a microcontroller-esque system to provide a re-programmable device with several open-ended uses and applications. 

Able to create logic circuits in hardware, huge difference to a microcontroller as it is able to handle several tasks at once which can sometimes be complex for microcontrollers.

Code is used to describe the hardware i.e. HDL like Verilog or VHDL. A visual programming language/editor is used to program the FPGA in the video. 

Key terms:
Logic gates
Programmable
Programmable Logic Blocks
Look up tables (LUTs)
Registers

----

# [ The "Do Anything" Chip: FPGA](https://youtu.be/ePwo3P1iZO4)

Reprogrammable, configurable chip that can be used for various functions. Using building blocks in logic gates and so on.

The FPGA usually also includes I/O blocks to connect various peripherals (ethernet and so on).

Good for cost (as FGPA can reprogrammed and reused) and for implementing later improvements (is flexible) though less accessible (due to high price of the board).

Often the fastest solution with regards to microcontroller-esque task.

Better option than developing own ASIC or similar boards.

Uses a config memory to store configurations/config file.

Is good for quick iterations and rapid style lifecycles.

Programmed in HDL such as Verilog or VHDL to describe the intended circuit, this code is then compiled into a configuration file that is loaded onto the board. 

There are some challenges: Specialised knowledge, More power hungry.

Good choice when performance and flexibility are critical. 

Various board types with own advantages and disadvantages.

Growing interest for FPGA use in ML and AI applications. 

Mix type FPGA boards that include microprocessors or GPUs.

Industry move to cloud-based FPGA deployment/services.

Development of Open source FPGA tools and tech to make the FPGA more accessible.

