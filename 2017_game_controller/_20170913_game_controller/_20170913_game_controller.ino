const char joystick[4] = { A0, A1, A2, A3 };
const char button_key[8] = { 'q', 'w', 'e', 'r', 'a', 's', 'd', 'f' };
const char joystick_key[4] = { KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW };

boolean button_status[8] = {};
boolean joystick_status[4] = {};

int i;

void setup()
{
  //button
  for( i = 1; i <= 8; i++ )
    pinMode( i, INPUT_PULLUP );

  //joystick
  for( i = 1; i <= 4; i++ )
    pinMode( joystick[i-1], INPUT_PULLUP );

  Keyboard.begin();
}


void loop()
{
  for( i = 1, i <= 8; i++ )
  {
    if( digitalRead(i) ) Keyboard.press( button_key[i-1] );
    else Keyboard.release( button_key[i-1] );
  }

  for( i = 1; i <= 4; i++ )
  {
    if( digitalRead(i) ) Keyboard.press( joystick_key[i-1] );
    else Keyboard.release( joystick_key[i-1] );
  } 
}
