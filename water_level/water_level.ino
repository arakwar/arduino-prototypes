const int red_pin = 10;
const int green_pin = 9;
const int blue_pin = 8;
const int water_pin = A0;

const int sensor_max = 600;
const int sensor_min = 480;
int sensor_diff = 0;

float level = 0;
int red = 0;
int green = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  sensor_diff = sensor_max - sensor_min;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  level = analogRead(A0);
  Serial.print("level : ");
  Serial.print(level);
  Serial.print(" diff : ");
  Serial.print(sensor_diff);
  Serial.print(" after : ");
  level = level - sensor_min;
  if(level < 0) level = 0;
  else if(level > sensor_diff) level = sensor_diff;
  level = level / sensor_diff * 100;
  Serial.println(level);
  red = 255 - ((level - 50) * 5.1);
  if (red > 255) red = 255;
  green = level * 64 / 100;
  Serial.print("red   : "); 
  Serial.println(red);
  Serial.print("green : ");
  Serial.println(green);
  setColor(red,green,0);
  delay(1000);
}


void setColor(int red, int green, int blue)
{
  analogWrite(red_pin, red);
  analogWrite(green_pin, green);
  analogWrite(blue_pin, blue);  
}
