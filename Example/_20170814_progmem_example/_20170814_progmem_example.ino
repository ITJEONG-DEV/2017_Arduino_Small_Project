#include <avr/pgmspace.h>

const PROGMEM uint16_t charSet[] = { 65000, 32796, 16843, 10, 11234};
const char signMessage[] PROGMEM = {"I AM PREDATOR, UNSEEN COMBATANT.CREATED BY THE UNITED STATES DEPART"};

unsigned int displayInt;
int k; // counter variable
char myChar;

void loop()
{
}

void setup()
{
  Serial.begin(9600);
  while (!Serial);
  // put your setup code here, to run once:
  // read back a 2-byte int
  for (k = 0; k < 5; k++)
  {
    displayInt = pgm_read_word (charSet + k);
    Serial.println(displayInt);
  }
  Serial.println();
  // read back a char
  int len = strlen_P(signMessage);
  for (k = 0; k < len; k++)
  {
    myChar = pgm_read_byte (signMessage + k);
    Serial.print(myChar);
  }
  Serial.println();
}
