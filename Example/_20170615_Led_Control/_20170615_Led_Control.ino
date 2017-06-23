#include <LedControl.h>

#define CLK 7
#define CS 8
#define DIN 9
#define BRIGHTNESS 8

LedControl lc = LedControl( DIN, CLK, CS, 1);
void setup()
{
  lc.shutdown( 0, false );
  lc.setIntensity( 0, BRIGHTNESS );
  lc.clearDisplay( 0 );

  lc.setRow( 0, 2, B01110011 );
  lc.setColumn( 0, 0, B10000011 );
  lc.setLed( 0, 7, 6, true );
}

void loop()
{
}
