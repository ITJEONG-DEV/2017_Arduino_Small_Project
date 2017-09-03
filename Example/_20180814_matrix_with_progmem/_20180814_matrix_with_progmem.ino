// 8x8 LED Matrix Drive
// by akapo@naver.com

#include <avr/pgmspace.h>
#include "font.h"
#include "LedControl.h"
#define CLK 10
#define CS 11
#define DIN 12
#define BIRGHTNESS 8
#define COUNT 4
#define MAX 40 // maximum string length
#define WIDTH (MAX+COUNT)

byte frame[WIDTH][8];
LedControl lc = LedControl(DIN, CLK, CS, COUNT);

void setup()
{
  Serial.begin(9600);

  Serial.println((uint16_t)(font + ( ( ( 1 * 8 ) ) / 8 ) + (1/8) ), DEC); //342 //334
  Serial.println((uint16_t)&font[1][1], DEC); //343 //334
  
  for(int c=0; c<COUNT; c++)
  {
    lc.shutdown(c, false);
    lc.setIntensity(c, BIRGHTNESS);
    lc.clearDisplay(c);
  }
}

void makeFrame(char* str)
{
  int x, y;
  int len = strlen(str);
  for(x=0; x<WIDTH; x++)
  {
    for(y=0; y<8; y++)
    {
      int a = ( (str[x-COUNT]*8)+y )
      if(x < COUNT) frame[x][y] = 0x0;
      //else if(x < len+COUNT) frame[x][y] = pgm_read_word( &font[str[x-COUNT]][y] );
      else if(x < len+COUNT) frame[x][y] = pgm_read_word( font +  a );
      // else if(x < len+COUNT) frame[x][y] = font[str[x-COUNT]][y];
      else frame[x][y] = 0x0;
    }
  }
}

void slideFrame()
{
  int x, y;
  for(y=0; y<8; y++)
  {
    for(x=0; x<WIDTH; x++)
    {
      frame[x][y] = frame[x][y]<<1;
      if(x<WIDTH-1) frame[x][y] |= (frame[x+1][y] & 0x80) >> 7;
    }
  }
}

char msg[4][MAX] =
{
  "Hello~ MATRIX",
  "I'm neo.",
  "Keanu Reeves",
  "Wachowski Bros."
};

void draw()
{
  for(int n=COUNT-1; n>=0; n--)
  {
    for(int l=0; l<8; l++)
    {
      lc.setRow(n, l, frame[COUNT-1-n][l]);
    }
  }
}

void loop()
{
  for(int m=0; m<4; m++)
  {
    makeFrame(msg[m]);
    int len = strlen(msg[m]);
    // COUNT+len+2 = COUNT+문자열길이+여백2글자
    for(int s=0; s<(COUNT+len+2)*8; s++)
    {
      draw();
      delay(40);
      slideFrame();
    }
  }
}
