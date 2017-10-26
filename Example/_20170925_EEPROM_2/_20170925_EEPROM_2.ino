#include <EEPROM.h>
#define NVM 1000

byte step;

void setup()
{
  Serial.begin(9600);
  step = EEPROM.read(NVM);
  Serial.print("continue at ");
  Serial.print(step, DEC);
}

void loop()
{x
  step++;
  EEPROM.write( NVM, step );
  Serial.print("now working at ");
  Serial.println( step, DEC );
  delay(1000);
}

