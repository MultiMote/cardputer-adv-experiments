#include "CardputerDisplay.h"
#include "CardputerKeyboard.h"
#include "CardputerLayout.h"
#include "CardputerSpeaker.h"
#include "globals.h"
#include <Arduino.h>
#include <SD.h>
#include <SPI.h>
#include <Wire.h>


CardputerDisplay lcd;
CardputerSpeaker speaker;
CardputerKeyboard kb;
CardputerLayout lay;

void setup() {
  Serial.begin(115200);

  pinMode(PIN_LORA_NSS, OUTPUT);
  digitalWrite(PIN_LORA_NSS, HIGH);

  delay(1000);

  Wire1.setPins(PIN_I2C_INTERNAL_SDA, PIN_I2C_INTERNAL_SCL);
  Wire1.begin();

  lcd.begin();
  speaker.begin();
  kb.begin();
  lay.begin();

  Serial.println("Done");
  speaker.queueTone(5000, 50);

  lcd.setCursor(0, 0);
  lcd.setColor(TFT_WHITE);

  SPI.begin(PIN_SPI_SCK, PIN_SPI_MISO, PIN_SPI_MOSI, PIN_SD_SPI_CS);

  if (!SD.begin(PIN_SD_SPI_CS, SPI, 25000000)) {
    Serial.println("SD init failed");
    lcd.print("SD init failed");
    while (1) {
    }
  }

  Serial.printf("SD Card Size: %lluMB\n", SD.cardSize() / (1024 * 1024));

  lay.begin(SD);

  lcd.print(">");
  lcd.print(lay.getCurrentCode());
  lcd.print("\n");
}

void loop() {
  Keyboard::Event event = kb.poll();

  if (event.changed) {
    if (event.down && event.key != Keyboard::KEY_NONE) {
      if (event.key == Keyboard::KEY_ESC) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(">");
      } else if (event.key == Keyboard::KEY_SPACE && event.modifiers.ctrl) {
        lay.switchLayout();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(">");
        lcd.print(lay.getCurrentCode());
        lcd.print("\n");
      } else {
        const char *mbch = lay.lookup(event);
        Serial.printf("Key: %d Lookup: '%s'\n", event.key, mbch);

        if (mbch[0]) {
          lcd.print(mbch);
        }
      }
      speaker.queueTone(2000, 10);
    }
  }

  speaker.processQueue();
  delay(10);
}
