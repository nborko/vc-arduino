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

// affects BPM
#define DELAY         1.2

#ifdef USE_EFX
#define PERIOD        21800
#define EFX_GLISS     B01000000
#define EFX_VOICE1    B00000000
#define EFX_VOICE2    B00100000
#else
#define PERIOD        22500
#endif

// uncomment for LED diagnostic
//#define DIAG 0

typedef struct Note {
  byte effect;
  int voice1;
  int voice2;
} Note;

#include "music.h"

volatile int r = 16;
int t[] = { 0, 0 };

#ifdef USE_EFX
volatile byte effect = 0;
int tp[] = { 0, 0 };
#endif

void doSound() {
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
  boolean g = (effect & EFX_GLISS) && ((effect & (voice << 5)) == voice) && (tp[voice] != t[voice]);
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
  voice_period = (voice_period + 1 < PERIOD / f) ? voice_period + 1 : 0;
  if (voice_period == 0) {
#ifdef USE_EFX
    if(g) tp[voice] = tp[voice] != t[voice] ? (tp[voice] < t[voice] ? min(t[voice], tp[voice] + (effect & B00111111)) : max(t[voice], tp[voice] - (effect & B00111111))) : t[voice];
#endif
    if (++pulse > f / r) {
      pulse = 0;
      voice = !voice;
    }
  }
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
}
void loop() {
#ifdef DIAG
  boolean lit = false;
#endif
  int i = 0;
  while(1) {
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
#ifdef DIAG
    digitalWrite(DIAG, lit = !lit);
#endif
    _delay_ms(DELAY);
    i++;
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
