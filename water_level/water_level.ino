const int red_pin = 10;
const int green_pin = 9;
const int blue_pin = 8;
const int water_pin = 7;

int level = 0;
int red = 0;
int green = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  level = analogRead(A0);
  Serial.println(level);
  level = level - 500;
  if(level < 0) level = 0;
  else if(level > 60) level = 60;
  level = level / 60 * 100;
  red = 255 - ((level - 50) * 5.1);
  if (red > 255) red = 255;
  green = level * 5.1;
  if (green > 255) green = 255;
  setColor(red,green,0);
  delay(10);
}


void setColor(int red, int green, int blue)
{
  analogWrite(red_pin, red);
  analogWrite(green_pin, green);
  analogWrite(blue_pin, blue);  
}
