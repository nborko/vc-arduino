// Chip synth sketch
// Copyright 2013 by Nick Borko

// Arduino:
// A2 -> 10k linear pot wiper
// D8,D9 -> piezo speaker
// ATtiny85:
// Pin 3 -> 10k linear pot wiper
// Pins 5,6 -> piezo speaker

#include <avr/pgmspace.h>
#ifdef __AVR_ATtiny85__
#include <avr/sleep.h>
#include <util/delay.h>
#endif

// Arduino:
// 1. Get FlexiTimer2 from http://playground.arduino.cc/Main/FlexiTimer2
// 2. Uncomment the next line
//#include <FlexiTimer2.h>

#define USE_EFX

// Duration of notes, affects BPM
#define DELAY         133

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

// change to bach.h to get a Bach tune instead
#include "music.h"

// This is tied to the interrupt clock
// NOTE: Change ONLY to tune!
const unsigned int PERIOD = 64000;

int tone_period[] = { 0, 0 };
volatile unsigned char voice = 0;

void toneGenerator() {
  static unsigned int p_count = 0;
  unsigned int current_period = tone_period[voice];
  
  if (current_period) {
    if (p_count == 0) {
      PORTB &= B11111110;
      PORTB |= B00000010;
    } else if(p_count == current_period >> 1) {
      PORTB &= B11111101;
      PORTB |= B00000001;
    }
  }
  p_count = (p_count + 1 < current_period) ? p_count + 1 : 0;
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
  toneGenerator();
}
#else
void setup_timer() {
  FlexiTimer2::set(1, 1/(float)PERIOD, toneGenerator);
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
  unsigned int pattern = 0,
               index = 0,
               arp = 1,
               arp_count = 0,
               arp_delay;
  int tone_period0, tone_period1;
  Note *note;
  while(1) {
    arp = analogRead(A2);
    arp_delay = DELAY * (arp / 2048.0);
    arp_delay = arp_delay < 4.0 ? 4.0 : arp_delay;
    note = (Note*)pgm_read_word(&score[pattern]);
    if(!note) {
        tone_period[0] = 0;
        tone_period[1] = 0;
        break;
    }
    tone_period0 = pgm_read_word(&note[index].voice1);
    if(tone_period0 < 0) {
      pattern += 1;
      index = 0;
      continue;
    }
    tone_period1 = pgm_read_word(&note[index].voice2);
    tone_period0 = tone_period0 ? PERIOD / tone_period0 : 0;
    tone_period1 = tone_period1 ? PERIOD / tone_period1 : 0;
#ifdef DIAG
    digitalWrite(DIAG, lit = !lit);
#endif
#ifdef USE_EFX
    byte effect = pgm_read_byte(&note[index].effect),
         effect_param = (effect & B00011111);
    boolean effect0 = 0,
            effect1 = 0,
            effect_voice = (effect & (1 << 5)) == 1;
    if ((effect & EFX_MASK) == EFX_GLISS) {
      effect0 = !effect_voice && (tone_period[0] != tone_period0);
      effect1 = effect_voice && (tone_period[1] != tone_period1);
    }
    if(!effect0) {
#endif
      tone_period[0] = tone_period0;
#ifdef USE_EFX
    }
    if(!effect1) {
#endif
      tone_period[1] = tone_period1;
#ifdef USE_EFX
    }
    if (!effect0 && !effect1) {
      if ((effect & EFX_MASK) == EFX_SLIDE_UP) {
        effect0 = !effect_voice;
        effect1 = effect_voice;
        tone_period0 = PERIOD / 20000; // should be beyond human hearing
      } else if ((effect & EFX_MASK) == EFX_SLIDE_DN) {
        effect0 = !effect_voice;
        effect1 = effect_voice;
        tone_period0 = PERIOD / 40;
      }
    }
#endif
    for(int y = 0; y < DELAY; y += 1) {
      if(!(arp_count = arp_count < arp_delay ? arp_count + 1 : 0)) {
        voice = tone_period[!voice] ? !voice : voice;
      }
      voice = tone_period[voice] ? voice : !voice;
#ifdef __AVR_ATtiny85__
      _delay_ms(0.5);
#else
      delayMicroseconds(50);
#endif
#ifdef USE_EFX
       if(effect0) {
         tone_period[0] = tone_period[0] != tone_period0 ? (tone_period[0] < tone_period0 ? min(tone_period0, tone_period[0] + effect_param) : max(tone_period0, tone_period[0] - effect_param)) : tone_period0;
       }
       if(effect1) {
         tone_period[1] = tone_period[1] != tone_period1 ? (tone_period[1] < tone_period1 ? min(tone_period1, tone_period[1] + effect_param) : max(tone_period1, tone_period[1] - effect_param)) : tone_period1;
       }
#endif
    }
    index += 1;
  }
  // go to sleep to conserve power
  PORTB = B0;
#ifdef __AVR_ATtiny85__
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_mode();
#endif
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
