#include <MsTimer2.h>

#define CLOCK 2
#define LATCH 3
#define DATA 12

#define FND_D0 A0
#define FND_D1 A1
#define FND_D2 A2
#define FND_D3 A3

byte FND_FONT[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71 };

int FND_NUMBER;
int FND_PNTPOS;

void setup()
{
  pinMode( CLOCK, OUTPUT );
  pinMode( LATCH, OUTPUT );
  pinMode( DATA, OUTPUT );
  
  for(int i = FND_D0; i<= FND_D3; i++ )
  {
    pinMode( i, OUTPUT );
    digitalWrite( i, HIGH );
  }

  MsTimer2::set(12, outputNumber);
  MsTimer2::start();
}

void outputFND( int num, bool dot )
{
  byte font = FND_FONT[num] | ( dot << 7 );

  digitalWrite( LATCH, LOW );
  shiftOut( DATA, CLOCK, MSBFIRST, font );
  digitalWrite( LATCH, HIGH );
}

void outputNumber()
{
  int number = FND_NUMBER;
  for(int p=FND_D0; p<=FND_D3; p++)
  {
    int digit = number % 10;
    outputFND(digit, p == FND_PNTPOS);
    digitalWrite(p, LOW); // p FND ON
    delayMicroseconds(1000); // 1ms
    digitalWrite(p, HIGH); // p FND OFF
    
    number = number /10;
    if(number <= 0) break;
  }
}

bool dot = false;

void loop()
{
  FND_NUMBER = 10;
  FND_PNTPOS = FND_D1;

  while( FND_NUMBER <= 9999 )
  {
    delay(10);
    FND_NUMBER++;
  }
}

void myShiftOut( int dataPin, int clkPin, int seq, byte data )
{
  byte maskbit;
  if( seq == MSBFIRST ) maskbit = 0x80;
  else maskbit = 0x01;

  for( int i = 0; i < 8; i++ )
  {
    bool b = data & maskbit;
    digitalWrite( clkPin, LOW );
    digitalWrite( dataPin, b );
    digitalWrite( clkPin, HIGH );

    if( seq == MSBFIRST ) data = data << 1;
    else data = data >> 1;
  }
}
