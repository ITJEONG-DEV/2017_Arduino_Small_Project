#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define BT_RX 11 //HM10의 TX가 아두이노의 RX
#define BT_TX 13 //HM10의 RX가 아두이노의 TX.. 아두이노 기준으로 선언하는것임을 염두

SoftwareSerial HM10(BT_RX,BT_TX);

void setup()
{
  Serial.begin(9600);
  HM10.begin(9600);
}
void loop() {
  if (HM10.available())
  {
    Serial.write(HM10.read());
  }
  if (Serial.available())
  {
    byte c = Serial.read();
    //Serial.write(c); // SEND msg echo
    HM10.write(c);
  }
}
