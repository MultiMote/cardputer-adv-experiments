#pragma once

#include <stdint.h>

/** Basic ES8311 blocking driver */
class CardputerSpeaker {
private:
  void initI2C();
  void initI2S();
  bool writeReg(uint8_t reg, uint8_t val);

public:
  CardputerSpeaker() {}

  void begin() {
    initI2S();
    initI2C();
  }
  void sleep();
  void wake();
  void playTone(float frequency_hz, uint32_t duration_ms, float volume = 0.5f);
};

