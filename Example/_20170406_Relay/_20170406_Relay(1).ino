#define SW 2

void setup() {
  pinMode(SW, OUTPUT);
}
void loop() {
  // Relay NO ON
  digitalWrite(SW, HIGH);
  delay(3000);
  // Relay NC ON
  digitalWrite(SW, LOW);
  delay(3000);
}
