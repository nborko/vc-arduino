// Bach multitone sketch
// by Nick Borko

// A0 -> 10k linear pot
// D2 -> piezo speaker

#include <FlexiTimer2.h>

#define VOICES 2
#define PERIOD 20000

int r = 1;
int t[] = { 0, 0 };

void doSound() {
  static byte voice = 0;
  static int voice_period = 0;
  static byte pulse = 0;
  
  if (!t[voice]) {
    byte current_voice = voice;
    PORTD &= B11111011;
    voice_period = 0;
    pulse = 0;
    while (!t[current_voice]) {
      current_voice = (current_voice + 1 < VOICES) ? current_voice + 1 : 0;
      if (current_voice == voice) {
         break;
      }
    }
    voice = current_voice;
  }
  if (t[voice]) {
    if (voice_period == 0) {
      PORTD |= B00000100;
    } else if(voice_period == (PERIOD / 2) / t[voice]) {
      PORTD &= B11111011;
    }
  }
  voice_period = (voice_period + 1 < PERIOD / t[voice]) ? voice_period + 1 : 0;
  if (voice_period == 0) {
    pulse = pulse + 1;
    if (pulse > t[voice] / r) {
      pulse = 0;
      voice = (voice + 1 < VOICES) ? voice + 1 : 0;
    }
  }
}

void setup() {
  DDRD |= B00000100;
  FlexiTimer2::set(1, 1/(float)PERIOD, doSound);
  FlexiTimer2::start();
  //pinMode(13, OUTPUT);
}

int score[][3] = {
  { 0, 82, 16 },
  { 330, 82, 16 },
  { 440, 220, 16 },
  { 523, 220, 16 },
  { 494, 220, 16 },
  { 330, 220, 16 },
  { 494, 208, 16 },
  { 587, 208, 16 },
  { 523, 220, 16 },
  { 523, 165, 16 },
  { 659, 220, 16 },
  { 659, 262, 16 },
  { 415, 247, 16 },
  { 415, 165, 16 },
  { 659, 247, 16 },
  { 659, 294, 16 },
  { 440, 262, 16 },
  { 330, 262, 16 },
  { 440, 220, 16 },
  { 523, 220, 16 },
  { 494, 208, 16 },
  { 330, 208, 16 },
  { 494, 165, 16 },
  { 587, 165, 16 },
  { 523, 220, 16 },
  { 523, 165, 16 },
  { 440, 220, 16 },
  { 440, 262, 16 },
  { 0, 247, 16 },
  { 0, 165, 16 },
  { 0, 247, 16 },
  { 0, 294, 16 },
  { 0, 262, 16 },
  { 659, 262, 16 },
  { 523, 220, 16 },
  { 659, 220, 16 },
  { 440, 262, 16 },
  { 523, 262, 16 },
  { 330, 220, 16 },
  { 392, 220, 16 },
  { 349, 294, 16 },
  { 349, 220, 16 },
  { 440, 175, 16 },
  { 440, 220, 16 },
  { 587, 147, 16 },
  { 587, 176, 16 },
  { 698, 82, 16 },
  { 698, 131, 16 },
  { 698, 123, 16 },
  { 587, 123, 16 },
  { 494, 147, 16 },
  { 587, 147, 16 },
  { 392, 165, 16 },
  { 494, 165, 16 },
  { 294, 247, 16 },
  { 349, 247, 16 },
  { 330, 247, 16 },
  { 330, 165, 16 },
  { 392, 131, 16 },
  { 392, 165, 16 },
  { 523, 110, 16 },
  { 523, 131, 16 },
  { 659, 98, 16 },
  { 659, 123, 16 },
  { 659, 110, 16 },
  { 523, 110, 16 },
  { 440, 131, 16 },
  { 523, 131, 16 },
  { 349, 147, 16 },
  { 349, 175, 16 },
  { 587, 123, 16 },
  { 587, 147, 16 },
  { 587, 98, 16 },
  { 494, 98, 16 },
  { 392, 123, 16 },
  { 494, 123, 16 },
  { 330, 131, 16 },
  { 330, 165, 16 },
  { 523, 110, 16 },
  { 523, 131, 16 },
  { 523, 87, 16 },
  { 440, 87, 16 },
  { 349, 73, 16 },
  { 440, 73, 16 },
  { 294, 98, 16 },
  { 294, 196, 16 },
  { 494, 175, 16 },
  { 494, 196, 16 },
  { 523, 131, 16 },
  { 523, 196, 16 },
  { 0, 262, 16 },
  { 0, 330, 16 },
  { 0, 294, 16 },
  { 0, 196, 16 },
  { 0, 294, 16 },
  { 0, 349, 16 },
  { -1, -1, 0 }
};

void loop() {
  boolean lit = false;
  for(int i = 0; score[i][0] > -1; i++) {
    r = max(analogRead(A0) / 6, 10);
    t[0] = score[i][0];
    t[1] = score[i][1];
    //digitalWrite(13, lit = ~lit);
    delay(4000/score[i][2]);
  }
}

/*
 This work is licensed under the Creative Commons
 Attribution-NonCommercial-ShareAlike 3.0 Unported
 License. To view a copy of this license, visit
 http://creativecommons.org/licenses/by-nc-sa/3.0/
 or send a letter to:

 Creative Commons, 444 Castro Street
 Suite 900
 Mountain View, California, 94041, USA.
*/
