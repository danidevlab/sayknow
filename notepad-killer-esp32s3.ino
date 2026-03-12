/*
  Geekble Nano ESP32-S3 (USB HID Keyboard)
  Opens Win+R and runs taskkill for notepad.

  For authorized testing environments only.
*/

#include "USB.h"
#include "USBHIDKeyboard.h"

USBHIDKeyboard Keyboard;

bool sent = false;

void sendTaskkillNotepad() {
  // Win + R
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(80);
  Keyboard.releaseAll();
  delay(300);

  // Run command
  Keyboard.print("cmd /c taskkill /IM notepad.exe /F");
  delay(80);

  // Enter
  Keyboard.write(KEY_RETURN);
}

void setup() {
  USB.begin();
  Keyboard.begin();

  delay(1500); // wait for host recognition

  if (!sent) {
    sendTaskkillNotepad();
    sent = true;
  }
}

void loop() {
  delay(1000);
}
