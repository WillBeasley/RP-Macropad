#include "USBKeyboard.h"

#define KEY_COUNT 9

USBKeyboard2 mKeyboard;

// Define board pins Buttons 0-9 map to the GPIO pins below
int pins [KEY_COUNT] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
bool lastKeyState [KEY_COUNT] = {false};
KEYMAP keys[KEY_COUNT] = {{KEY_F13,0}, {KEY_F14,0}, {KEY_F15,0}, {KEY_F16,0}, {KEY_F17,0}, {KEY_F18,0}, {KEY_F19,0}, {KEY_F20,0}, {KEY_F21,0}};


void setup() {
  // Run through key inputs and set them up has inputs and to pull-up.
  for (int i = 0; i < KEY_COUNT; i++){
    pinMode(pins[i], INPUT_PULLUP);
  }
  
}

// The main program loop we basically just want to scan through and press any keys we've been told to
void loop() {
  bool keyPressed = false;
  for (int i=0; i < KEY_COUNT; i++){
    keyPressed = !digitalRead(pins[i]);

    // '0' means the key is being pressed
    // If the button wasn't being pressed and is now being pressed, send the relevant mapped key. 
    if (keyPressed) {
      if (!lastKeyState[i]){
        mKeyboard.key_code(keys[i].usage, keys[i].modifier);
      }
    }

    // The lastKeyState prevents the key from being constsntly retriggered whilst it is held down.
    lastKeyState[i] = keyPressed;
    
  }
}