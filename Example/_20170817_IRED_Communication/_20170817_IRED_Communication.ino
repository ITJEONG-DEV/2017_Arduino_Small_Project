#include <IRremote.h>
#define L 8
#define E 13
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.print("hi");

  pinMode( L, OUTPUT );
  pinMode( E, OUTPUT );
}

void loop()
{
  if(irrecv.decode(&results) )
  {
    switch( results.value )
    {
      case 0xFF30CF :
        digitalWrite( L, HIGH );
        digitalWrite( E, HIGH );
      case 0XFF18E7 :
        digitalWrite( L, LOW );
        digitalWrite( E, LOW );
      case :
    }
      Serial.println(results.value, HEX);
      irrecv.resume();
  }
}

