#include <Wire.h> // I2C control library
#include <LiquidCrystal_I2C.h> // LCD library

#define LED 9
#define R A0

// set the LCD address to 0x3F for a 16 chars and 2 line display

LiquidCrystal_I2C lcd(0x3F,16,2);

void setup()
{
  Serial.begin(9600);
  pinMode( LED, OUTPUT );
  pinMode( R, INPUT );
  lcd.init(); // initialize the lcd
  lcd.backlight(); // turn on backlight
  delay(2000);
  lcd.cursor();
}

void loop()
{
  lcd.clear();
  int a = analogRead(R);
  Serial.println(a);
  analogWrite(LED, a);
  lcd.print(a, DEC);
  delay(200);
}
