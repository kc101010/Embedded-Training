#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/kernel.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kyle Christie");
MODULE_DESCRIPTION("I2C driver to turn on an SSD1306 OLED");

//define macros for re-used vars
#define I2C_BUS_AVAILABLE 	1
#define OLED_ADDR 		0x3C
#define OLED_NAME 		"OLED"
#define DISPLAY_BUFFER_SZ 	(512 + 1)

static struct i2c_adapter *adapter = NULL; 	//this struct seems to represent the I2C connection
static struct i2c_client *client_oled = NULL; 		//this struct represents the client, in this case the OLED
uint8_t* display_buffer;
 
// ##################################################
// ##################################################
// I2C funcs

//function sends data to slave over i2c bus
static int I2C_write(unsigned char *buf, unsigned int len){
	//this function will send the start condition and slave addr
	int ret = i2c_master_send(client_oled, buf, len);
	return ret;
}

//function reads data from slave over i2c bus
static int I2C_read(unsigned char *out_buf, unsigned int len){
	//see comment in I2C_write()
	int ret = i2c_master_recv(client_oled, out_buf, len);
	return ret;
}

//end I2C funcs
// ##################################################
// ##################################################

// ##################################################
// ##################################################
// OLED management

//function writes both data and commands to the oled
static void write_oled(bool is_cmd, unsigned char data){
	//7th bit must be 0 regardless of a command or data
	//declare var for return
	unsigned char buf[2] = {0};
	int ret;

	//if the next write should be a command, set the 6th bit to 0
	//otherwise set to 1 to indicate data??
	if(is_cmd == true){
		buf[0] = 0x00;
	}else{
		buf[0] = 0x40;
	}

	//store data in between the type indicator bit and message end bit?
	//perform a write to the device
	buf[1] = data;
	ret = I2C_write(buf, 2);
}

//function used to turn the OLED on when probed
static int activate_oled(void){
	msleep(100);

	//write the various commands which will init the OLED
	write_oled(true, 0xAE);	//turn full display off
	write_oled(true, 0xD5);	//set display clock divide ratio & oscillator freq.
	write_oled(true, 0x80); //set default, recommened settings for DCD Rat. and Osc. Freq.
	write_oled(true, 0xA8); //set multiplex ratio
	write_oled(true, 0x3F); //denote 64 COM lines
	write_oled(true, 0xD3);	//set display offset
	write_oled(true, 0x00);	//0 offset

	write_oled(true, 0x40);	//set first line as the starting line for the display
	write_oled(true, 0x8D); //charge pump
	write_oled(true, 0x14);	//enable charge pump (above) while display is on
	write_oled(true, 0x20);	//set mem addressing mode
	write_oled(true, 0x00);	//set as horizontal addressng mode
	write_oled(true, 0xA1);	//set segment remap w/ col addr 127 mapped to seg 0
	write_oled(true, 0xC8);	//set COM output scan dir, scan from COM63 to COM0
	write_oled(true, 0xDA);	//set COM pins hardware config
	write_oled(true, 0x12);	//alt COM pin config, disable COM left/right remap
	write_oled(true, 0x81);	//set contrast control
	write_oled(true, 0x80);	//set contrast to 128
	write_oled(true, 0xD9);	//set period for pre-charge
	write_oled(true, 0xF1);	//phase 1 period of 15 DCLK, phase 2 period of 1 DCLK
	write_oled(true, 0xDB);	//set Vcomh deselect level
	write_oled(true, 0x20);	//Vcomh deslect level ~0.77 Vcc
	write_oled(true, 0xA4);	//turn full display on, resume to displaying contents of RAM
	write_oled(true, 0xA6);	//set display in normal mode (1 = ON, 0 = OFF)
	write_oled(true, 0x2E);	//deactivate scroll
	write_oled(true, 0xAF); //display on in normal mode

	//todo: fill display so it looks nice
	return 0;
}

//function used to draw individual pixels to OLED
void drw_pixel_oled(int x, int y){
	int cell;
	int row;
	uint8_t bit;
	const int offset = sizeof(0x40);

	//calculate cell address, add offset for DMA
	row = y / 8;
	cell = (x + row * 128) + offset;
	bit = (1 << y % 8);

	display_buffer[cell] |= bit;
	I2C_write(display_buffer, DISPLAY_BUFFER_SZ);
}

//function used to fill OLED screen 
/*
Examples:
	fill_oled(0xFF);	//fill with white (In b+w device)
	fill_oled(0x00);	//fill with nothing (screen is blank)
	fill_oled('a');		//results in a segmented fill
*/
static void fill_oled(unsigned char data){
	//128 segments of 8 bit data used to represent full display
	unsigned int total = 128 * 8;
	unsigned int i = 0;

	//write given data to each row/col of OLED
	for(i = 0; i < total; i++) write_oled(false, data);
	//memset(display_buffer, (int)data, DISPLAY_BUFFER_SZ);
}

// end OLED management
// ##################################################
// ##################################################

// ##################################################
// ##################################################
// Driver code

//function used when probing the i2c slave
static int oled_probe(struct i2c_client *client, const struct i2c_device_id *id){
	activate_oled();

	//fill_oled(0x00);
	//fill_oled(0xFF);
	//fill_oled(0x00);

	//drw_pixel_oled(0, 0);
	//drw_pixel_oled(0, 1);
	//drw_pixel_oled(0, 2);
	//drw_pixel_oled(0, 3);
	//drw_pixel_oled(0, 4);
	//drw_pixel_oled(0, 5);

	for(int i = 0; i < 30; i++){
		drw_pixel_oled(0, i);
	}

	printk(KERN_ALERT "I2C OLED: PROBED!");

	return 0;
}

//function used to close down OLED connection when driver unloads
static void oled_remove(struct i2c_client *client){

	msleep(500);

	write_oled(true, 0xAE);
	printk(KERN_ALERT "I2C OLED: REMOVED!");
} 


//declare struct which holds the id for the client device (OLED)
static const struct i2c_device_id oled_id[] = {
	{ OLED_NAME, 0 },
	{ }
};

MODULE_DEVICE_TABLE(i2c, oled_id);

//declare struct that represents this driver and its relevant functions
static struct i2c_driver oled_drv ={

	.driver = {
		.name = OLED_NAME,
		.owner = THIS_MODULE,
	},

	.probe = oled_probe,
	.remove = oled_remove,
	.id_table = oled_id,

};

//declare struct that holds the board info of the OLED
static struct i2c_board_info oled_board_info = {
	I2C_BOARD_INFO(OLED_NAME, OLED_ADDR)
}; 

// end Driver code
// ##################################################
// ##################################################


// ##################################################
// ##################################################
//Driver entry/exit

//define init function for setup
static int __init oled_init(void){
	printk(KERN_ALERT "I2C OLED INIT");
	int ret = -1;

	//try to get adapter for bus
	adapter = i2c_get_adapter(I2C_BUS_AVAILABLE);

	//if the adapter exists then register a new device with relevant information
	if(adapter != NULL){
		//reg new device on adapter using board_info
		//NOTE: i2c_client_driver was deprecated as per: https://lore.kernel.org/all/20200618084323.GB954398@dell/T/
		client_oled = i2c_new_client_device(adapter, &oled_board_info);

		//allocate memory from kernel for OLED display buffer (GFP=GET FREE PAGES)
		display_buffer = (uint8_t*)kmalloc(DISPLAY_BUFFER_SZ, GFP_KERNEL);

		//write 0 to display buffer memory
		memset(display_buffer, 0, DISPLAY_BUFFER_SZ);

		//assign first line of OLED hw to buffer
		display_buffer[0] = (uint8_t) 0x40;

		//if the new device is successful and exists then add the
		//previously declared driver info
		if(client_oled != NULL){
			i2c_add_driver(&oled_drv);
			ret = 0;
		}
	}

	//I assume the line below basically initialises the i2c bus with all the previously set info
	i2c_put_adapter(adapter);

	printk(KERN_ALERT  "I2C OLED Driver added successfully");
	return ret;
}

//define exit function for closing/freeing
static void __exit oled_exit(void){
	//unreg oled device and delete driver
	i2c_unregister_device(client_oled);
	i2c_del_driver(&oled_drv);

	//free memory used for display buffer
	memset(&display_buffer[1], 0x00, DISPLAY_BUFFER_SZ - 1);
	kfree(display_buffer);

	printk(KERN_ALERT "I2C OLED EXIT");
}


// end Driver entry/exit
// ##################################################
// ##################################################


//define init and exit functions to use
module_init(oled_init);
module_exit(oled_exit);
