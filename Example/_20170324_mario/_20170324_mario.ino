#include "pitches.h"
#define melodyPin 3
unsigned long prevPlayTime = 0;
unsigned long playDuration = 0;
int currentMelody = 0;
//Mario main theme melody
int melodySize = 75;
int melody[] = {
  NOTE_E7, NOTE_E7,   0,     NOTE_E7,     0,    NOTE_C7,  NOTE_E7,    0,
  NOTE_G7,    0,      0,        0,    NOTE_G6,     0,        0,       0,
  NOTE_C7,    0,      0,     NOTE_G6,     0,       0,     NOTE_E6,    0,
     0,    NOTE_A6,   0,     NOTE_B6,     0,    NOTE_AS6, NOTE_A6,    0,
  NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7,     0,    NOTE_F7,  NOTE_G7,    0,
  NOTE_E7,    0,    NOTE_C7, NOTE_D7, NOTE_B6,     0,        0,    NOTE_C7,
     0,       0,    NOTE_G6,    0,        0,     NOTE_E6,    0,       0,    
  NOTE_A6,    0,    NOTE_B6,    0,    NOTE_AS6,  NOTE_A6,    0,    NOTE_G6,
  NOTE_E7, NOTE_G7, NOTE_A7,    0,    NOTE_F7,   NOTE_G7,    0,    NOTE_E7,
     0,    NOTE_C7, NOTE_D7, NOTE_B6,    0,        0,     NOTE_C7,    0,
  NOTE_G6, 
};
//Mario main them tempo
int tempo[] = {
12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
 9,  9,  9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
 9,  9,  9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12
};
//Underworld melody
int underworld_melody[] = {
NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
NOTE_AS3, NOTE_AS4, 0, 0,
NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
NOTE_AS3, NOTE_AS4, 0, 0,
NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
NOTE_DS3, NOTE_DS4, 0, 0,
NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
NOTE_DS3, NOTE_DS4, 0,
0, NOTE_DS4, NOTE_CS4, NOTE_D4,
NOTE_CS4, NOTE_DS4,
NOTE_DS4, NOTE_GS3,
NOTE_G3, NOTE_CS4,
NOTE_C4, NOTE_FS4,NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
NOTE_GS4, NOTE_DS4, NOTE_B3,
NOTE_AS3, NOTE_A3, NOTE_GS3,
0, 0, 0
};
//Underwolrd tempo
int underworld_tempo[] = {
12, 12, 12, 12, 12, 12, 6, 3,
12, 12, 12, 12, 12, 12, 6, 3,
12, 12, 12, 12, 12, 12, 6, 3,
12, 12, 12, 12, 12, 12, 6,
6, 18, 18, 18, 6, 6, 6, 6, 6, 6,
18, 18, 18,18, 18, 18,
10, 10, 10, 10, 10, 10, 3, 3, 3
};

int jingleSong[ ] = { 
 NOTE_G4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_G4, 0, // 솔미레도솔(쉼표)
 NOTE_G4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A4, 0, // 솔미레도라(쉼표)
 NOTE_A4, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_B4, 0, // 라파미레시(쉼표)
 NOTE_G5, NOTE_G5, NOTE_F5, NOTE_D5, NOTE_E5, NOTE_C5, 0  // 솔솔파레미도(쉼표)
};

// 징글벨 첫 소절 연주시간
int jingleTime[ ] = {
 250, 250, 250, 250, 750, 250, // 8분음표 = 250ms
 250, 250, 250, 250, 750, 250,
 250, 250, 250, 250, 750, 250,
 250, 250, 250, 250, 500, 250, 250
 };



void sing() {
if(millis() < prevPlayTime + playDuration) {
// music is playing. do nothing
return;
}
// stop the tone playing:
noTone(8);
if(currentMelody >= melodySize)
currentMelody = 0;
// to calculate the note duration, take one second
// divided by the note type.
//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
int noteDuration = 1000/underworld_tempo[currentMelody];
tone(melodyPin, underworld_melody[currentMelody], noteDuration);
prevPlayTime = millis();
playDuration = noteDuration * 1.30;
currentMelody++;
}
void setup() {
pinMode(melodyPin, OUTPUT);
}
void loop() {
// Do what you want
// play music
sing();
}
