#include <SoftwareSerial.h>
SoftwareSerial swSerial(10,11);

void setup()
{
  Serial.begin(9600);
  swSerial.begin(9600);
}

int c = 'A';
void SerialSend()
{
  for(int i=0; i<3; i++)
    swSerial.write(c++);
  if(c > 'z') c='A';
}

long before = 0;

void loop()
{
  long now = millis();
  if(now - before >= 1000)
  {
    SerialSend();
    before = now;
  }

  if (Serial.available() > 0)
  {
    byte incomingByte = Serial.read();
    Serial.print("\nI received: ");
    Serial.write(incomingByte);
  }
}
