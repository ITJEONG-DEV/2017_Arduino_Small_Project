#define BUTTON 11
#define LED 10
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  bool b = digitalRead(BUTTON);
  if(b==0) { digitalWrite(LED, HIGH); }
  else { digitalWrite(LED, LOW); }
}
