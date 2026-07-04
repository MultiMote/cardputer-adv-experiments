#include "CardputerDisplay.h"
#include "CardputerKeyboard.h"
#include "CardputerLayout.h"
#include "CardputerSpeaker.h"
#include "globals.h"
#include <Arduino.h>
#include <Wire.h>

CardputerDisplay lcd;
CardputerSpeaker speaker;
CardputerKeyboard kb;
CardputerLayout lay;

void setup() {
  Wire1.setPins(PIN_I2C_INTERNAL_SDA, PIN_I2C_INTERNAL_SCL);
  Wire1.begin();

  Serial.begin(115200);
  lcd.begin();
  speaker.begin();
  kb.begin();
  lay.begin();

  Serial.println("Done");
  speaker.queueTone(5000, 50);

  lcd.setCursor(0, 0);
  lcd.setColor(TFT_WHITE);
  lcd.print(">");
}

void loop() {
  Keyboard::Event event = kb.poll();

  if (event.changed) {
    if (event.down && event.key != Keyboard::KEY_NONE) {
      const char *mbch = lay.lookup(event);
      Serial.printf("Key: %d Lookup: '%s'\n", event.key, mbch);
      if (event.key == Keyboard::KEY_ESC) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(">");
      } else if (mbch[0]){
        lcd.print(mbch);
      }
      speaker.queueTone(2000, 50);
    }
  }

  speaker.processQueue();
  delay(10);
}
