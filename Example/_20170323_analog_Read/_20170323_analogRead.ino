void setup() {
  Serial.begin(9600);
}

void loop() {
  //double v = analogRead(A0);
  //v = v / 1023 * 5;
  int v = analogRead(A0);
  Serial.println(v);
  //Serial.println(" V");
  delay(1000);
}
