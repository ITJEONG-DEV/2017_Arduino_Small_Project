#define RED 10
#define GREEN 9
#define BLUE 8

int n = 1;

void setup()
{
  for( int p = BLUE; p <= RED; p++ )
  {
    pinMode(p, OUTPUT);
  }
  Serial.begin( 9600 );
}

void loop()
{
  for( int c = 0; c < 8; c++ )
  {
    bool r = ( bool )( 1 & c );
    bool g = ( bool )( 2 & c );
    bool b = ( bool )( 4 & c );

    digitalWrite( RED, r );
    digitalWrite( GREEN, g );
    digitalWrite( BLUE, b );

    Serial.println( "USART COMM." );
    Serial.print("RED : ");
    Serial.print(r);
    Serial.print("\n");
    Serial.print("GREEN : ");
    Serial.print(g);
    Serial.print("\n");
    Serial.print("BLUE : ");
    Serial.print(b);
    Serial.print("\n");
    n++;

    delay( 1250 );
  }
}

