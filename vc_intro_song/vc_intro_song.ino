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
#define BEAT          37440  // 125BPM (or there abouts)
#define DELAY_MICROS  16

#define USE_EFX        true

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
  /*
  // This is without properly transposing (GB is up 4 semitones so it starts on Em, not Cm)
  // Arp Chords for first part
  // 1
  { 0 ,	 NOTE_E4 , NOTE_B4  , 1 },
  { 0 ,	 NOTE_E4 , NOTE_B4  , 1 },
  { 0 ,	 NOTE_G4 , NOTE_D4  , 1 },
  { 0 ,	 NOTE_A4 , NOTE_E4  , 1 },
  // 2
  { 0 ,	 NOTE_B3 , NOTE_E4  , 1 },
  { 0 ,	 NOTE_B3 , NOTE_E4  , 1 },
  { 0 ,	 NOTE_G4 , NOTE_D4  , 1 },
  { 0 ,	 NOTE_A4 , NOTE_E4  , 1 },

  // Slow Melody with bass
  // 1a
  { 0 ,	 NOTE_B5  , NOTE_E3  , 2 },
  { 0 ,	 NOTE_G5  , NOTE_E3  , 2 },
  { 0 ,	 NOTE_A5  , NOTE_E3  , 2 },
  { 0 ,	 NOTE_E5  , NOTE_E3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_E3  , 4 },
  // 1b
  { 0 ,	 NOTE_B5  , NOTE_G3  , 2 },
  { 0 ,	 NOTE_G5  , NOTE_G3  , 2 },
  { 0 ,	 NOTE_A5  , NOTE_A3  , 2 },
  { 0 ,	 NOTE_E5  , NOTE_A3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_A3  , 4 },
  // 1c
  { 0 ,	 NOTE_B5  , NOTE_E3  , 2 },
  { 0 ,	 NOTE_G5  , NOTE_E3  , 2 },
  { 0 ,	 NOTE_A5  , NOTE_E3  , 2 },
  { 0 ,	 NOTE_E5  , NOTE_E3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_E3  , 4 },
  // 1d
  { 0 ,	 NOTE_B5  , NOTE_G3  , 2 },
  { 0 ,	 NOTE_G5  , NOTE_G3  , 2 },
  { 0 ,	 NOTE_A5  , NOTE_A3  , 2 },
  { 0 ,	 NOTE_E5  , NOTE_A3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_A3  , 4 },
  // 2a
  { 0 ,	 NOTE_B5  , NOTE_E3  , 2 },
  { 0 ,	 NOTE_G5  , NOTE_E3  , 2 },
  { 0 ,	 NOTE_A5  , NOTE_E3  , 2 },
  { 0 ,	 NOTE_E5  , NOTE_E3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_E3  , 4 },
  // 2b
  { 0 ,	 NOTE_B5  , NOTE_G3  , 2 },
  { 0 ,	 NOTE_G5  , NOTE_G3  , 2 },
  { 0 ,	 NOTE_A5  , NOTE_A3  , 2 },
  { 0 ,	 NOTE_E5  , NOTE_A3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_A3  , 4 },
  // 2c
  { 0 ,	 NOTE_B5  , NOTE_E3  , 2 },
  { 0 ,	 NOTE_G5  , NOTE_E3  , 2 },
  { 0 ,	 NOTE_A5  , NOTE_E3  , 2 },
  { 0 ,	 NOTE_E5  , NOTE_E3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_E3  , 4 },
  // 2d
  { 0 ,	 NOTE_B5  , NOTE_G3  , 2 },
  { 0 ,	 NOTE_G5  , NOTE_G3  , 2 },
  { 0 ,	 NOTE_A5  , NOTE_A3  , 2 },
  { 0 ,	 NOTE_E5  , NOTE_A3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_A3  , 4 },

  //Faster Melody with Bass
  //1a
  { 0 ,	 NOTE_B5  , NOTE_E3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_E4  , 4 },  
  { 0 ,	 NOTE_G5  , NOTE_E3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_E4  , 4 },
  //1b
  { 0 ,	 NOTE_A5  , NOTE_E3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_E4  , 4 },
  { 0 ,	 NOTE_E5  , NOTE_E3  , 8 },
  { 0 ,	 NOTE_D5  , NOTE_E3  , 8 },
  { 0 ,	 NOTE_B4  , NOTE_E3  , 8 },
  { 0 ,	 NOTE_D5  , NOTE_E3  , 8 },
  //1c (same as 1a)
  { 0 ,	 NOTE_B5  , NOTE_E3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_E4  , 4 },  
  { 0 ,	 NOTE_G5  , NOTE_E3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_E4  , 4 },
  //1d
  { 0 ,	 NOTE_A5  , NOTE_E3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_E4  , 4 },
  { 0 ,	 NOTE_E5  , NOTE_E3  , 8 },
  { 0 ,	 NOTE_D5  , NOTE_E3  , 8 },
  { 0 ,	 NOTE_G5  , NOTE_E3  , 8 },
  { 0 ,	 NOTE_FS5 , NOTE_E3  , 8 },
  //2a
  { 0 ,	 NOTE_B5  , NOTE_E3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_E4  , 4 },  
  { 0 ,	 NOTE_G5  , NOTE_E3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_E4  , 4 },
  //2b
  { 0 ,	 NOTE_A5  , NOTE_E3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_E4  , 4 },
  { 0 ,	 NOTE_E5  , NOTE_E3  , 8 },
  { 0 ,	 NOTE_D5  , NOTE_E3  , 8 },
  { 0 ,	 NOTE_B4  , NOTE_E3  , 8 },
  { 0 ,	 NOTE_D5  , NOTE_E3  , 8 },
  //2c (same as 2a)
  { 0 ,	 NOTE_B5  , NOTE_E3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_E4  , 4 },  
  { 0 ,	 NOTE_G5  , NOTE_E3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_E4  , 4 },
  //2d
  { 0 ,	 NOTE_A5  , NOTE_E3  , 4 },
  { 0 ,	 NOTE_D5  , NOTE_E4  , 4 },
  { 0 ,	 NOTE_E5  , NOTE_E3  , 8 },
  { 0 ,	 NOTE_D5  , NOTE_E3  , 8 },
  { 0 ,	 NOTE_G5  , NOTE_E3  , 8 },
  { 0 ,	 NOTE_FS5 , NOTE_E3  , 8 },

*/ 
  // Fast Melody No Bass
  //1a
  { EFX_GLISS | EFX_VOICE1 | ,	 NOTE_B5  , 0        , 8 },
  { EFX_GLISS | EFX_VOICE1 | 1,	 NOTE_B4  , 0        , 8 },
  { EFX_GLISS | EFX_VOICE1 | 1,	 NOTE_D5  , 0        , 8 },  
  { EFX_GLISS | EFX_VOICE1 | 1, NOTE_D4  , 0        , 8 },  
  { EFX_GLISS | EFX_VOICE1 | 1, NOTE_G5  , 0        , 8 },
  { EFX_GLISS | EFX_VOICE1 | 1, NOTE_G4  , 0        , 8 },
  { EFX_GLISS | EFX_VOICE1 | 1,NOTE_D5  , 0        , 8 },
  { EFX_GLISS | EFX_VOICE1 | 1,NOTE_D4  , 0        , 8 },
  
  /*
  //1b
  { 0 ,	 NOTE_A5  , 0        , 8 },
  { 0 ,	 NOTE_A4  , 0        , 8 },
  { 0 ,	 NOTE_D4  , 0        , 8 },
  { 0 ,	 NOTE_D3  , 0        , 8 },
  { 0 ,	 NOTE_E5  , 0        , 8 },
  { 0 ,	 NOTE_D5  , 0        , 8 },
  { 0 ,	 NOTE_B4  , 0        , 8 },
  { 0 ,	 NOTE_D5  , 0        , 8 },
  //1c (same as 1a)
  { 0 ,	 NOTE_B5  , 0        , 8 },
  { 0 ,	 NOTE_B4  , 0        , 8 },
  { 0 ,	 NOTE_D5  , 0        , 8 },  
  { 0 ,	 NOTE_D4  , 0        , 8 },  
  { 0 ,	 NOTE_G5  , 0        , 8 },
  { 0 ,	 NOTE_G4  , 0        , 8 },
  { 0 ,	 NOTE_D5  , 0        , 8 },
  { 0 ,	 NOTE_D4  , 0        , 8 },
  //1d
  { 0 ,	 NOTE_A5  , 0        , 8 },
  { 0 ,	 NOTE_A4  , 0        , 8 },
  { 0 ,	 NOTE_D4  , 0        , 8 },
  { 0 ,	 NOTE_D3  , 0        , 8 },
  { 0 ,	 NOTE_E5  , 0        , 8 },
  { 0 ,	 NOTE_D5  , 0        , 8 },
  { 0 ,	 NOTE_G5  , 0        , 8 },
  { 0 ,	 NOTE_FS5 , 0        , 8 },
  //2a
  { 0 ,	 NOTE_B5  , 0        , 8 },
  { 0 ,	 NOTE_B4  , 0        , 8 },
  { 0 ,	 NOTE_D5  , 0        , 8 },  
  { 0 ,	 NOTE_D4  , 0        , 8 },  
  { 0 ,	 NOTE_G5  , 0        , 8 },
  { 0 ,	 NOTE_G4  , 0        , 8 },
  { 0 ,	 NOTE_D5  , 0        , 8 },
  { 0 ,	 NOTE_D4  , 0        , 8 },
  //2b  
  { 0 ,	 NOTE_A5  , 0        , 8 },
  { 0 ,	 NOTE_A4  , 0        , 8 },
  { 0 ,	 NOTE_D4  , 0        , 8 },
  { 0 ,	 NOTE_D3  , 0        , 8 },
  { 0 ,	 NOTE_E5  , 0        , 8 },
  { 0 ,	 NOTE_D5  , 0        , 8 },
  { 0 ,	 NOTE_B4  , 0        , 8 },
  { 0 ,	 NOTE_D5  , 0        , 8 },
  //2c (same as 2a)
  { 0 ,	 NOTE_B5  , 0        , 8 },
  { 0 ,	 NOTE_B4  , 0        , 8 },
  { 0 ,	 NOTE_D5  , 0        , 8 },  
  { 0 ,	 NOTE_D4  , 0        , 8 },  
  { 0 ,	 NOTE_G5  , 0        , 8 },
  { 0 ,	 NOTE_G4  , 0        , 8 },
  { 0 ,	 NOTE_D5  , 0        , 8 },
  { 0 ,	 NOTE_D4  , 0        , 8 },
  //2d
  { 0 ,	 NOTE_A5  , 0        , 8 },
  { 0 ,	 NOTE_A4  , 0        , 8 },
  { 0 ,	 NOTE_D4  , 0        , 8 },
  { 0 ,	 NOTE_D3  , 0        , 8 },
  { 0 ,	 NOTE_E5  , 0        , 8 },
  { 0 ,	 NOTE_D5  , 0        , 8 },
  { 0 ,	 NOTE_G5  , 0        , 8 },
  { 0 ,	 NOTE_FS5 , 0        , 8 },

  // Arp Melody No Bass
  //1a
  { 0 ,	 NOTE_B5  , 0      , 16 },
  { 0 ,	 NOTE_B3  , 0      , 16 },
  { 0 ,	 NOTE_B4  , 0      , 16 },
  { 0 ,	 NOTE_B3  , 0      , 16 },
  { 0 ,	 NOTE_D5  , 0      , 16 },  
  { 0 ,	 NOTE_D3  , 0      , 16 },
  { 0 ,	 NOTE_D4  , 0      , 16 },  
  { 0 ,	 NOTE_D3  , 0      , 16 },
  { 0 ,	 NOTE_G5  , 0      , 16 },
  { 0 ,	 NOTE_G3  , 0      , 16 },
  { 0 ,	 NOTE_G4  , 0      , 16 },
  { 0 ,	 NOTE_G3  , 0      , 16 },
  { 0 ,	 NOTE_D5  , 0      , 16 },
  { 0 ,	 NOTE_D3  , 0      , 16 },
  { 0 ,	 NOTE_D4  , 0      , 16 },
  { 0 ,	 NOTE_D3  , 0      , 16 },
  //1b
  { 0 ,	 NOTE_A5  , 0      , 16 },
  { 0 ,	 NOTE_A3  , 0      , 16 },
  { 0 ,	 NOTE_A4  , 0      , 16 },
  { 0 ,	 NOTE_A3  , 0      , 16 },
  { 0 ,	 NOTE_D4  , 0      , 16 },
  { 0 ,	 NOTE_D3  , 0      , 16 },
  { 0 ,	 NOTE_D4  , 0      , 16 },
  { 0 ,	 NOTE_D2  , 0      , 16 },
  { 0 ,	 NOTE_E5  , 0      , 16 },
  { 0 ,	 NOTE_E4  , 0      , 16 },
  { 0 ,	 NOTE_D5  , 0      , 16 },
  { 0 ,	 NOTE_D4  , 0      , 16 },
  { 0 ,	 NOTE_B4  , 0      , 16 },
  { 0 ,	 NOTE_B3  , 0      , 16 },
  { 0 ,	 NOTE_D5  , 0      , 16 },
  { 0 ,	 NOTE_D4  , 0      , 16 },
  //1c (same as 1a)
  { 0 ,	 NOTE_B5  , 0      , 16 },
  { 0 ,	 NOTE_B3  , 0      , 16 },
  { 0 ,	 NOTE_B4  , 0      , 16 },
  { 0 ,	 NOTE_B3  , 0      , 16 },
  { 0 ,	 NOTE_D5  , 0      , 16 },  
  { 0 ,	 NOTE_D3  , 0      , 16 },
  { 0 ,	 NOTE_D4  , 0      , 16 },  
  { 0 ,	 NOTE_D3  , 0      , 16 },
  { 0 ,	 NOTE_G5  , 0      , 16 },
  { 0 ,	 NOTE_G3  , 0      , 16 },
  { 0 ,	 NOTE_G4  , 0      , 16 },
  { 0 ,	 NOTE_G3  , 0      , 16 },
  { 0 ,	 NOTE_D5  , 0      , 16 },
  { 0 ,	 NOTE_D3  , 0      , 16 },
  { 0 ,	 NOTE_D4  , 0      , 16 },
  { 0 ,	 NOTE_D3  , 0      , 16 },
  //1d
  { 0 ,	 NOTE_A5  , 0      , 16 },
  { 0 ,	 NOTE_A3  , 0      , 16 },
  { 0 ,	 NOTE_A4  , 0      , 16 },
  { 0 ,	 NOTE_A3  , 0      , 16 },
  { 0 ,	 NOTE_D4  , 0      , 16 },
  { 0 ,	 NOTE_D5  , 0      , 16 },
  { 0 ,	 NOTE_D3  , 0      , 16 },
  { 0 ,	 NOTE_D2  , 0      , 16 },
  { 0 ,	 NOTE_E5  , 0      , 16 },
  { 0 ,	 NOTE_E3  , 0      , 16 },
  { 0 ,	 NOTE_D5  , 0      , 16 },
  { 0 ,	 NOTE_D3  , 0      , 16 },
  { 0 ,	 NOTE_G5  , 0      , 16 },
  { 0 ,	 NOTE_G3  , 0      , 16 },
  { 0 ,	 NOTE_FS5 , 0      , 16 },
  { 0 ,	 NOTE_FS3 , 0      , 16 },
  //2a
  { 0 ,	 NOTE_B5  , 0      , 16 },
  { 0 ,	 NOTE_B3  , 0      , 16 },
  { 0 ,	 NOTE_B4  , 0      , 16 },
  { 0 ,	 NOTE_B3  , 0      , 16 },
  { 0 ,	 NOTE_D5  , 0      , 16 },  
  { 0 ,	 NOTE_D3  , 0      , 16 },
  { 0 ,	 NOTE_D4  , 0      , 16 },  
  { 0 ,	 NOTE_D3  , 0      , 16 },
  { 0 ,	 NOTE_G5  , 0      , 16 },
  { 0 ,	 NOTE_G3  , 0      , 16 },
  { 0 ,	 NOTE_G4  , 0      , 16 },
  { 0 ,	 NOTE_G3  , 0      , 16 },
  { 0 ,	 NOTE_D5  , 0      , 16 },
  { 0 ,	 NOTE_D3  , 0      , 16 },
  { 0 ,	 NOTE_D4  , 0      , 16 },
  { 0 ,	 NOTE_D3  , 0      , 16 },
  //2b
  { 0 ,	 NOTE_A5  , 0      , 16 },
  { 0 ,	 NOTE_A3  , 0      , 16 },
  { 0 ,	 NOTE_A4  , 0      , 16 },
  { 0 ,	 NOTE_A3  , 0      , 16 },
  { 0 ,	 NOTE_D4  , 0      , 16 },
  { 0 ,	 NOTE_D3  , 0      , 16 },
  { 0 ,	 NOTE_D4  , 0      , 16 },
  { 0 ,	 NOTE_D2  , 0      , 16 },
  { 0 ,	 NOTE_E5  , 0      , 16 },
  { 0 ,	 NOTE_E4  , 0      , 16 },
  { 0 ,	 NOTE_D5  , 0      , 16 },
  { 0 ,	 NOTE_D4  , 0      , 16 },
  { 0 ,	 NOTE_B4  , 0      , 16 },
  { 0 ,	 NOTE_B3  , 0      , 16 },
  { 0 ,	 NOTE_D5  , 0      , 16 },
  { 0 ,	 NOTE_D4  , 0      , 16 },
  //2c (same as 2a)
  { 0 ,	 NOTE_B5  , 0      , 16 },
  { 0 ,	 NOTE_B3  , 0      , 16 },
  { 0 ,	 NOTE_B4  , 0      , 16 },
  { 0 ,	 NOTE_B3  , 0      , 16 },
  { 0 ,	 NOTE_D5  , 0      , 16 },  
  { 0 ,	 NOTE_D3  , 0      , 16 },
  { 0 ,	 NOTE_D4  , 0      , 16 },  
  { 0 ,	 NOTE_D3  , 0      , 16 },
  { 0 ,	 NOTE_G5  , 0      , 16 },
  { 0 ,	 NOTE_G3  , 0      , 16 },
  { 0 ,	 NOTE_G4  , 0      , 16 },
  { 0 ,	 NOTE_G3  , 0      , 16 },
  { 0 ,	 NOTE_D5  , 0      , 16 },
  { 0 ,	 NOTE_D3  , 0      , 16 },
  { 0 ,	 NOTE_D4  , 0      , 16 },
  { 0 ,	 NOTE_D3  , 0      , 16 },
  //2d
  { 0 ,	 NOTE_A5  , 0      , 16 },
  { 0 ,	 NOTE_A3  , 0      , 16 },
  { 0 ,	 NOTE_A4  , 0      , 16 },
  { 0 ,	 NOTE_A3  , 0      , 16 },
  { 0 ,	 NOTE_D4  , 0      , 16 },
  { 0 ,	 NOTE_D5  , 0      , 16 },
  { 0 ,	 NOTE_D3  , 0      , 16 },
  { 0 ,	 NOTE_D2  , 0      , 16 },
  { 0 ,	 NOTE_E5  , 0      , 16 },
  { 0 ,	 NOTE_E3  , 0      , 16 },
  { 0 ,	 NOTE_D5  , 0      , 16 },
  { 0 ,	 NOTE_D3  , 0      , 16 },
  { 0 ,	 NOTE_G5  , 0      , 16 },
  { 0 ,	 NOTE_G3  , 0      , 16 },
  { 0 ,	 NOTE_FS5 , 0      , 16 },
  { 0 ,	 NOTE_FS3 , 0      , 16 },
  // Loop 
  */
  { 0 ,	 -1       ,-1  , 0 }
};



int t[] = { 0, 0 };
#ifdef USE_EFX
int tp[] = { 0, 0 };
#endif

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
#ifdef USE_EFX
    tp[0] = t[0]; tp[1] = t[1];
#endif
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
