#pragma once

#include "CardputerKeyboard.h"
#include <stdint.h>

#define TOTAL_KEYS 56

class CardputerLayout {

  enum LayerMask {
    LAYER_MASK_BASE = 0x00,
    LAYER_MASK_FN = 0x01,
    LAYER_MASK_CTRL = 0x02,
    LAYER_MASK_SHIFT = 0x04,
    LAYER_MASK_OPT = 0x08,
    LAYER_MASK_ALT = 0x10
  };

  struct layout_entry {
    char data[4];
  };

  struct layout_layer {
    uint8_t modifiers_mask;
    layout_entry entries[TOTAL_KEYS];
  };

  struct layout_data {
    uint8_t layers_count;
    layout_layer layers[7];
  };

  // layout-cz_sk
  layout_data layout = {
      .layers_count = 7,
      .layers = {
          {(LAYER_MASK_BASE),
           {"`", "",  "",  "",  "1", "q",  "",  "",  "2", "w", "a", "",
            "3", "e", "s", "z", "4", "r",  "d", "x", "5", "t", "f", "c",
            "6", "y", "g", "v", "7", "u",  "h", "b", "8", "i", "j", "n",
            "9", "o", "k", "m", "0", "p",  "l", ",", "-", "[", ";", ".",
            "=", "]", "'", "/", "",  "\\", "",  ""}},
          {(LAYER_MASK_CTRL),
           {"",  "",  "", "",  "",  "",  "", "",  "", "",  "á", "",  "", "é",
            "š", "ž", "", "ř", "ď", "",  "", "ť", "", "č", "",  "ý", "", "",
            "",  "ú", "", "",  "",  "í", "", "ň", "", "ó", "",  "",  "", "",
            "ľ", "",  "", "",  "",  "",  "", "",  "", "",  "",  "",  "", ""}},
          {(LAYER_MASK_SHIFT),
           {"~", "",  "",   "",  "!", "Q", "",  "",  "@", "W", "A", "",
            "#", "E", "S",  "Z", "$", "R", "D", "X", "%", "T", "F", "C",
            "^", "Y", "G",  "V", "&", "U", "H", "B", "*", "I", "J", "N",
            "(", "O", "K",  "M", ")", "P", "L", "<", "_", "{", ":", ">",
            "+", "}", "\"", "?", "",  "|", "",  ""}},
          {(LAYER_MASK_OPT),
           {"",  "",  "", "",  "", "", "", "", "", "",  "ä", "", "", "ě",
            "",  "",  "", "ŕ", "", "", "", "", "", "",  "",  "", "", "",
            "",  "ů", "", "",  "", "", "", "", "", "ô", "",  "", "", "",
            "ĺ", "",  "", "",  "", "", "", "", "", "",  "",  "", "", ""}},
          {(LAYER_MASK_ALT),
           {"", "", "", "", "", "", "", "", "", "", "", "", "", "€",
            "", "", "", "", "", "", "", "", "", "", "", "", "", "",
            "", "", "", "", "", "", "", "", "", "", "", "", "", "",
            "", "", "", "", "", "", "", "", "", "", "", "", "", ""}},
          {(LAYER_MASK_CTRL | LAYER_MASK_SHIFT),
           {"",  "",  "", "",  "",  "",  "", "",  "", "",  "Á", "",  "", "É",
            "Š", "Ž", "", "Ř", "Ď", "",  "", "Ť", "", "Č", "",  "Ý", "", "",
            "",  "Ú", "", "",  "",  "Í", "", "Ň", "", "Ó", "",  "",  "", "",
            "Ľ", "",  "", "",  "",  "",  "", "",  "", "",  "",  "",  "", ""}},
          {(LAYER_MASK_SHIFT | LAYER_MASK_OPT),
           {"",  "",  "", "",  "", "", "", "", "", "",  "Ä", "", "", "Ě",
            "",  "",  "", "Ŕ", "", "", "", "", "", "",  "",  "", "", "",
            "",  "Ů", "", "",  "", "", "", "", "", "Ô", "",  "", "", "",
            "Ĺ", "",  "", "",  "", "", "", "", "", "",  "",  "", "", ""}}}};

public:
  CardputerLayout() {};
  void begin();
  uint8_t getLayerMask(Keyboard::Modifiers modifiers) const;
  const char *lookup(Keyboard::Event &event);
};
