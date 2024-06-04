use rppal::i2c::I2c;

use std::error::Error;
use std::thread;
use std::time::Duration;

const OLED_ADDR: u16 = 0x3C;

fn main() -> Result<(), Box<dyn Error>> {
    I2c::with_bus(1);

    let mut i2c = I2c::new()?;
   
    i2c.set_slave_address(OLED_ADDR)?;

    println!("I2C: OLED on");
 
    //write ON command
    i2c.block_write(
        0x00, //indicates command
        &[0xAF]  //indicates screen ON
    )?;

    //sleep 2 secs
    thread::sleep(Duration::from_secs(5));

    println!("I2C: OLED off");

    //write OFF command
    i2c.block_write(
        0x00, //indicates command
        &[0xAE]  //indicates screen OFF
    )?;
   
    Ok(())
}