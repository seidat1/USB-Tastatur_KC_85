/*
 * Jona Scheidat
 * 
 * März/2024
 * 
 * 
 * 
 */

#include "KC85KEYS.h"
#include "KC85KeyTables.h"


#define KCsign D2

uint16_t Burst[] = {16, 16, 16, 16, 16, 16, 16, 16, 16};
#define bitNull 5120 - 144
#define bitEins 7168 - 144
#define tDW 14336

uint8_t key_table = 0;


void writeBurst()
{
  for (uint8_t i=0; i<=9; i++)
  {
    digitalWrite(KCsign, ! digitalRead(KCsign));           // turn the LED off by making the voltage LOW
    delayMicroseconds(6); 
  }
}
/************************************************************************************************/
void writeKeyKC(uint8_t asciiKey)
{
  for (uint8_t j=0; j<2; j++)
  {
    uint8_t tmpKey = asciiKey;
    for(uint8_t i=0; i<7; i++)
    {
      writeBurst();
      tmpKey = tmpKey << 1;
      if ((tmpKey & 0x80) == 0x80)
      {
        delayMicroseconds(bitEins);
      }
      else
      {
        delayMicroseconds(bitNull);
      }
    }
    writeBurst();
    delayMicroseconds(tDW); 
  }
}
/************************************************************************************************/


// the setup function runs once when you press reset or power the board
void setupKC()
{
  pinMode(KCsign, OUTPUT);
  
  // Anzahl der Elemente im Array kc_key feststellen
  NUM_KEYS = 0; // sizeof(kc_key);
  while (kc_key[key_table][NUM_KEYS].KeyCode != 0xFF)
  {
    NUM_KEYS++;
  }
  Serial.print("Es sind Tasten definiert: ");
  Serial.println(NUM_KEYS);
}


void KConvert(uint8_t key)
{  
  int arrayLength = sizeof(Taste) / sizeof(Taste[0]);
  for (uint8_t i=0; i<arrayLength; i++)
  {
    if (Taste[i][1] == key)
    {
      writeKeyKC(Taste[i][0]);
      return;
    }
  }
}


void KC_PrintString(String kcStrg)
{
  char letztesZeichen = 0;
  for (uint16_t zz=0; zz < kcStrg.length(); zz++)
  {
    if (kcStrg[zz] == letztesZeichen) delay(20);
    KConvert(kcStrg[zz]);
    letztesZeichen = kcStrg[zz];
  }
}


void KC_PrintKey(uint8_t modraw, uint8_t key)
{
  uint8_t mod = modraw;

  if (mod == 0x40)
  {
    if (key == 0x1E)
    { // Zeichentabelle 1
      key_table = 0;
      setupKC();
    }
    else if (key == 0x1F)
    { // Zeichentabelle 2
      key_table = 1;
      setupKC();
    }
  }
  

  // rechte SHIFT-Taste, wie linke SHIFT-Taste behandeln
  // muss noch verbessert werden
  if (mod == 0x20) mod = 0x02;

  // nur Buchstaben sollen groß geschrieben werden
  if (kleds.bmCapsLock)
  {
    if (key >= CapsLow and key <= CapsHigh) mod = mod ^ 0x02;
  }

  for (uint16_t ii=0; ii < NUM_KEYS; ii++)
  {
    if (kc_key[key_table][ii].KeyCode == key && kc_key[key_table][ii].KeyCnt == (mod & kc_key[key_table][ii].CntMask))
    {
      Serial.print(kc_key[key_table][ii].Strg);
      KC_PrintString(kc_key[key_table][ii].Strg);
      return;
    }
  }
}
