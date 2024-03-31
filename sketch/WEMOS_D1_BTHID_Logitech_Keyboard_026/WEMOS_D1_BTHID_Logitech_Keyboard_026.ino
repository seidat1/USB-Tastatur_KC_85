/*
 * Jona Scheidat
 * 
 * März/2024
 * 
 * 
 * 
 */

#define Schalter D1
#define SWPOS HIGH  // dieser Wert bestimmt, in welcher Schalterposition BT benutzt wird

#include <hidboot.h>
//#include <usbhub.h>
#include <BTHID.h>
#include <SPI.h>
KBDLEDS kleds;
#include "KC85.h"
#include "KeyboardParser.h"

USB     Usb;
//USBHub     Hub(&Usb);
HIDBoot<USB_HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);

BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so

/* You can create the instance of the class in two ways */
// This will start an inquiry and then pair with your device - you only have to do this once
// If you are using a Bluetooth keyboard, then you should type in the password on the keypad and then press enter
BTHID bthid(&Btd, PAIR, "0000");


KbdRptParser Prs;


void setup()
{
  Serial.begin( 115200 );
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  // initialize digital pin D1 as an input.
  pinMode(Schalter, INPUT_PULLUP);
  
  delay(200); // Auszeit für die serielle Schnittstelle
  Serial.println("Start");

  setupKC(); 

  if (Usb.Init() == -1) 
  {
    Serial.println("OSC did not start.");
    while(1==1);
  }
  
  // prüfe die Schalterstellung und initialisiere für BT-Tastatur oder USB-Tastatur
  if (digitalRead(Schalter) == SWPOS)
  { // BT-Tastatur
    bthid.SetReportParser(KEYBOARD_PARSER_ID, &Prs);
    // If "Boot Protocol Mode" does not work, then try "Report Protocol Mode"
    // If that does not work either, then uncomment PRINTREPORT in BTHID.cpp to see the raw report
    bthid.setProtocolMode(USB_HID_BOOT_PROTOCOL); // Boot Protocol Mode
    //bthid.setProtocolMode(HID_RPT_PROTOCOL); // Report Protocol Mode
    Serial.println("Software fuer BT-HID initialisiert");
    KC_PrintString(" Modus:BT\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x0A%");
  }
  else
  { // USB-Tastatur
    HidKeyboard.SetReportParser(0, &Prs);
    Serial.println("Software fuer USB-Keyboard initialisiert");
    KC_PrintString(" Modus:USB\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x0A%");
  }
}

void loop()
{
  Usb.Task();
}
