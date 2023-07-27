/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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
#include "keycodes.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,
  // ├─────────────────────────────────────────────┤  ├─────────────────────────────────────────────┤
          KC_A,    KC_R,    KC_S,    KC_T,    KC_G,       KC_M,    KC_N,    KC_E,    KC_I,   KC_O,
  // ├─────────────────────────────────────────────┤  ├─────────────────────────────────────────────┤
          KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,
  // ╰─────────────────────────────────────────────┤  ├─────────────────────────────────────────────╯
                         XXXXXXX, SPC_LAY, ESC_LAY,      BSP_LAY, OS_SHFT
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_NUMNAV] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
        RESET,  KC_HOME,  KC_UP,  KC_END,  KC_PGUP,     KC_EQL,   KC_7,    KC_8,    KC_9,  KC_COLN,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,    KC_MINS,   KC_1,    KC_2,    KC_3,   KC_0,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LGUI,KC_INSERT,KC_BSPC, KC_DEL,  KC_MPLY,    KC_PLUS,   KC_4,    KC_5,    KC_6,   KC_NO,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, _______,    _______, KC_LCTL
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_SYMBOLS] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       KC_GRV,  KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,   RALT(KC_BSLS), RALT(KC_5), RALT(KC_G), RALT(KC_F), RALT(KC_SLSH),
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_EXLM, KC_CIRC, KC_LPRN, KC_RPRN, KC_HASH,   KC_ASTR, KC_BSLS, KC_EQL,  KC_PLUS, KC_DQT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_TILD, KC_DLR,  KC_LBRC, KC_RBRC, KC_PERC,   KC_PIPE, KC_AMPR, KC_LABK, KC_RABK, KC_QUES,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, _______,    _______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_FUNC] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       _______, _______, _______, _______, _______,    _______,  KC_F7,   KC_F8,   KC_F9,  KC_F10,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,    _______,  KC_F1,   KC_F2,   KC_F3,  KC_F11,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, RGB_SAD, RGB_HUD, RGB_VAD,RGB_RMOD,    _______,  KC_F4,   KC_F5,   KC_F6,  KC_F12,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, _______,    _______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _SYMBOLS, _NUMNAV, _FUNC);
// }
