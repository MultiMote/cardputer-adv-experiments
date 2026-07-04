#pragma once

#include <LovyanGFX.hpp>

class LGFX : public lgfx::LGFX_Device {
  lgfx::Panel_ST7789 panel_instance_;
  lgfx::Bus_SPI bus_instance_;
  lgfx::Light_PWM light_instance_;

public:
  LGFX();
};

class CardputerDisplay {
private:
  bool _isOn = false;
  uint16_t _lastColor = 0;
  int16_t _fontYAdvance = 1;
  LGFX LCD;
  void updateFontYAdvance();

public:
  CardputerDisplay() {}
  bool begin();

  bool isOn() { return _isOn; };
  void turnOn();
  void turnOff();
  void clear();
  void startFrame(uint16_t bkg = TFT_BLACK);
  void setTextSize(int sz);
  void setColor(uint16_t c);
  void setCursor(int x, int y);
  void print(const char *str);
  void fillRect(int x, int y, int w, int h);
  void drawRect(int x, int y, int w, int h);
  void drawXbm(int x, int y, const uint8_t *bits, int w, int h);
  void endFrame();
  uint16_t getTextWidth(const char *str);
  int32_t getFontHeight() const;
  int16_t getFontLineHeight() const;
};
