// Das ist nicht auf meinem Mist gewachsen

class KbdRptParser : public KeyboardReportParser
{
    void PrintKey(uint8_t mod, uint8_t key);

  protected:
    virtual uint8_t HandleLockingKeys(USBHID *hid, uint8_t key);
    void OnControlKeysChanged(uint8_t before, uint8_t after);
    void OnKeyDown  (uint8_t mod, uint8_t key);
    void OnKeyUp  (uint8_t mod, uint8_t key);
    void OnKeyPressed(uint8_t key);
};


uint8_t KbdRptParser::HandleLockingKeys(USBHID *hid, uint8_t key)
{
  uint8_t old_keys = kbdLockingKeys.bLeds;

  switch(key)
  {
    case UHS_HID_BOOT_KEY_NUM_LOCK:
          kbdLockingKeys.kbdLeds.bmNumLock = ~kbdLockingKeys.kbdLeds.bmNumLock;
          kleds.bmNumLock = kbdLockingKeys.kbdLeds.bmNumLock;
          break;
    case UHS_HID_BOOT_KEY_CAPS_LOCK:
          kbdLockingKeys.kbdLeds.bmCapsLock = ~kbdLockingKeys.kbdLeds.bmCapsLock;
          kleds.bmCapsLock = kbdLockingKeys.kbdLeds.bmCapsLock;
          break;
    case UHS_HID_BOOT_KEY_SCROLL_LOCK:
          kbdLockingKeys.kbdLeds.bmScrollLock = ~kbdLockingKeys.kbdLeds.bmScrollLock;
          kleds.bmCapsLock = kbdLockingKeys.kbdLeds.bmCapsLock;
          break;
  }

  if(old_keys != kbdLockingKeys.bLeds && hid)
  {
    if (digitalRead(Schalter) == SWPOS)
    {
      BTHID *pBTHID = reinterpret_cast<BTHID *> (hid); // A cast the other way around is done in BTHID.cpp
      pBTHID->setLeds(kbdLockingKeys.bLeds); // Update the LEDs on the keyboard
    }
    else
    {
      uint8_t lockLeds = kbdLockingKeys.bLeds;
      return (hid->SetReport(0, 0/*hid->GetIface()*/, 2, 0, 1, &lockLeds));
    }
  }
  return 0;
}


void KbdRptParser::PrintKey(uint8_t m, uint8_t key)
{
  MODIFIERKEYS mod;
  *((uint8_t*)&mod) = m;
  Serial.print((mod.bmLeftCtrl   == 1) ? "C" : " ");
  Serial.print((mod.bmLeftShift  == 1) ? "S" : " ");
  Serial.print((mod.bmLeftAlt    == 1) ? "A" : " ");
  Serial.print((mod.bmLeftGUI    == 1) ? "G" : " ");

  Serial.print(" >");
  PrintHex<uint8_t>(m, 0x00);
  Serial.print("  ");
  PrintHex<uint8_t>(key, 0x80);
  Serial.print("< ");

  Serial.print((mod.bmRightCtrl   == 1) ? "C" : " ");
  Serial.print((mod.bmRightShift  == 1) ? "S" : " ");
  Serial.print((mod.bmRightAlt    == 1) ? "A" : " ");
  Serial.println((mod.bmRightGUI  == 1) ? "G" : " ");
};

void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)
{
  Serial.print("DN ");
  PrintKey(mod, key);
  uint8_t c = OemToAscii(mod, key);

  if (c) OnKeyPressed(c);

  KC_PrintKey(mod, key);
}

void KbdRptParser::OnControlKeysChanged(uint8_t before, uint8_t after) {

  MODIFIERKEYS beforeMod;
  *((uint8_t*)&beforeMod) = before;

  MODIFIERKEYS afterMod;
  *((uint8_t*)&afterMod) = after;

  if (beforeMod.bmLeftCtrl != afterMod.bmLeftCtrl) {
    Serial.println("LeftCtrl changed");
  }
  if (beforeMod.bmLeftShift != afterMod.bmLeftShift) {
    Serial.println("LeftShift changed");
  }
  if (beforeMod.bmLeftAlt != afterMod.bmLeftAlt) {
    Serial.println("LeftAlt changed");
  }
  if (beforeMod.bmLeftGUI != afterMod.bmLeftGUI) {
    Serial.println("LeftGUI changed");
  }

  if (beforeMod.bmRightCtrl != afterMod.bmRightCtrl) {
    Serial.println("RightCtrl changed");
  }
  if (beforeMod.bmRightShift != afterMod.bmRightShift) {
    Serial.println("RightShift changed");
  }
  if (beforeMod.bmRightAlt != afterMod.bmRightAlt) {
    Serial.println("RightAlt changed");
  }
  if (beforeMod.bmRightGUI != afterMod.bmRightGUI) {
    Serial.println("RightGUI changed");
  }

}

void KbdRptParser::OnKeyUp(uint8_t mod, uint8_t key)
{
  Serial.print("UP ");
  PrintKey(mod, key);
}

void KbdRptParser::OnKeyPressed(uint8_t key)
{
  Serial.print("ASCII: ");
  Serial.println((char)key);
};
