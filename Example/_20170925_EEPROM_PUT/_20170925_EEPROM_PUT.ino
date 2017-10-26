#include <EEPROM.h>

struct MyObject
{
  float field1;
  byte field2;
  char name[10];
};

void setup()
{
  Serial.begin(9600);
 
  while (!Serial) { }

  float f = 123.456f; //Variable to store in EEPROM.
  int eeAddress = 0; //Location we want the data to be put.
 
  //One simple call, with the address first and the object second.
  EEPROM.put(eeAddress, f);
  
  Serial.println("Written float data type!");
  
  //Data to store.
  MyObject customVar =
  {
    3.14f,
    65,
    "Working!"
  };

  //Move address to the next byte after float 'f'.
  eeAddress += sizeof(float);

  EEPROM.put(eeAddress, customVar);
  Serial.print("Written custom data type! \n\nView the example
  sketch eeprom_get to see how you can retrieve the values!");
}

void loop()
{
  /* Empty loop */
}
