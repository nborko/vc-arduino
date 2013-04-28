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
//#define BEAT          61440

//#define BEAT          38400  // 125BPM (or there abouts)
#define BEAT          38400  // 125BPM (or there abouts)
#define DELAY_MILLIS  16

// uncomment for pin 13 LED diagnostic
//#define DIAG

// Whether or not to use a pot to control the arp rate
const boolean usePot = false;
// If not using a pot, the static arp-rate to use
const int arpRate = 32;

const int score[][3] PROGMEM = {
  // This is without properly transposing (GB is up 4 semitones so it starts on Em, not Cm)
  // Arp Chords for first part
  // 1
  { NOTE_E4 , NOTE_B4  , 1 },
  { NOTE_E4 , NOTE_B4  , 1 },
  { NOTE_G4 , NOTE_D4  , 1 },
  { NOTE_A4 , NOTE_E4  , 1 },
  // 2
  { NOTE_B3 , NOTE_E4  , 1 },
  { NOTE_B3 , NOTE_E4  , 1 },
  { NOTE_G4 , NOTE_D4  , 1 },
  { NOTE_A4 , NOTE_E4  , 1 },

  // Slow Melody with bass
  // 1a
  { NOTE_B5  , NOTE_E3  , 2 },
  { NOTE_G5  , NOTE_E3  , 2 },
  { NOTE_A5  , NOTE_E3  , 2 },
  { NOTE_E5  , NOTE_E3  , 4 },
  { NOTE_D5  , NOTE_E3  , 4 },
  // 1b
  { NOTE_B5  , NOTE_G3  , 2 },
  { NOTE_G5  , NOTE_G3  , 2 },
  { NOTE_A5  , NOTE_A3  , 2 },
  { NOTE_E5  , NOTE_A3  , 4 },
  { NOTE_D5  , NOTE_A3  , 4 },
  // 1c
  { NOTE_B5  , NOTE_E3  , 2 },
  { NOTE_G5  , NOTE_E3  , 2 },
  { NOTE_A5  , NOTE_E3  , 2 },
  { NOTE_E5  , NOTE_E3  , 4 },
  { NOTE_D5  , NOTE_E3  , 4 },
  // 1d
  { NOTE_B5  , NOTE_G3  , 2 },
  { NOTE_G5  , NOTE_G3  , 2 },
  { NOTE_A5  , NOTE_A3  , 2 },
  { NOTE_E5  , NOTE_A3  , 4 },
  { NOTE_D5  , NOTE_A3  , 4 },
  // 2a
  { NOTE_B5  , NOTE_E3  , 2 },
  { NOTE_G5  , NOTE_E3  , 2 },
  { NOTE_A5  , NOTE_E3  , 2 },
  { NOTE_E5  , NOTE_E3  , 4 },
  { NOTE_D5  , NOTE_E3  , 4 },
  // 2b
  { NOTE_B5  , NOTE_G3  , 2 },
  { NOTE_G5  , NOTE_G3  , 2 },
  { NOTE_A5  , NOTE_A3  , 2 },
  { NOTE_E5  , NOTE_A3  , 4 },
  { NOTE_D5  , NOTE_A3  , 4 },
  // 2c
  { NOTE_B5  , NOTE_E3  , 2 },
  { NOTE_G5  , NOTE_E3  , 2 },
  { NOTE_A5  , NOTE_E3  , 2 },
  { NOTE_E5  , NOTE_E3  , 4 },
  { NOTE_D5  , NOTE_E3  , 4 },
  // 2d
  { NOTE_B5  , NOTE_G3  , 2 },
  { NOTE_G5  , NOTE_G3  , 2 },
  { NOTE_A5  , NOTE_A3  , 2 },
  { NOTE_E5  , NOTE_A3  , 4 },
  { NOTE_D5  , NOTE_A3  , 4 },

  //Faster Melody with Bass
  //1a
  { NOTE_B5  , NOTE_E3  , 4 },
  { NOTE_D5  , NOTE_E4  , 4 },  
  { NOTE_G5  , NOTE_E3  , 4 },
  { NOTE_D5  , NOTE_E4  , 4 },
  //1b
  { NOTE_A5  , NOTE_E3  , 4 },
  { NOTE_D5  , NOTE_E4  , 4 },
  { NOTE_E5  , NOTE_E3  , 8 },
  { NOTE_D5  , NOTE_E3  , 8 },
  { NOTE_B4  , NOTE_E3  , 8 },
  { NOTE_D5  , NOTE_E3  , 8 },
  //1c (same as 1a)
  { NOTE_B5  , NOTE_E3  , 4 },
  { NOTE_D5  , NOTE_E4  , 4 },  
  { NOTE_G5  , NOTE_E3  , 4 },
  { NOTE_D5  , NOTE_E4  , 4 },
  //1d
  { NOTE_A5  , NOTE_E3  , 4 },
  { NOTE_D5  , NOTE_E4  , 4 },
  { NOTE_E5  , NOTE_E3  , 8 },
  { NOTE_D5  , NOTE_E3  , 8 },
  { NOTE_G5  , NOTE_E3  , 8 },
  { NOTE_FS5 , NOTE_E3  , 8 },
  //2a
  { NOTE_B5  , NOTE_E3  , 4 },
  { NOTE_D5  , NOTE_E4  , 4 },  
  { NOTE_G5  , NOTE_E3  , 4 },
  { NOTE_D5  , NOTE_E4  , 4 },
  //2b
  { NOTE_A5  , NOTE_E3  , 4 },
  { NOTE_D5  , NOTE_E4  , 4 },
  { NOTE_E5  , NOTE_E3  , 8 },
  { NOTE_D5  , NOTE_E3  , 8 },
  { NOTE_B4  , NOTE_E3  , 8 },
  { NOTE_D5  , NOTE_E3  , 8 },
  //2c (same as 2a)
  { NOTE_B5  , NOTE_E3  , 4 },
  { NOTE_D5  , NOTE_E4  , 4 },  
  { NOTE_G5  , NOTE_E3  , 4 },
  { NOTE_D5  , NOTE_E4  , 4 },
  //2d
  { NOTE_A5  , NOTE_E3  , 4 },
  { NOTE_D5  , NOTE_E4  , 4 },
  { NOTE_E5  , NOTE_E3  , 8 },
  { NOTE_D5  , NOTE_E3  , 8 },
  { NOTE_G5  , NOTE_E3  , 8 },
  { NOTE_FS5 , NOTE_E3  , 8 },


  
  // Fast Melody No Bass
  //1a
  { NOTE_B5  , 0        , 8 },
  { NOTE_B4  , 0        , 8 },
  { NOTE_D5  , 0        , 8 },  
  { NOTE_D4  , 0        , 8 },  
  { NOTE_G5  , 0        , 8 },
  { NOTE_G4  , 0        , 8 },
  { NOTE_D5  , 0        , 8 },
  { NOTE_D4  , 0        , 8 },
  //1b
  { NOTE_A5  , 0        , 8 },
  { NOTE_A4  , 0        , 8 },
  { NOTE_D4  , 0        , 8 },
  { NOTE_D3  , 0        , 8 },
  { NOTE_E5  , 0        , 8 },
  { NOTE_D5  , 0        , 8 },
  { NOTE_B4  , 0        , 8 },
  { NOTE_D5  , 0        , 8 },
  //1c (same as 1a)
  { NOTE_B5  , 0        , 8 },
  { NOTE_B4  , 0        , 8 },
  { NOTE_D5  , 0        , 8 },  
  { NOTE_D4  , 0        , 8 },  
  { NOTE_G5  , 0        , 8 },
  { NOTE_G4  , 0        , 8 },
  { NOTE_D5  , 0        , 8 },
  { NOTE_D4  , 0        , 8 },
  //1d
  { NOTE_A5  , 0        , 8 },
  { NOTE_A4  , 0        , 8 },
  { NOTE_D4  , 0        , 8 },
  { NOTE_D3  , 0        , 8 },
  { NOTE_E5  , 0        , 8 },
  { NOTE_D5  , 0        , 8 },
  { NOTE_G5  , 0        , 8 },
  { NOTE_FS5 , 0        , 8 },
  //2a
  { NOTE_B5  , 0        , 8 },
  { NOTE_B4  , 0        , 8 },
  { NOTE_D5  , 0        , 8 },  
  { NOTE_D4  , 0        , 8 },  
  { NOTE_G5  , 0        , 8 },
  { NOTE_G4  , 0        , 8 },
  { NOTE_D5  , 0        , 8 },
  { NOTE_D4  , 0        , 8 },
  //2b  
  { NOTE_A5  , 0        , 8 },
  { NOTE_A4  , 0        , 8 },
  { NOTE_D4  , 0        , 8 },
  { NOTE_D3  , 0        , 8 },
  { NOTE_E5  , 0        , 8 },
  { NOTE_D5  , 0        , 8 },
  { NOTE_B4  , 0        , 8 },
  { NOTE_D5  , 0        , 8 },
  //2c (same as 2a)
  { NOTE_B5  , 0        , 8 },
  { NOTE_B4  , 0        , 8 },
  { NOTE_D5  , 0        , 8 },  
  { NOTE_D4  , 0        , 8 },  
  { NOTE_G5  , 0        , 8 },
  { NOTE_G4  , 0        , 8 },
  { NOTE_D5  , 0        , 8 },
  { NOTE_D4  , 0        , 8 },
  //2d
  { NOTE_A5  , 0        , 8 },
  { NOTE_A4  , 0        , 8 },
  { NOTE_D4  , 0        , 8 },
  { NOTE_D3  , 0        , 8 },
  { NOTE_E5  , 0        , 8 },
  { NOTE_D5  , 0        , 8 },
  { NOTE_G5  , 0        , 8 },
  { NOTE_FS5 , 0        , 8 },

  // Arp Melody No Bass
  //1a
  { NOTE_B5  , 0  , 16 },
  { NOTE_B3  , 0  , 16 },
  { NOTE_B4  , 0  , 16 },
  { NOTE_B3  , 0  , 16 },
  { NOTE_D5  , 0  , 16 },  
  { NOTE_D3  , 0  , 16 },
  { NOTE_D4  , 0  , 16 },  
  { NOTE_D3  , 0  , 16 },
  { NOTE_G5  , 0  , 16 },
  { NOTE_G3  , 0  , 16 },
  { NOTE_G4  , 0  , 16 },
  { NOTE_G3  , 0  , 16 },
  { NOTE_D5  , 0  , 16 },
  { NOTE_D3  , 0  , 16 },
  { NOTE_D4  , 0  , 16 },
  { NOTE_D3  , 0  , 16 },
  //1b
  { NOTE_A5  , 0  , 16 },
  { NOTE_A3  , 0  , 16 },
  { NOTE_A4  , 0  , 16 },
  { NOTE_A3  , 0  , 16 },
  { NOTE_D4  , 0  , 16 },
  { NOTE_D3  , 0  , 16 },
  { NOTE_D4  , 0  , 16 },
  { NOTE_D2  , 0  , 16 },
  { NOTE_E5  , 0  , 16 },
  { NOTE_E4  , 0  , 16 },
  { NOTE_D5  , 0  , 16 },
  { NOTE_D4  , 0  , 16 },
  { NOTE_B4  , 0  , 16 },
  { NOTE_B3  , 0  , 16 },
  { NOTE_D5  , 0  , 16 },
  { NOTE_D4  , 0  , 16 },
  //1c (same as 1a)
  { NOTE_B5  , 0  , 16 },
  { NOTE_B3  , 0  , 16 },
  { NOTE_B4  , 0  , 16 },
  { NOTE_B3  , 0  , 16 },
  { NOTE_D5  , 0  , 16 },  
  { NOTE_D3  , 0  , 16 },  
  { NOTE_D4  , 0  , 16 },  
  { NOTE_D3  , 0  , 16 },  
  { NOTE_G5  , 0  , 16 },
  { NOTE_G3  , 0  , 16 },
  { NOTE_G4  , 0  , 16 },
  { NOTE_G3  , 0  , 16 },
  { NOTE_D5  , 0  , 16 },
  { NOTE_D3  , 0  , 16 },
  { NOTE_D4  , 0  , 16 },
  { NOTE_D3  , 0  , 16 },
  //1d
  { NOTE_A5  , 0  , 16 },
  { NOTE_A3  , 0  , 16 },
  { NOTE_A4  , 0  , 16 },
  { NOTE_A3  , 0  , 16 },
  { NOTE_D4  , 0  , 16 },
  { NOTE_D5  , 0  , 16 },
  { NOTE_D3  , 0  , 16 },
  { NOTE_D2  , 0  , 16 },
  { NOTE_E5  , 0  , 16 },
  { NOTE_E3  , 0  , 16 },
  { NOTE_D5  , 0  , 16 },
  { NOTE_D3  , 0  , 16 },
  { NOTE_G5  , 0  , 16 },
  { NOTE_G3  , 0  , 16 },
  { NOTE_FS5 , 0  , 16 },
  { NOTE_FS3 , 0  , 16 },
  //2a
  { NOTE_B5  , 0  , 16 },
  { NOTE_B3  , 0  , 16 },
  { NOTE_B4  , 0  , 16 },
  { NOTE_B3  , 0  , 16 },
  { NOTE_D5  , 0  , 16 },  
  { NOTE_D3  , 0  , 16 },
  { NOTE_D4  , 0  , 16 },  
  { NOTE_D3  , 0  , 16 },
  { NOTE_G5  , 0  , 16 },
  { NOTE_G3  , 0  , 16 },
  { NOTE_G4  , 0  , 16 },
  { NOTE_G3  , 0  , 16 },
  { NOTE_D5  , 0  , 16 },
  { NOTE_D3  , 0  , 16 },
  { NOTE_D4  , 0  , 16 },
  { NOTE_D3  , 0  , 16 },
  //2b
  { NOTE_A5  , 0  , 16 },
  { NOTE_A3  , 0  , 16 },
  { NOTE_A4  , 0  , 16 },
  { NOTE_A3  , 0  , 16 },
  { NOTE_D4  , 0  , 16 },
  { NOTE_D3  , 0  , 16 },
  { NOTE_D4  , 0  , 16 },
  { NOTE_D2  , 0  , 16 },
  { NOTE_E5  , 0  , 16 },
  { NOTE_E4  , 0  , 16 },
  { NOTE_D5  , 0  , 16 },
  { NOTE_D4  , 0  , 16 },
  { NOTE_B4  , 0  , 16 },
  { NOTE_B3  , 0  , 16 },
  { NOTE_D5  , 0  , 16 },
  { NOTE_D4  , 0  , 16 },
  //2c (same as 2a)
  { NOTE_B5  , 0  , 16 },
  { NOTE_B3  , 0  , 16 },
  { NOTE_B4  , 0  , 16 },
  { NOTE_B3  , 0  , 16 },
  { NOTE_D5  , 0  , 16 },  
  { NOTE_D3  , 0  , 16 },  
  { NOTE_D4  , 0  , 16 },  
  { NOTE_D3  , 0  , 16 },  
  { NOTE_G5  , 0  , 16 },
  { NOTE_G3  , 0  , 16 },
  { NOTE_G4  , 0  , 16 },
  { NOTE_G3  , 0  , 16 },
  { NOTE_D5  , 0  , 16 },
  { NOTE_D3  , 0  , 16 },
  { NOTE_D4  , 0  , 16 },
  { NOTE_D3  , 0  , 16 },
  //2d
  { NOTE_A5  , 0  , 16 },
  { NOTE_A3  , 0  , 16 },
  { NOTE_A4  , 0  , 16 },
  { NOTE_A3  , 0  , 16 },
  { NOTE_D4  , 0  , 16 },
  { NOTE_D5  , 0  , 16 },
  { NOTE_D3  , 0  , 16 },
  { NOTE_D2  , 0  , 16 },
  { NOTE_E5  , 0  , 16 },
  { NOTE_E3  , 0  , 16 },
  { NOTE_D5  , 0  , 16 },
  { NOTE_D3  , 0  , 16 },
  { NOTE_G5  , 0  , 16 },
  { NOTE_G3  , 0  , 16 },
  { NOTE_FS5 , 0  , 16 },
  { NOTE_FS3 , 0  , 16 },
 
  { -1       ,-1  , 0 }
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
    /* 
       If there is a pot, read it's value to adjust arp.
       If not, set r to a static amount
    */
    if(usePot)
    {
      r = analogRead(A3) / 4;
      r = r < 16 ? 16 : r;
    }
    else
      r = arpRate;
      
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
