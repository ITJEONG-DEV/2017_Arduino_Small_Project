#define BUZZER 3
#define LED 13
void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
}
void loop() {
  int r = rand() % 10000;

  r = r + 20;

  tone(BUZZER, r, 50); 
  delay(22);
}
