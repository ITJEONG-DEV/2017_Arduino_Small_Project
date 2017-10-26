#define clock 2
#define latch 3
#define data 13
 
void setup() 
{
  pinMode(latch, OUTPUT);
  pinMode(data, OUTPUT); 
  pinMode(clock, OUTPUT);

  for( int i = 4; i < 11; i++ )
    pinMode( i, INPUT_PULLUP );
}

int num;
void loop() 
{
  num = 0;
  for( int i = 1; i < 8; i++ )
  {
    if ( !digitalRead(i+3 ) ) num+= ( 1 << i );
  }
  digitalWrite( latch, LOW );
  shiftOut( data, clock, MSBFIRST, num );
  digitalWrite( latch, HIGH );
}
