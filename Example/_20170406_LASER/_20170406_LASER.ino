#define LASER 7

void setup()
{
  pinMode(LASER, OUTPUT);
}

void loop()
{
  digitalWrite(LASER, HIGH);
  delay(50);
  digitalWrite(LASER, LOW);
  delay(50);
}

