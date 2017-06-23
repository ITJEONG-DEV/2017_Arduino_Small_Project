#include "font.h"
#include <LedControl.h> 

#define CLK 10
#define CS  11
#define DIN 12

#define BIRGHTNESS 1
#define COUNT 2   // number of 8x8 matrix
#define MAX 15    // maximum string length
#define WIDTH (MAX+COUNT)

byte frame[WIDTH][8];

char msg[4][MAX] =
{
  "Hello~ MATRIX",
  "I'm NEO",
  "Keau Reeves",
  "Wachowski Bros"  
};

LedControl lc = LedControl(DIN, CLK, CS, COUNT);  
 
void makeFrame(char* str) {
  int x, y;
  int len = strlen(str);

  for( x = 0; x < WIDTH; x++ )
  {
    for( y = 0; y < 8; y++ )
    {
      if( x < COUNT ) frame[x][y] = 0;
      else if( x < len + COUNT ) frame[x][y] = font[str[x-COUNT]][y];
      else frame[x][y] = 0x0;
    }
  }
}

void setup() {
  for(int c=0; c<COUNT; c++) {
    lc.shutdown(c, false);  
    lc.setIntensity(c, BIRGHTNESS);
    lc.clearDisplay(c);
  }
}

void draw() {
  for(int n=COUNT-1; n>=0; n--) {
    for(int l=0; l<8; l++) {
      lc.setRow(n, l, frame[COUNT-1-n][l]);
    }
  }
}

void slideFrame()
{
  int x, y;
  for( y = 0; y < 8; y++) // h
  {
    for( x = 0; x < WIDTH; x++ )
    {
      if( x == 0 ) frame[WIDTH-1][y] = frame[WIDTH-1][y] | (frame[0][y] & B10000000 >> 7 );

      frame[x][y] = frame[x][y] << 1;

      if( x < WIDTH-1 ) frame[x][y] = frame[x][y] | ( frame[x+1][y] & 0x80 ) >> 7;
    }
  }
}
  
void loop()
{ 
  for( int m = 0; m < 4; m++)
  {
    makeFrame(msg[m]);
    
    for( int s = 0; s < ( strlen(msg[m]) + 1 ) * 8; s++ )
    {
      draw();
      delay(50);
      slideFrame();
    }
  }
}
