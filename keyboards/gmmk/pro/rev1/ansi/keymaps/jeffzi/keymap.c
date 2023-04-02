/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "os_detection.h"
#include "print.h"
#include "rgb.h"

enum layers { MAC = 0, WIN, FN };
enum my_keycodes { WINLOCK = SAFE_RANGE, RGB_NIGHT };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off

    /* Base Layout
     *
     *
     * ,-------------------------------------------------------------------------------------------------------------.
     * | Esc  ||  F1  |  F2  |  F3  |  F4  ||  F5  |  F6  |  F7  |  F8  ||  F9  | F10  | F11  | F12  || Play || Mute |
     * |=============================================================================================================|
     * |  ` ~ |  1 ! |  2 @ |  3 # |  4 $ |  5 % |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |  - _ |  = + |  Backspc || Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+----------++------|
     * |   Tab   |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | [ }  | ] }  |  \ |  || PgUp |
     * |---------+------+------+------+------+------+------+------+------+------+------+------+------+-------++------|
     * |  MEH/Caps  |  A   |  S   |  D   |  F  |  G   |  H   |  J   |  K   |  L   | ; :  | ' "  |    Enter   || PgDn |
     * |------------+------+------+------+-----+------+------+------+------+------+------+------|----+========+------|
     * |    LShift    |  Z   |  X   |  C   |  V   |  B   |  N   |  M   | , <  | . >  | / ?  | RShift ||  Up  || End  |
     * |--------------+------+------+------+------+------+------+------+------+------+------+--+=====++------++======|
     * |  Ctrl  |   Win  |  LAlt  |                 Space                 | RAlt |  Fn  | Ctrl || Left | Down | Rght |
     * `-------------------------------------------------------------------------------------------------------------'
     */

    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
     [WIN] = LAYOUT(
        KC_ESC,          KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PLAY_PAUSE,          KC_MUTE,
        KC_GRV,          KC_1,       KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,             KC_EQL,              KC_BSPC,                      KC_DEL,
        KC_TAB,          KC_Q,       KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,             KC_RBRC,             KC_BSLS,                      KC_PGUP,
        HYPR_T(KC_CAPS), KC_A,       KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                                  KC_ENT,                       KC_PGDN,
        KC_LSFT,         KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                                           KC_RSFT,             KC_UP,   KC_END,
        KC_LCTL,         KC_LGUI,    KC_LALT,                   KC_SPC,                             KC_RALT, MO(FN),  KC_RCTL,                                              KC_LEFT, KC_DOWN, KC_RGHT
    ),

     [MAC] = LAYOUT(
        KC_ESC,          KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PLAY_PAUSE,          KC_MUTE,
        KC_GRV,          KC_1,       KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,             KC_EQL,              KC_BSPC,                      KC_DEL,
        KC_TAB,          KC_Q,       KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,             KC_RBRC,             KC_BSLS,                      KC_PGUP,
        HYPR_T(KC_CAPS), KC_A,       KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                                  KC_ENT,                       KC_PGDN,
        KC_LSFT,         KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                                           KC_RSFT,             KC_UP,   KC_END,
        KC_LCTL,         KC_LALT,    KC_LGUI,                   KC_SPC,                             KC_RALT, MO(FN),  KC_RCTL,                                              KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [FN] = LAYOUT(
        _______,         KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,              KC_F12,              KC_SYSTEM_POWER,              _______,
        _______,         _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______,             _______,                      _______,
        _______,         _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______,             QK_BOOT,                      _______,
        _______,         _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                                  _______,                      _______,
        _______,         RGB_TOG,    _______, _______, QK_BOOT, _______, _______, _______, _______, _______, _______,                                           _______,             _______, _______,
        _______,         WINLOCK,    _______,                   _______,                            _______, _______, _______,                                              _______, _______, _______
    ),
    // clang-format on
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_AUDIO_VOL_UP);
    } else {
        tap_code(KC_AUDIO_VOL_DOWN);
    }
    return true;
}

#ifdef OS_DETECTION_ENABLE

os_variant_t os_type;

uint32_t set_macos_compatibility(uint32_t trigger_time, void *cb_arg) {
    os_type = detected_host_os();
    if (os_type) {
        switch (os_type) {
            case OS_UNSURE:
                dprint("unknown OS Detected\n");
                break;
            case OS_LINUX:
                dprint("Linux Detected\n");
                break;
            case OS_WINDOWS:
                dprint("Windows Detected\n");
                break;
            case OS_MACOS:
                dprint("MacOS Detected\n");
                break;
            case OS_IOS:
                dprint("iOS Detected\n");
                break;
        }
        bool is_mac = (os_type == OS_MACOS) || (os_type == OS_IOS);
        // keymap_config.swap_lalt_lgui = is_mac;
        if (is_mac) {
            default_layer_set(MAC);
            layer_on(MAC);
            layer_off(WIN);
        } else {
            default_layer_set(WIN);
            layer_on(WIN);
            layer_off(MAC);
        }
    }

    return os_type ? 0 : 500;
}
#endif

#ifdef RGB_MATRIX_ENABLE

void set_color_leds(const uint8_t leds[], size_t n_leds, const uint8_t r,
                    const uint8_t g, const uint8_t b) {
    for (uint8_t i = 0; i < n_leds; i++) {
        rgb_matrix_set_color(leds[i], r, g, b);
    }
}

void highlight_capslock(void) {
    set_color_leds(LED_CAPSLOCK, ARRAY_SIZE(LED_CAPSLOCK), RGB_CHARTREUSE);
    set_color_leds(LED_SIDE_LEFT, ARRAY_SIZE(LED_SIDE_LEFT), RGB_CHARTREUSE);
    set_color_leds(LED_SIDE_RIGHT, ARRAY_SIZE(LED_SIDE_RIGHT), RGB_CHARTREUSE);
}

void highlight_gaming(void) {
    set_color_leds(LED_WASD, ARRAY_SIZE(LED_WASD), RGB_PINK_BRIGHT);
    set_color_leds(LED_GAMING_WO_WASD, ARRAY_SIZE(LED_GAMING_WO_WASD), RGB_NAUTILUS);
    set_color_leds(LED_SIDE_LEFT, ARRAY_SIZE(LED_SIDE_LEFT), RGB_PINK_BRIGHT);
    set_color_leds(LED_SIDE_RIGHT, ARRAY_SIZE(LED_SIDE_RIGHT), RGB_PINK_BRIGHT);
    rgb_matrix_set_color(LED_LWIN, RGB_RED);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    led_t led_state = host_keyboard_led_state();

    // CapsLock RGB setup
    if (led_state.caps_lock) {
        highlight_capslock();
    }

    // Winkey disabled (gaming) mode RGB setup
    if (keymap_config.no_gui) {
        highlight_gaming();
    }

    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Windows Key lockout
        case WINLOCK:
            if (record->event.pressed) {
                keymap_config.no_gui = !keymap_config.no_gui; // toggle status

            } else {
                unregister_code16(keycode);
            }
            break;
    }
    return true;
}

void keyboard_post_init_user(void) {
#ifdef OS_DETECTION_ENABLE
#    if defined(DEFERRED_EXEC_ENABLE)
    defer_exec(100, set_macos_compatibility, NULL);
#    else
    defer_exec(0, NULL);
#    endif

#endif
    rgblight_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
}
