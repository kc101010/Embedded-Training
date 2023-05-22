[[I2C]] 
 [[GPIO]]

# [ Let's code a Linux Driver - 5: LCD text display driver (HD44780)](https://youtu.be/HH3OOtJwBz4)

+ Configures/inits GPIOs in a for loop for simplicity. Same for freeing. 
+ Stores GPIO numbers in a struct.
+ Stores buffer of LCD as a static char array.
+ Send data to the LCD 1 byte at a time

https://github.com/Johannes4Linux/Linux_Driver_Tutorial/blob/main/05_lcd_driver/lcd_driver.c

Own driver ~~~may ~~~ will need to use I2C to manage the OLED.
My OLED is an I2C IIC 12864 128x64 Pixel OLED LCD, Module SSD1306.

Commands are sent to the LCD with hexadecimal codes;
`lcd_command(0x30);` as an example which will be very similar to the OLED.

'Hello, World' is sent using `lcd_data()` function within a loop. 

Able to use `echo` with `>` to give string input from the command line which is then displayed on the LCD screen.

# [ SSD1306 I2C Linux Device Driver using Raspberry PI – Linux Device Driver Tutorial Part 41](https://embetronicx.com/tutorials/linux/device-drivers/ssd1306-i2c-linux-device-driver-using-raspberry-pi/)

*includes useful, in-depth about the OLED and using it.*

# [Github: armlabs/ssd1306_linux](https://github.com/armlabs/ssd1306_linux)

This is a userspace application intended to control an OLED but this will be useful to use as an inspiration for own driver and insight into what may/may not be required. 

# [SSD1306: Advance Information pdf](https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf)
