use rppal_dht11::{Dht11, Measurement};
use rppal::{gpio::{Gpio, Mode}, hal::Delay};

use std::process::Command;
use std::thread;
use std::time::Duration;
use std::error::Error;

const DHT_SIGNAL: u8 = 21;//PIN 40	
const LED: u8 = 26; //PIN 37


fn main() -> Result<(), Box<dyn Error>> {

	let dhtPin = Gpio::new()?.get(DHT_SIGNAL)?.into_io(Mode::Output);
	let mut led = Gpio::new()?.get(LED)?.into_output();

	let mut dht = Dht11::new(dhtPin);
	let mut delay = Delay::new();

	loop{
		led.set_high();
		thread::sleep(Duration::from_millis(100));

		let mes = match dht.perform_measurement(&mut delay) {
			Ok(m) => {
				 	let temp: f32 = (m.temperature as f32) / 10.;
				 	println!("Temp: {}", temp);
					
					let cmd = format!("echo \"{:?}\" > /dev/oled", temp);
					

				 	let mut wr_oled = Command::new("sh");
				 	wr_oled.arg("-c").arg(cmd);
					wr_oled.status().expect("echo command failed");
					thread::sleep(Duration::from_millis(250));
				},

			Err(e) => {
				 	print!("error: {:?}", e);
				 	continue;
				}
		};

		
		led.set_low();
		thread::sleep(Duration::from_millis(100));
	}

	Ok(())	
}
