#include "CardputerKeyboard.h"
#include "CardputerSpeaker.h"
#include "globals.h"
#include <Arduino.h>
#include <Wire.h>

CardputerSpeaker speaker;
CardputerKeyboard kb;

// void TCA8418_irq() {}

void setup() {
  Wire1.setPins(PIN_I2C_INTERNAL_SDA, PIN_I2C_INTERNAL_SCL);
  Wire1.begin();

  Serial.begin(115200);
  speaker.begin();
  kb.begin();

  //   pinMode(PIN_KEYBOARD_INT, INPUT);
  //   attachInterrupt(digitalPinToInterrupt(PIN_KEYBOARD_INT), TCA8418_irq,
  //                   FALLING);

  Serial.println("Done");
  speaker.playTone(5000.0f, 50);
}

void loop() {
  Keyboard::Event event = kb.poll();

  if (event.key != Keyboard::KEY_NONE) {
    Serial.printf("Key: %d Down: %d\n", event.key, event.down);
    Serial.printf("Shift: %d, Opt: %d, Alt: %d, Ctrl: %d, Fn: %d\n",
                  event.modifiers.shift, event.modifiers.opt,
                  event.modifiers.alt, event.modifiers.ctrl,
                  event.modifiers.fn);

    if (event.down) {
      speaker.playTone(500.0f + event.key * 50, 60);
    }
  }
  delay(10);
}
