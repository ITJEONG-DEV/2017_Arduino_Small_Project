#include <MsTimer2.h>

#define CLOCK 2
#define LATCH 3
#define DATA 12

#define BC 6
#define BN 7

#define BUZZER 8

#define GL 9
#define BL 10

#define FND_D0 A0
#define FND_D1 A1
#define FND_D2 A2
#define FND_D3 A3

byte FND_FONT[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71 };

int nCount = 1;
int FND_PNTPOS;

unsigned long preTime = 0;
unsigned long curTime;

void setup()
{
  pinMode( BC, INPUT_PULLUP );
  pinMode( BN, INPUT_PULLUP );

  pinMode( BUZZER, OUTPUT );

  pinMode( CLOCK, OUTPUT );
  pinMode( LATCH, OUTPUT );
  pinMode( DATA, OUTPUT );

  for(int i = FND_D0; i<= FND_D3; i++ )
  {
    pinMode( i, OUTPUT );
    digitalWrite( i, HIGH );
  }

  //Serial.begin(9600);

  MsTimer2::set(12, outputNumber);
  MsTimer2::start();
}

void outputFND( int num )
{
  byte font = FND_FONT[num];

  digitalWrite( LATCH, LOW );
  shiftOut( DATA, CLOCK, MSBFIRST, font );
  digitalWrite( LATCH, HIGH );
}

void outputNumber()
{
  int number = nCount;
  for(int p=FND_D0; p<=FND_D3; p++)
  {
    int digit = number % 10;
    outputFND(digit);
    digitalWrite(p, LOW); // p FND ON
    delayMicroseconds(1000); // 1ms
    digitalWrite(p, HIGH); // p FND OFF
    
    number = number /10;
    if(number <= 0) break;
  }
}

//3,6,9 조건이 해당하는지 검사하는 함수
bool is3()
{
  int nN = nCount;

  while(nN>=1)
  {
    //각 자리에 3,6,9가 있는가?
    if( ( nN % 10 )% 3 == 0 && ( nN % 10 ) != 0 ) return true;
    //없으면 10으로 나누기
    else nN = nN/10;
  }

  return false;
}

// 결과에 따라 소리내기
int buzz(int n)
{
  //숫자 버튼
  if( n == 1 )
  {
    tone(BUZZER, 1200);
    delay(150);
    tone(BUZZER, 600);
    delay(150);
    noTone(BUZZER);
  }
  //박수 버튼
  else if( n == 2 )
  {
    tone(BUZZER, 600);
    delay(150);
    tone(BUZZER, 1200);
    delay(150);
    noTone(BUZZER);
  }
  //틀림 or 시간초과
  else if( n == 3 )
  {
    tone(BUZZER, 900);
    delay(150);
    noTone(BUZZER);
  }
}

//가산점부분) 맞으면 파란불, 틀리면 초록 불
bool isLED( bool c )
{
  int ob;
  //맞으면 파란 불
  if(c) ob = BL;
  //틀리면 초록 불
  else ob = GL;

  //on
  digitalWrite( ob, HIGH );
  delay(250);
  //off
  digitalWrite( ob, LOW );  
}

void loop()
{
  //Serial.print(nCount);
  //Serial.print("\n");
  FND_PNTPOS = FND_D1;
  bool BC1 = digitalRead(BC);
  bool BN1 = digitalRead(BN);

  //1.5초가 지났는지 검사
  is1500();

  //박수 버튼을 올바르게 누름
  if( !BC1 && is3() )
  {
    nCount++;
    buzz(2);
    isLED(true);
    preTime = curTime;
  }
  //숫자 버튼을 올바르게 누름
  else if( !BN1 && !is3() )
  {
    nCount++;
    buzz(1);
    isLED(true);
    preTime = curTime;
  }
  //잘못 누름
  else if( !BC1 || !BN1 )
  {
    buzz(3);
    nCount++;
    isLED(false);
    preTime = curTime;
  }
}

void is1500()
{
  curTime = millis();
  if( curTime > preTime + 1500 )
  {
    //1.5초가 지나면, 틀림처리
    nCount++;
    buzz(3);
    isLED(false);
    preTime = curTime;
  }
}
