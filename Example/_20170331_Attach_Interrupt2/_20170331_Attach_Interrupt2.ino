#define RED 2
#define LED 13
#define BUTTON 3

bool isOn = false;

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  Serial.begin(9600);

  attachInterrupt(1, button_changed, FALLING);
}

void loop()
{
  isOn = !isOn;
  digitalWrite(LED, isOn);
  delay(1000);
}

//button_changed() 약간 개조함)
bool redOn = false;
int n = 1;
void button_changed()
{
  //delayMicroseconds(100000); //10ms
  Serial.println(n++, DEC);
  redOn = !redOn;
  digitalWrite(RED, redOn);
}

