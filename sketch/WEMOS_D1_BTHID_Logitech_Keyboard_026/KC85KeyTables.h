const KC_Key kc_key[4][255] PROGMEM = 
{
  // 1. Zeichentabelle  (Tastatur: MROS113)
  { 
       { 0x04, 0xFF, 0x3A, "Zeichentabelle 1 (MROS113)" }     // ALT-F1
      ,{ 0x04, 0xFF, 0x3B, "ABCDEFGHIJKLMNOPQRSTUVWXYZ" }     // ALT-F2
      ,{ 0x04, 0xFF, 0x3C, "Programmiererin: Jona Scheidat" } // ALT-F3
    
      //----------------------------------------------
    
      // Arrow-Tasten, ENTER & Leertaste
      ,{ 0x00, 0x00, 0x4F, "\x09" } // RIGHT
      ,{ 0x00, 0x00, 0x50, "\x08" } // LEFT
      ,{ 0x00, 0x00, 0x51, "\x0A" } // DOWN
      ,{ 0x00, 0x00, 0x52, "\x0B" } // UP
    
      ,{ 0x00, 0x00, 0x28, "\x0D" } // ENTER
      ,{ 0x00, 0x00, 0x2C, " " }    // SPACE
      // mit Numtaste
      ,{ 0x00, 0x00, 0x58, "\x0D" } // ENTER
      
      // Ziffern
      ,{ 0x00, 0xFF, 0x1E, "1" }    // char '1'
      ,{ 0x00, 0xFF, 0x1F, "2" }
      ,{ 0x00, 0xFF, 0x20, "3" }
      ,{ 0x00, 0xFF, 0x21, "4" }
      ,{ 0x00, 0xFF, 0x22, "5" }
      ,{ 0x00, 0xFF, 0x23, "6" }
      ,{ 0x00, 0xFF, 0x24, "7" }
      ,{ 0x00, 0xFF, 0x25, "8" }
      ,{ 0x00, 0xFF, 0x26, "9" }
      ,{ 0x00, 0xFF, 0x27, "0" }
    
      // Zweitbelegung (SHIFT) der Ziffern
      ,{ 0x02, 0xFF, 0x1E, "!" }    // char '!'
      ,{ 0x02, 0xFF, 0x1F, "\x22" } // char '"'
      ,{ 0x02, 0xFF, 0x20, " " }    // zurzeit nicht benutzt
      ,{ 0x02, 0xFF, 0x21, "$" }
      ,{ 0x02, 0xFF, 0x22, "%" }
      ,{ 0x02, 0xFF, 0x23, "&" }
      ,{ 0x02, 0xFF, 0x24, "/" }
      ,{ 0x02, 0xFF, 0x25, "(" }
      ,{ 0x02, 0xFF, 0x26, ")" }
      ,{ 0x02, 0xFF, 0x27, "=" }
    
      // Sonderzeichen
      ,{ 0x00, 0xFF, 0x2D, "ss" }
      ,{ 0x00, 0xFF, 0x2E, "´" }
      ,{ 0x00, 0xFF, 0x2F, "ue" }
      ,{ 0x00, 0xFF, 0x30, "+" }
      ,{ 0x00, 0xFF, 0x31, "#" }
      ,{ 0x00, 0xFF, 0x33, "oe" }
      ,{ 0x00, 0xFF, 0x34, "ae" }
      ,{ 0x00, 0xFF, 0x35, "^" }
      ,{ 0x00, 0xFF, 0x36, "," }
      ,{ 0x00, 0xFF, 0x37, "." }
      ,{ 0x00, 0xFF, 0x38, "-" }
    
      // Zweitbelegung (SHIFT) der Sonderzeichen
      ,{ 0x02, 0xFF, 0x2D, "?" }
      ,{ 0x02, 0xFF, 0x2E, "`" }
      ,{ 0x02, 0xFF, 0x2F, "Ue" }
      ,{ 0x02, 0xFF, 0x30, "*" }
      ,{ 0x02, 0xFF, 0x31, "'" }
      ,{ 0x02, 0xFF, 0x33, "Oe" }
      ,{ 0x02, 0xFF, 0x34, "Ae" }
      ,{ 0x00, 0xFF, 0x35, "\x5D" } // Haken rechts oben
      ,{ 0x02, 0xFF, 0x36, ";" }
      ,{ 0x02, 0xFF, 0x37, ":" }
      ,{ 0x02, 0xFF, 0x38, "_" }
    
      // @-Zeichen 
      ,{ 0x05, 0xDD, 0x14, "@" }    // STRG-ALT-q
      ,{ 0x40, 0xDD, 0x14, "@" }    // ALTGR-q
    
      // Sondertasten
      ,{ 0x08, 0xFD, 0x3D, "\x03" } // BRK-Taste
      ,{ 0x08, 0xFD, 0x3E, "\x13" } // STOP-Taste
      ,{ 0x08, 0xFD, 0x3F, "\x1A" } // INS-Taste
      ,{ 0x08, 0xFF, 0x40, "\x12" } // DEL-Taste
      ,{ 0x08, 0xFF, 0x41, "\x01" } // CLR-Taste (BS)
      ,{ 0x08, 0xFD, 0x42, "\x10" } // HOME-Taste
      ,{ 0x0A, 0xFF, 0x40, "\x02" } // (CLEAR LINE)
      ,{ 0x0A, 0xFF, 0x41, "\x0F" } // (HCOPY)
    
      // Löschtasten
      ,{ 0x00, 0x00, 0x2A, "\x01" } // Backstep-Taste
      ,{ 0x00, 0x00, 0x4C, "\x12" } // DEL-Taste
    
      // kleine Buchstaben
      ,{ 0x00, 0xFF, 0x04, "a" }    // char 'a'
      ,{ 0x00, 0xFF, 0x05, "b" }    // char 'b'
      ,{ 0x00, 0xFF, 0x06, "c" }    // char 'c'
      ,{ 0x00, 0xFF, 0x07, "d" }    // char 'd'
      ,{ 0x00, 0xFF, 0x08, "e" }    // char 'e'
      ,{ 0x00, 0xFF, 0x09, "f" }    // char 'f'
      ,{ 0x00, 0xFF, 0x0A, "g" }
      ,{ 0x00, 0xFF, 0x0B, "h" }
      ,{ 0x00, 0xFF, 0x0C, "i" }
      ,{ 0x00, 0xFF, 0x0D, "j" }
      ,{ 0x00, 0xFF, 0x0E, "k" }
      ,{ 0x00, 0xFF, 0x0F, "l" }
      ,{ 0x00, 0xFF, 0x10, "m" }
      ,{ 0x00, 0xFF, 0x11, "n" }
      ,{ 0x00, 0xFF, 0x12, "o" }
      ,{ 0x00, 0xFF, 0x13, "p" }
      ,{ 0x00, 0xFF, 0x14, "q" }
      ,{ 0x00, 0xFF, 0x15, "r" }
      ,{ 0x00, 0xFF, 0x16, "s" }
      ,{ 0x00, 0xFF, 0x17, "t" }
      ,{ 0x00, 0xFF, 0x18, "u" }
      ,{ 0x00, 0xFF, 0x19, "v" }
      ,{ 0x00, 0xFF, 0x1A, "w" }
      ,{ 0x00, 0xFF, 0x1B, "x" }
      ,{ 0x00, 0xFF, 0x1D, "y" }
      ,{ 0x00, 0xFF, 0x1C, "z" }
    
      // große Buchstaben
      ,{ 0x02, 0xFF, 0x04, "A" }    // char 'A'
      ,{ 0x02, 0xFF, 0x05, "B" }    // char 'B'
      ,{ 0x02, 0xFF, 0x06, "C" }    // char 'C'
      ,{ 0x02, 0xFF, 0x07, "D" }    // char 'D'
      ,{ 0x02, 0xFF, 0x08, "E" }    // char 'E'
      ,{ 0x02, 0xFF, 0x09, "F" }    // char 'F'
      ,{ 0x02, 0xFF, 0x0A, "G" }
      ,{ 0x02, 0xFF, 0x0B, "H" }
      ,{ 0x02, 0xFF, 0x0C, "I" }
      ,{ 0x02, 0xFF, 0x0D, "J" }
      ,{ 0x02, 0xFF, 0x0E, "K" }
      ,{ 0x02, 0xFF, 0x0F, "L" }
      ,{ 0x02, 0xFF, 0x10, "M" }
      ,{ 0x02, 0xFF, 0x11, "N" }
      ,{ 0x02, 0xFF, 0x12, "O" }
      ,{ 0x02, 0xFF, 0x13, "P" }
      ,{ 0x02, 0xFF, 0x14, "Q" }
      ,{ 0x02, 0xFF, 0x15, "R" }
      ,{ 0x02, 0xFF, 0x16, "S" }
      ,{ 0x02, 0xFF, 0x17, "T" }
      ,{ 0x02, 0xFF, 0x18, "U" }
      ,{ 0x02, 0xFF, 0x19, "V" }
      ,{ 0x02, 0xFF, 0x1A, "W" }
      ,{ 0x02, 0xFF, 0x1B, "X" }
      ,{ 0x02, 0xFF, 0x1D, "Y" }
      ,{ 0x02, 0xFF, 0x1C, "Z" }
    
      // Ziffern und Sonderzeichen mit NUM
      ,{ 0x00, 0xFF, 0x59, "1" }    // char '1'
      ,{ 0x00, 0xFF, 0x5A, "2" }
      ,{ 0x00, 0xFF, 0x5B, "3" }
      ,{ 0x00, 0xFF, 0x5C, "4" }
      ,{ 0x00, 0xFF, 0x5D, "5" }
      ,{ 0x00, 0xFF, 0x5E, "6" }
      ,{ 0x00, 0xFF, 0x5F, "7" }
      ,{ 0x00, 0xFF, 0x60, "8" }
      ,{ 0x00, 0xFF, 0x61, "9" }
      ,{ 0x00, 0xFF, 0x62, "0" }
      ,{ 0x00, 0xFF, 0x55, "*" }
      ,{ 0x00, 0xFF, 0x56, "-" }
      ,{ 0x00, 0xFF, 0x57, "+" }
      ,{ 0x00, 0xFF, 0x54, "/" }
    
      // F-Tasten
      ,{ 0x00, 0xFF, 0x3A, "\xF1" }
      ,{ 0x00, 0xFF, 0x3B, "\xF2" }
      ,{ 0x00, 0xFF, 0x3C, "\xF3" }
      ,{ 0x00, 0xFF, 0x3D, "\xF4" }
      ,{ 0x00, 0xFF, 0x3E, "\xF5" }
      ,{ 0x00, 0xFF, 0x3F, "\xF6" }
      ,{ 0x00, 0xFF, 0x40, "\xF7" }
      ,{ 0x00, 0xFF, 0x41, "\xF8" }
      ,{ 0x00, 0xFF, 0x42, "\xF9" }
      ,{ 0x00, 0xFF, 0x43, "\xFA" }
      ,{ 0x00, 0xFF, 0x44, "\xFB" }
      ,{ 0x00, 0xFF, 0x45, "\xFC" }
    
      // Texte mit Fn II (Windows-Taste)
      ,{ 0x08, 0xFD, 0x1A, "WINDOW" }     // w
      ,{ 0x08, 0xFD, 0x08, "EDIT" }       // e
      ,{ 0x08, 0xFD, 0x15, "RENUMBER" }   // r
      ,{ 0x08, 0xFD, 0x17, "RANDOMIZE" }  // t 
      ,{ 0x08, 0xFD, 0x1C, "PRESET" }     // z 
      ,{ 0x08, 0xFD, 0x18, "PEEK" }       // u
      ,{ 0x08, 0xFD, 0x0C, "INPUT" }      // i
      ,{ 0x08, 0xFD, 0x12, "OUT" }        // o
      ,{ 0x08, 0xFD, 0x13, "PAUSE" }      // p
      ,{ 0x08, 0xFD, 0x2F, "CLICK" }      // ü
      ,{ 0x08, 0xFD, 0x04, "AUTO" }       // a
      ,{ 0x08, 0xFD, 0x16, "SOUND" }      // s
      ,{ 0x08, 0xFD, 0x07, "DELETE" }     // d 
      ,{ 0x08, 0xFD, 0x09, "FOR" }        // f
      ,{ 0x08, 0xFD, 0x0A, "GOTO" }       // g
      ,{ 0x08, 0xFD, 0x0B, "HOME" }       // h
      ,{ 0x08, 0xFD, 0x0D, "JOYST" }      // j 
      ,{ 0x08, 0xFD, 0x0E, "KEYLIST" }    // k
      ,{ 0x08, 0xFD, 0x0F, "LIST" }       // l
      ,{ 0x08, 0xFD, 0x33, "CSAVE" }      // ö
      ,{ 0x08, 0xFD, 0x34, "CLOAD" }      // ä
      ,{ 0x08, 0xFD, 0x1D, "PSET" }       // y
      ,{ 0x08, 0xFD, 0x1B, "NEW" }        // x
      ,{ 0x08, 0xFD, 0x06, "COLOR" }      // c
      ,{ 0x08, 0xFD, 0x19, "POKE" }       // v
      ,{ 0x08, 0xFD, 0x05, "BEEP" }       // b
      ,{ 0x08, 0xFD, 0x11, "NEXT" }       // n
      ,{ 0x08, 0xFD, 0x10, "EDAS" }       // m
      ,{ 0x08, 0xFD, 0x36, "<" }          // ,
      ,{ 0x08, 0xFD, 0x37, ">" }          // .
      ,{ 0x08, 0xFD, 0x38, "|" }          // -
      ,{ 0x08, 0xFD, 0x63, ">" }          // .
      ,{ 0x08, 0xFD, 0x54, "|" }          // -
    
      // Endekennzeichen
      ,{ 0xFF, 0xFF, 0xFF, "0xFF" } // Endekennzeichen; wird benötigt, um die Größe des Arrays festzustellen

  }
  // Ende 1. Zeichentabelle  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  

  // 2. Zeichentabelle  
  ,{
       { 0x04, 0xFF, 0x1E, "Zeichentabelle 2" }  // ALT-1
      ,{ 0x04, 0xFF, 0x1F, "ABC ... xyz" }       // ALT-2
      ,{ 0x04, 0xFF, 0x20, "Jona Scheidat" }     // ALT-3

      //----------------------------------------------
    
      // Arrow-Tasten, ENTER & Leertaste
      ,{ 0x00, 0x00, 0x4F, "\x09" } // RIGHT
      ,{ 0x00, 0x00, 0x50, "\x08" } // LEFT
      ,{ 0x00, 0x00, 0x51, "\x0A" } // DOWN
      ,{ 0x00, 0x00, 0x52, "\x0B" } // UP
    
      ,{ 0x00, 0x00, 0x28, "\x0D" } // ENTER
      ,{ 0x00, 0x00, 0x2C, " " }    // SPACE
      // mit Numtaste
      ,{ 0x00, 0x00, 0x58, "\x0D" } // ENTER
      
      // Ziffern
      ,{ 0x00, 0xFF, 0x1E, "1" }    // char '1'
      ,{ 0x00, 0xFF, 0x1F, "2" }
      ,{ 0x00, 0xFF, 0x20, "3" }
      ,{ 0x00, 0xFF, 0x21, "4" }
      ,{ 0x00, 0xFF, 0x22, "5" }
      ,{ 0x00, 0xFF, 0x23, "6" }
      ,{ 0x00, 0xFF, 0x24, "7" }
      ,{ 0x00, 0xFF, 0x25, "8" }
      ,{ 0x00, 0xFF, 0x26, "9" }
      ,{ 0x00, 0xFF, 0x27, "0" }
    
      // Zweitbelegung (SHIFT) der Ziffern
      ,{ 0x02, 0xFF, 0x1E, "!" }    // char '!'
      ,{ 0x02, 0xFF, 0x1F, "\x22" } // char '"'
      ,{ 0x02, 0xFF, 0x20, " " }    // zurzeit nicht benutzt
      ,{ 0x02, 0xFF, 0x21, "$" }
      ,{ 0x02, 0xFF, 0x22, "%" }
      ,{ 0x02, 0xFF, 0x23, "&" }
      ,{ 0x02, 0xFF, 0x24, "/" }
      ,{ 0x02, 0xFF, 0x25, "(" }
      ,{ 0x02, 0xFF, 0x26, ")" }
      ,{ 0x02, 0xFF, 0x27, "=" }
    
      // Sonderzeichen
      ,{ 0x00, 0xFF, 0x2D, "ss" }
      ,{ 0x00, 0xFF, 0x2E, "´" }
      ,{ 0x00, 0xFF, 0x2F, "ue" }
      ,{ 0x00, 0xFF, 0x30, "+" }
      ,{ 0x00, 0xFF, 0x31, "#" }
      ,{ 0x00, 0xFF, 0x33, "oe" }
      ,{ 0x00, 0xFF, 0x34, "ae" }
      ,{ 0x00, 0xFF, 0x35, "^" }
      ,{ 0x00, 0xFF, 0x36, "," }
      ,{ 0x00, 0xFF, 0x37, "." }
      ,{ 0x00, 0xFF, 0x38, "-" }
    
      // Zweitbelegung (SHIFT) der Sonderzeichen
      ,{ 0x02, 0xFF, 0x2D, "?" }
      ,{ 0x02, 0xFF, 0x2E, "`" }
      ,{ 0x02, 0xFF, 0x2F, "Ue" }
      ,{ 0x02, 0xFF, 0x30, "*" }
      ,{ 0x02, 0xFF, 0x31, "'" }
      ,{ 0x02, 0xFF, 0x33, "Oe" }
      ,{ 0x02, 0xFF, 0x34, "Ae" }
      ,{ 0x00, 0xFF, 0x35, "\x5D" } // Haken rechts oben
      ,{ 0x02, 0xFF, 0x36, ";" }
      ,{ 0x02, 0xFF, 0x37, ":" }
      ,{ 0x02, 0xFF, 0x38, "_" }
    
      // @-Zeichen 
      ,{ 0x05, 0xDD, 0x14, "@" }    // STRG-ALT-q
      ,{ 0x40, 0xDD, 0x14, "@" }    // ALTGR-q
    
      // Sondertasten
      ,{ 0x08, 0xFD, 0x3D, "\x03" } // BRK-Taste
      ,{ 0x08, 0xFD, 0x3E, "\x13" } // STOP-Taste
      ,{ 0x08, 0xFD, 0x3F, "\x1A" } // INS-Taste
      ,{ 0x08, 0xFF, 0x40, "\x12" } // DEL-Taste
      ,{ 0x08, 0xFF, 0x41, "\x01" } // CLR-Taste (BS)
      ,{ 0x08, 0xFD, 0x42, "\x10" } // HOME-Taste
      ,{ 0x0A, 0xFF, 0x40, "\x02" } // (CLEAR LINE)
      ,{ 0x0A, 0xFF, 0x41, "\x0F" } // (HCOPY)
    
      // Löschtasten
      ,{ 0x00, 0x00, 0x2A, "\x01" } // Backstep-Taste
      ,{ 0x00, 0x00, 0x4C, "\x12" } // DEL-Taste
    
      // kleine Buchstaben
      ,{ 0x00, 0xFF, 0x04, "a" }    // char 'a'
      ,{ 0x00, 0xFF, 0x05, "b" }    // char 'b'
      ,{ 0x00, 0xFF, 0x06, "c" }    // char 'c'
      ,{ 0x00, 0xFF, 0x07, "d" }    // char 'd'
      ,{ 0x00, 0xFF, 0x08, "e" }    // char 'e'
      ,{ 0x00, 0xFF, 0x09, "f" }    // char 'f'
      ,{ 0x00, 0xFF, 0x0A, "g" }
      ,{ 0x00, 0xFF, 0x0B, "h" }
      ,{ 0x00, 0xFF, 0x0C, "i" }
      ,{ 0x00, 0xFF, 0x0D, "j" }
      ,{ 0x00, 0xFF, 0x0E, "k" }
      ,{ 0x00, 0xFF, 0x0F, "l" }
      ,{ 0x00, 0xFF, 0x10, "m" }
      ,{ 0x00, 0xFF, 0x11, "n" }
      ,{ 0x00, 0xFF, 0x12, "o" }
      ,{ 0x00, 0xFF, 0x13, "p" }
      ,{ 0x00, 0xFF, 0x14, "q" }
      ,{ 0x00, 0xFF, 0x15, "r" }
      ,{ 0x00, 0xFF, 0x16, "s" }
      ,{ 0x00, 0xFF, 0x17, "t" }
      ,{ 0x00, 0xFF, 0x18, "u" }
      ,{ 0x00, 0xFF, 0x19, "v" }
      ,{ 0x00, 0xFF, 0x1A, "w" }
      ,{ 0x00, 0xFF, 0x1B, "x" }
      ,{ 0x00, 0xFF, 0x1D, "y" }
      ,{ 0x00, 0xFF, 0x1C, "z" }
    
      // große Buchstaben
      ,{ 0x02, 0xFF, 0x04, "A" }    // char 'A'
      ,{ 0x02, 0xFF, 0x05, "B" }    // char 'B'
      ,{ 0x02, 0xFF, 0x06, "C" }    // char 'C'
      ,{ 0x02, 0xFF, 0x07, "D" }    // char 'D'
      ,{ 0x02, 0xFF, 0x08, "E" }    // char 'E'
      ,{ 0x02, 0xFF, 0x09, "F" }    // char 'F'
      ,{ 0x02, 0xFF, 0x0A, "G" }
      ,{ 0x02, 0xFF, 0x0B, "H" }
      ,{ 0x02, 0xFF, 0x0C, "I" }
      ,{ 0x02, 0xFF, 0x0D, "J" }
      ,{ 0x02, 0xFF, 0x0E, "K" }
      ,{ 0x02, 0xFF, 0x0F, "L" }
      ,{ 0x02, 0xFF, 0x10, "M" }
      ,{ 0x02, 0xFF, 0x11, "N" }
      ,{ 0x02, 0xFF, 0x12, "O" }
      ,{ 0x02, 0xFF, 0x13, "P" }
      ,{ 0x02, 0xFF, 0x14, "Q" }
      ,{ 0x02, 0xFF, 0x15, "R" }
      ,{ 0x02, 0xFF, 0x16, "S" }
      ,{ 0x02, 0xFF, 0x17, "T" }
      ,{ 0x02, 0xFF, 0x18, "U" }
      ,{ 0x02, 0xFF, 0x19, "V" }
      ,{ 0x02, 0xFF, 0x1A, "W" }
      ,{ 0x02, 0xFF, 0x1B, "X" }
      ,{ 0x02, 0xFF, 0x1D, "Y" }
      ,{ 0x02, 0xFF, 0x1C, "Z" }
    
      // Ziffern und Sonderzeichen mit NUM
      ,{ 0x00, 0xFF, 0x59, "1" }    // char '1'
      ,{ 0x00, 0xFF, 0x5A, "2" }
      ,{ 0x00, 0xFF, 0x5B, "3" }
      ,{ 0x00, 0xFF, 0x5C, "4" }
      ,{ 0x00, 0xFF, 0x5D, "5" }
      ,{ 0x00, 0xFF, 0x5E, "6" }
      ,{ 0x00, 0xFF, 0x5F, "7" }
      ,{ 0x00, 0xFF, 0x60, "8" }
      ,{ 0x00, 0xFF, 0x61, "9" }
      ,{ 0x00, 0xFF, 0x62, "0" }
      ,{ 0x00, 0xFF, 0x55, "*" }
      ,{ 0x00, 0xFF, 0x56, "-" }
      ,{ 0x00, 0xFF, 0x57, "+" }
      ,{ 0x00, 0xFF, 0x54, "/" }
    
      // F-Tasten
      ,{ 0x00, 0xFF, 0x3A, "\xF1" }
      ,{ 0x00, 0xFF, 0x3B, "\xF2" }
      ,{ 0x00, 0xFF, 0x3C, "\xF3" }
      ,{ 0x00, 0xFF, 0x3D, "\xF4" }
      ,{ 0x00, 0xFF, 0x3E, "\xF5" }
      ,{ 0x00, 0xFF, 0x3F, "\xF6" }
      ,{ 0x00, 0xFF, 0x40, "\xF7" }
      ,{ 0x00, 0xFF, 0x41, "\xF8" }
      ,{ 0x00, 0xFF, 0x42, "\xF9" }
      ,{ 0x00, 0xFF, 0x43, "\xFA" }
      ,{ 0x00, 0xFF, 0x44, "\xFB" }
      ,{ 0x00, 0xFF, 0x45, "\xFC" }
    
      // Texte mit Fn II (Windows-Taste)
      ,{ 0x08, 0xFD, 0x1A, "WINDOW" }     // w
      ,{ 0x08, 0xFD, 0x08, "EDIT" }       // e
      ,{ 0x08, 0xFD, 0x15, "RENUMBER" }   // r
      ,{ 0x08, 0xFD, 0x17, "RANDOMIZE" }  // t 
      ,{ 0x08, 0xFD, 0x1C, "PRESET" }     // z 
      ,{ 0x08, 0xFD, 0x18, "PEEK" }       // u
      ,{ 0x08, 0xFD, 0x0C, "INPUT" }      // i
      ,{ 0x08, 0xFD, 0x12, "OUT" }        // o
      ,{ 0x08, 0xFD, 0x13, "PAUSE" }      // p
      ,{ 0x08, 0xFD, 0x2F, "CLICK" }      // ü
      ,{ 0x08, 0xFD, 0x04, "AUTO" }       // a
      ,{ 0x08, 0xFD, 0x16, "SOUND" }      // s
      ,{ 0x08, 0xFD, 0x07, "DELETE" }     // d 
      ,{ 0x08, 0xFD, 0x09, "FOR" }        // f
      ,{ 0x08, 0xFD, 0x0A, "GOTO" }       // g
      ,{ 0x08, 0xFD, 0x0B, "HOME" }       // h
      ,{ 0x08, 0xFD, 0x0D, "JOYST" }      // j 
      ,{ 0x08, 0xFD, 0x0E, "KEYLIST" }    // k
      ,{ 0x08, 0xFD, 0x0F, "LIST" }       // l
      ,{ 0x08, 0xFD, 0x33, "CSAVE" }      // ö
      ,{ 0x08, 0xFD, 0x34, "CLOAD" }      // ä
      ,{ 0x08, 0xFD, 0x1D, "PSET" }       // y
      ,{ 0x08, 0xFD, 0x1B, "NEW" }        // x
      ,{ 0x08, 0xFD, 0x06, "COLOR" }      // c
      ,{ 0x08, 0xFD, 0x19, "POKE" }       // v
      ,{ 0x08, 0xFD, 0x05, "BEEP" }       // b
      ,{ 0x08, 0xFD, 0x11, "NEXT" }       // n
      ,{ 0x08, 0xFD, 0x10, "EDAS" }       // m
      ,{ 0x08, 0xFD, 0x36, "<" }          // ,
      ,{ 0x08, 0xFD, 0x37, ">" }          // .
      ,{ 0x08, 0xFD, 0x38, "|" }          // -
      ,{ 0x08, 0xFD, 0x63, ">" }          // .
      ,{ 0x08, 0xFD, 0x54, "|" }          // -

      
      // Endekennzeichen
      ,{ 0xFF, 0xFF, 0xFF, "0xFF" } // Endekennzeichen; wird benötigt, um die Größe des Arrays festzustellen
  }
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  

  // 3. Zeichentabelle  
  ,{
       { 0x04, 0xFF, 0x3A, "Zeichentabelle 3" }  // ALT-F1
      ,{ 0x04, 0xFF, 0x3B, "ABC" }  // ALT-F2
      ,{ 0x04, 0xFF, 0x3C, "Jona Scheidat" } // ALT-F3

      // Endekennzeichen
      ,{ 0xFF, 0xFF, 0xFF, "0xFF" } // Endekennzeichen; wird benötigt, um die Größe des Arrays festzustellen
  }
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  

  // 4. Zeichentabelle  
  ,{
       { 0x04, 0xFF, 0x3A, "Zeichentabelle 4" }  // ALT-F1
      ,{ 0x04, 0xFF, 0x3B, "ABC" }  // ALT-F2
      ,{ 0x04, 0xFF, 0x3C, "Jona Scheidat" } // ALT-F3

      // Endekennzeichen
      ,{ 0xFF, 0xFF, 0xFF, "0xFF" } // Endekennzeichen; wird benötigt, um die Größe des Arrays festzustellen
  }
};
