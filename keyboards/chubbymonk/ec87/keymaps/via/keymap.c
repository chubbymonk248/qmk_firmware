/* Copyright 2022 Cipulot
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

#include "ec_switch_matrix.h"
#include "timer.h"

enum custom_keycodes { DOUBLE_0 = SAFE_RANGE };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,  KC_F4,  KC_F5,   KC_F6,  KC_F7,  KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,                KC_PSCR,  KC_NUM,   KC_PAUS,
    KC_GRV,   KC_1,     KC_2,     KC_3,   KC_4,   KC_5,    KC_6,   KC_7,   KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,
    KC_TAB,   KC_Q,     KC_W,     KC_E,   KC_R,   KC_T,    KC_Y,   KC_U,   KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,
    KC_LCTL,  KC_A,     KC_S,     KC_D,   KC_F,   KC_G,    KC_H,   KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENTER,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,   KC_V,   KC_B,    KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,                                    KC_UP,
    KC_CAPS,  KC_LGUI,  KC_LALT,                  KC_SPC,                            KC_RALT,  KC_RGUI,  MO(1),  KC_RCTL,               KC_LEFT,  KC_DOWN,  KC_RIGHT),

    [1] = LAYOUT_all(
    RESET,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_SYRQ,  KC_SCRL,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                                   KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,                  KC_TRNS,                           KC_TRNS, KC_APP,   KC_TRNS,  KC_TRNS,                        KC_MUTE,  KC_VOLD,  KC_VOLU),

    [2] = LAYOUT_all(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                                  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,                  KC_TRNS,                           KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,                       KC_TRNS,  KC_TRNS,  KC_TRNS),

    [3] = LAYOUT_all(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_P7,    KC_P8,    KC_P9,    KC_TRNS,  KC_PMNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_P4,    KC_P5,    KC_P6,    KC_TRNS,  KC_PENT,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_P1,    KC_P2,    KC_P3,    KC_PPLS,  KC_PAST,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_P0,    DOUBLE_0, KC_PDOT,  KC_PSLS,  KC_TRNS,                                  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,                  KC_TRNS,                         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                        KC_TRNS,  KC_TRNS,  KC_TRNS)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DOUBLE_0:
            if (record->event.pressed) {
                tap_code(KC_P0);
                wait_ms(3);
                tap_code(KC_P0);
            }
            break;
    }
    return true;
}

void keyboard_post_init_user() {
    layer_state_set_user(layer_state);
}

static uint8_t old_usb_led = 0; // 0 = off, 2 = on
void led_set_user(uint8_t usb_led) {
    wait_ms(10);

    if ((usb_led & (1 << USB_LED_NUM_LOCK)) && !(old_usb_led & (1 << USB_LED_NUM_LOCK))) {
        // If CAPS LK LED is turning on...
        layer_on(3);
    } else if (!(usb_led & (1 << USB_LED_NUM_LOCK)) && (old_usb_led & (1 << USB_LED_NUM_LOCK))) {
        // If CAPS LK LED is turning off...
        layer_off(3);
    }

    old_usb_led = usb_led;
}