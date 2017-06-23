#include <Keyboard.h>
#include <Bounce2.h>

#define b1 3
#define b2 4
#define b3 5
#define b4 6

Bounce db1 = Bounce();
Bounce db2 = Bounce();
Bounce db3 = Bounce();
Bounce db4 = Bounce();

void setup()
{
  Keyboard.begin();

  pinMode( b1, INPUT_PULLUP );
  pinMode( b2, INPUT_PULLUP );
  pinMode( b3, INPUT_PULLUP );
  pinMode( b4, INPUT_PULLUP );

  db1.attach(b1);
  db1.interval(5);

  db2.attach(b2);
  db2.interval(5);

  db3.attach(b3);
  db3.interval(5);

  db4.attach(b4);
  db4.interval(5);
}

void loop()
{
  int v1 = db1.read();
  int v2 = db2.read();
  int v3 = db3.read();
  int v4 = db4.read();

  if( v1 == 0 ) Keyboard.press('d');
  if( v2 == 0 ) Keyboard.press('f');
  if( v3 == 0 ) Keyboard.press('j');
  if( v4 == 0 ) Keyboard.press('k');

  Serial.print(v1);
  Serial.print(v2);
  Serial.print(v3);
  Serial.println(v4);

  delay(50);
}
