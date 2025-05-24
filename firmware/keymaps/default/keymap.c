// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <keymap_us_international.h>
#include <sendstring_us_international.h>

enum layers {
    _colemak = 0,
    _fn,
    _algr,
    _rs,
    _menu,
};

enum custom_keycodes {
    C_GRAV = SAFE_RANGE,
    C_APOS,
    C_TDLE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case C_GRAV:
        if (record->event.pressed) {
            SEND_STRING("`");
        }
        break;
    case C_APOS:
        if (record->event.pressed) {
            SEND_STRING("'");
        }
        break;
    case C_TDLE:
        if (record->event.pressed) {
            SEND_STRING("~");
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_colemak] = LAYOUT(
        C_GRAV,  US_1,    US_2,    US_3,    US_4,    US_5,        US_6,    US_7,    US_8,    US_9,    US_0,    CW_TOGG,
        KC_TAB,  US_Q,    US_W,    US_F,    US_P,    US_B,        US_J,    US_L,    US_U,    US_Y,    US_SCLN, US_BSLS,
        KC_BSPC, US_A,    US_R,    US_S,    US_T,    US_G,        US_M,    US_N,    US_E,    US_I,    US_O,    C_APOS,
        KC_LSFT, US_Z,    US_X,    US_C,    US_D,    US_V,        US_K,    US_H,    US_COMM, US_DOT,  US_SLSH, KC_ENT,
        KC_LCTL, KC_LWIN, KC_LALT, MO(_fn), KC_SPC,                        KC_SPC,  MO(_algr),MO(_rs),MO(_menu),KC_RCTL
    ),
    [_fn] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,  KC_F12,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_algr] = LAYOUT(
        US_DGRV, US_IEXL, US_DIAE,ALGR(S(3)),US_4,    US_5,        US_6,    US_7,    US_8,    US_9,    US_0,    CW_TOGG,
        KC_TAB,  US_Q,    US_W,    US_F,    US_P,    US_B,        US_J,    US_L,    US_U,    US_Y,    US_SCLN, US_BSLS,
        KC_BSPC, US_A,    US_R,    US_S,    US_T,    US_G,        US_M,    US_N,    US_E,    US_I,    US_O,    C_APOS,
        KC_LSFT, US_Z,    US_X,    US_C,    US_D,    US_V,        US_K,    US_H,    US_COMM, US_DOT,  US_SLSH, KC_ENT,
        KC_LCTL, MO(1),   KC_LALT, MO(2),   KC_SPC,                        KC_SPC,  MO(3),   MO(4),   MO(5),   KC_RCTL
    ),
    [_rs] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_menu] = LAYOUT(
        KC_TRNS, KC_PGUP, KC_PGDN, KC_INS,  KC_DEL,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};
