use rppal::gpio::Gpio;
use std::thread;
use std::time::Duration;
use std::error::Error;


const LED: u8 = 26;

fn main() -> Result<(), Box<dyn Error>> {
	let mut pin = Gpio::new()?.get(LED)?.into_output();
	
	loop{
		pin.set_high();
		thread::sleep(Duration::from_millis(500));
		pin.set_low();
		thread::sleep(Duration::from_millis(500));
	}

	/*pin.set_high();
	thread::sleep(Duration::from_millis(500));
	pin.set_low();*/
	
	Ok(())
	
}
