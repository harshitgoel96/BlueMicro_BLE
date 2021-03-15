/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"
#define KEYBOARD_MASTER RIGHT


#if KEYBOARD_SIDE == SINGLE
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
        KC_1,  KC_2,    KC_3,    KC_4,    KC_5,    KC_6, 
        KC_1,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  
        KC_2,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  
        KC_3,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_SPC,
        KC_4,  KC_5,    KC_6,    KC_7
    )};

void setupKeymap() {

   // no layers for master keymap
   // this is a keymap that's used for testing that each key is responding properly to key presses
   // flash this keymap to both left and right to test whether each half works properly.
   // once tested, you can flash the left and right to their respective halves.

}
#endif


#if KEYBOARD_SIDE == LEFT


std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
         KC_NO,KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,  \
  KC_NO,KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,  \
  KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,    \
  KC_NO ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO ,KC_NO , KC_NO,   \
                             KC_NO, KC_NO, KC_NO, KC_NO  \
    )};

 
void setupKeymap() {

 uint32_t press[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
       KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  
        LAYER_1,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  
        KC_LSFT, KC_NO,    KC_X,    KC_C,    KC_V,    KC_B, KC_SPC,
                          KC_LCTRL, KC_LALT, KC_SPC, KC_BSPACE 
);
    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
       KC_GRAVE,KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,  \
  KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,   KC_5,  \
  LAYER_1  ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,    \
  KC_LSFT ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 , KC_SPC,   \
                             KC_LCTRL, KC_LALT, KC_SPC, KC_BSPACE  \
);
  
 uint32_t tap[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
       KC_NO,KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,  \
  KC_NO,KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,  \
  KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,    \
  KC_NO ,KC_Z  ,KC_NO  ,KC_NO  ,KC_NO ,KC_NO , KC_NO,   \
                             KC_NO, KC_NO, KC_NO, KC_NO  \
);
  
 uint32_t hold[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
       KC_NO,KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,  \
  KC_NO,KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,  \
  KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,    \
  KC_NO ,LAYER_2  ,KC_NO  ,KC_NO  ,KC_NO ,KC_NO , KC_NO,   \
                             KC_NO, KC_NO, KC_NO, KC_NO  \
);
 uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
       OUT_USB,OUT_BT,   KC_F2,  KC_F3,   KC_F4,   PRINT_BATTERY,  \
  KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,   KC_5,  \
  KC_CAPSLOCK   ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,    \
  KC_LSFT ,LAYER_2  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 , KC_SPC,   \
                             KC_LCTRL, KC_LALT, KC_SPC, KC_BSPACE  \
);
    /*
     * add the other layers on the regular presses.
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {matrix[row][col].addActivation(_QWERTY, Method::PRESS, press[row][col]);
          matrix[row][col].addActivation(_QWERTY, Method::MT_TAP, tap[row][col]);
            matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
            matrix[row][col].addActivation(_QWERTY, Method::MT_HOLD, hold[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS, layer2[row][col]);
            
        }
    }

    // if you want to add Tap/Hold or Tap/Doubletap activations, then you add them below.

}

#endif  // left



#if KEYBOARD_SIDE == RIGHT



std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
          KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,      KC_NO,  \
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO, 
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO,
     KC_NO,   KC_NO,    KC_NO,    KC_NO,KC_NO,  KC_NO ,   KC_NO,
        KC_NO,  KC_NO, KC_NO, KC_NO
    )};

 

void setupKeymap() {
 uint32_t press[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
         KC_6,    KC_7,    KC_8,    KC_9,     KC_0,      KC_MINS,  \
        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_BSLS, 
        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCOLON, KC_QUOTE,
     KC_SPC,   KC_N,    KC_M,    KC_COMMA,KC_DOT,  KC_NO,   KC_RSHIFT,
        KC_ENT,  KC_SPC, KC_LGUI, LAYER_1
);
 uint32_t tap[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
         KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,      KC_NO,  \
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO, 
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO,
     KC_NO,   KC_NO,    KC_NO,    KC_NO,KC_NO,  KC_SLASH ,   KC_NO,
        KC_NO,  KC_NO, KC_NO, KC_NO
);
    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
         KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_EQUAL ,  \
    KC_6,    KC_7,    KC_UP,    KC_9,     KC_F11,      KC_F12,  \
    KC_F6,   KC_LEFT, KC_DOWN,  KC_RIGHT,  KC_RBRC,   KC_BSLS,   \
 KC_SPC,    KC_F12,  KC_NUHS, KC_NUBS, _______,  _______,   _______,  \
    KC_ENT,  KC_SPC, KC_LGUI, LAYER_1\
);
 uint32_t hold[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
         KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,      KC_NO,  \
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO, 
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO,
     KC_NO,   KC_NO,    KC_NO,    KC_NO,KC_NO,  LAYER_2,   KC_NO,
        KC_NO,  KC_NO, KC_NO, KC_NO
);

   uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
         PRINT_BATTERY,    KC_F7,    KC_F8,    KC_F9,    OUT_BT,   OUT_USB,  \
    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,      KC_F12,  \
    KC_F6,   KC_MINS, KC_EQL,  KC_LBRC,  KC_RBRC,   KC_BSLS,   \
 KC_SPC,    KC_F12,  KC_NUHS, KC_NUBS, _______,  LAYER_2,   _______,  \
    KC_ENT,  KC_SPC, KC_LGUI, _______\
);
    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {matrix[row][col].addActivation(_QWERTY, Method::PRESS, press[row][col]);
          matrix[row][col].addActivation(_QWERTY, Method::MT_TAP, tap[row][col]);
            matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
           matrix[row][col].addActivation(_QWERTY, Method::MT_HOLD, hold[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS, layer2[row][col]);
        }
    }

}


#endif