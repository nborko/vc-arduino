// Bach multitone sketch
// by Nick Borko

// Arduino:
// A3 -> 10k linear pot
// D9,D10 -> piezo speaker
// ATtiny85:
// Pin 2 -> 10k linear pot
// Pins 6,7 -> piezo speaker

#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include <util/delay.h>

// Arduino:
// 1. Get FlexiTimer2 from http://playground.arduino.cc/Main/FlexiTimer2
// 2. Uncomment the next line
//#include <FlexiTimer2.h>

#define USE_EFX

// Duration of notes, affects BPM
#define DELAY         250.0

#define EFX_MASK      B11000000
#define EFX_GLISS     B01000000
#define EFX_SLIDE_UP  B10000000
#define EFX_SLIDE_DN  B11000000
#define EFX_VOICE1    B00000000
#define EFX_VOICE2    B00100000

// uncomment for LED diagnostic
//#define DIAG 2

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
      PORTB &= B11111110;
      PORTB |= B00000010;
    } else if(voice_period == f>>1) {
      PORTB &= B11111101;
      PORTB |= B00000001;
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
  DDRB |= B00001111;
  PORTB |= B00001000; // set high for pot
#ifdef DIAG
  pinMode(DIAG, OUTPUT);
#endif
  setup_timer();
#ifdef DIAG
  boolean lit = false;
#endif
  unsigned int p = 0, i = 0, arp, c = 0, z;
  int t0, t1;
  Note *n;
  while(1) {
    arp = analogRead(A2);
    z = DELAY * (arp / 2048.0);
    z = z < 4.0 ? 4.0 : z;
    n = (Note*)pgm_read_word(&score[p]);
    if(!n) {
        t[0] = 0;
        t[1] = 0;
        break;
    }
    t0 = pgm_read_word(&n[i].voice1);
    if(t0 < 0) {
      p += 1;
      i = 0;
      continue;
    }
    t1 = pgm_read_word(&n[i].voice2);
    t0 = t0 ? PERIOD / t0 : 0;
    t1 = t1 ? PERIOD / t1 : 0;
#ifdef DIAG
    digitalWrite(DIAG, lit = !lit);
#endif
#ifdef USE_EFX
    byte effect = pgm_read_byte(&n[i].effect);
    byte fxp = (effect & B00011111);
    boolean g0 = 0, g1 = 0, fxv = (effect & (1 << 5)) == 1;
    if ((effect & EFX_MASK) == EFX_GLISS) {
      g0 = !fxv && (t[0] != t0);
      g1 = fxv && (t[1] != t1);
    }
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
    if (!g0 && !g1) {
      if ((effect & EFX_MASK) == EFX_SLIDE_UP) {
        g0 = !fxv;
        g1 = fxv;
        t0 = PERIOD / 20000; // should be beyond human hearing
      } else if ((effect & EFX_MASK) == EFX_SLIDE_DN) {
        g0 = !fxv;
        g1 = fxv;
        t0 = PERIOD / 40;
      }
    }
#endif
    for(int y = 0; y < DELAY; y += 1) {
      if(!(c = c < z ? c + 1 : 0)) {
        voice = t[!voice] ? !voice : voice;
      }
      voice = t[voice] ? voice : !voice;
      _delay_ms(1);
#ifdef USE_EFX
       if(g0) t[0] = t[0] != t0 ? (t[0] < t0 ? min(t0, t[0] + fxp) : max(t0, t[0] - fxp)) : t0;
       if(g1) t[1] = t[1] != t1 ? (t[1] < t1 ? min(t1, t[1] + fxp) : max(t1, t[1] - fxp)) : t1;
#endif
    }
    i++;
  }
  // go to sleep to conserve power
  PORTB = B0;
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_mode();
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
