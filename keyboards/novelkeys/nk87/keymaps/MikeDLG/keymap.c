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
    _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          _______,
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

// Determine which hand a key belongs to for bilateral combination filtering
static bool is_right_hand_key(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    switch(keycode) {
        case KC_Y: case KC_U: case KC_I: case KC_O: case KC_P:
        case KC_H: case KC_J: case KC_K: case KC_L: case KC_SCLN:
        case KC_N: case KC_M: case KC_COMM: case KC_DOT: case KC_SLSH:
        case KC_LBRC: case KC_RBRC: case KC_QUOT: case KC_BSLS:
        case KC_6: case KC_7: case KC_8: case KC_9: case KC_0:
        case KC_MINS: case KC_EQL:
        case KC_BSPC: case KC_ENT:
        case KC_INS: case KC_HOME: case KC_PGUP:
        case KC_DEL: case KC_END: case KC_PGDN:
        case KC_UP: case KC_DOWN: case KC_LEFT: case KC_RGHT:
            return true;
        default:
            return false;
    }
}

// Extract the modifier bits from a mod-tap keycode
static uint8_t get_mod_from_mod_tap(uint16_t keycode) {
    uint8_t mod = (keycode >> 8) & 0x1F;
    // QMK stores right-side mods with bit 4 set; convert to real mod bits
    if (mod & 0x10) {
        return (mod & 0x0F) << 4;
    }
    return mod;
}

// Bilateral combination state
static uint16_t last_mod_timer = 0;
static uint16_t active_mod = KC_NO;
static bool active_mod_is_right = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t caps_timer;

    bool is_mod_tap = false;
    bool is_right_mod = false;

    switch(keycode) {
        case LGUI_T(KC_A):
        case LALT_T(KC_S):
        case LSFT_T(KC_D):
        case LCTL_T(KC_F):
            is_mod_tap = true;
            is_right_mod = false;
            break;
        case RCTL_T(KC_J):
        case RSFT_T(KC_K):
        case RALT_T(KC_L):
        case RGUI_T(KC_SCLN):
            is_mod_tap = true;
            is_right_mod = true;
            break;
    }

    // Mod-tap key held (not tapped)
    if (is_mod_tap && record->event.pressed && record->tap.count == 0) {
        active_mod = keycode;
        active_mod_is_right = is_right_mod;
        last_mod_timer = timer_read();
        return true;
    }

    // Mod-tap key released
    if (is_mod_tap && !record->event.pressed) {
        if (keycode == active_mod) {
            active_mod = KC_NO;
        }
        return true;
    }

    // Bilateral combination: same-hand key pressed while a home row mod is held
    if (!is_mod_tap && record->event.pressed && active_mod != KC_NO) {
        bool is_right_key = is_right_hand_key(keycode);

        if (is_right_key == active_mod_is_right && timer_elapsed(last_mod_timer) < TAPPING_TERM) {
            // Unregister the modifier that QMK activated on the hold
            uint8_t mod_bits = get_mod_from_mod_tap(active_mod);
            unregister_mods(mod_bits);

            // Send the base letter of the mod-tap key
            tap_code16(active_mod & 0xFF);

            active_mod = KC_NO;

            // Let QMK process the current key normally
            return true;
        }
    }

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
