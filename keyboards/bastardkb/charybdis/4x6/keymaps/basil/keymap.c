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

enum {
    A_UMLAUT = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case A_UMLAUT:
            if (record->event.pressed) {
               // opt 5
                SEND_STRING(SS_LALT("5"));
            }
            return false;
    }

    return true;
}

/// This is not actually for umlaut, its how we do left bracket and all the other keys remapped by intl layouts
enum {
    TD_A_UMLAUT,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_A_UMLAUT] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_QUOT),
};

enum charybdis_keymap_layers {
     LAYER_BASE = 0,
     _L1,
     LAYER_COLEMAK = 7,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     // Basil base layer
     [LAYER_BASE] = LAYOUT_charybdis_4x6(
     // Querty, with tapdance for intl chars
     // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
          KC_CAPS,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DEL,
     // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
          KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_GRAVE,
     // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
          KC_TAB,    TD(TD_A_UMLAUT),    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_COMM, KC_DOT,
     // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
          XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_MS_BTN1,  KC_MS_BTN2, KC_SLSH, KC_LALT,
     // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                   KC_ENT, KC_LSFT,   KC_LGUI,      KC_SPC,  KC_BSPC,
                                        KC_LCTL, TO(0),     XXXXXXX
     //                            ╰───────────────────────────╯ ╰──────────────────╯
     ),

     [_L1] = LAYOUT_charybdis_4x6(
     // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
     // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
          XXXXXXX, XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX,    KC_KP_DOT, KC_7, KC_8, KC_9, KC_KP_MINUS, KC_KP_PLUS, 
     // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
          XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX,    KC_KP_COMMA, KC_4, KC_5, KC_6, KC_KP_EQUAL_AS400, KC_KP_ASTERISK, 
     // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
          XXXXXXX, KC_END, KC_PAGE_UP, KC_PAGE_DOWN, KC_HOME, XXXXXXX,    KC_0, KC_1, KC_2, KC_3, KC_KP_SLASH, KC_KP_ENTER, 
     // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,
                                             XXXXXXX, XXXXXXX,      XXXXXXX
     //                            ╰───────────────────────────╯ ╰──────────────────╯
     ),

     [LAYER_COLEMAK] = LAYOUT_charybdis_4x6(
     // Colemak-dh(m?)
     // ignore top row to start with, aiming for a minimal usable layout to build on
     // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
          KC_ESC,    KC_NO,    KC_NO,    KC_VOLD,    KC_VOLU,    KC_MPLY,       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK,
     // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
          KC_NO,    MT(MOD_LSFT,KC_Q),    MT(MOD_LALT,KC_W),    MT(MOD_LCTL,KC_F),    MT(MOD_LGUI,KC_P),    KC_B, KC_J,       MT(MOD_LGUI,KC_L),    MT(MOD_LCTL,KC_U),    MT(MOD_LALT,KC_Y),    KC_NO, KC_NO,
     // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
          KC_ESC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,       KC_M,    KC_N,    KC_E,    KC_I, KC_O, KC_NO,
     // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
          KC_TAB,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_NO,
     // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                   MO(2), KC_LSFT,   LT(1,KC_SPC),      KC_ENT,  LT(3,KC_BSPC),
                                             XXXXXXX, TO(2),     MO(1)
     //  
     ),

// Andy's mouse layer
//   [LAYER_NUM_MOUSE] = LAYOUT_charybdis_4x6(
//   // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
//        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
//   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//        XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, XXXXXXX, XXXXXXX,    XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX, XXXXXXX, 
//   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//        XXXXXXX, XXXXXXX, KC_MS_BTN2, XXXXXXX, KC_MS_BTN1, XXXXXXX,    XXXXXXX, KC_4, KC_5, KC_6, XXXXXXX, XXXXXXX, 
//   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_0, KC_1, KC_2, KC_3, XXXXXXX, XXXXXXX, 
//   // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
//                                   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,
//                                            XXXXXXX, XXXXXXX,      XXXXXXX
//   //                            ╰───────────────────────────╯ ╰──────────────────╯
//   ),

// // Transparent template
//      // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
//           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
//      // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
//      // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
//      // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
//      // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
//                                    XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,
//                                              XXXXXXX, XXXXXXX,      XXXXXXX
//      //                            ╰───────────────────────────╯ ╰──────────────────╯
};
// clang-format on
