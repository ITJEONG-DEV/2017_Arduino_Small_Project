#define BUTTON 11
#define LED 10

void setup()
{
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

void loop()
{
 bool r = digitalRead(BUTTON);
 Serial.println(r);
 delay(300);

}
  
