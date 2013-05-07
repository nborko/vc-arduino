#include "pitches.h"

  // Arp Chords for first part
  // Pattern 1:
const Note p1a[] PROGMEM = {
  // 1a
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
const Note p1b[] PROGMEM = {
  // 1b
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
const Note p1c[] PROGMEM = {
  // 1c
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
const Note p1d[] PROGMEM = {
  // 1d
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
  // Slow Melody with bass
  // Pattern 2
const Note p2a[] PROGMEM = {
  // 2a
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
const Note p2b[] PROGMEM = {
  // 2b
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
  // Faster Melody with Bass
  // Pattern 3:
const Note p3a[] PROGMEM = {
  // 3a
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
const Note p3b[] PROGMEM = {
  // 3b
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
const Note p3c[] PROGMEM = {
  // 3c
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
  { EFX_GLISS | EFX_VOICE1 | 1 ,	 NOTE_G5  , NOTE_E3  },
  { 0                          ,	 NOTE_G5  , NOTE_E3  },  
  { 0 , NOTE_FS5 , NOTE_E3  },
  { 0 , NOTE_FS5 , NOTE_E3  },  
  { 0, -1, -1 }
};

  // Fast Melody Arp Bass
  // Pattern 4:
const Note p4a[] PROGMEM = {
  // 4a
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

const Note p4b[] PROGMEM = {
  // 4b
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, 0, 0},
  { 0 ,	 NOTE_A5  , NOTE_A4        },
  { 0 ,	 NOTE_A5  , NOTE_A4        },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, 0, 0},
  { 0 ,	 NOTE_D4  , NOTE_D3        },
  { 0 ,	 NOTE_D4  , NOTE_D3        },  
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, 0, 0},
  { 0 ,	 NOTE_D5  , 0        },
  { 0 ,	 NOTE_D4  , 0        },  
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0, 0, 0},
  { 0 ,	 NOTE_D5  , 0        },
  { 0 ,	 NOTE_D4  , 0        },  
  { 0, -1, -1 }
};

const Note p4c[] PROGMEM = {
  // 4c
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
  { 0 ,  NOTE_FS5 , 0  },
  { 0 ,	 NOTE_FS4 , 0        },
  { 0 ,	 NOTE_FS3 , 0        },
  { 0, -1, -1 }
};

  // Fast Melody No Bass
  // Pattern 5:
const Note p5a[] PROGMEM = {
  // 5a
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
const Note p5c[] PROGMEM = {
  // 5c
  { 0 ,	 NOTE_B4  , 0        },
  { 0 ,	 NOTE_B3  , 0        },
  { 0 ,	 NOTE_D5  , 0        },
  { 0 ,	 NOTE_D4  , 0        },
  { 0 ,	 NOTE_E5  , 0        },
  { 0 ,	 NOTE_E4  , 0        },
  { 0 ,	 NOTE_B4 , 0        },
  { 0 ,	 NOTE_B3 , 0        },
  { 0 ,	 NOTE_G4, NOTE_B5        },
  { 0 ,	 NOTE_B4, NOTE_G4        },
  { 0 ,	 NOTE_FS5 , NOTE_B5        },
  { 0 ,	 NOTE_B4 , NOTE_FS5        },
  { 0 ,  NOTE_E5 , NOTE_B5  },
  { 0 ,  NOTE_B4 , NOTE_E5  },
  { 0 ,	 NOTE_D5, NOTE_B5        },
  { 0 ,	 NOTE_B4, NOTE_D5        },
  // Loop (not)
  { 0 ,	 -1       ,-1  }
};

// Pattern 6: Fast Leads
const Note p6a[] PROGMEM = {
  // 6a
  { 0 ,	 NOTE_B5  , 0  },
  { EFX_GLISS | EFX_VOICE1 | 2 , NOTE_B4  , 0  },
  { 0 ,	 NOTE_B3  , 0  },
  { 0 ,  NOTE_G5  , 0  },
  { 0 ,  NOTE_E5  , 0  },  
  { 0 ,	 NOTE_E4  , 0  },
  { 0 ,	 NOTE_E3  , 0  },
  { EFX_GLISS | EFX_VOICE1 | 1 , NOTE_FS3  , 0  },
  { 0 ,	 NOTE_G5  , 0  },
  { 0 ,	 NOTE_G4  , 0  },  
  { 0 ,	 NOTE_G3  , 0  },  
  { EFX_GLISS | EFX_VOICE1 | 2 , NOTE_FS3  , 0  },  
  { 0 ,	 NOTE_D5  , 0  },
  { 0 ,	 NOTE_D4  , 0 },  
  { 0 ,	 NOTE_D3  , 0  },  
  { 0 ,	 NOTE_D5  , 0  },  
  { 0, -1, -1 }
};

const Note p6b[] PROGMEM = {
  // 6b
  { 0 ,	 NOTE_A5  , 0  },
  { 0 ,	 NOTE_A4  , 0  },
  { 0 ,	 NOTE_A3  , 0  }, 
  { 0 ,	 NOTE_A4  , 0  },
  { 0 ,	 NOTE_G4  , 0  },  
  { EFX_GLISS | EFX_VOICE1 | 1, NOTE_FS4  , 0  },
  { 0 ,  NOTE_E4  , 0  },
  { 0 ,  NOTE_D4  , 0  },
  { 0 ,	 NOTE_G5  , 0  },  
  { EFX_GLISS | EFX_VOICE1 | 1, NOTE_FS5  , 0  },
  { 0 ,  NOTE_E5  , 0  },
  { 0 ,  NOTE_D5  , 0  },
  { 0 , NOTE_B3  , 0  },
  { 0 , NOTE_D4  , 0  },
  { EFX_GLISS | EFX_VOICE1 | 1, NOTE_FS4  , 0  },
  { 0, NOTE_D4  , 0  },
  { 0, -1, -1 }
};

const Note p6c[] PROGMEM = {
  // 6c
  { 0 ,	 NOTE_A5  , 0  },
  { 0 ,	 NOTE_A4  , 0  },
  { 0 ,	 NOTE_A3  , 0  }, 
  { 0 ,	 NOTE_A4  , 0  },
  { 0 ,	 NOTE_G4  , 0  },  
  { EFX_GLISS | EFX_VOICE1 | 1, NOTE_FS4  , 0  },
  { 0 ,  NOTE_E4  , 0  },
  { 0 ,  NOTE_D4  , 0  },
  { 0 ,  NOTE_DS4  , 0  },
  { 0 , NOTE_E4   , 0  }, 
  { 0 , NOTE_B4   , 0  },  
  { EFX_GLISS | EFX_VOICE1 | 1 , NOTE_D5   , 0  },
  { 0 , NOTE_FS5  , 0  },
  { 0 , NOTE_G5   , 0  },
  { EFX_GLISS | EFX_VOICE1 | 1 , NOTE_E5   , 0  },
  { 0 , NOTE_FS5  , 0  },
  { 0, -1, -1 }
};

// Pattern 7: Leads, Bassdrum
const Note p7a[] PROGMEM = {
  // 7a
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { EFX_GLISS | EFX_VOICE1 | 2 , NOTE_B4  , 0  },
  { 0 ,	 NOTE_B3  , 0  },
  { 0 ,  NOTE_G5  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_E4  , 0  },
  { 0 ,	 NOTE_E3  , 0  },
  { EFX_GLISS | EFX_VOICE1 | 1 , NOTE_FS3  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_G4  , 0  },  
  { 0 ,	 NOTE_G3  , 0  },  
  { EFX_GLISS | EFX_VOICE1 | 2 , NOTE_FS3  , 0  },  
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_D4  , 0 },  
  { 0 ,	 NOTE_D3  , 0  },  
  { 0 ,	 NOTE_D5  , 0  },  
  { 0, -1, -1 }
};

const Note p7b[] PROGMEM = {
  // 7b
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_A4  , 0  },
  { 0 ,	 NOTE_A3  , 0  }, 
  { 0 ,	 NOTE_A4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { EFX_GLISS | EFX_VOICE1 | 1, NOTE_FS4  , 0  },
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

const Note p7c[] PROGMEM = {
  // 7c
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 ,	 NOTE_A4  , 0  },
  { 0 ,	 NOTE_A3  , 0  }, 
  { 0 ,	 NOTE_A4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { EFX_GLISS | EFX_VOICE1 | 1, NOTE_FS4  , 0  },
  { 0 ,  NOTE_E4  , 0  },
  { 0 ,  NOTE_D4  , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 , NOTE_E4   , 0  }, 
  { 0 , NOTE_B4   , 0  },  
  { EFX_GLISS | EFX_VOICE1 | 1 , NOTE_D5   , 0  },
  { EFX_SLIDE_DN | EFX_VOICE1 | 10, NOTE_C5, 0 },
  { 0 , NOTE_G5   , 0  },
  { EFX_GLISS | EFX_VOICE1 | 1 , NOTE_E5   , 0  },
  { 0 , NOTE_FS5  , 0  },
  { 0, -1, -1 }
};

// Pattern 8: Build Up to End
const Note p8a[] PROGMEM = {
  // 8a
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

const Note p8b[] PROGMEM = {
  // 8b
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

const Note p8c[] PROGMEM = {
  // 8c
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

  // Faster Melody with Bass
  // Pattern 9:
const Note p9a[] PROGMEM = {
  // 9a
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
const Note p9b[] PROGMEM = {
  // 9b
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
const Note p9c[] PROGMEM = {
  // 9c
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
  { EFX_GLISS | EFX_VOICE1 | 1 ,	 NOTE_G5  , NOTE_E3  },
  { 0                          ,	 NOTE_G5  , NOTE_E3  },  
  { 0 , NOTE_FS5 , NOTE_E3  },
  { 0 , NOTE_FS5 , NOTE_E3  },  
  { 0, -1, -1 }
};


/*
// Even Faster Melody with Bass
// Pattern 9:
const Note p9a[] PROGMEM = {
  // 9a
  { 0 ,	 NOTE_B5  , NOTE_B3  },
  { 0 ,	 NOTE_G5  , NOTE_B3  },
  { 0 ,	 NOTE_FS5 , NOTE_B3  },
  { 0 ,	 NOTE_E5  , NOTE_B3  },

  { 0 ,	 NOTE_D5  , NOTE_B4  },  
  { 0 ,	 NOTE_FS5 , NOTE_B4  },  
  { 0 ,	 NOTE_G5  , NOTE_B4  },
  { 0 ,	 NOTE_FS5 , NOTE_B4  },

  { 0 ,	 NOTE_G5  , NOTE_B3  },
  { 0 ,	 NOTE_FS5 , NOTE_B3  },
  { 0 ,	 NOTE_E5  , NOTE_B3  },
  { 0 ,	 NOTE_B4  , NOTE_B3  },

  { 0 ,	 NOTE_D5  , NOTE_B4  },  
  { 0 ,	 NOTE_FS5 , NOTE_B4  },  
  { 0 ,	 NOTE_G5  , NOTE_B4  },
  { 0 ,	 NOTE_FS5 , NOTE_B4  },
  { 0, -1, -1 }
};
const Note p9b[] PROGMEM = {
  // 9b
  { 0 ,	 NOTE_A5  , NOTE_E3  },
  { 0 ,	 NOTE_G5  , NOTE_E3  },
  { 0 ,	 NOTE_FS5 , NOTE_E3  },
  { 0 ,	 NOTE_G5  , NOTE_E3  },

  { 0 ,	 NOTE_D5  , NOTE_E4  },
  { 0 ,	 NOTE_B4  , NOTE_E4  },
  { 0 ,	 NOTE_FS5 , NOTE_E4  },
  { 0 ,	 NOTE_G5  , NOTE_E4  },
 
  { 0 ,	 NOTE_E5  , NOTE_E3  },
  { 0 ,	 NOTE_B4  , NOTE_E3  },
 
  { 0 ,	 NOTE_D5  , NOTE_E3  },
  { 0 ,	 NOTE_FS4 , NOTE_E3  },
 
  { 0 ,	 NOTE_B4  , NOTE_E3  },
  { 0 ,	 NOTE_E4  , NOTE_E3  },
 
  { 0 ,	 NOTE_D5  , NOTE_E3  },
  { 0 ,	 NOTE_FS5 , NOTE_E3  },
  { 0, -1, -1 }
};
const Note p9c[] PROGMEM = {
  // 9c
  { 0 ,	 NOTE_A5  , NOTE_E3  },
  { 0 ,	 NOTE_A4  , NOTE_E3  },  
  { 0 ,	 NOTE_A5  , NOTE_E3  },
  { 0 ,	 NOTE_A4  , NOTE_E3  },  
  { 0 ,	 NOTE_D5  , NOTE_E4  },
  { 0 ,	 NOTE_D4  , NOTE_E4  },  
  { 0 ,	 NOTE_D5  , NOTE_E4  },
  { 0 ,	 NOTE_D4  , NOTE_E4  },  
  { 0 ,	 NOTE_E5  , NOTE_E3  },
  { 0 ,	 NOTE_E4  , NOTE_E3  },  
  { 0 ,	 NOTE_D5  , NOTE_E3  },
  { 0 ,	 NOTE_D4  , NOTE_E3  },  
  { EFX_GLISS | EFX_VOICE1 | 1 ,	 NOTE_G5  , NOTE_E3  },
  { 0                          ,	 NOTE_G4  , NOTE_E3  },  
  { 0 , NOTE_FS5 , NOTE_E3  },
  { 0 , NOTE_FS4 , NOTE_E3  },  
  { 0, -1, -1 }
};
*/

const Note *score[] PROGMEM = {
  p1a, p1b, p1c, p1d,  // Intro Chords
  p1a, p1b, p1c, p1d,
  p2a, p2b, p2a, p2b,  // Slow Melody With Bass
  p2a, p2b, p2a, p2b,
  p3a, p3b, p3a, p3c,  // Slow Melody With Chords
  p3a, p3b, p3a, p3c,
  p9a, p9b, p9a, p9c,  // Fancy Melody With Chords
  p9a, p9b, p9a, p9c,
  p4a, p4b, p4a, p4c,  // Enter Drums! Go EDM!
  p4a, p4b, p4a, p4c,
  p5a, p5b, p5a, p5c,  // Enter Drums, Part 2
  p5a, p5b, p5a, p5c,
  p6a, p6b, p6a, p6c,  // Crazy Acid-Like Lead
  p6a, p6b, p6a, p6c,
  p7a, p7b, p7a, p7c,  // Moar Drums!
  p8a, p8b, p8a, p8c,  // RAWR!
  p1a, p1a,             // And End on Chords
  /*
  p1a, p1b, p1c, p1d,
  p1a, p1b, p1c, p1d,
  p2a, p2b, p2a, p2b, 
  p2a, p2b, p2a, p2b,
  p3a, p3b, p3a, p3c,
  p3a, p3b, p3a, p3c,
  p9a, p9b, p9a, p9c,
  p9a, p9b, p9a, p9c,
  p6a, p6b, p6a, p6c,
  p6a, p6b, p6a, p6c,
  p4a, p4b, p4a, p4c,
  p4a, p4b, p4a, p4c,
  p5a, p5b, p5a, p5c,
  p5a, p5b, p5a, p5c,
  p7a, p7b, p7a, p7c,
  p8a, p8b, p8a, p8c,
  p1a, p1b, p1c, p1d,
  p1a, p1b, p1c, p1d,
  */
  0
};

/*
const Note pattern[] PROGMEM = {
  //{ 0, 440, 0, 1 },{ 0, 440, 0, 1 }, {0, -1, -1, 0}, //test tone, 440Hz
  { 0,       0, NOTE_E2 },
  { 0, NOTE_E4, NOTE_E2 },
  { 0, NOTE_A4, NOTE_A3 },
  { 0, NOTE_C5, NOTE_A3 },
  { 0, NOTE_B4, NOTE_A3 },
  { 0, NOTE_E4, NOTE_A3 },
  { 0, NOTE_B4, NOTE_GS3 },
  { 0, NOTE_D5, NOTE_GS3 },
  { 0, NOTE_C5, NOTE_A3 },
  { 0, NOTE_C5, NOTE_E3 },
  { 0, NOTE_E5, NOTE_A3 },
  { 0, NOTE_E5, NOTE_C4 },
  { 0, NOTE_GS4, NOTE_B3 },
  { 0, NOTE_GS4, NOTE_E3 },
  { 0, NOTE_E5, NOTE_B3 },
  { 0, NOTE_E5, NOTE_D4 },
  { 0, NOTE_A4, NOTE_C4 },
  { 0, NOTE_E4, NOTE_C4 },
  { 0, NOTE_A4, NOTE_A3 },
  { 0, NOTE_C5, NOTE_A3 },
  { 0, NOTE_B4, NOTE_GS3 },
  { 0, NOTE_E4, NOTE_GS3 },
  { 0, NOTE_B4, NOTE_E3 },
  { 0, NOTE_D5, NOTE_E3 },
  { 0, NOTE_C5, NOTE_A3 },
  { 0, NOTE_C5, NOTE_E3 },
  { 0, NOTE_A4, NOTE_A3 },
  { 0, NOTE_A4, NOTE_C4 },
  { 0,       0, NOTE_B3 },
  { 0,       0, NOTE_E3 },
  { 0,       0, NOTE_B3 },
  { 0,       0, NOTE_D4 },
  { 0,       0, NOTE_C4 },
  { 0, NOTE_E5, NOTE_C4 },
  { 0, NOTE_C5, NOTE_A3 },
  { 0, NOTE_E5, NOTE_A3 },
  { 0, NOTE_A4, NOTE_C4 },
  { 0, NOTE_C5, NOTE_C4 },
  { 0, NOTE_E4, NOTE_A3 },
  { 0, NOTE_G4, NOTE_A3 },
  { 0, NOTE_F4, NOTE_D4 },
  { 0, NOTE_F4, NOTE_A3 },
  { 0, NOTE_A4, NOTE_F3 },
  { 0, NOTE_A4, NOTE_A3 },
  { 0, NOTE_D5, NOTE_D3 },
  { 0, NOTE_D5, NOTE_F3 },
  { 0, NOTE_F5, NOTE_E2 },
  { 0, NOTE_F5, NOTE_C3 },
  { 0, NOTE_F5, NOTE_B2 },
  { 0, NOTE_D5, NOTE_B2 },
  { 0, NOTE_B4, NOTE_D3 },
  { 0, NOTE_D5, NOTE_D3 },
  { 0, NOTE_G4, NOTE_E3 },
  { 0, NOTE_B4, NOTE_E3 },
  { 0, NOTE_D4, NOTE_B3 },
  { 0, NOTE_F4, NOTE_B3 },
  { 0, NOTE_E4, NOTE_B3 },
  { 0, NOTE_E4, NOTE_E3 },
  { 0, NOTE_G4, NOTE_C3 },
  { 0, NOTE_G4, NOTE_E3 },
  { 0, NOTE_C5, NOTE_A2 },
  { 0, NOTE_C5, NOTE_C3 },
  { 0, NOTE_E5, NOTE_G2 },
  { 0, NOTE_E5, NOTE_B2 },
  { 0, NOTE_E5, NOTE_A2 },
  { 0, NOTE_C5, NOTE_A2 },
  { 0, NOTE_A4, NOTE_C3 },
  { 0, NOTE_C5, NOTE_C3 },
  { 0, NOTE_F4, NOTE_D3 },
  { 0, NOTE_F4, NOTE_F3 },
  { 0, NOTE_D5, NOTE_B2 },
  { 0, NOTE_D5, NOTE_D3 },
  { 0, NOTE_D5, NOTE_G2 },
  { 0, NOTE_B4, NOTE_G2 },
  { 0, NOTE_G4, NOTE_B2 },
  { 0, NOTE_B4, NOTE_B2 },
  { 0, NOTE_E4, NOTE_C3 },
  { 0, NOTE_E4, NOTE_E3 },
  { 0, NOTE_C5, NOTE_A2 },
  { 0, NOTE_C5, NOTE_C3 },
  { 0, NOTE_C5, NOTE_F2 },
  { 0, NOTE_A4, NOTE_F2 },
  { 0, NOTE_F4, NOTE_G2 },
  { 0, NOTE_A4, NOTE_G2 },
  { 0, NOTE_D4, NOTE_G2 },
  { 0, NOTE_D4, NOTE_G3 },
  { 0, NOTE_B4, NOTE_F3 },
  { 0, NOTE_B4, NOTE_G3 },
  { 0, NOTE_C5, NOTE_C3 },
  { 0, NOTE_C5, NOTE_G3 },
  { 0,       0, NOTE_C4 },
  { 0,       0, NOTE_E4 },
  { 0,       0, NOTE_D4 },
  { 0,       0, NOTE_G3 },
  { 0,       0, NOTE_D4 },
  { 0,       0, NOTE_F4 },
  { 0,       0, NOTE_E4 },
  { 0, NOTE_G4, NOTE_E4 },
  { 0, NOTE_C5, NOTE_C4 },
  { 0, NOTE_E5, NOTE_C4 },
  { 0, NOTE_D5, NOTE_B3 },
  { 0, NOTE_G4, NOTE_B3 },
  { 0, NOTE_D5, NOTE_G3 },
  { 0, NOTE_F5, NOTE_G3 },
  { 0, NOTE_E5, NOTE_C4 },
  { 0, NOTE_E5, NOTE_G3 },
  { 0, NOTE_G5, NOTE_C4 },
  { 0, NOTE_G5, NOTE_E4 },
  { 0, NOTE_B4, NOTE_D4 },
  { 0, NOTE_B4, NOTE_G3 },
  { 0, NOTE_G5, NOTE_D4 },
  { 0, NOTE_G5, NOTE_F4 },
  { 0, NOTE_C5, NOTE_E4 },
  { 0, NOTE_G4, NOTE_E4 },
  { 0, NOTE_C5, NOTE_C4 },
  { 0, NOTE_E5, NOTE_C4 },
  { 0, NOTE_D5,       0 },
  { 0, NOTE_G4,       0 },
  { 0, NOTE_D5,       0 },
  { 0, NOTE_F5,       0 },
  { 0, NOTE_E5,       0 },
  { 0, NOTE_E5, NOTE_G4 },
  { 0, NOTE_C5, NOTE_E4 },
  { 0, NOTE_C5, NOTE_G4 },
  { 0, NOTE_G5, NOTE_C4 },
  { 0, NOTE_G5, NOTE_E4 },
  { 0, NOTE_E5, NOTE_G3 },
  { 0, NOTE_E5, NOTE_B3 },
  { 0, NOTE_C6, NOTE_A3 },
  { 0, NOTE_A5, NOTE_A3 },
  { 0, NOTE_E5, NOTE_C4 },
  { 0, NOTE_A5, NOTE_C4 },
  { 0, NOTE_C5, NOTE_E4 },
  { 0, NOTE_E5, NOTE_E4 },
  { 0, NOTE_A4, NOTE_G4 },
  { 0, NOTE_C5, NOTE_G4 },
  { 0, NOTE_D5, NOTE_FS4 },
  { 0, NOTE_D5, NOTE_A4 },
  { 0, NOTE_FS5, NOTE_D4 },
  { 0, NOTE_FS5, NOTE_FS4 },
  { 0, NOTE_A5, NOTE_A3 },
  { 0, NOTE_A5, NOTE_D4 },
  { 0, NOTE_C6, NOTE_FS3 },
  { 0, NOTE_C6, NOTE_A3 },
  { 0, NOTE_B5, NOTE_G3 },
  { 0, NOTE_G5, NOTE_G3 },
  { 0, NOTE_D5, NOTE_B3 },
  { 0, NOTE_G5, NOTE_B3 },
  { 0, NOTE_B4, NOTE_D4 },
  { 0, NOTE_D5, NOTE_D4 },
  { 0, NOTE_G4, NOTE_FS4 },
  { 0, NOTE_B4, NOTE_FS4 },
  { 0, NOTE_C5, NOTE_E4 },
  { 0, NOTE_C5, NOTE_G4 },
  { 0, NOTE_E5, NOTE_C4 },
  { 0, NOTE_E5, NOTE_E4 },
  { 0, NOTE_G5, NOTE_G3 },
  { 0, NOTE_G5, NOTE_C4 },
  { 0, NOTE_B5, NOTE_E3 },
  { 0, NOTE_B5, NOTE_G3 },
  { 0, NOTE_A5, NOTE_FS3 },
  { 0, NOTE_FS5, NOTE_FS3 },
  { 0, NOTE_DS5, NOTE_A3 },
  { 0, NOTE_FS5, NOTE_A3 },
  { 0, NOTE_B4, NOTE_B3 },
  { 0, NOTE_DS5, NOTE_B3 },
  { 0, NOTE_FS4, NOTE_DS4 },
  { 0, NOTE_A4, NOTE_DS4 },
  { 0, NOTE_G4,       0 },
  { 0, NOTE_G4, NOTE_E4 },
  { 0, NOTE_G5, NOTE_C4 },
  { 0, NOTE_G5, NOTE_E4 },
  { 0, NOTE_G5, NOTE_A3 },
  { 0, NOTE_E5, NOTE_C4 },
  { 0, NOTE_C5, NOTE_E4 },
  { 0, NOTE_E5, NOTE_G4 },
  { 0, NOTE_A4, NOTE_FS4 },
  { 0, NOTE_A4, NOTE_D4 },
  { 0, NOTE_FS5, NOTE_B3 },
  { 0, NOTE_FS5, NOTE_D4 },
  { 0, NOTE_FS5, NOTE_G3 },
  { 0, NOTE_D5, NOTE_B3 },
  { 0, NOTE_B4, NOTE_D4 },
  { 0, NOTE_D5, NOTE_FS4 },
  { 0, NOTE_G4, NOTE_E4 },
  { 0, NOTE_G4, NOTE_C4 },
  { 0, NOTE_E5, NOTE_A3 },
  { 0, NOTE_E5, NOTE_C4 },
  { 0, NOTE_E5, NOTE_FS3 },
  { 0, NOTE_C5, NOTE_A3 },
  { 0, NOTE_A4, NOTE_C4 },
  { 0, NOTE_C5, NOTE_C4 },
  { 0, NOTE_FS4, NOTE_C4 },
  { 0, NOTE_G5, NOTE_B3 },
  { 0, NOTE_FS5, NOTE_C4 },
  { 0, NOTE_E5, NOTE_A3 },
  { 0, NOTE_DS5, NOTE_B3 },
  { 0, NOTE_FS5, NOTE_B3 },
  { 0, NOTE_B4, NOTE_B2 },
  { 0, NOTE_DS5, NOTE_B2 },
  { 0, NOTE_E5, NOTE_E3 },
  { 0, NOTE_E5, NOTE_E4 },
  { 0,       0, NOTE_B3 },
  { 0,       0, NOTE_G3 },
  { 0,       0, NOTE_E3 },
  { 0,       0, NOTE_B2 },
  { 0,       0, NOTE_G2 },
  { 0,       0, NOTE_B2 },
  { 0,       0, NOTE_E2 },
  { 0,       0, NOTE_E2 },
  { 0,       0, NOTE_E2 },
  { 0,       0, NOTE_E2 },
  { 0, 0, 0 },
  { 0, 0, 0 },
  { 0, 0, 0 },
  { 0, 0, 0 },
  { 0, -1, -1 }
};
const Note *score[] PROGMEM = { pattern, 0 };
*/

