const uint8_t gamma[] = {
  0, 0, 0, 0, 1, 1, 1, 2, 3, 4, 4, 5, 7, 8, 9, 11,
  13, 14, 16, 18, 20, 23, 25, 28, 31, 33, 36, 40, 43, 46, 50, 54,
  57, 61, 66, 70, 74, 79, 84, 89, 94, 99, 105, 110, 116, 122, 128, 134,
  140, 147, 153, 160, 167, 174, 182, 189, 197, 205, 213, 221, 229, 238, 246, 255
};

#define LED 3
void setup() {
  pinMode(3, OUTPUT);
}

void loop() {
  int i;
  //fade in
  for(i=0; i<64; i++)
  {
    //int b = i*4;
    int c = gamma[i];
    analogWrite(LED, c);
    delay(30);
  }
  //fade out
  for(i=64; i>0; i-=1)
  {
    //int b = i * 4;
    int c = gamma[i];
    analogWrite(LED, c);
    delay(30);
  }
}
