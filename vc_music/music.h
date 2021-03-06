/* 
 * Arduintro by Victim Cache
 *
 * Copyright 2013 Victim Cache
 * 
 * Licensed Under CC BY-NC-ND 3.0
 * https://creativecommons.org/licenses/by-nc-nd/3.0/
 *
 * Briefly speaking, you can distribute this songs freely to anyone
 * you like (please do!), but you are required to attribute the song to 
 * Victim Cache. Derivative works are not allowed, nor is any commercial use.
 * If you would like to do something beyond this license, however, simply 
 * contact us!
 * 
 * For info about the band, visit our website at http://victimcache.com/ 
 * To contact us, simply send an e-mail to theband@victimcache.com
 *
 *  Song speed is set by editing vc_music.ino and setting:
 *    #define DELAY         132.5
 *  Song was originally composed with a delay of 132.5 (~ 120BPM),
 *  but feel free to experiment!! 
 */

#include "pitches.h"

/*
 * Pattern arrays. Think of these like patterns in a conventional tracker
 * which can be arranged individually to comprise the song.
 */

// Pattern 1: Arp Chords for first part
// 1a
const Note p1a[] PROGMEM = {
  { 0 ,	 NOTE_E4 , NOTE_B4  },
  { 0 ,	 NOTE_E4 , NOTE_B4  },
  { 0 ,	 NOTE_E4 , NOTE_B4  },
  { 0 ,	 NOTE_E4 , NOTE_B4  },
  { 0 ,	 NOTE_E4 , NOTE_B4  },
  { 0 ,	 NOTE_E4 , NOTE_B4  },
  { 0 ,	 NOTE_E4 , NOTE_B4  },
  { 0 ,	 NOTE_E4 , NOTE_B4  },
  { 0 ,	 NOTE_E4 , NOTE_B4  },
  { 0 ,	 NOTE_E4 , NOTE_B4  },
  { 0 ,	 NOTE_E4 , NOTE_B4  },
  { 0 ,	 NOTE_E4 , NOTE_B4  },
  { 0 ,	 NOTE_E4 , NOTE_B4  },
  { 0 ,	 NOTE_E4 , NOTE_B4  },
  { 0 ,	 NOTE_E4 , NOTE_B4  },
  { 0 ,	 NOTE_E4 , NOTE_B4  },
  { 0, -1, -1 }
};
// 1b
const Note p1b[] PROGMEM = {
  { 0 ,	 NOTE_B3 , NOTE_E4  },
  { 0 ,	 NOTE_B3 , NOTE_E4  },
  { 0 ,	 NOTE_B3 , NOTE_E4  },
  { 0 ,	 NOTE_B3 , NOTE_E4  },
  { 0 ,	 NOTE_B3 , NOTE_E4  },
  { 0 ,	 NOTE_B3 , NOTE_E4  },
  { 0 ,	 NOTE_B3 , NOTE_E4  },
  { 0 ,	 NOTE_B3 , NOTE_E4  },
  { 0 ,	 NOTE_B3 , NOTE_E4  },
  { 0 ,	 NOTE_B3 , NOTE_E4  },
  { 0 ,	 NOTE_B3 , NOTE_E4  },
  { 0 ,	 NOTE_B3 , NOTE_E4  },
  { 0 ,	 NOTE_B3 , NOTE_E4  },
  { 0 ,	 NOTE_B3 , NOTE_E4  },
  { 0 ,	 NOTE_B3 , NOTE_E4  },
  { 0 ,	 NOTE_B3 , NOTE_E4  },
  { 0, -1, -1 }
};
// 1c
const Note p1c[] PROGMEM = {
  { 0 ,	 NOTE_G4 , NOTE_D4  },
  { 0 ,	 NOTE_G4 , NOTE_D4  },
  { 0 ,	 NOTE_G4 , NOTE_D4  },
  { 0 ,	 NOTE_G4 , NOTE_D4  },
  { 0 ,	 NOTE_G4 , NOTE_D4  },
  { 0 ,	 NOTE_G4 , NOTE_D4  },
  { 0 ,	 NOTE_G4 , NOTE_D4  },
  { 0 ,	 NOTE_G4 , NOTE_D4  },
  { 0 ,	 NOTE_G4 , NOTE_D4  },
  { 0 ,	 NOTE_G4 , NOTE_D4  },
  { 0 ,	 NOTE_G4 , NOTE_D4  },
  { 0 ,	 NOTE_G4 , NOTE_D4  },
  { 0 ,	 NOTE_G4 , NOTE_D4  },
  { 0 ,	 NOTE_G4 , NOTE_D4  },
  { 0 ,	 NOTE_G4 , NOTE_D4  },
  { 0 ,	 NOTE_G4 , NOTE_D4  },
  { 0, -1, -1 }
};
// 1d
const Note p1d[] PROGMEM = {
  { 0 ,	 NOTE_A4 , NOTE_E4  },
  { 0 ,	 NOTE_A4 , NOTE_E4  },
  { 0 ,	 NOTE_A4 , NOTE_E4  },
  { 0 ,	 NOTE_A4 , NOTE_E4  },
  { 0 ,	 NOTE_A4 , NOTE_E4  },
  { 0 ,	 NOTE_A4 , NOTE_E4  },
  { 0 ,	 NOTE_A4 , NOTE_E4  },
  { 0 ,	 NOTE_A4 , NOTE_E4  },
  { 0 ,	 NOTE_A4 , NOTE_E4  },
  { 0 ,	 NOTE_A4 , NOTE_E4  },
  { 0 ,	 NOTE_A4 , NOTE_E4  },
  { 0 ,	 NOTE_A4 , NOTE_E4  },
  { 0 ,	 NOTE_A4 , NOTE_E4  },
  { 0 ,	 NOTE_A4 , NOTE_E4  },
  { 0 ,	 NOTE_A4 , NOTE_E4  },
  { 0 ,	 NOTE_A4 , NOTE_E4  },
  { 0, -1, -1 }
};
// 1e
const Note p1e[] PROGMEM = {
  { 0 ,	 NOTE_E3 , NOTE_B3  },
  { 0 ,	 NOTE_E3 , NOTE_B3  },
  { 0 ,	 NOTE_E3 , NOTE_B3  },
  { 0 ,	 NOTE_E3 , NOTE_B3  },
  { 0 ,	 NOTE_E3 , NOTE_B3  },
  { 0 ,	 NOTE_E3 , NOTE_B3  },
  { 0 ,	 NOTE_E3 , NOTE_B3  },
  { 0 ,	 NOTE_E3 , NOTE_B3  },
  { 0 ,	 NOTE_E3 , NOTE_B3  },
  { 0 ,	 NOTE_E3 , NOTE_B3  },
  { 0 ,	 NOTE_E3 , NOTE_B3  },
  { 0 ,	 NOTE_E3 , NOTE_B3  },
  { 0 ,	 NOTE_E3 , NOTE_B3  },
  { 0 ,	 NOTE_E3 , NOTE_B3  },
  { 0 ,	 NOTE_E3 , NOTE_B3  },
  { 0 ,	 NOTE_E3 , NOTE_B3  },
  { 0, -1, -1 }
};

// Pattern 2: Slow Melody with bass
// 2a
const Note p2a[] PROGMEM = {
  { 0 ,	 NOTE_B5  , NOTE_E3  },
  { 0 ,	 NOTE_B5  , NOTE_E3  },
  { 0 ,	 NOTE_B5  , NOTE_E3  },
  { 0 ,	 NOTE_B5  , NOTE_E3  },
  { 0 ,	 NOTE_G5  , NOTE_E3  },
  { 0 ,	 NOTE_G5  , NOTE_E3  },
  { 0 ,	 NOTE_G5  , NOTE_E3  },
  { 0 ,	 NOTE_G5  , NOTE_E3  },
  { 0 ,	 NOTE_A5  , NOTE_E3  },  
  { 0 ,	 NOTE_A5  , NOTE_E3  },
  { 0 ,	 NOTE_A5  , NOTE_E3  },
  { 0 ,	 NOTE_A5  , NOTE_E3  },
  { 0 ,	 NOTE_E5  , NOTE_E3  },
  { 0 ,	 NOTE_E5  , NOTE_E3  },
  { 0 ,	 NOTE_D5  , NOTE_E3  },
  { 0 ,	 NOTE_D5  , NOTE_E3  },
  { 0, -1, -1 }
};
// 2b
const Note p2b[] PROGMEM = {
  { 0 ,	 NOTE_B5  , NOTE_G3  },
  { 0 ,	 NOTE_B5  , NOTE_G3  },
  { 0 ,	 NOTE_B5  , NOTE_G3  },
  { 0 ,	 NOTE_B5  , NOTE_G3  },
  { 0 ,	 NOTE_G5  , NOTE_G3  },
  { 0 ,	 NOTE_G5  , NOTE_G3  },
  { 0 ,	 NOTE_G5  , NOTE_G3  },
  { 0 ,	 NOTE_G5  , NOTE_G3  },
  { 0 ,	 NOTE_A5  , NOTE_A3  },
  { 0 ,	 NOTE_A5  , NOTE_A3  },
  { 0 ,	 NOTE_A5  , NOTE_A3  },
  { 0 ,	 NOTE_A5  , NOTE_A3  },
  { 0 ,	 NOTE_E5  , NOTE_A3  },
  { 0 ,	 NOTE_E5  , NOTE_A3  },
  { 0 ,	 NOTE_D5  , NOTE_A3  },
  { 0 ,	 NOTE_D5  , NOTE_A3  },
  { 0, -1, -1 }
};
// 2c
const Note p2c[] PROGMEM = {
  { 0 ,	 NOTE_B5  , NOTE_G3  },
  { 0 ,	 NOTE_B5  , NOTE_G3  },
  { 0 ,	 NOTE_B5  , NOTE_G3  },
  { 0 ,	 NOTE_B5  , NOTE_G3  },
  { 0 ,	 NOTE_G5  , NOTE_G3  },
  { 0 ,	 NOTE_G5  , NOTE_G3  },
  { 0 ,	 NOTE_G5  , NOTE_G3  },
  { 0 ,	 NOTE_G5  , NOTE_G3  },
  { 0 ,	 NOTE_A5  , NOTE_A3  },
  { 0 ,	 NOTE_A5  , NOTE_A3  },
  { 0 ,	 NOTE_A5  , NOTE_A3  },
  { 0 ,	 NOTE_A5  , NOTE_A3  },
  { 0 ,	 NOTE_E5  , NOTE_A3  },
  { 0 ,	 NOTE_E6  , NOTE_A3  },
  { 0 ,	 NOTE_D5  , NOTE_A3  },
  { 0 ,	 NOTE_D6  , NOTE_A3  },
  { 0, -1, -1 }
};

// Pattern 3: Faster Melody with Bass
// 3a
const Note p3a[] PROGMEM = {
  { 0 ,	 NOTE_B5  , NOTE_E3  },
  { 0 ,	 NOTE_B5  , NOTE_E3  },
  { 0 ,	 NOTE_B5  , NOTE_E3  },
  { 0 ,	 NOTE_B5  , NOTE_E3  },
  { 0 ,	 NOTE_D5  , NOTE_E4  },  
  { 0 ,	 NOTE_D5  , NOTE_E4  },  
  { 0 ,	 NOTE_D5  , NOTE_E4  },
  { 0 ,	 NOTE_D5  , NOTE_E4  },
  { 0 ,	 NOTE_G5  , NOTE_E3  },
  { 0 ,	 NOTE_G5  , NOTE_E3  },
  { 0 ,	 NOTE_G5  , NOTE_E3  },
  { 0 ,	 NOTE_G5  , NOTE_E3  },
  { 0 ,	 NOTE_D5  , NOTE_E4  },
  { 0 ,	 NOTE_D5  , NOTE_E4  },
  { 0 ,	 NOTE_D5  , NOTE_E4  },
  { 0 ,	 NOTE_D5  , NOTE_E4  },  
  { 0, -1, -1 }
};
// 3b
const Note p3b[] PROGMEM = {
  { 0 ,	 NOTE_A5  , NOTE_E3  },
  { 0 ,	 NOTE_A5  , NOTE_E3  },
  { 0 ,	 NOTE_A5  , NOTE_E3  },
  { 0 ,	 NOTE_A5  , NOTE_E3  },
  { 0 ,	 NOTE_D5  , NOTE_E4  },
  { 0 ,	 NOTE_D5  , NOTE_E4  },
  { 0 ,	 NOTE_D5  , NOTE_E4  },
  { 0 ,	 NOTE_D5  , NOTE_E4  },
  { 0 ,	 NOTE_E5  , NOTE_E3  },
  { 0 ,	 NOTE_E5  , NOTE_E3  },
  { 0 ,	 NOTE_D5  , NOTE_E3  },
  { 0 ,	 NOTE_D5  , NOTE_E3  },
  { 0 ,	 NOTE_B4  , NOTE_E3  },
  { 0 ,	 NOTE_B4  , NOTE_E3  },
  { 0 ,	 NOTE_D5  , NOTE_E3  },
  { 0 ,	 NOTE_D5  , NOTE_E3  },
  { 0, -1, -1 }
};
// 3c
const Note p3c[] PROGMEM = {
  { 0 ,	 NOTE_B5  , NOTE_G3  },
  { 0 ,	 NOTE_B5  , NOTE_G3  },
  { 0 ,	 NOTE_B5  , NOTE_G3  },
  { 0 ,	 NOTE_B5  , NOTE_G3  },
  { 0 ,	 NOTE_D5  , NOTE_G4  },  
  { 0 ,	 NOTE_D5  , NOTE_G4  },  
  { 0 ,	 NOTE_D5  , NOTE_G4  },
  { 0 ,	 NOTE_D5  , NOTE_G4  },
  { 0 ,	 NOTE_G5  , NOTE_G3  },
  { 0 ,	 NOTE_G5  , NOTE_G3  },
  { 0 ,	 NOTE_G5  , NOTE_G3  },
  { 0 ,	 NOTE_G5  , NOTE_G3  },
  { 0 ,	 NOTE_D5  , NOTE_G4  },
  { 0 ,	 NOTE_D5  , NOTE_G4  },
  { 0 ,	 NOTE_D5  , NOTE_G4  },
  { 0 ,	 NOTE_D5  , NOTE_G4  },  
  { 0, -1, -1 }
};
// 3d
const Note p3d[] PROGMEM = {
  { 0 ,	 NOTE_A5  , NOTE_A3  },
  { 0 ,	 NOTE_A5  , NOTE_A3  },  
  { 0 ,	 NOTE_A5  , NOTE_A3  },
  { 0 ,	 NOTE_A5  , NOTE_A3  },  
  { 0 ,	 NOTE_D5  , NOTE_A4  },
  { 0 ,	 NOTE_D5  , NOTE_A4  },  
  { 0 ,	 NOTE_D5  , NOTE_A4  },
  { 0 ,	 NOTE_D5  , NOTE_A4  },  
  { 0 ,	 NOTE_E5  , NOTE_A3  },
  { 0 ,	 NOTE_E5  , NOTE_A3  },  
  { 0 ,	 NOTE_D5  , NOTE_A3  },
  { 0 ,	 NOTE_D5  , NOTE_A3  },  
  { EFX_GLISS | EFX_VOICE1 | 1 ,	 NOTE_G5  , NOTE_A4  },
  { 0                          ,	 NOTE_G5  , NOTE_A4  },  
  { 0 , NOTE_FS5 , NOTE_A4  },
  { 0 , NOTE_FS6 , NOTE_A4  },  
  { 0, -1, -1 }
};

// Pattern 4: Fast Melody Arp Bass
// 4a
const Note p4a[] PROGMEM = {
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, 0, 0},
  { 0 ,	 NOTE_B5  , NOTE_B4        },
  { 0 ,	 NOTE_B5  , NOTE_B4        },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, 0, 0},
  { 0 ,	 NOTE_D5  , NOTE_D4        },  
  { 0 ,	 NOTE_D5  , NOTE_D4        },  
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, 0, 0},
  { 0 ,	 NOTE_G5  , NOTE_G4        },
  { 0 ,	 NOTE_G5  , NOTE_G4        },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, 0, 0},
  { 0 ,	 NOTE_D5  , NOTE_D4        },
  { 0 ,	 NOTE_D5  , NOTE_D4        },
  { 0, -1, -1 }
};
// 4b
const Note p4b[] PROGMEM = {
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, 0, 0},
  { 0 ,	 NOTE_A5  , NOTE_A4        },
  { 0 ,	 NOTE_A5  , NOTE_A4        },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, 0, 0},
  { 0 ,	 NOTE_D4  , NOTE_D3        },
  { 0 ,	 NOTE_D4  , NOTE_D3        },  
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_D5  , 0        },
  { 0 ,	 NOTE_D4  , 0        },  
  { 0 ,	 NOTE_D3  , 0        },  
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_D5  , 0        },
  { 0 ,	 NOTE_D4  , 0        },  
  { 0 ,	 NOTE_D3  , 0        },  
  { 0, -1, -1 }
};
// 4c
const Note p4c[] PROGMEM = {
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, 0, 0},
  { 0 ,	 NOTE_A5  , NOTE_A4        },
  { 0 ,	 NOTE_A5  , NOTE_A4        },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, 0, 0},
  { 0 ,	 NOTE_D4  , NOTE_D3        },
  { 0 ,	 NOTE_D4  , NOTE_D3        },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_E5  , 0        },
  { 0 ,	 NOTE_D5  , 0        },
  { 0 ,	 NOTE_D4  , 0        },  
  { EFX_GLISS | EFX_VOICE1 | 2 , NOTE_FS5 , 0  },
  { 0 ,  NOTE_FS4 , 0  },
  { 0 ,	 NOTE_FS5 , 0        },
  { 0 ,	 NOTE_FS6 , 0        },
  { 0, -1, -1 }
};

// Pattern 5: Fast Melody No Bass
// 5a
const Note p5a[] PROGMEM = {
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, 0, 0},
  { 0 ,	 NOTE_E5  , NOTE_E4        },
  { 0 ,	 NOTE_E5  , NOTE_E4        },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, 0, 0},
  { 0 ,	 NOTE_G5  , NOTE_G4        },  
  { 0 ,	 NOTE_G5  , NOTE_G4        },  
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_D4  , 0        },
  { 0 ,	 NOTE_B5  , 0        },
  { 0 ,	 NOTE_B4  , 0        },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_B5  , NOTE_B5        },
  { 0 ,	 NOTE_G4  , 0        },
  { 0 ,	 NOTE_G3  , 0        },
  { 0, -1, -1 }
};
// 5b
const Note p5b[] PROGMEM = {
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, 0, 0},
  { 0 ,	 NOTE_A5  , NOTE_A4        },
  { 0 ,	 NOTE_A5  , NOTE_A4        },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, 0, 0},
  { 0 ,	 NOTE_G5  , NOTE_G4        },
  { 0 ,	 NOTE_G5  , NOTE_G4        },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, 0, 0},
  { 0 ,	 NOTE_FS5  , NOTE_FS4        },
  { 0 ,	 NOTE_FS5  , NOTE_FS4        },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_E4 , 0        },
  { EFX_GLISS | EFX_VOICE1 | 1 ,	 NOTE_B5  , 0        },
  { EFX_GLISS | EFX_VOICE1 | 2 ,	 NOTE_B4  , 0        },
  { 0, -1, -1 }
};
// 5c
const Note p5c[] PROGMEM = {
  { 0 ,	 NOTE_B4  , 0        },
  { 0 ,	 NOTE_B3  , 0        },
  { 0 ,	 NOTE_D5  , 0        },
  { 0 ,	 NOTE_D4  , 0        },
  { 0 ,	 NOTE_E5  , 0        },
  { 0 ,	 NOTE_E4  , 0        },
  { 0 ,	 NOTE_B4  , 0        },
  { 0 ,	 NOTE_B3  , 0        },
  { 0 ,	 NOTE_G4  , NOTE_B5  },
  { 0 ,	 NOTE_B4  , NOTE_G4  },
  { 0 ,	 NOTE_FS5 , NOTE_B5  },
  { 0 ,	 NOTE_B4  , NOTE_FS5 },
  { 0 ,  NOTE_E5  , NOTE_B5  },
  { 0 ,  NOTE_B4  , NOTE_E5  },
  { 0 ,	 NOTE_D5  , NOTE_B5  },
  { 0 ,	 NOTE_B4  , NOTE_D5  },
  { 0, -1, -1 }
};

// Pattern 6: Acid-Lead with Drums
// 6a
const Note p6a[] PROGMEM = {
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { EFX_GLISS | EFX_VOICE1 | 5 , NOTE_B4  , 0  },
  { 0 ,	 NOTE_B5  , 0  },
  { 0 ,  NOTE_G5  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_E4  , 0  },
  { 0 ,	 NOTE_E5  , 0  },
  { 0 , NOTE_FS4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_G4  , 0  },  
  { 0 ,	 NOTE_G5  , 0  },  
  { EFX_GLISS | EFX_VOICE1 | 2 , NOTE_FS4  , 0  },  
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_D4  , 0 },  
  { 0 ,	 NOTE_D3  , 0  },  
  { 0 ,	 NOTE_D5  , 0  },  
  { 0, -1, -1 }
};
// 6b
const Note p6b[] PROGMEM = {
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_A4  , 0  },
  { 0 ,	 NOTE_A5  , 0  }, 
  { 0 ,	 NOTE_A4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { EFX_GLISS | EFX_VOICE1 | 5, NOTE_FS4  , 0  },
  { 0 ,  NOTE_E4  , 0  },
  { 0 ,  NOTE_D4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { EFX_GLISS | EFX_VOICE1 | 1, NOTE_FS5  , 0  },
  { 0 ,  NOTE_E5  , 0  },
  { 0 ,  NOTE_D5  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 , NOTE_D4  , 0  },
  { EFX_GLISS | EFX_VOICE1 | 1, NOTE_FS4  , 0  },
  { 0, NOTE_D4  , 0  },
  { 0, -1, -1 }
};
// 6c
const Note p6c[] PROGMEM = {
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_A3  , 0  }, 
  { 0 ,	 NOTE_A4  , 0  },
  { 0 ,	 NOTE_G4  , 0  },  
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,  NOTE_E4  , 0  },
  { 0 ,  NOTE_D4  , 0  },
  { 0 ,  NOTE_DS4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 , NOTE_B4   , 0  },  
  { EFX_GLISS | EFX_VOICE1 | 1 , NOTE_D5   , 0  },
  { 0 , NOTE_FS5  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { EFX_GLISS | EFX_VOICE1 | 1 , NOTE_E5   , 0  },
  { 0 , NOTE_FS5  , 0  },
  { 0 , NOTE_D5  , 0  },
  { 0, -1, -1 }
};

// Pattern 7: Moar Drums!
// 7a
const Note p7a[] PROGMEM = {
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { EFX_GLISS | EFX_VOICE1 | 2 , NOTE_B4  , 0  },
  { 0 ,	 NOTE_B3  , 0  },
  { 0 ,  NOTE_G5  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_E4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, NOTE_E5 },
  { 0 , NOTE_FS3  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_G4  , 0  },  
  { 0 ,	 NOTE_G3  , 0  },  
  { EFX_GLISS | EFX_VOICE1 | 2 , NOTE_FS3  , 0  },  
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_D4  , 0 },  
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, NOTE_D3 },
  { 0 ,	 NOTE_D5  , 0  },  
  { 0, -1, -1 }
};
// 7b
const Note p7b[] PROGMEM = {
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_A4  , 0  },
  { 0 ,	 NOTE_A3  , 0  }, 
  { 0 ,	 NOTE_A4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, NOTE_FS4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, NOTE_E4 },
  { 0 ,  NOTE_D4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 , NOTE_FS5  , 0  },
  { 0 ,  NOTE_E5  , 0  },
  { 0 ,  NOTE_D5  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 , NOTE_D4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, NOTE_FS4 },
  { 0, NOTE_D4  , 0  },
  { 0, -1, -1 }
};
// 7c
const Note p7c[] PROGMEM = {
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_A4  , 0  },
  { 0 ,	 NOTE_A3  , 0  }, 
  { 0 ,	 NOTE_A4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, NOTE_FS4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, NOTE_D4 },
  { 0 ,  NOTE_D4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 , NOTE_E4   , 0  }, 
  { 0 , NOTE_B4   , 0  },  
  { EFX_GLISS | EFX_VOICE1 | 1 , NOTE_D5   , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 , NOTE_G5   , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_D5, 0 },
  { 0 , NOTE_FS5  , 0  },
  { 0, -1, -1 }
};

// Pattern 8: Build Up to End
// 8a
const Note p8a[] PROGMEM = {
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 , NOTE_B4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,  NOTE_G5  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_E4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 , NOTE_FS3  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_G4  , 0  },  
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 , NOTE_FS3  , 0  },  
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_D4  , 0 },  
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_D5  , 0  },  
  { 0, -1, -1 }
};
// 8b
const Note p8b[] PROGMEM = {
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_A4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_A4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, NOTE_FS4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,  NOTE_D4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, NOTE_FS5  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,  NOTE_D5  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 , NOTE_D4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, NOTE_D4  , 0  },
  { 0, -1, -1 }
};
// 8c
const Note p8c[] PROGMEM = {
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_A4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_A4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, NOTE_FS4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,  NOTE_D4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 , NOTE_E4   , 0  }, 
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 , NOTE_D5   , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, -1, -1 }
};

// Pattern 9: Faster Melody with Bass
// 9a
const Note p9a[] PROGMEM = {
  { 0 ,	 NOTE_B5  , NOTE_E3  },
  { 0 ,	 NOTE_B5  , NOTE_E3  },
  { 0 ,	 NOTE_B4  , NOTE_E3  },
  { 0 ,	 NOTE_B4  , NOTE_E3  },
  { 0 ,	 NOTE_D5  , NOTE_E4  },  
  { 0 ,	 NOTE_D5  , NOTE_E4  },  
  { 0 ,	 NOTE_D6  , NOTE_E4  },
  { 0 ,	 NOTE_D6  , NOTE_E4  },
  { 0 ,	 NOTE_G5  , NOTE_E3  },
  { 0 ,	 NOTE_G5  , NOTE_E3  },
  { 0 ,	 NOTE_G4  , NOTE_E3  },
  { 0 ,	 NOTE_G4  , NOTE_E3  },
  { 0 ,	 NOTE_D5  , NOTE_E4  },
  { 0 ,	 NOTE_D5  , NOTE_E4  },
  { 0 ,	 NOTE_D6  , NOTE_E4  },
  { 0 ,	 NOTE_D6  , NOTE_E4  },  
  { 0, -1, -1 }
};
// 9b
const Note p9b[] PROGMEM = {
  { 0 ,	 NOTE_A5  , NOTE_E3  },
  { 0 ,	 NOTE_A5  , NOTE_E3  },
  { 0 ,	 NOTE_A4  , NOTE_E3  },
  { 0 ,	 NOTE_A4  , NOTE_E3  },
  { 0 ,	 NOTE_D5  , NOTE_E4  },
  { 0 ,	 NOTE_D5  , NOTE_E4  },
  { 0 ,	 NOTE_D6  , NOTE_E4  },
  { 0 ,	 NOTE_D6  , NOTE_E4  },
  { 0 ,	 NOTE_E5  , NOTE_E3  },
  { 0 ,	 NOTE_E5  , NOTE_E3  },
  { 0 ,	 NOTE_D5  , NOTE_E3  },
  { 0 ,	 NOTE_D5  , NOTE_E3  },
  { 0 ,	 NOTE_B4  , NOTE_E3  },
  { 0 ,	 NOTE_B4  , NOTE_E3  },
  { 0 ,	 NOTE_D5  , NOTE_E3  },
  { 0 ,	 NOTE_D5  , NOTE_E3  },
  { 0, -1, -1 }
};
// 9c
const Note p9c[] PROGMEM = {
  { 0 ,	 NOTE_B5  , NOTE_G3  },
  { 0 ,	 NOTE_B5  , NOTE_G3  },
  { 0 ,	 NOTE_B4  , NOTE_G3  },
  { 0 ,	 NOTE_B4  , NOTE_G3  },
  { 0 ,	 NOTE_D5  , NOTE_G4  },  
  { 0 ,	 NOTE_D5  , NOTE_G4  },  
  { 0 ,	 NOTE_D6  , NOTE_G4  },
  { 0 ,	 NOTE_D6  , NOTE_G4  },
  { 0 ,	 NOTE_G5  , NOTE_G3  },
  { 0 ,	 NOTE_G5  , NOTE_G3  },
  { 0 ,	 NOTE_G4  , NOTE_G3  },
  { 0 ,	 NOTE_G4  , NOTE_G3  },
  { 0 ,	 NOTE_D5  , NOTE_G4  },
  { 0 ,	 NOTE_D5  , NOTE_G4  },
  { 0 ,	 NOTE_D6  , NOTE_G4  },
  { 0 ,	 NOTE_D6  , NOTE_G4  },  
  { 0, -1, -1 }
};
// 9d
const Note p9d[] PROGMEM = {
  { 0 ,	 NOTE_A5  , NOTE_A3  },
  { 0 ,	 NOTE_A5  , NOTE_A3  },  
  { 0 ,	 NOTE_A4  , NOTE_A3  },
  { 0 ,	 NOTE_A4  , NOTE_A3  },  
  { 0 ,	 NOTE_D5  , NOTE_A4  },
  { 0 ,	 NOTE_D5  , NOTE_A4  },  
  { 0 ,	 NOTE_D6  , NOTE_A4  },
  { 0 ,	 NOTE_D6  , NOTE_A4  },  
  { 0 ,	 NOTE_E5  , NOTE_A3  },
  { 0 ,	 NOTE_E5  , NOTE_A3  },  
  { 0 ,	 NOTE_D5  , NOTE_A3  },
  { 0 ,	 NOTE_D5  , NOTE_A3  },  
  { EFX_GLISS | EFX_VOICE1 | 1 ,	 NOTE_G5  , NOTE_A4  },
  { 0 , NOTE_G5  , NOTE_A4  },  
  { 0 , NOTE_FS5 , NOTE_A4  },
  { 0 , NOTE_FS5 , NOTE_A4  },  
  { 0, -1, -1 }
};
// 9e
const Note p9e[] PROGMEM = {
  { 0 ,	 NOTE_A5  , NOTE_A3  },
  { 0 ,	 NOTE_A5  , NOTE_A3  },  
  { 0 ,	 NOTE_A4  , NOTE_A3  },
  { 0 ,	 NOTE_A4  , NOTE_A3  },  
  { 0 ,	 NOTE_D5  , NOTE_A4  },
  { 0 ,	 NOTE_D5  , NOTE_A4  },  
  { 0 ,	 NOTE_D6  , NOTE_A4  },
  { 0 ,	 NOTE_D6  , NOTE_A4  },  
  { 0 ,	 NOTE_E5  , NOTE_A3  },
  { 0 ,	 NOTE_E5  , NOTE_A3  },  
  { 0 ,	 NOTE_D5  , NOTE_A3  },
  { 0 ,	 NOTE_D5  , NOTE_A3  },  
  { 0 ,	 NOTE_G6  , NOTE_A4  },
  { 0 ,  NOTE_G5  , NOTE_A4  },  
  { 0 ,  NOTE_FS6 , NOTE_A4  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 1,  NOTE_FS5 , 0  },  
  { 0, -1, -1 }
};

/*
 * Ordering of patterns. Think of this like an order list in a conventional tracker.
 * Notice that the patterns need not be sequential in their ordering
 * (e.g. pattern 9 comes after pattern 3; pattern 1 is re-used at the end)
 */
const Note *score[] PROGMEM = {
  p1a, p1b, p1c, p1d,  // Intro Chords
  p1e, p1b, p1c, p1d,  // Repeat, with Variation
  p2a, p2b, p2a, p2c,  // Slow Melody With Bass
  p2a, p2b, p2a, p2c,  // Repeat
  p3a, p3b, p3c, p3d,  // Slow Melody With Chords
  p3a, p3b, p3c, p3d,  // Repeat
  p9a, p9b, p9c, p9d,  // Fancy Melody With Chords
  p9a, p9b, p9c, p9e,  // Repeat, with Variation
  p4a, p4b, p4a, p4c,  // Enter Drums! Go EDM!
  p4a, p4b, p4a, p4c,  // Repeat
  p5a, p5b, p5a, p5c,  // Enter Drums, Part 2
  p5a, p5b, p5a, p5c,  // Repeat
  p6a, p6b, p6a, p6c,  // Crazy Acid-Like Lead
  p6a, p6b, p6a, p6c,  // Repeat
  p7a, p7b, p7a, p7c,  // Moar Drums!
  p8a, p8b, p8a, p8c,  // RAWR!
  p1a, p1b, p1c, p1d,  // End on Chords
  p1e, p1b, p1c, p1d,  // These are longer to
  p1a, p1b, p1c, p1d,  // blend into Victim Cache's
  p1e, p1b, p1c, p1d,  // Intro song
  0                    // End
};

