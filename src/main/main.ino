#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <avr/power.h>
SoftwareSerial serial(2, 3); //RX, TX
/*
Due to the fact that the MCU running the display is slower than the one we are
programming, we need to include lots of delays for them to catch up to eachother,
so they don't trip over commands and we don't end up with a corrupted image on
the display.
-Nolan Adams
This code is released under the MIT License
*/


void setup()
{
  serial.begin(115200); //Start serial port at 115200 baud
  delay(3500); //wait for display microcontroller to boot
  clearScreen(); //make sure display is free of errors

  delay(50); //Stability delay

  setHome(); //sets X and Y back to 0

  delay(50); //stability delay

  drawGridlines(); //Main box around labels and data output text

  setX(25); //set location for title text
  setY(8); // ^
  delay(50); //stability delay
  serial.print("Sensor Test Bench"); //title at the top of the screen
  delay(50);
  setX(25);
  setY(23);
  serial.print("Analog");
  setX(100);
  serial.print("Digital");

  delay(200); //replaces smile for stability's sake
  printXColumnA();
  delay(50);
  printXColumnB();
  delay(100); //delay before loop starts
}

void loop()
{
  setHome();
  delay(200);
  printYColumnA();
  delay(10);
  printYColumnB();
  delay(1100);
  eraseBlock(43, 33, 79, 119);
  //delay(100);
  eraseBlock(118, 33, 154, 119);
  delay(150);
  //clear the area where the values are displayed to remove residual digits if value gains or loses a digit

}
