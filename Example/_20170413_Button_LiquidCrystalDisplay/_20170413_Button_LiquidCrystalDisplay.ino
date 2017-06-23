#include <Wire.h> // I2C control library
#include <LiquidCrystal_I2C.h> // LCD library

#define LED 13
#define BUTTON 3
#define LED1 5
#define LED2 6

// set the LCD address to 0x3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F,16,2);

void setup() {
  pinMode( LED, OUTPUT );
  pinMode( LED1, OUTPUT );
  pinMode( LED2, OUTPUT );
  pinMode( BUTTON, INPUT_PULLUP );
  lcd.init( );
  lcd.backlight( );
  lcd.print( "Start!" );
  delay( 2000 );

  Serial.begin(9600);
}

bool isOn = false;

void land()
{
  lcd.clear();
  int r = rand() % 10;
  delay(50);

  switch(r)
  {
    case 1: lcd.print("Korea Digital Me"); lcd.setCursor(0,1); lcd.print("dia High School"); break;
    case 2: lcd.print("Dimigo!"); break;
    case 3: lcd.print("E-Business"); break;
    case 4: lcd.print("Digital Contents"); break;
    case 5: lcd.print("Web Programing"); break;
    case 6: lcd.print("Hacking Defence"); break;
    case 7: lcd.print("Arduino"); break;
    case 8: lcd.print("Micro Processor"); break;
    case 9: lcd.print("MEGA ADK"); break;
    case 10: lcd.print("ITJEONG"); break;
    default: lcd.print("miss"); break;
  }

  if(r%2)
  {
    digitalWrite( LED1, HIGH );
    digitalWrite( LED2, LOW );
  }
  else
  {
    digitalWrite( LED1, LOW );
    digitalWrite( LED2, HIGH );
  }
}

void loop() {
  isOn = digitalRead(BUTTON);
  digitalWrite( LED, !isOn );
  if(!isOn) land();
}
