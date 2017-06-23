#include "font.h"
#include "LedControl.h"
#define DIN 12
#define CLK 11
#define LOAD 10 // CS
#define BIRGHTNESS 8
LedControl lc=LedControl(12,11,10, 1); //
void setup()
{
lc.shutdown(0, false);
lc.setIntensity(0, BIRGHTNESS);
lc.setIntensity(0, 2);
lc.clearDisplay(0);
lc.setRow(0, 2, B11100011);
delay(5000);
}
void loop()
{
for(int c=32; c<=125; c++)
{
for(int l=0; l<8; l++)
{
lc.setRow(0, l, font[c][l]);
}
delay(500);
}
}
