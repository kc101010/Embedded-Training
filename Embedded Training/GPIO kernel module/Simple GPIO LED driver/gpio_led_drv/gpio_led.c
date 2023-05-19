#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kyle Christie");
MODULE_DESCRIPTION("Very simple GPIO driver to interact with an LED before exiting");

/**
Program steps/Planning
1. init the gpio to control the LED
2. turn the LED on
3. turn the LED off and exit

Similar to a Hello, World but with an LED!

**/

//ensure LED is off then turn on
void write_gpio(void){
	gpio_set_value(4,0);
	gpio_set_value(4,1);
}

//define init function for setup
static int gpio_led_init(void){
	printk(KERN_ALERT "GPIO LED INIT");

	//init GPIO
	if(gpio_request(4, "rpi-gpio-4")){
		printk("GPIO LED: Cannot allocate GPIO pin\n");
		goto AddError;
	}

	//set GPIO to output
	if(gpio_direction_output(4,0)){
		printk("GPIO LED: Cannot set GPIO 4 to output\n");
		goto Gpio4Error;
	}

	//write to the GPIO pin to activate the LED
	write_gpio();

	return 0;

	//Error labels
	Gpio4Error:
		gpio_free(4);
	AddError:
		return -1;
}

//define exit function for closing/freeing
static void gpio_led_exit(void){
	gpio_set_value(4,0);
	gpio_free(4);
	printk(KERN_ALERT "GPIO LED EXIT");
}


//define init and exit functions to use
module_init(gpio_led_init);
module_exit(gpio_led_exit);
