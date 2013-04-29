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
#define DELAY_MICROS  16

//#define USE_EFX

#ifdef USE_EFX
#define EFX_GLISS B01000000
#define EFX_VOICE1    B00000000
#define EFX_VOICE2    B00100000
#endif
// uncomment for LED diagnostic
//#define DIAG 0

typedef struct Note {
  byte effect;
  int voice1;
  int voice2;
  byte duration;
} Note;

const Note score[] PROGMEM = {
  { 0,       0, NOTE_E2, 16 },
  { 0, NOTE_E4, NOTE_E2, 16 },
  { 0, NOTE_A4, NOTE_A3, 16 },
  { 0, NOTE_C5, NOTE_A3, 16 },
  { 0, NOTE_B4, NOTE_A3, 16 },
  { 0, NOTE_E4, NOTE_A3, 16 },
  { 0, NOTE_B4, NOTE_GS3, 16 },
  { 0, NOTE_D5, NOTE_GS3, 16 },
  { 0, NOTE_C5, NOTE_A3, 16 },
  { 0, NOTE_C5, NOTE_E3, 16 },
  { 0, NOTE_E5, NOTE_A3, 16 },
  { 0, NOTE_E5, NOTE_C4, 16 },
  { 0, NOTE_GS4, NOTE_B3, 16 },
  { 0, NOTE_GS4, NOTE_E3, 16 },
  { 0, NOTE_E5, NOTE_B3, 16 },
  { 0, NOTE_E5, NOTE_D4, 16 },
  { 0, NOTE_A4, NOTE_C4, 16 },
  { 0, NOTE_E4, NOTE_C4, 16 },
  { 0, NOTE_A4, NOTE_A3, 16 },
  { 0, NOTE_C5, NOTE_A3, 16 },
  { 0, NOTE_B4, NOTE_GS3, 16 },
  { 0, NOTE_E4, NOTE_GS3, 16 },
  { 0, NOTE_B4, NOTE_E3, 16 },
  { 0, NOTE_D5, NOTE_E3, 16 },
  { 0, NOTE_C5, NOTE_A3, 16 },
  { 0, NOTE_C5, NOTE_E3, 16 },
  { 0, NOTE_A4, NOTE_A3, 16 },
  { 0, NOTE_A4, NOTE_C4, 16 },
  { 0,       0, NOTE_B3, 16 },
  { 0,       0, NOTE_E3, 16 },
  { 0,       0, NOTE_B3, 16 },
  { 0,       0, NOTE_D4, 16 },
  { 0,       0, NOTE_C4, 16 },
  { 0, NOTE_E5, NOTE_C4, 16 },
  { 0, NOTE_C5, NOTE_A3, 16 },
  { 0, NOTE_E5, NOTE_A3, 16 },
  { 0, NOTE_A4, NOTE_C4, 16 },
  { 0, NOTE_C5, NOTE_C4, 16 },
  { 0, NOTE_E4, NOTE_A3, 16 },
  { 0, NOTE_G4, NOTE_A3, 16 },
  { 0, NOTE_F4, NOTE_D4, 16 },
  { 0, NOTE_F4, NOTE_A3, 16 },
  { 0, NOTE_A4, NOTE_F3, 16 },
  { 0, NOTE_A4, NOTE_A3, 16 },
  { 0, NOTE_D5, NOTE_D3, 16 },
  { 0, NOTE_D5, NOTE_F3, 16 },
  { 0, NOTE_F5, NOTE_E2, 16 },
  { 0, NOTE_F5, NOTE_C3, 16 },
  { 0, NOTE_F5, NOTE_B2, 16 },
  { 0, NOTE_D5, NOTE_B2, 16 },
  { 0, NOTE_B4, NOTE_D3, 16 },
  { 0, NOTE_D5, NOTE_D3, 16 },
  { 0, NOTE_G4, NOTE_E3, 16 },
  { 0, NOTE_B4, NOTE_E3, 16 },
  { 0, NOTE_D4, NOTE_B3, 16 },
  { 0, NOTE_F4, NOTE_B3, 16 },
  { 0, NOTE_E4, NOTE_B3, 16 },
  { 0, NOTE_E4, NOTE_E3, 16 },
  { 0, NOTE_G4, NOTE_C3, 16 },
  { 0, NOTE_G4, NOTE_E3, 16 },
  { 0, NOTE_C5, NOTE_A2, 16 },
  { 0, NOTE_C5, NOTE_C3, 16 },
  { 0, NOTE_E5, NOTE_G2, 16 },
  { 0, NOTE_E5, NOTE_B2, 16 },
  { 0, NOTE_E5, NOTE_A2, 16 },
  { 0, NOTE_C5, NOTE_A2, 16 },
  { 0, NOTE_A4, NOTE_C3, 16 },
  { 0, NOTE_C5, NOTE_C3, 16 },
  { 0, NOTE_F4, NOTE_D3, 16 },
  { 0, NOTE_F4, NOTE_F3, 16 },
  { 0, NOTE_D5, NOTE_B2, 16 },
  { 0, NOTE_D5, NOTE_D3, 16 },
  { 0, NOTE_D5, NOTE_G2, 16 },
  { 0, NOTE_B4, NOTE_G2, 16 },
  { 0, NOTE_G4, NOTE_B2, 16 },
  { 0, NOTE_B4, NOTE_B2, 16 },
  { 0, NOTE_E4, NOTE_C3, 16 },
  { 0, NOTE_E4, NOTE_E3, 16 },
  { 0, NOTE_C5, NOTE_A2, 16 },
  { 0, NOTE_C5, NOTE_C3, 16 },
  { 0, NOTE_C5, NOTE_F2, 16 },
  { 0, NOTE_A4, NOTE_F2, 16 },
  { 0, NOTE_F4, NOTE_G2, 16 },
  { 0, NOTE_A4, NOTE_G2, 16 },
  { 0, NOTE_D4, NOTE_G2, 16 },
  { 0, NOTE_D4, NOTE_G3, 16 },
  { 0, NOTE_B4, NOTE_F3, 16 },
  { 0, NOTE_B4, NOTE_G3, 16 },
  { 0, NOTE_C5, NOTE_C3, 16 },
  { 0, NOTE_C5, NOTE_G3, 16 },
  { 0,       0, NOTE_C4, 16 },
  { 0,       0, NOTE_E4, 16 },
  { 0,       0, NOTE_D4, 16 },
  { 0,       0, NOTE_G3, 16 },
  { 0,       0, NOTE_D4, 16 },
  { 0,       0, NOTE_F4, 16 },
  { 0,       0, NOTE_E4, 16 },
  { 0, NOTE_G4, NOTE_E4, 16 },
  { 0, NOTE_C5, NOTE_C4, 16 },
  { 0, NOTE_E5, NOTE_C4, 16 },
  { 0, NOTE_D5, NOTE_B3, 16 },
  { 0, NOTE_G4, NOTE_B3, 16 },
  { 0, NOTE_D5, NOTE_G3, 16 },
  { 0, NOTE_F5, NOTE_G3, 16 },
  { 0, NOTE_E5, NOTE_C4, 16 },
  { 0, NOTE_E5, NOTE_G3, 16 },
  { 0, NOTE_G5, NOTE_C4, 16 },
  { 0, NOTE_G5, NOTE_E4, 16 },
  { 0, NOTE_B4, NOTE_D4, 16 },
  { 0, NOTE_B4, NOTE_G3, 16 },
  { 0, NOTE_G5, NOTE_D4, 16 },
  { 0, NOTE_G5, NOTE_F4, 16 },
  { 0, NOTE_C5, NOTE_E4, 16 },
  { 0, NOTE_G4, NOTE_E4, 16 },
  { 0, NOTE_C5, NOTE_C4, 16 },
  { 0, NOTE_E5, NOTE_C4, 16 },
  { 0, NOTE_D5,       0, 16 },
  { 0, NOTE_G4,       0, 16 },
  { 0, NOTE_D5,       0, 16 },
  { 0, NOTE_F5,       0, 16 },
  { 0, NOTE_E5,       0, 16 },
  { 0, NOTE_E5, NOTE_G4, 16 },
  { 0, NOTE_C5, NOTE_E4, 16 },
  { 0, NOTE_C5, NOTE_G4, 16 },
  { 0, NOTE_G5, NOTE_C4, 16 },
  { 0, NOTE_G5, NOTE_E4, 16 },
  { 0, NOTE_E5, NOTE_G3, 16 },
  { 0, NOTE_E5, NOTE_B3, 16 },
  { 0, NOTE_C6, NOTE_A3, 16 },
  { 0, NOTE_A5, NOTE_A3, 16 },
  { 0, NOTE_E5, NOTE_C4, 16 },
  { 0, NOTE_A5, NOTE_C4, 16 },
  { 0, NOTE_C5, NOTE_E4, 16 },
  { 0, NOTE_E5, NOTE_E4, 16 },
  { 0, NOTE_A4, NOTE_G4, 16 },
  { 0, NOTE_C5, NOTE_G4, 16 },
  { 0, NOTE_D5, NOTE_FS4, 16 },
  { 0, NOTE_D5, NOTE_A4, 16 },
  { 0, NOTE_FS5, NOTE_D4, 16 },
  { 0, NOTE_FS5, NOTE_FS4, 16 },
  { 0, NOTE_A5, NOTE_A3, 16 },
  { 0, NOTE_A5, NOTE_D4, 16 },
  { 0, NOTE_C6, NOTE_FS3, 16 },
  { 0, NOTE_C6, NOTE_A3, 16 },
  { 0, NOTE_B5, NOTE_G3, 16 },
  { 0, NOTE_G5, NOTE_G3, 16 },
  { 0, NOTE_D5, NOTE_B3, 16 },
  { 0, NOTE_G5, NOTE_B3, 16 },
  { 0, NOTE_B4, NOTE_D4, 16 },
  { 0, NOTE_D5, NOTE_D4, 16 },
  { 0, NOTE_G4, NOTE_FS4, 16 },
  { 0, NOTE_B4, NOTE_FS4, 16 },
  { 0, NOTE_C5, NOTE_E4, 16 },
  { 0, NOTE_C5, NOTE_G4, 16 },
  { 0, NOTE_E5, NOTE_C4, 16 },
  { 0, NOTE_E5, NOTE_E4, 16 },
  { 0, NOTE_G5, NOTE_G3, 16 },
  { 0, NOTE_G5, NOTE_C4, 16 },
  { 0, NOTE_B5, NOTE_E3, 16 },
  { 0, NOTE_B5, NOTE_G3, 16 },
  { 0, NOTE_A5, NOTE_FS3, 16 },
  { 0, NOTE_FS5, NOTE_FS3, 16 },
  { 0, NOTE_DS5, NOTE_A3, 16 },
  { 0, NOTE_FS5, NOTE_A3, 16 },
  { 0, NOTE_B4, NOTE_B3, 16 },
  { 0, NOTE_DS5, NOTE_B3, 16 },
  { 0, NOTE_FS4, NOTE_DS4, 16 },
  { 0, NOTE_A4, NOTE_DS4, 16 },
  { 0, NOTE_G4,       0, 16 },
  { 0, NOTE_G4, NOTE_E4, 16 },
  { 0, NOTE_G5, NOTE_C4, 16 },
  { 0, NOTE_G5, NOTE_E4, 16 },
  { 0, NOTE_G5, NOTE_A3, 16 },
  { 0, NOTE_E5, NOTE_C4, 16 },
  { 0, NOTE_C5, NOTE_E4, 16 },
  { 0, NOTE_E5, NOTE_G4, 16 },
  { 0, NOTE_A4, NOTE_FS4, 16 },
  { 0, NOTE_A4, NOTE_D4, 16 },
  { 0, NOTE_FS5, NOTE_B3, 16 },
  { 0, NOTE_FS5, NOTE_D4, 16 },
  { 0, NOTE_FS5, NOTE_G3, 16 },
  { 0, NOTE_D5, NOTE_B3, 16 },
  { 0, NOTE_B4, NOTE_D4, 16 },
  { 0, NOTE_D5, NOTE_FS4, 16 },
  { 0, NOTE_G4, NOTE_E4, 16 },
  { 0, NOTE_G4, NOTE_C4, 16 },
  { 0, NOTE_E5, NOTE_A3, 16 },
  { 0, NOTE_E5, NOTE_C4, 16 },
  { 0, NOTE_E5, NOTE_FS3, 16 },
  { 0, NOTE_C5, NOTE_A3, 16 },
  { 0, NOTE_A4, NOTE_C4, 16 },
  { 0, NOTE_C5, NOTE_C4, 16 },
  { 0, NOTE_FS4, NOTE_C4, 16 },
  { 0, NOTE_G5, NOTE_B3, 16 },
  { 0, NOTE_FS5, NOTE_C4, 16 },
  { 0, NOTE_E5, NOTE_A3, 16 },
  { 0, NOTE_DS5, NOTE_B3, 16 },
  { 0, NOTE_FS5, NOTE_B3, 16 },
  { 0, NOTE_B4, NOTE_B2, 16 },
  { 0, NOTE_DS5, NOTE_B2, 16 },
  { 0, NOTE_E5, NOTE_E3, 16 },
  { 0, NOTE_E5, NOTE_E4, 16 },
  { 0,       0, NOTE_B3, 16 },
  { 0,       0, NOTE_G3, 16 },
  { 0,       0, NOTE_E3, 16 },
  { 0,       0, NOTE_B2, 16 },
  { 0,       0, NOTE_G2, 16 },
  { 0,       0, NOTE_B2, 16 },
  { 0,       0, NOTE_E2, 4 },
  { 0, 0, 0, 4 },
  { 0, 0, 0, 2 },
  { 0, -1, -1, 0 }
};

int t[] = { 0, 0 };
int tp[] = { 0, 0 };

#ifdef USE_EFX
boolean doSound(byte efx, int r) {
#else
boolean doSound(int r) {
#endif
  static byte voice = 0;
  static int voice_period = 0;
  static int pulse = 0;
  int f;
  
  if (!t[voice]) {
    PORTB &= B11111001;
    voice_period = 0;
    pulse = 0;
    voice = !voice;
  }
#ifdef USE_EFX
  boolean g = (efx & EFX_GLISS) && (efx & (voice << 5) == voice ) && (tp[voice] != t[voice]);
  f =  g ? tp[voice] : t[voice];
#else
  f = t[voice];
#endif
  if (f) {
    if (voice_period == 0) {
      PORTB &= B11111101;
      PORTB |= B00000100;
    } else if(voice_period == (PERIOD / 2) / f) {
      PORTB &= B11111011;
      PORTB |= B00000010;
    }
  }
  delayMicroseconds(DELAY_MICROS);
  voice_period = (voice_period + 1 < PERIOD / f) ? voice_period + 1 : 0;
  if (voice_period == 0) {
#ifdef USE_EFX
    if(g) tp[voice] = tp[voice] != t[voice] ? (tp[voice] < t[voice] ? min(t[voice], tp[voice] + (efx & B00111111)) : max(t[voice], tp[voice] - (efx & B00111111))) : t[voice];
#endif
    if (++pulse > f / r) {
      pulse = 0;
      voice = !voice;
    }
  }
}

void setup() {
  DDRB |= B00000110;
#ifdef DIAG
  pinMode(DIAG, OUTPUT);
#endif
}

void loop() {
#ifdef DIAG
  boolean lit = false;
#endif
  int i = 0, r = 16;
#ifdef USE_EFX
  byte effect;
#endif
  byte duration;
  while(++i) {
    r = analogRead(A3) / 4;
    r = r < 16 ? 16 : r;
    tp[0] = t[0]; tp[1] = t[1];
    t[0] = pgm_read_word(&score[i].voice1);
    if(t[0] < 0) {
      break;
    }
#ifdef USE_EFX
    effect = pgm_read_byte(&score[i].effect);
#endif
    t[1] = pgm_read_word(&score[i].voice2);
    duration = pgm_read_byte(&score[i].duration);
#ifdef DIAG
    digitalWrite(DIAG, lit = !lit);
#endif
    for(int j = BEAT/duration; j; j--) {
#ifdef USE_EFX
      doSound(effect, r);
#else
      doSound(r);
#endif
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
