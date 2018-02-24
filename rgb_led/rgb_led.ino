/*
Adafruit Arduino - Lesson 3. RGB LED
*/

int redPin = 10;
int greenPin = 9;
int bluePin = 8;

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

void loop()
{
  setColor(255, 0, 0);  // red
  delay(1000);
  setColor(255, 32, 0);  // yellow
  delay(1000);  
  setColor(0, 64, 0);  // green
  delay(1000);
//  setColor(0, 0, 255);  // blue
//  delay(1000);
//  setColor(80, 0, 80);  // purple
//  delay(1000);
//  setColor(0, 255, 255);  // aqua
//  delay(1000);
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
