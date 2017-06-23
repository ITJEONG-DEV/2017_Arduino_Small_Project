int n;

void setup()
{
  Serial.begin(2400);
  Serial.println("USART Comm.");
}

void loop()
{
  Serial.print("Current n = ");
  Serial.print(n);
  Serial.print("\n");
  n++;
  delay(1000);
}
