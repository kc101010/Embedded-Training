
// Written by Kyle Christie
// 12/5/23
// Trying to fix RTC and OLED project for a new project

//library includes
#include <DS3231.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


//Init display with dimensions and wire address
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

DS3231 clock;
RTCDateTime dt;

void setup() {
  //init serial line for debug
  Serial.begin(9600);

  
  //init display, clear it and then prepare for display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();

  //init RTC
  clock.begin();
  clock.setDateTime(2023, 5, 12, 22, 34, 00);
  
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  

  display.println("Hello, World!");
}

void loop() {

  dt = clock.getDateTime();
  
  display.setCursor(1,1);
  display.clearDisplay();
  display.print("Current time from RTC: ");
  display.print(dt.hour, DEC);
  display.print(":");
  display.print(dt.minute, DEC);
  display.display();
  
  Serial.print("Current time from RTC: ");
  Serial.print(dt.hour, DEC);
  Serial.print(":");
  Serial.print(dt.minute, DEC);
  Serial.println(" ");
  
  
  delay(1000);

}
