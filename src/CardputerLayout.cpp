#include "CardputerLayout.h"



uint8_t CardputerLayout::getLayerMask(Keyboard::Modifiers modifiers) const {
  return (modifiers.fn ? LAYER_MASK_FN : 0) |
         (modifiers.ctrl ? LAYER_MASK_CTRL : 0) |
         (modifiers.shift ? LAYER_MASK_SHIFT : 0) |
         (modifiers.opt ? LAYER_MASK_OPT : 0) |
         (modifiers.alt ? LAYER_MASK_ALT : 0);
}



void CardputerLayout::begin() {}

const char *CardputerLayout::lookup(Keyboard::Event &event) {
  if (event.key == Keyboard::KEY_NONE) {
    return "";
  }

  uint8_t mask = getLayerMask(event.modifiers);
  uint8_t key = event.key - 1;

  // Try to find an exact match in the current modifier layer
  for (uint8_t i = 0; i < layout.layers_count; i++) {
    if (mask == layout.layers[i].modifiers_mask) {
      char* data = layout.layers[i].entries[key].data;
      if (data[0]) {
        return data;
      }
    }
  }

  // If Shift is pressed and nothing was found, try the dedicated SHIFT layer
  if (event.modifiers.shift && mask != LAYER_MASK_SHIFT) {
    for (uint8_t i = 0; i < layout.layers_count; i++) {
      if (LAYER_MASK_SHIFT == layout.layers[i].modifiers_mask) {
        char* data = layout.layers[i].entries[key].data;
        if (data[0]) {
          return data;
        }
      }
    }
  }

  // Fallback to the BASE layer if we haven't returned anything yet
  if (mask != LAYER_MASK_BASE) {
    for (uint8_t i = 0; i < layout.layers_count; i++) {
      if (LAYER_MASK_BASE == layout.layers[i].modifiers_mask) {
        char* data = layout.layers[i].entries[key].data;
        if (data[0]) {
          return data;
        }
      }
    }
  }

  return "";
}
