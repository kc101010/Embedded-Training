MIPI - Mobile Industry Processor Interface

CSI - Camera Serial Interface

[MIPI camera vs USB camera – a detailed comparison - e-con Systems](https://www.e-consystems.com/blog/camera/technology/mipi-camera-vs-usb-camera-a-detailed-comparison/)

Popular and convenient method of interfacing cameras with host processors. Camera interface that connects an image sensor with an embedded board (which controls, processes image data).  It allows both the embedded system and the camera to act as one larger camera system. 

MIPI-based cameras provide higher performance (through better resolution and frame rate) than the older parallel interface camera module (DVP) interface. MIPI CSI-2 cameras are even preferred over USB cameras. CSI-2 provides a larger bandwidth over USB, is generally more efficient and faster compared to the general-purpose USB interface. 

MIPI CSI-2 also supports high-performance applications and high-resolution imaging, able to transmit images in 1080p, 4K and 8K. Suited for both single and multi-cam setups. 

CSI-1 - Original standard MIPI architecture which defined an interface between a camera and host cpu

CSI-2 (2005) - protocol divided into layers;
Physical
Lane merger
Low-level protocol
Pixel to Byte Conversion
Application

Various versions released in later years with various improvements/new features 

CSI-3 (2012) - High speed, bi-directional protocol for img and video transmission between cams and hosts. 


CSI-2 is a common interface used in mobile and remote applications - autonomous driving, drones, medical imaging, computer vision.

Technical
MIPI CSI-2 supports the MIPI D-PHY physical layer to communicate with the processor or SoC. Camera sensor captures and transmits image to the CSI-2 host where it is then placed in memory as individual frames. These frames are transmitted through virtual channels which are then split into lines and transmitted one at a time. And so completes image transmission from the same image sensor with multiple pixel streams. 

For comms, uses packets which include the data format and error correction code (ECC) functionalities. A packet moves through the D-PHY layer then splits into the number of required data lanes.

D-PHY operates in high-speed mode and transmits the packet to the receiver through the channel. The receiver is then provided with D-PHY physical layer to extract and decode the packet. This process repeats for each frame from the CSI-2 device to the hsot in an implementation seen as efficient and low-cost. 

[Camera Serial Interface 2 (MIPI CSI-2) | MIPI](https://www.mipi.org/specifications/csi-2)

