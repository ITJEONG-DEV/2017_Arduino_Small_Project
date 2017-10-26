#include <Keyboard.h>


const char joystick[4] = { A0, A1, A3, A5 };
const char button_key[8] = { 'f', 'g', (char)32, 'b', 'e', 'd', 'h', 'c' };
const char joystick_key[4] = { KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW };

int i;

void setup()
{
  for( i = 0; i < 8; i++ )
    pinMode(i, INPUT_PULLUP );

  for( i = 0; i < 4; i++ )
    pinMode( joystick[i], INPUT_PULLUP );

}

void loop()
{
  for( i = 0; i < 8; i++ )
  {
    //if( !digitalRead( button[i] ) ) Serial.print( button_key[i] );
    //else Serial.print('x');
    if( !digitalRead( i ) ) Keyboard.press( button_key[i] );
    else Keyboard.release( button_key[i] );
  }

  for( i = 0; i < 4; i++ )
  {
    //if( !digitalRead( joystick[i] ) ) Serial.print( joystick_key[i] );
    //else Serial.print('x');
    if( !digitalRead( joystick[i] ) ) Keyboard.press( joystick_key[i] );
    else Keyboard.release( joystick_key[i] );
  }

  //Serial.println();
  
}
