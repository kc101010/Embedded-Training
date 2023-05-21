#communicationprot

## [Texas Instruments: Introduction to the Controller Area Network](https://www.ti.com/lit/an/sloa101b/sloa101b.pdf?ts=1684509708228&ref_url=https%253A%252F%252Fwww.google.com%252F#:~:text=The%20CAN%20protocol%20incorporates%20five,generated%20from%20the%20receiving%20node.)

Controller Area Network
+ Cost, performance & upgradeability lead to great flexibility when designing.

Multi-master, message broadcast system bus developed by BOSCH. It differs to traditional networks (USB, Ethernet) as it does not send large blocks of data point-to-point, from node A to B, under the supervision of a central bus master. A CAN network see's many short messages broadcast to the entire network which benefits data consistency in every node of the system.

### CAN Standard
ISO defined serial communications bus, originally developed in the automotive industry to replace a complex wiring harness with a 2-wire bus. Specification calls for high immunity to electrical interference and ability to self-diagnose and repair data errors. Such features have resulted in CANs popularity in various industries including building, automation, medical and manufacturing.

The CAN communications protocol describes the passing of information between devices on a network and conforms to the layers described in the OSI model.

CAN communication seems to pass from a Embedded controller to a transceiver and finally to the bus line, which passes through the application and data-link layers into the physical. Before the CAN controller is used, a communication link is established to a higher-level application protocol. Such protocols may have specific applications such industrial automation, diesel engines or aviation with examples including CANopen, KVASER Can kingdom and Rockwell automation DeviceNet.

### Standard CAN/Extended CAN
The CAN communication is a carrier-sense, multiple-access protocol which implements collision detection and message priority management (Examples in CSMA & CD+AMP). 

CSMA means each node on a given bus must wait and go spend time inactive before trying to send a message. CD+AMP means collisions are solved via bit-wise arbitration which is based on preprogrammed priority found in each messages identifier field. The higher priority identifier always wins bus access - the last logic-high within the identifier keeps transmitting as it is the highest priority. 

The ISO-1189:2003 Standard has an 11-bit identifier which provides for signalling rates from 125 kbps to 1 Mbps. This was later amended with an extended 29-bit identifier. The standard 11-bit id field allows 2^11 (or 2048) different message identifiers, whereas the extended bit identifier allows 2^29 (or 537 million) identifiers.

Standard CAN communications consist of a complex set of fields including the aformentioned identifier and between 0 and 8 bytes of data. To expand, the various fields within a standard CAN  message consist of:
+ SOF: Single dominant start of frame bit. Typically marks the start of a message and used to sync nodes on a bus after being idle.
+ Identifier: Standard CAN 11 bit ID. Is used to establish message priority. The lower the binary value, the higher the given priority.
+ RTR: Single remote transmission request bit - dominant when information is required from another node. All nodes receive the request but the id is used to determine the specific node. Responding data is also received by all nodes and used by any node interested. With this, all data being used in a system is uniform.
+ IDE: Dominant single identifier extension bit. Means a standard CAN identifier with no extension is being transmitted.
+ r0: A reserved bit. To possible be used by future standard amendment.
+ DLC: 4-bit data length code. Contains number of bytes of data being transmitted.
+ Data: Up to 64-bits (8 bytes) of application data may be transmitted.
+ CRC: 16-bit (15 its plus delimiter) cyclic redundancy check. Contains checksum (number of bits transmitted) of the preceding application data for error detection.
+ ACK: Every node receiving accurate message overwrites this recessive bit in the original message with a dominate bit to indicate that an error-free message was sent. If a receiving node detects an error and leave the bit recessive, it discards the message and the message is repeated from the sending node. With this, each node acknowledges the integrity of its data. ACK is 2 bits, 1 acknowledgement bit and 1 delimiter.
+ EOF: end-of-frame, 7-bit field that marks the end of a CAN message and disable bit-stuffing, indicates a stuffing error when dominant. When 5 bits of the same logic level occur in succession during normal operation then a bit of the opposite logic level is *stuffed* into the data.
+ IFS: 7-bit interframe space. Contains time required by controller to move a correctly received frame to its proper position in a message buffer area.

(SOF)-(11b ID)-(RTR)-(IDE)-(R0)-(DLC)-(0-8BY DATA)-(CRC)-(ACK)-(EOF)-(IFS)

Extended CAN uses the same formatting as standard CAN, with additions including:
+ SRR: Substitute remote request bit replaces RTR bit in standard message location as placeholder in the extended format.
+ IDE: Recessive bit in identifier extension indicates that more id bits follows. An 18-bit extension follows IDE
+ r1: Following RTR and r0 bits, an additional reserve fbit has been included ahread of the DLC bit.

(SOF)-(11b ID)-(SRR)-(IDE)-(18b ID)-(RTR)-(R1)-(R0)-(DLC)-(0-8BY DATA)-(CRC)-(ACK)-(EOF)-(IFS)

###  A CAN Message

#### Arbitration (Message Management)
A fundmental characteristic of CAN is its opposite logic state between bus, driver input and receiver output. A CAN bus does not use the typical associations (and seems to in fact be inverted). This explains why TI CAN transceivers have driver input and receiver output pins passively pulled high internally so, in the absence of any input, the device auto defaults to a recessive bus state on all input and output pins.

A recessive bit can be represented as a 1, with a dominant bit represented as a 0.

Bus access is event-driven and occurs randomly. If 2 nodes try to occupt the bus at the same time then access is implemented with a nondestructive, bit-wise arbitration. Nondestructive means the node winning arbitration simply continues with the message, without the message being destroyed or corrupted by another node.

Allocation of priority to messages within the identifier is a feature that makes CAN particularly attractive to use within a real-time control environment. The lower the binary message id number, the higher priority thus an id consisting entirely of zeroes is the highest priority message on a given network as it holds the bus dominant the longest. If 2 nodes begin to transmit at the same time, the node that sends a last identifier bit as a 0 while other nodes send a 1 retains control of the CAN bus and completes its message. A dominant bit always overwrites a recessive bit on a CAN bus.

#### Message Types

##### Data Frame
Most common message type, consists of the Arbitration field, the Data field, the CRC field and the Acknowledgement field. The arbitration field contains an 11-bit identifier and the RTR bit, which is dominant for data frames. There is also a data field which contains 0 to 8 bytes of data as well as the CRC Field which contains the 16-bit checksum used in error detection. Last is the acknowledgement field. 

##### Remote Frame
Its intended purpose is to solicit transmission of data from another node. This frame is similar to the data frame but has 2 important differences. First, this message type is explicitly marked as a remote frame by a recessive RTR bit in the arbitration field. Secondly, there is no data.

##### Error Frame
A special message that violates the formatting rules of a CAN message. It is transmitted when a node detects an error in a message, causing all other nodes in the network to also send an error frame. The original transmitter then automatically retransmits the message. An elaborate system of error counters found in the CAN controller makes sure that a node can't tie up a bus by repeatedly transmitting error frames.

##### Overload Frame
Similar to the error frame in terms of formatting. Transmitted by a node that becomes too busy with its primary use being to provide an extra delay between messages. 

#### Error Checking and Fault Confinement
Robustness in CAN may be partly attributed to its plethora of error-checking procedures. CAN incorporates 5 methods of error checking: 3 at message level and 2 at bit level.

If a message fails any one of these error detection methods, it is not accepted an an error frame generated from the receiving node. This then forces the transmitting node to resend the message until received correctly. Although, if a faulty node hangs up a bus by continuously repeating an error, its transmit capability is removed by its controller after an error limit is reached. 

Error checking at message level is enforced by the CRC and ACK slots. The 16-bit CRC contains the checksum of the preceding application data for error detection using a 15-bit checksum and 1-bit delimiter. The ACK field is 2 bits long, consisting of 1 ack bit and 1 delimiter bit. At this level, there is also a form check which looks for fields in the message that must always contain recessive bits. An error is generated upon detecting a dominant bit. The SOF, EOF and ACK & CRC delimiter bits are checked.

At the bit level, each transmitted bit is monitored by the transmitter of the message. If a data bit is written onto the bus and its opposite is read then an error is generated. The only exceptions for this are the message id field (used for arbitration) and the ack slot which requires a recessive bit to be overwritten by a dominant bit.

The final method is with the bit-stuffing rules. After 5 consecutive bits of the same logic level, if the next bit is *not* a complement then an error is generated. Stuffing makes sure that rising edges are available for on-going network synchronisation. It also ensures that a stream of bits will not be mistaken for an error frame or the 7-bit interframe space which signifies a messages end. Stuffed bits are removed by a receiving nodes controller before data is forwarded to the application.

In using this logic, an active error frame consists of 6 dominant bits which violates the bit stuffing rule. This is interpreted as an erro rby all CAN nodes which will then generate their own error frame. Meaning that an error frame can be up to 12 bits long (including the preceding 6) with all the replies. This error frame is then followed by a delimiter field of 8 recessive bits and a bus idle period before the corrupted message is retransmitted. It should be noted that the retransmitted message still has to contend for arbitration on the bus. 

# [Introduction to the Controller Area Network (CAN)](https://youtu.be/8nl3XkL1eTc)

Vehicles today use several communication units aka nodes that control some of the most critical aspects of the car. These nodes themself are critical for reliability and so on. 

Most used vehicle communication network. 

Has low cost as each node is placed on a single CAN bus. Is efficient as everything is message based, nodes can determine whether or not a message is relevant to read. Is reliable as it uses 5 methods of error detection. Robust as the CAN lines are resistant to eletrical interruptions, the nodes themselves have temperature resistant and fault tolerant varieties. CAN is flexible as nodes can be added and removed with no hardware or software modification to be performed. 

Is used in ECU and sensor communication in almost all automotive applications. Growing in popularity in industrial applications such as building automation, medical devices and aviation. 

# [Improving my electric longboard with a CAN Bus! What can the CAN Bus do? EB#44](https://youtu.be/PL0TPdrhMuI)

Cheap to implement.
ID-based priority system.

High-speed CAN, low-speed CAN and CAN-FD.