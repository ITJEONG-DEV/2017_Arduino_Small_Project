#include <Keyboard.h>

#define buttonL 3
#define buttonR 4
#define buttonU 5
#define buttonD 6

void setup()
{
  pinMode( buttonL, INPUT_PULLUP );
  pinMode( buttonR, INPUT_PULLUP );
  pinMode( buttonU, INPUT_PULLUP );
  pinMode( buttonD, INPUT_PULLUP );

  Keyboard.begin();
  Serial.begin(9600);
}

void loop()
{
  int vL = digitalRead( buttonL );
  int vR = digitalRead( buttonR );
  int vU = digitalRead( buttonU );
  int vD = digitalRead( buttonD );

  if( !vL ) Keyboard.press(KEY_LEFT_ARROW);
  if( !vR ) Keyboard.press(KEY_RIGHT_ARROW);
  if( !vD ) Keyboard.press(KEY_DOWN_ARROW);
  if( !vU ) Keyboard.press(KEY_UP_ARROW);
  
  Serial.print( vL );
  Serial.print( " " );
  Serial.print( vR );
  Serial.print( " " );
  Serial.print( vD );
  Serial.print( " " );
  Serial.println( vU );
  
  delay(50);
  Keyboard.releaseAll();
}
