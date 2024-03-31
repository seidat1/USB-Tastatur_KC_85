/*
 * Jona Scheidat
 * 
 * März/2024
 * 
 * 
 * 
 */

typedef struct
  {
    uint8_t KeyCnt;
    uint8_t CntMask;
    uint8_t KeyCode;
    String Strg;
  } KC_Key;


uint8_t CapsLow = 0x04;     // erstes Zeichen, das von CapsLook erfasst wird
uint8_t CapsHigh = 0x1D;    // letztes Zeichen, das von CapsLook erfasst wird

int16_t NUM_KEYS;

//***************************************************************************************************************************************************

uint8_t Taste[][2] =
{ // alle möglichen Tasten und -kombinationen des KC 85/3
  // 1. Zeile ohne SHIFT          
    {0x5F, 0xF1}                  
  , {0x58, 0xF2}                  
  , {0x5C, 0xF3}                  
  , {0x5B, 0xF4}                  
  , {0x5A, 0xF5}                  
  , {0x5D, 0xF6}                  
  , {0x5E, 0x03}  // BRK          
  , {0x59, 0x13}  // STOP         
  , {0x4E, 0x1A}  // INS          
  , {0x4A, 0x12}  // DEL          
  , {0x4C, 0x01}  // CLR (BS)     
  , {0x48, 0x10}  // HOME         

  // 2. Zeile ohne SHIFT      
  , {0x57, '1'}                   
  , {0x50, '2'}           
  , {0x54, '3'}                   
  , {0x53, '4'}                   
  , {0x52, '5'}                   
  , {0x55, '6'}                   
  , {0x56, '7'}                   
  , {0x51, '8'}                   
  , {0x6E, '9'}                   
  , {0x6A, '0'}                   
  , {0x6C, ':'}                   
  , {0x68, '-'}                   
  , {0x4F, 0x0B}  // UP           

  // 3. Zeile ohne SHIFT      
  , {0x47, 'Q'}                   
  , {0x40, 'W'}                   
  , {0x44, 'E'}                   
  , {0x43, 'R'}                   
  , {0x42, 'T'}                   
  , {0x45, 'Z'}                   
  , {0x46, 'U'}                   
  , {0x41, 'I'}                   
  , {0x76, 'O'}                   
  , {0x72, 'P'}                   
  , {0x74, 0x5E}  // ^            
  , {0x70, 0x08}  // LEFT         
  , {0x6F, 0x09}  // RIGHT        

  // 4. Zeile ohne SHIFT      
  , {0x67, 0x16}  // SHIFT LOCK   
  , {0x60, 'A'}                   
  , {0x64, 'S'}                   
  , {0x63, 'D'}                   
  , {0x62, 'F'}                   
  , {0x65, 'G'}                   
  , {0x66, 'H'}                   
  , {0x61, 'J'}                   
  , {0x49, 'K'}                   
  , {0x4D, 'L'}                   
  , {0x4B, '+'}                   
  , {0x73, '_'}                   
  , {0x77, 0x0A}  // DOWN         

  // 5. Zeile ohne SHIFT      
  , {0x78, 'Y'}                   
  , {0x7C, 'X'}                   
  , {0x7B, 'C'}                   
  , {0x7A, 'V'}                   
  , {0x7D, 'B'}                   
  , {0x7E, 'N'}                   
  , {0x79, 'M'}                   
  , {0x69, ','}                   
  , {0x6D, '.'}                   
  , {0x6B, '/'}                   
  , {0x7F, 0x0D}  // ENTER
  , {0x71, ' '}   // SPACE       

  // 1. Zeile mit SHIFT
  , {0x1F, 0xF7}
  , {0x18, 0xF8}
  , {0x1C, 0xF9}
  , {0x1B, 0xFA}
  , {0x1A, 0xFB}
  , {0x1D, 0xFC}
  , {0x1E, 0x03}  // BRK
  , {0x19, 0x13}  // STOP
  , {0x0E, 0x1A}  // INS
  , {0x0A, 0x02}  // (CLEAR LINE)
  , {0x0C, 0x0F}  // (HCOPY)
  , {0x08, 0x10}  // HOME

  // 2. Zeile mit SHIFT
  , {0x17, '!'}
  , {0x10, '"'}
  , {0x14, '#'}
  , {0x13, '$'}
  , {0x12, '%'}
  , {0x15, '&'}
  , {0x16, 0x27}  // '
  , {0x11, '('}
  , {0x2E, ')'}
  , {0x2A, '@'}
  , {0x2C, '*'}
  , {0x28, '='}
  , {0x0F, 0x11}  // PAGE

  // 3. Zeile mit SHIFT
  , {0x07, 'q'}
  , {0x00, 'w'}
  , {0x04, 'e'}
  , {0x03, 'r'}
  , {0x02, 't'}
  , {0x05, 'z'}
  , {0x06, 'u'}
  , {0x01, 'i'}
  , {0x36, 'o'}
  , {0x32, 'p'}
  , {0x34, 0x5D}  // 
  , {0x30, 0x19}
  , {0x2F, 0x1E}  // CONT

  // 4. Zeile mit SHIFT
  , {0x27, 0x16}  // SHIFT LOCK
  , {0x20, 'a'}
  , {0x24, 's'}
  , {0x23, 'd'}
  , {0x22, 'f'}
  , {0x25, 'g'}
  , {0x26, 'h'}
  , {0x21, 'j'}
  , {0x09, 'k'}
  , {0x0D, 'l'}
  , {0x0B, ';'}
  , {0x33, '|'}
  , {0x37, 0x12}  // SCROLL

  // 5. Zeile mit SHIFT
  , {0x38, 'y'}
  , {0x3C, 'x'}
  , {0x3B, 'c'}
  , {0x3A, 'v'}
  , {0x3D, 'b'}
  , {0x3E, 'n'}
  , {0x39, 'm'}
  , {0x29, '<'}
  , {0x2D, '>'}
  , {0x2B, '?'}
  , {0x3F, 0x0D}  // ENTER
}; 
