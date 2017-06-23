int mi = 1500, ma = 0;
#define LED 10
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  int v = analogRead(A0);
  if(v<mi) mi = v;
  if(v>ma) ma = v;
  if(v>800) digitalWrite( LED, HIGH );
  else digitalWrite( LED, LOW );
  
  Serial.print("now: ");
  Serial.print(v);
  Serial.print("\tmin: ");
  Serial.print(mi);
  Serial.print("\tmax: ");
  Serial.println(ma);
}
