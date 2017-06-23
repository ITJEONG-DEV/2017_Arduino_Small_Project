#include "font.h"
#include "LedControl.h"

#define CLK 10
#define CS 11
#define DIN 12

#define BRIGHTNESS 15
#define COUNT 2
#define MAX 15
#define WIDTH (MAX+COUNT)

byte frame[WIDTH][8];

LedControl lc = LedControl(DIN, CLK, CS, COUNT);

void makeFrame(char* str) 
{ 
  int x, y; 
  int len = strlen(str);
  // 파라미터로 넘어온 str문자열에서 
  // 각 문자에 대한 폰트 정보를 얻어와 
  // frame 버퍼에 채우는 코드를 구현하세요. 
  
  for(x=0; x<WIDTH; x++) 
  { 
    for(y=0; y<8; y++) 
    { 
      frame[x][y] = font[str[x]][y]; 
    } 
  }
}

void setup()
{
  for( int c = 0; c < COUNT; c++)
  {
    lc.shutdown(c, false);
    lc.setIntensity(c, BRIGHTNESS);
    lc.clearDisplay(c);
  }
  makeFrame("Hello~ MATRIX");
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

void draw()
{
  for(int n=COUNT-1; n>=0; n--) 
  { 
    for(int l=0; l<8; l++) 
    { 
      lc.setRow(n, l, font[COUNT-1-n][l]); 
    } 
  }
}

// 왼쪽 모듈부터 출력 
void loop() 
{
  draw();
  delay(1000);
  slideFrame();
}


