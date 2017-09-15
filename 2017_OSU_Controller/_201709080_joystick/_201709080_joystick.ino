#include <Keyboard.h>

/*
#define U A3
#define D A4
#define L A2
#define R A1
*/
#define U 2
#define D 0
#define L 1
#define R 3
#define S 6
#define DELAY 50

// OSU : DELAY 50
// NORMAL : DELAY 250
// U D
// D K
// L J
// R F

void setup()
{
  pinMode( U, INPUT_PULLUP );       
  pinMode( D, INPUT_PULLUP );
  pinMode( L, INPUT_PULLUP );
  pinMode( R, INPUT_PULLUP );
  //pinMode( S, INPUT_PULLUP );

  Serial.begin(9600);
}

void loop()
{
  int UU = digitalRead( U );
  int DD = digitalRead( D );
  int LL = digitalRead( L );
  int RR = digitalRead( R );
  //int SS = digitalRead( S );

  //dfjk

  if( !UU )
  {
    // Keyboard.press( KEY_UP_ARROW );
    Keyboard.press('d');
  } else Keyboard.release('d');
  if( !DD )
  {
    //Keyboard.press( KEY_DOWN_ARROW );
    Keyboard.press('k');
  } else Keyboard.release('k');
  if( !LL )
  {
    //Keyboard.press( KEY_LEFT_ARROW );
    Keyboard.press('j');
  } else Keyboard.release('j');
  if( !RR )
  { //d
   //Keyboard.press( KEY_RIGHT_ARROW );
   Keyboard.press('f');
  } else Keyboard.release('f');
  //if( !SS ) Keyboard.press( 32 );
  //else Keyboard.release( 32 );

  Serial.print("UP : ");
  Serial.print(UU);
  Serial.print("  DOWN : ");
  Serial.print(DD);
  Serial.print("  LEFT : ");
  Serial.print(LL);
  Serial.print("  RIGHT : ");
  Serial.println(RR);
  //Serial.print("  SPACE : ");
  //Serial.println(SS);
  delay(DELAY);
  //Keyboard.releaseAll();
}
