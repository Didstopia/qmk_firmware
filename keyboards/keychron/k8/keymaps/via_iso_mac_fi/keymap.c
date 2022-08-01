/* Copyright 2020 Adam Honse <calcprogrammer1@gmail.com>
 * Copyright 2020 Dimitris Mantzouranis <d3xter93@gmail.com>
 * Copyright 2022 Harrison Chan (Xelus)
 * Copyright 2022 Thomas Bowman Mørch (tbowmo)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

/*

FIXME: The following default keys should be set correctly:

- F1 - Brightness Down
- F2 - Brightness Up
- F3 - Expose (TODO: What key?)
- F4 - Mission Control (TODO: What key?)
- F5 - Keyboard Brightness Down
- F6 - Keyboard Brightness Up
- F7 - Previous Song (macOS)
- F8 - Play/Pause
- F9 - Next Song (macOS)
- F10 - Mute
- F11 - Volume Down
- F12 - Volume Up
- F13 - Screenshot (TODO: What key?)
- F14 - Siri (Fn+Space)
- F15 - Cycle RGB Mode (TODO: Or maybe for enabling/disabling lighting entirely?)

FIXME: The following functionality should be implemented

- Sleep keyboard and/or backlight when not in use (with stock firmware, pressing a key will wake the keyboard and it will never go back to sleep)

*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*  +--------------------------------------------------------------------------+----------------+
    | ESC |  | F1 | F2 | F3 | F4 | | F5 | F6 | F7 | F8 | | F9| F10| F11| F12|  | |PSCR|????|PAUS|
    +--------------------------------------------------------------------------+------|----|----|
    |  ~  |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP | |INS |SCRL|PGUP|
    +--------------------------------------------------------------------------+------|----|----|
    |  TAB  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |      | |DEL |END |PGDN|
    +--------------------------------------------------------------------  RET | +--------------+
    | CAPSLCK  |  A |  S |  D |  F |  G |  H |  J |  K |  L | ; | ' |  # |     |                |
    +--------------------------------------------------------------------------+      |----|    |
    | LSHIFT     |  Z |  X |  C |  V |  B |  N |  M | , | . |  / |   RSHIFT    |      | UP |    |
    +--------------------------------------------------------------------------+------|----|----|
    |LCTRL| LALT| LGUI |            SPACE            | RGUI| RALT | FN | RCTRL | |LFT |DWN |RGT |
    +--------------------------------------------------------------------------+----------------+
*/
    [0] = LAYOUT_tkl_iso(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,      KC_PSCR, KC_SLCK, KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,     KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,              KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                       KC_UP,
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                                      KC_RGUI, KC_RALT, MO(1),   KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_tkl_iso(
          RESET,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     RGB_SPI, RGB_SAI, RGB_HUI,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              RGB_SPD, RGB_SAD, RGB_HUD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                       RGB_VAI,
        _______, _______, _______,                   _______,                                     _______, _______, _______, _______,     RGB_RMOD,RGB_VAD, RGB_MOD
    ),
    [2] = LAYOUT_tkl_iso(
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                       _______,
        _______, _______, _______,                   _______,                                     _______, _______, _______, _______,     _______, _______, _______
    ),
    [3] = LAYOUT_tkl_iso(
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                       _______,
        _______, _______, _______,                   _______,                                     _______, _______, _______, _______,     _______, _______, _______
    )
};

// TODO: Added this, but not sure if we need it?
bool dip_switch_update_kb(uint8_t index, bool active) {
    if (!dip_switch_update_user(index, active)) { return false; }
    return true;
}

// FIXME: Implemenmt this
bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {  // Win/Android mode
                           // do stuff
                           // FIXME: Implement switching to Windows layout
            } else {       // Mac/iOS mode
                           // do stuff
                           // FIXME: Implement switching to macOS layout
            }
            break;
        case 1:
            if (active) {  // Cable mode
                // do stuff
                // FIXME: Do we need to do anything special here?
            } else {  // BT mode
                // do stuff
                // FIXME: BT is not supported :-( --- Could we utilize this for something.. different, like emulating a mouse for instance?
            }
            break;
    }
    return true;  // Returning true allows keyboard code to execute, false will tell the keyboard code "I've already handled it".
}

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    // debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
}
