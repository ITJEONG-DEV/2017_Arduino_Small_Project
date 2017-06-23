#include "pitches.h"

#define LED_R 1
#define LED_G 2
#define LED_B 3
#define LED_W 4
#define BUZZER 5
#define BUTTON 13

int line[5] = { 1, 2, 3, 2, 1 };
unsigned long ledTime = 0;
unsigned long curTime2;

void makeLine()
{
  for( int i = 0; i < 5; i++ )
    line[i] = rand()%4 + 1;
}

void showLine()
{
  for( int i = 0; i < 5; i++ )
  {
    turnLED(line[i]);
  }  
}

void turnLED(int object)
{
  //digitalWrite(object, HIGH);
  curTime2 = millis();  

  if( curTime2 >= ledTime+500 )
  {
    bool c = digitalRead(object);
    digitalWrite(object, !c);
    ledTime = curTime2;
  }
}

void first()
{
  makeLine();
  showLine();
}


unsigned long prevPlayTime = 0;
unsigned long noteDuration = 0;
unsigned long pauseDuration = 0;


int currentMelody = 0;

int mario_melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0, 0, NOTE_G6, 0, 0, 0,
  NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0,
  NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0,NOTE_C7, NOTE_D7, NOTE_B6, 0, 0,
  NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0,
  NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0,NOTE_C7, NOTE_D7, NOTE_B6, 0, 0
};
int mario_tempo[] = {
  12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
  12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
  9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
  12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
  9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
};
void sing(int *melody, int *tempo, int melodySize) {
  if(millis() < prevPlayTime + noteDuration + pauseDuration) { return; }
  if(currentMelody >= melodySize) currentMelody = 0;
  noteDuration = 1000/tempo[currentMelody];
  pauseDuration = noteDuration * 1.20;
  prevPlayTime = millis();
  tone(BUZZER, melody[currentMelody], noteDuration);
  currentMelody++;
}

void setup()
{
  pinMode( LED_R, OUTPUT );
  pinMode( LED_G, OUTPUT );
  pinMode( LED_B, OUTPUT );
  pinMode( LED_W, OUTPUT );
  pinMode( BUZZER, OUTPUT );
  pinMode( BUTTON, INPUT_PULLUP );
}

void loop()
{
  sing(mario_melody, mario_tempo, sizeof(mario_melody)/sizeof(int));
  first();
}
