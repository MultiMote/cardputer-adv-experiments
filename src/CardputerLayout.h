#pragma once

#include "CardputerKeyboard.h"
#include "globals.h"
#include <FS.h>
#include <stdint.h>

#define TOTAL_KEYS 56

namespace Keyboard {
namespace Layout {
enum LayoutType { LAYOUT_TYPE_MAIN, LAYOUT_TYPE_ALT };

enum LayerMask {
  LAYER_MASK_BASE = 0x00,
  LAYER_MASK_FN = 0x01,
  LAYER_MASK_CTRL = 0x02,
  LAYER_MASK_SHIFT = 0x04,
  LAYER_MASK_OPT = 0x08,
  LAYER_MASK_ALT = 0x10
};

struct LayoutEntry {
  char data[KB_LAYOUT_CHAR_MAX + 1];
};

struct LayoutLayer {
  uint8_t modifiers_mask;
  LayoutEntry entries[TOTAL_KEYS];
};

struct LayoutData {
  char language_code[3];
  uint8_t layers_count;
  LayoutLayer *layers;
};

class CardputerLayout {
private:
  LayoutData *base_layout = nullptr;
  LayoutData *alternate_layout = nullptr;
  LayoutData *current_layout = nullptr;
  LayoutType current_layout_type = LAYOUT_TYPE_MAIN;

public:
  CardputerLayout();
  void begin();
  uint8_t getLayerMask(Keyboard::Modifiers modifiers) const;
  const char *lookup(Keyboard::Event &event);

  void begin(FS &fs);
  void parseLayout(FS &fs, LayoutType layoutType);
  void switchLayout();
  inline const char *getCurrentCode() const {
    return current_layout ? current_layout->language_code : "??";
  }
};

} // namespace Layout

} // namespace Keyboard

using Keyboard::Layout::CardputerLayout;
