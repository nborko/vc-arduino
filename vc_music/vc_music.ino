// Bach multitone sketch
// by Nick Borko

// Arduino:
// A3 -> 10k linear pot
// D9,D10 -> piezo speaker
// ATtiny85:
// Pin 2 -> 10k linear pot
// Pins 6,7 -> piezo speaker

#include <avr/pgmspace.h>
#include <util/delay.h>

// Arduino:
// 1. Get FlexiTimer2 from http://playground.arduino.cc/Main/FlexiTimer2
// 2. Uncomment the next line
//#include <FlexiTimer2.h>

#define USE_EFX

// Duration of notes, affects BPM
#define DELAY         200.0

#define EFX_GLISS     B01000000
#define EFX_VOICE1    B00000000
#define EFX_VOICE2    B00100000

// uncomment for LED diagnostic
//#define DIAG 0

typedef struct Note {
  byte effect;
  int voice1;
  int voice2;
} Note;

#include "music.h"

// This is tied to the interrupt clock
// NOTE: Change ONLY to tune!
const unsigned int PERIOD = 64000;

int t[] = { 0, 0 };
volatile unsigned char voice = 0;

void doSound() {
  static unsigned int voice_period = 0;
  unsigned int f = t[voice];
  
  if (f) {
    if (voice_period == 0) {
      PORTB &= B11111101;
      PORTB |= B00000100;
    } else if(voice_period == f>>1) {
      PORTB &= B11111011;
      PORTB |= B00000010;
    }
  }
  voice_period = (voice_period + 1 < f) ? voice_period + 1 : 0;
}

#ifdef __AVR_ATtiny85__
void setup_timer() {
    TCCR1 = 0;                  //stop the timer
    TCNT1 = 0;                  //zero the timer
    GTCCR = _BV(PSR1);          //reset the prescaler
    OCR1B = 255;                //set the compare value
    TIMSK = _BV(OCIE1B);  
    TCCR1 = _BV(CTC1) | _BV(CS10);
    //sei();
}

ISR(TIMER1_COMPB_vect) {
  doSound();
}
#else
void setup_timer() {
  FlexiTimer2::set(1, 1/(float)PERIOD, doSound);
  FlexiTimer2::start();
}
#endif

void setup() {
  DDRB |= B00000110;
#ifdef DIAG
  pinMode(DIAG, OUTPUT);
#endif
  setup_timer();
#ifdef DIAG
  boolean lit = false;
#endif
  unsigned int i = 0, arp;
  int t0, t1;
  int z;
  while(1) {
    arp = analogRead(A3);
    z = DELAY * (arp / 2048.0);
    z = z < 4.0 ? 4.0 : z;
    t0 = pgm_read_word(&score[i].voice1);
    if(t0 < 0) {
      t[0] = 0;
      t[1] = 0;
      break;
    }
    t1 = pgm_read_word(&score[i].voice2);
    t0 = t0 ? PERIOD / t0 : 0;
    t1 = t1 ? PERIOD / t1 : 0;
#ifdef DIAG
    digitalWrite(DIAG, lit = !lit);
#endif
#ifdef USE_EFX
    byte effect = pgm_read_byte(&score[i].effect);
    boolean g0 = (effect & EFX_GLISS) && ((effect & (0 << 5)) == 0) && (t[0] != t0),
            g1 = (effect & EFX_GLISS) && ((effect & (1 << 5)) == 1) && (t[1] != t1);
    if(!g0) {
#endif
      t[0] = t0;
#ifdef USE_EFX
    }
    if(!g1) {
#endif
      t[1] = t1;
#ifdef USE_EFX
    }
#endif
    for(int y = 1; y <= DELAY; y += 1) {
      if(!(y % z)) voice = t[!voice] ? !voice : voice;
      _delay_ms(1);
#ifdef USE_EFX
       if(g0) t[0] = t[0] != t0 ? (t[0] < t0 ? min(t0, t[0] + (effect & B00111111)) : max(t0, t[0] - (effect & B00111111))) : t0;
       if(g1) t[1] = t[1] != t1 ? (t[1] < t1 ? min(t1, t[1] + (effect & B00111111)) : max(t1, t[1] - (effect & B00111111))) : t1;
#endif
    }
    i++;
  }
}

void loop() {
  // idle
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
