#define TILT 7 
#define LASER 8

void setup()
{
  pinMode(TILT, INPUT);
  pinMode(LASER, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  bool r = digitalRead(TILT);
  if(r) digitalWrite(LASER, LOW);
  else digitalWrite(LASER, HIGH);
  Serial.println(r, DEC);
}

