#define BUTTON 11
#define RED 8
#define LED 13

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

unsigned long preTime = 0;
bool c = false;

void turnLED()
{
  unsigned long curTime = millis();

  if(curTime > preTime + 1000)
  {
    c = !c;
    digitalWrite(LED, c);

    preTime = curTime;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  bool b = digitalRead(BUTTON);
  
  digitalWrite(RED, !b);

  turnLED();
}
