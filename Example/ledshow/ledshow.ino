#include "font.h"
#include <LedControl.h> 

#define CLK 10
#define CS  11
#define DIN 12

#define BIRGHTNESS 8
#define COUNT 2   // number of 8x8 matrix
#define MAX 15    // maximum string length
#define WIDTH (MAX+COUNT)

byte frame[WIDTH][8];

LedControl lc = LedControl(DIN, CLK, CS, COUNT);  
 
void makeFrame(char* str) {
  int x, y;
  int len = strlen(str);

  for(x=0; x<WIDTH; x++) {
    for(y=0; y<8; y++) {
      if(x<len)
        frame[x][y] = font[str[x]][y];
      else
        frame[x][y] = 0x0;
    }
  }
}

void setup() {
  for(int c=0; c<COUNT; c++) {
    lc.shutdown(c, false);  
    lc.setIntensity(c, BIRGHTNESS);
    lc.clearDisplay(c);
  }
  makeFrame("Hello~ MATRIX");
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
  for( y = 0; y < 8; y++)
  {
    for( x = 0; x < WIDTH; x++ )
    {
      frame[x][y] = frame[x][y] << 1;

      if( x < WIDTH-1 ) frame[x][y] |= ( frame[x+1][y] & 0x80 ) >> 7;
    }
  }
}

void loop() { 
  draw();
  delay(80);
  slideFrame();
}
