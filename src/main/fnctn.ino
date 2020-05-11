#include <Arduino.h>
void clearScreen()
{
  serial.write(0x7C);
  serial.write((byte)0);
}
void setHome()
{
  serial.write(0x7C);
  serial.write(0x18);
  serial.write((byte)0);//set x back to 0
  serial.write(0x7C);
  serial.write(0x19);
  serial.write((byte)0);//set y back to 0
}
void drawLine(byte x1, byte y1, byte x2, byte y2, byte set)
{
  //draws a line from two given points. You can set and reset just as the pixel function.
  serial.write(0x7C);
  serial.write(0x0C);//CTRL l
  serial.write(x1);
  serial.write(y1);
  serial.write(x2);
  serial.write(y2);
  serial.write(0x01);
  delay(5);
}
void drawCircle(byte x, byte y, byte rad, byte set) {
//draws a circle from a point x,y with a radius of rad.
//Circles can be drawn off-grid, but only those pixels that fall within the
//display boundaries will be written.
  serial.write(0x7C);
  serial.write(0x03);//CTRL c
  serial.write(x);
  serial.write(y);
  serial.write(rad);
  serial.write(0x01);
  delay(10);
}
void drawBox(byte x1, byte y1, byte x2, byte y2, byte set)
{
  //draws a box from two given points. You can set and reset just as the pixel function.
  serial.write(0x7C);
  serial.write(0x0F);//CTRL o
  serial.write(x1);
  serial.write(y1);
  serial.write(x2);
  serial.write(y2);
  serial.write(0x01);
  delay(10);
}
void eraseBlock(byte x1, byte y1, byte x2, byte y2) {
  //This is just like the draw box command, except the contents of the box are erased to the background color
  serial.write(0x7C);
  serial.write(0x05);//CTRL e
  serial.write(x1);
  serial.write(y1);
  serial.write(x2);
  serial.write(y2);
  delay(20);
}
void drawSmile()
{
  drawCircle(132, 100, 20, 0); //large circle
  drawCircle(122, 95, 2, 0); //left eye
  drawCircle(142, 95, 2, 0); //right eye
  drawLine(122, 107, 127, 110, 0); //left smile line
  drawLine(127, 110, 137, 110, 0); //center line
  drawLine(137, 110, 142, 107, 0); //right line
}
void drawGridlines()
{
  drawLine(4, 4, 155, 4, 0); //title bar top
  drawLine(4, 20, 155, 20, 0); //box top
  drawLine(4, 32, 155, 32, 0); //boxtitles bottom
  drawLine(4, 20, 4, 120, 0); //box left
  drawLine(4, 120, 155, 120, 0); //box bottom
  drawLine(155, 20, 155, 120, 0); //box right
  drawLine(42, 32, 42, 120, 0); //box divider
  drawLine(80, 32, 80, 120, 0); //box divider
  drawLine(117, 32, 117, 120, 0); //box divider
}
void setY(byte posY)//0-63 or 0-127 pixels
{
  //Set the y position
  serial.write(0x7C);
  serial.write(0x19);//CTRL y
  serial.write(posY);

}
void setX(byte posX) //0-127 or 0-159 pixels
{
  //Set the X position
  serial.write(0x7C);
  serial.write(0x18);//CTRL x
  serial.write(posX);
}
void printXColumnA()
{
  delay(10);
  setX(18);
  setY(37);
  serial.println("A0");
  serial.println("A1");
  //delay(30);
  serial.println("A2");
  serial.println("A3");
  //delay(30);
  serial.println("A4");
  delay(50);
  serial.println("A5");
  //delay(30);
  serial.println("A6");
  serial.println("A7");
  //delay(30);
  serial.println("A8");
  serial.println("A9");
  delay(10);
}
void printYColumnA()
{
  setX(52);
  setY(37);
  serial.println(analogRead(A0));
  serial.println(analogRead(A1));
  serial.println(analogRead(A2));
  serial.println(analogRead(A3));
  delay(50);
  serial.println(analogRead(A4));
  serial.println(analogRead(A5));
  serial.println(analogRead(A6));
  serial.println(analogRead(A7));
  delay(50);
  serial.println(analogRead(A8));
  serial.println(analogRead(A9));

}
void printXColumnB()
{
  delay(10);
  setX(90);
  setY(37);
  serial.println("D2R");
  serial.println("D4R");
  //delay(30);
  serial.println("D5R");
  serial.println("D6R");
  //delay(30);
  serial.println("D7R");
  delay(50);
  serial.println("D8R");
  //delay(30);
  serial.println("D9F");
  serial.println("D10F");
  //delay(30);
  serial.println("D11F");
  serial.println("D12F");
  delay(10);
}
void printYColumnB()
{
  setX(133);
  setY(37);
  serial.println(digitalRead(2));
  serial.println(digitalRead(4));
  serial.println(digitalRead(5));
  serial.println(digitalRead(6));
  delay(50);
  serial.println(digitalRead(7));
  serial.println(digitalRead(8));
  serial.println(digitalRead(9));
  serial.println(digitalRead(10));
  delay(50);
  serial.println(digitalRead(11));
  serial.println(digitalRead(12));

}
