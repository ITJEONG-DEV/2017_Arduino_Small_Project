#define BUTTON 3
#define RED 2
#define LED 13
void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  attachInterrupt(1, button_changed, FALLING);
}

bool isOn = false;

void loop()
{
  isOn = !isOn;
  digitalWrite(LED, isOn);
  delay(1000);
}

bool redOn = false;
void button_changed()
{
  for(int i = 0; i < 50; i++)
    delayMicroseconds(10000);
  redOn = !redOn;
  digitalWrite(RED, redOn);
}

