// Bach multitone sketch
// by Nick Borko

// Arduino:
// A3 -> 10k linear pot
// D9,D10 -> piezo speaker
// ATtiny85:
// Pin 2 -> 10k linear pot
// Pins 6,7 -> piezo speaker

#include <avr/pgmspace.h>
#include "pitches.h"

#define PERIOD        20000
#define BEAT          61440
#define DELAY_MILLIS  16

// uncomment for pin 13 LED diagnostic
//#define DIAG

const int score[][3] PROGMEM = {
  {       0, NOTE_E2, 16 },
  { NOTE_E4, NOTE_E2, 16 },
  { NOTE_A4, NOTE_A3, 16 },
  { NOTE_C5, NOTE_A3, 16 },
  { NOTE_B4, NOTE_A3, 16 },
  { NOTE_E4, NOTE_A3, 16 },
  { NOTE_B4, NOTE_GS3, 16 },
  { NOTE_D5, NOTE_GS3, 16 },
  { NOTE_C5, NOTE_A3, 16 },
  { NOTE_C5, NOTE_E3, 16 },
  { NOTE_E5, NOTE_A3, 16 },
  { NOTE_E5, NOTE_C4, 16 },
  { NOTE_GS4, NOTE_B3, 16 },
  { NOTE_GS4, NOTE_E3, 16 },
  { NOTE_E5, NOTE_B3, 16 },
  { NOTE_E5, NOTE_D4, 16 },
  { NOTE_A4, NOTE_C4, 16 },
  { NOTE_E4, NOTE_C4, 16 },
  { NOTE_A4, NOTE_A3, 16 },
  { NOTE_C5, NOTE_A3, 16 },
  { NOTE_B4, NOTE_GS3, 16 },
  { NOTE_E4, NOTE_GS3, 16 },
  { NOTE_B4, NOTE_E3, 16 },
  { NOTE_D5, NOTE_E3, 16 },
  { NOTE_C5, NOTE_A3, 16 },
  { NOTE_C5, NOTE_E3, 16 },
  { NOTE_A4, NOTE_A3, 16 },
  { NOTE_A4, NOTE_C4, 16 },
  {       0, NOTE_B3, 16 },
  {       0, NOTE_E3, 16 },
  {       0, NOTE_B3, 16 },
  {       0, NOTE_D4, 16 },
  {       0, NOTE_C4, 16 },
  { NOTE_E5, NOTE_C4, 16 },
  { NOTE_C5, NOTE_A3, 16 },
  { NOTE_E5, NOTE_A3, 16 },
  { NOTE_A4, NOTE_C4, 16 },
  { NOTE_C5, NOTE_C4, 16 },
  { NOTE_E4, NOTE_A3, 16 },
  { NOTE_G4, NOTE_A3, 16 },
  { NOTE_F4, NOTE_D4, 16 },
  { NOTE_F4, NOTE_A3, 16 },
  { NOTE_A4, NOTE_F3, 16 },
  { NOTE_A4, NOTE_A3, 16 },
  { NOTE_D5, NOTE_D3, 16 },
  { NOTE_D5, NOTE_F3, 16 },
  { NOTE_F5, NOTE_E2, 16 },
  { NOTE_F5, NOTE_C3, 16 },
  { NOTE_F5, NOTE_B2, 16 },
  { NOTE_D5, NOTE_B2, 16 },
  { NOTE_B4, NOTE_D3, 16 },
  { NOTE_D5, NOTE_D3, 16 },
  { NOTE_G4, NOTE_E3, 16 },
  { NOTE_B4, NOTE_E3, 16 },
  { NOTE_D4, NOTE_B3, 16 },
  { NOTE_F4, NOTE_B3, 16 },
  { NOTE_E4, NOTE_B3, 16 },
  { NOTE_E4, NOTE_E3, 16 },
  { NOTE_G4, NOTE_C3, 16 },
  { NOTE_G4, NOTE_E3, 16 },
  { NOTE_C5, NOTE_A2, 16 },
  { NOTE_C5, NOTE_C3, 16 },
  { NOTE_E5, NOTE_G2, 16 },
  { NOTE_E5, NOTE_B2, 16 },
  { NOTE_E5, NOTE_A2, 16 },
  { NOTE_C5, NOTE_A2, 16 },
  { NOTE_A4, NOTE_C3, 16 },
  { NOTE_C5, NOTE_C3, 16 },
  { NOTE_F4, NOTE_D3, 16 },
  { NOTE_F4, NOTE_F3, 16 },
  { NOTE_D5, NOTE_B2, 16 },
  { NOTE_D5, NOTE_D3, 16 },
  { NOTE_D5, NOTE_G2, 16 },
  { NOTE_B4, NOTE_G2, 16 },
  { NOTE_G4, NOTE_B2, 16 },
  { NOTE_B4, NOTE_B2, 16 },
  { NOTE_E4, NOTE_C3, 16 },
  { NOTE_E4, NOTE_E3, 16 },
  { NOTE_C5, NOTE_A2, 16 },
  { NOTE_C5, NOTE_C3, 16 },
  { NOTE_C5, NOTE_F2, 16 },
  { NOTE_A4, NOTE_F2, 16 },
  { NOTE_F4, NOTE_G2, 16 },
  { NOTE_A4, NOTE_G2, 16 },
  { NOTE_D4, NOTE_G2, 16 },
  { NOTE_D4, NOTE_G3, 16 },
  { NOTE_B4, NOTE_F3, 16 },
  { NOTE_B4, NOTE_G3, 16 },
  { NOTE_C5, NOTE_C3, 16 },
  { NOTE_C5, NOTE_G3, 16 },
  {       0, NOTE_C4, 16 },
  {       0, NOTE_E4, 16 },
  {       0, NOTE_D4, 16 },
  {       0, NOTE_G3, 16 },
  {       0, NOTE_D4, 16 },
  {       0, NOTE_F4, 16 },
  {       0, NOTE_E4, 16 },
  { NOTE_G4, NOTE_E4, 16 },
  { NOTE_C5, NOTE_C4, 16 },
  { NOTE_E5, NOTE_C4, 16 },
  { NOTE_D5, NOTE_B3, 16 },
  { NOTE_G4, NOTE_B3, 16 },
  { NOTE_D5, NOTE_G3, 16 },
  { NOTE_F5, NOTE_G3, 16 },
  { NOTE_E5, NOTE_C4, 16 },
  { NOTE_E5, NOTE_G3, 16 },
  { NOTE_G5, NOTE_C4, 16 },
  { NOTE_G5, NOTE_E4, 16 },
  { NOTE_B4, NOTE_D4, 16 },
  { NOTE_B4, NOTE_G3, 16 },
  { NOTE_G5, NOTE_D4, 16 },
  { NOTE_G5, NOTE_F4, 16 },
  { NOTE_C5, NOTE_E4, 16 },
  { NOTE_G4, NOTE_E4, 16 },
  { NOTE_C5, NOTE_C4, 16 },
  { NOTE_E5, NOTE_C4, 16 },
  { NOTE_D5,       0, 16 },
  { NOTE_G4,       0, 16 },
  { NOTE_D5,       0, 16 },
  { NOTE_F5,       0, 16 },
  { NOTE_E5,       0, 16 },
  { NOTE_E5, NOTE_G4, 16 },
  { NOTE_C5, NOTE_E4, 16 },
  { NOTE_C5, NOTE_G4, 16 },
  { NOTE_G5, NOTE_C4, 16 },
  { NOTE_G5, NOTE_E4, 16 },
  { NOTE_E5, NOTE_G3, 16 },
  { NOTE_E5, NOTE_B3, 16 },
  { NOTE_C6, NOTE_A3, 16 },
  { NOTE_A5, NOTE_A3, 16 },
  { NOTE_E5, NOTE_C4, 16 },
  { NOTE_A5, NOTE_C4, 16 },
  { NOTE_C5, NOTE_E4, 16 },
  { NOTE_E5, NOTE_E4, 16 },
  { NOTE_A4, NOTE_G4, 16 },
  { NOTE_C5, NOTE_G4, 16 },
  { NOTE_D5, NOTE_FS4, 16 },
  { NOTE_D5, NOTE_A4, 16 },
  { NOTE_FS5, NOTE_D4, 16 },
  { NOTE_FS5, NOTE_FS4, 16 },
  { NOTE_A5, NOTE_A3, 16 },
  { NOTE_A5, NOTE_D4, 16 },
  { NOTE_C6, NOTE_FS3, 16 },
  { NOTE_C6, NOTE_A3, 16 },
  { NOTE_B5, NOTE_G3, 16 },
  { NOTE_G5, NOTE_G3, 16 },
  { NOTE_D5, NOTE_B3, 16 },
  { NOTE_G5, NOTE_B3, 16 },
  { NOTE_B4, NOTE_D4, 16 },
  { NOTE_D5, NOTE_D4, 16 },
  { NOTE_G4, NOTE_FS4, 16 },
  { NOTE_B4, NOTE_FS4, 16 },
  { NOTE_C5, NOTE_E4, 16 },
  { NOTE_C5, NOTE_G4, 16 },
  { NOTE_E5, NOTE_C4, 16 },
  { NOTE_E5, NOTE_E4, 16 },
  { NOTE_G5, NOTE_G3, 16 },
  { NOTE_G5, NOTE_C4, 16 },
  { NOTE_B5, NOTE_E3, 16 },
  { NOTE_B5, NOTE_G3, 16 },
  { NOTE_A5, NOTE_FS3, 16 },
  { NOTE_FS5, NOTE_FS3, 16 },
  { NOTE_DS5, NOTE_A3, 16 },
  { NOTE_FS5, NOTE_A3, 16 },
  { NOTE_B4, NOTE_B3, 16 },
  { NOTE_DS5, NOTE_B3, 16 },
  { NOTE_FS4, NOTE_DS4, 16 },
  { NOTE_A4, NOTE_DS4, 16 },
  { NOTE_G4,       0, 16 },
  { NOTE_G4, NOTE_E4, 16 },
  { NOTE_G5, NOTE_C4, 16 },
  { NOTE_G5, NOTE_E4, 16 },
  { NOTE_G5, NOTE_A3, 16 },
  { NOTE_E5, NOTE_C4, 16 },
  { NOTE_C5, NOTE_E4, 16 },
  { NOTE_E5, NOTE_G4, 16 },
  { NOTE_A4, NOTE_FS4, 16 },
  { NOTE_A4, NOTE_D4, 16 },
  { NOTE_FS5, NOTE_B3, 16 },
  { NOTE_FS5, NOTE_D4, 16 },
  { NOTE_FS5, NOTE_G3, 16 },
  { NOTE_D5, NOTE_B3, 16 },
  { NOTE_B4, NOTE_D4, 16 },
  { NOTE_D5, NOTE_FS4, 16 },
  { NOTE_G4, NOTE_E4, 16 },
  { NOTE_G4, NOTE_C4, 16 },
  { NOTE_E5, NOTE_A3, 16 },
  { NOTE_E5, NOTE_C4, 16 },
  { NOTE_E5, NOTE_FS3, 16 },
  { NOTE_C5, NOTE_A3, 16 },
  { NOTE_A4, NOTE_C4, 16 },
  { NOTE_C5, NOTE_C4, 16 },
  { NOTE_FS4, NOTE_C4, 16 },
  { NOTE_G5, NOTE_B3, 16 },
  { NOTE_FS5, NOTE_C4, 16 },
  { NOTE_E5, NOTE_A3, 16 },
  { NOTE_DS5, NOTE_B3, 16 },
  { NOTE_FS5, NOTE_B3, 16 },
  { NOTE_B4, NOTE_B2, 16 },
  { NOTE_DS5, NOTE_B2, 16 },
  { NOTE_E5, NOTE_E3, 16 },
  { NOTE_E5, NOTE_E4, 16 },
  {       0, NOTE_B3, 16 },
  {       0, NOTE_G3, 16 },
  {       0, NOTE_E3, 16 },
  {       0, NOTE_B2, 16 },
  {       0, NOTE_G2, 16 },
  {       0, NOTE_B2, 16 },
  {       0, NOTE_E2, 4 },
  { 0, 0, 4 },
  { 0, 0, 2 },
  { -1, -1, 0 }
};

int t[] = { 0, 0, 0 };

boolean doSound(int r) {
  static byte voice = 0;
  static int voice_period = 0;
  static int pulse = 0;
  
  if (!t[voice]) {
    PORTB &= B11111001;
    voice_period = 0;
    pulse = 0;
    voice = !voice;
  }
  if (t[voice]) {
    if (voice_period == 0) {
      PORTB &= B11111101;
      PORTB |= B00000100;
    } else if(voice_period == (PERIOD / 2) / t[voice]) {
      PORTB &= B11111011;
      PORTB |= B00000010;
    }
  }
  delayMicroseconds(DELAY_MILLIS);
  voice_period = (voice_period + 1 < PERIOD / t[voice]) ? voice_period + 1 : 0;
  if (voice_period == 0) {
    if (++pulse > t[voice] / r) {
      pulse = 0;
      voice = !voice;
    }
  }
}

void setup() {
  DDRB |= B00000110;
#ifdef DIAG
  pinMode(0, OUTPUT);
#endif
}

void loop() {
#ifdef DIAG
  boolean lit = false;
#endif
  int i = 0, r = 16;
  while(++i) {
    r = analogRead(A3) / 4;
    r = r < 16 ? 16 : r;
    t[0] = pgm_read_word_near(&score[i][0]);
    if(t[0] < 0) {
      i = 0;
      t[0] = pgm_read_word_near(&score[i][0]);
    }
    t[1] = pgm_read_word_near(&score[i][1]);
#ifdef DIAG
    digitalWrite(0, lit = !lit);
#endif
    for(int j = BEAT/(pgm_read_word_near(&score[i][2])); j; j--) {
      doSound(r);
    }
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
