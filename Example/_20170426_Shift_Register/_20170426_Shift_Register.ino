#define CLOCK 2
#define LATCH 3
#define DATA 12

byte FND_FONT[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71 };

void setup()
{
  pinMode( CLOCK, OUTPUT );
  pinMode( LATCH, OUTPUT );
  pinMode( DATA, OUTPUT );
}

void outputFND( int num, bool dot )
{
  byte font = FND_FONT[num] | ( dot << 7 );

  digitalWrite( LATCH, LOW );
  shiftOut( DATA, CLOCK, MSBFIRST, font );
  digitalWrite( LATCH, HIGH );
}

bool dot = false;

void loop()
{
  for( int num = 0x0; num <= 0xF; num++ )
  {
    outputFND(num, dot );
    delay(1000);
  }
  dot = !dot;
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

