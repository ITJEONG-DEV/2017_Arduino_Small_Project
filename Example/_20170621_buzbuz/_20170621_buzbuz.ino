#define l1 5
#define l2 6
#define l3 7

#define b1 21
#define b2 20
#define b3 19

#define buz 2

bool isClick = false;

void setup()
{
  pinMode( l1, OUTPUT );
  pinMode( l2, OUTPUT );
  pinMode( l3, OUTPUT );

  pinMode( b1, INPUT_PULLUP );
  pinMode( b2, INPUT_PULLUP );
  pinMode( b3, INPUT_PULLUP );

  pinMode( buz, OUTPUT );

  attachInterrupt( 2, onb, FALLING );
  attachInterrupt( 3, onb, FALLING );
  attachInterrupt( 4, onb, FALLING );

  Serial.begin(9600);
}

void onb()
{
  if(isClick)return;

  bool a1 = digitalRead( b1 );
  bool a2 = digitalRead( b2 );
  bool a3 = digitalRead( b3 );

  if(!a1)
  {
    isClick = true;
    digitalWrite( l1, HIGH );
    tone( buz, 220 );
  }
  if(!a2)
  {
    isClick = true;
    digitalWrite( l2, HIGH );
    tone( buz, 440 );
  }
  if(!a3)
  {
    isClick = true;
    digitalWrite( l3, HIGH );
    tone( buz, 660 );
  }
  //noTone( buz );
}
void reset()
{
  digitalWrite( l1, LOW );
  digitalWrite( l2, LOW );
  digitalWrite( l3, LOW );
  isClick = false;
}

void loop()
{
  if( isClick )
  {
    delay(500);
    noTone(buz);
    delay(3500);
    reset();
  }
}

