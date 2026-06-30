#pragma once
#include <Adafruit_TCA8418.h>
#include <stdint.h>

// Non normalized
// 1  5  11  15  21  25  31  35  41  45  51  55  61  65
// 2  6  12  16  22  26  32  36  42  46  52  56  62  66
// 3  7  13  17  23  27  33  37  43  47  53  57  63  67
// 4  8  14  18  24  28  34  38  44  48  54  58  64  68

// Normalized
//  0   4   8  12  16  20  24  28  32  36  40  44  48  52
//  1   5   9  13  17  21  25  29  33  37  41  45  49  53
//  2   6  10  14  18  22  26  30  34  38  42  46  50  54
//  3   7  11  15  19  23  27  31  35  39  43  47  51  55

namespace Keyboard {
// Normalized key codes
enum Key : uint8_t {
  // Column 1
  KEY_ESC = 0,
  KEY_TAB = 1,
  KEY_FN = 2,
  KEY_CTRL = 3,
  // Column 2
  KEY_1 = 4,
  KEY_Q = 5,
  KEY_SHIFT = 6,
  KEY_OPT = 7,
  // Column 3
  KEY_2 = 8,
  KEY_W = 9,
  KEY_A = 10,
  KEY_ALT = 11,
  // Column 4
  KEY_3 = 12,
  KEY_E = 13,
  KEY_S = 14,
  KEY_Z = 15,
  // Column 5
  KEY_4 = 16,
  KEY_R = 17,
  KEY_D = 18,
  KEY_X = 19,
  // Column 6
  KEY_5 = 20,
  KEY_T = 21,
  KEY_F = 22,
  KEY_C = 23,
  // Column 7
  KEY_6 = 24,
  KEY_Y = 25,
  KEY_G = 26,
  KEY_V = 27,
  // Column 8
  KEY_7 = 28,
  KEY_U = 29,
  KEY_H = 30,
  KEY_B = 31,
  // Column 9
  KEY_8 = 32,
  KEY_I = 33,
  KEY_J = 34,
  KEY_N = 35,
  // Column 10
  KEY_9 = 36,
  KEY_O = 37,
  KEY_K = 38,
  KEY_M = 39,
  // Column 11
  KEY_0 = 40,
  KEY_P = 41,
  KEY_L = 42,
  KEY_COMMA = 43,
  // Column 12
  KEY_MINUS = 44,
  KEY_LBRACKET = 45,
  KEY_SEMICOLON = 46,
  KEY_PERIOD = 47,
  // Column 13
  KEY_PLUS = 48,
  KEY_RBRACKET = 49,
  KEY_APOSTROPHE = 50,
  KEY_SLASH = 51,

  // Column 14
  KEY_BACK = 52,
  KEY_BACKSLASH = 53,
  KEY_RETURN = 54,
  KEY_SPACE = 55,

  KEY_NONE = 255
};

struct Modifiers {
  bool shift = false;
  bool opt = false;
  bool alt = false;
  bool ctrl = false;
  bool fn = false;
};

struct Event {
  Key key = KEY_NONE;
  bool changed = false;
  bool down = false;
  Modifiers modifiers;
};

}; // namespace Keyboard

class CardputerKeyboard {
private:
  Adafruit_TCA8418 tio;
  Keyboard::Modifiers modifiers;
  bool isModifier(Keyboard::Key key);
  void updateModifier(Keyboard::Key key, bool down);

public:
  CardputerKeyboard() {}
  void begin();
  Keyboard::Event poll();
};
