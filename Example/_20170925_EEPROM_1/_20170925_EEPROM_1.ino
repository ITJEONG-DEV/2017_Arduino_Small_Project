#include <EEPROM.h>

void setup()
{
  Serial.begin(9600);

  int maxAddr = EEPROM.lengh() / 16;

  for( int addr = 0; addr < maxAddr; addr++ )
  {
    int val = analogRead(0) % 256;
    EEPROM.write( addr, val );

    Serial.print(addr);
    Serial.print("\t");
    Serial.print( val, DEC );
    Serial.println();
  }
}

void loop()
{
  
}

