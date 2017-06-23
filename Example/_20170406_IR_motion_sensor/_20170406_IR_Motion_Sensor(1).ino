#define FND_A 4
#define FND_B 5
#define FND_C 6
#define FND_D 7
#define FND_E 8
#define FND_F 9
#define FND_G 10
#define FND_DP 11
unsigned char FND_FONT[]
= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
0x7F, 0x67, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71 };
void setup() {
for(int i=FND_A; i<=FND_DP; i++)
pinMode(i, OUTPUT);
}void outputFND(int num, bool dot) {
int maskbit = 0x1;
int font = FND_FONT[num] | (dot<<7);
for(int i=FND_A; i<=FND_DP; i++) {
if((font & maskbit) != 0)
digitalWrite(i, HIGH);
else
digitalWrite(i, LOW);
maskbit = maskbit << 1;
}
}
bool dot = false;
void loop() {
for(int num=0x0; num<=0xF; num++) {
outputFND(num, dot);
delay(1000);
}
dot = !dot;
}
