/* Copyright 2020 Yiancar
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

enum layers {
    _BASE = 0,
    _FN,
    _NAV,
    _VIA
};

enum custom_keycodes {
    ESC_CAPS = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_tkl_f13_ansi_tsangan(
    KC_ESC,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_PSCR, KC_SCRL, KC_PAUS,
    KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,
    KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  KC_END,  KC_PGDN,
    ESC_CAPS,
    LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F),
    KC_G,   KC_H,
    RCTL_T(KC_J), RSFT_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
    KC_QUOT,          KC_ENT,
    KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,                   KC_UP,
    KC_LCTL, KC_LGUI, KC_LALT,
    LT(_NAV, KC_SPC),
    KC_RALT, MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

[_FN] = LAYOUT_tkl_f13_ansi_tsangan(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, KC_VOLD, KC_MUTE,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                   _______,
    _______, _______, _______,                   _______,                                              _______, _______, _______, _______, _______, _______),

[_NAV] = LAYOUT_tkl_f13_ansi_tsangan(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_F13,  _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                   _______,
    _______, _______, _______,                   _______,                                              _______, _______, _______, _______, _______, _______),

[_VIA] = LAYOUT_tkl_f13_ansi_tsangan(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                   _______,
    _______, _______, _______,                   _______,                                              _______, _______, _______, _______, _______, _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t caps_timer;

    // ESC on tap, Caps Lock on hold
    if (keycode == ESC_CAPS) {
        if (record->event.pressed) {
            caps_timer = timer_read();
        } else {
            if (timer_elapsed(caps_timer) < TAPPING_TERM) {
                tap_code(KC_ESC);
            } else {
                tap_code(KC_CAPS);
            }
        }
        return false;
    }

    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NAV, KC_SPC):
            return 250;
        case LGUI_T(KC_A):
        case RGUI_T(KC_SCLN):
            return 250;
        case LALT_T(KC_S):
        case RALT_T(KC_L):
            return 225;
        case LSFT_T(KC_D):
        case RSFT_T(KC_K):
            return 200;
        case LCTL_T(KC_F):
        case RCTL_T(KC_J):
            return 225;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NAV, KC_SPC):
            return true;
        default:
            return false;
    }
}
