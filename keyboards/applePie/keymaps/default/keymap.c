/* Copyright 2020 ccullin
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
#include "version.h"
#include <print.h>
#include <stdio.h>
#ifdef SPLIT_KEYBOARD
// #include "split_util.h"
#endif

#ifdef BLUETOOTH
#include "adafruit_ble.h"
#endif

#ifdef RGB_MATRIX_ENABLE
#include <rgblight_list.h>
#endif

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    RGB_HUE = SAFE_RANGE,   //  RGB Matrix Hue (h)
    RGB_SAT,                //  RGB Matrix Saturation (s)
    RGB_BRT,                //  RGB Matrix Brightness (v)
    RGB_SPE,                //  RGB Matrix Speed of animiation
    RGB_RGB,                //  RGB color list step through
    KC_PRGM                //  Programable Key
};

bool shift_pressed = false;  // used to custom shift functions




#ifdef TEST_LEFT
    /*
    * test LEFT
    */
    const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_QWERTY] = LAYOUT(
        KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
                  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
                  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
                  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
        MO(_FN),  KC_LCTL, KC_LOPT, KC_LCMD,          KC_SPC
        ),
        [_FN] = LAYOUT(
        _______,  RGB_TOG, RGB_MOD, RGB_HUE, RGB_SAT, RGB_BRT, RGB_SPE,
                  _______, RGB_RGB, _______, _______, _______, _______,
                  _______, _______, _______, _______, _______, _______,
                  _______, _______, _______, _______, _______, _______,
        _______,  RESET,   _______, _______,          _______
        )
    };
#ifdef RGB_MATRIX_ENABLE
    const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {

        /*  LEFT SIDE */
        { 0,   A_5,  B_5,  C_5 }, //0
        { 0,   A_12, B_12, C_12 },
        { 0,   A_4,  B_4,  C_4 },
        { 0,   A_3,  B_3,  C_3 },
        { 0,   A_2,  B_2,  C_2 },
        { 0,   A_6,  B_6,  C_6 },
        { 0,   A_7,  B_7,  C_7 },

        { 0,   D_12, E_12, F_12 }, //7
        { 0,   D_4,  E_4,  F_4 },
        { 0,   D_3,  E_3,  F_3 },
        { 0,   D_2,  E_2,  F_2 },
        { 0,   D_6,  E_6,  F_6 },
        { 0,   D_7,  E_7,  F_7 },

        { 0,   G_12, H_12, I_12 }, //13
        { 0,   G_4,  H_4,  I_4 },
        { 0,   G_3,  H_3,  I_3 },
        { 0,   G_2,  H_2,  I_2 },
        { 0,   G_6,  H_6,  I_6 },
        { 0,   G_7,  H_7,  I_7 },

        { 0,   J_5,  K_5,  L_5 }, //19
        { 0,   J_12, K_12, L_12 },
        { 0,   J_4,  K_4,  L_4 },
        { 0,   J_3,  K_3,  L_3 },
        { 0,   J_2,  K_2,  L_2 },
        { 0,   J_6,  K_6,  L_6 },
        { 0,   J_7,  K_7,  L_7 },
        { 0,   J_8,  K_8,  L_8 },
        { 0,   J_9,  K_9,  L_9 },
        { 0,   J_11, K_11, L_11 },
        { 0,   J_10, K_10, L_10 } //29
    };


    led_config_t g_led_config = { {
    // Key Matrix to LED Index
    // position in list = key order.  No = LED list position above
    { 0,      1,       2,     3,     4,      5,      6,       },
    { NO_LED, 7,       8,     9,     10,     11,     12,      },
    { NO_LED, 13,     14,     15,    16,     17,     18,      },
    { NO_LED, 20,     21,     22,    23,     24,     25,      },
    { 19,     26,     27,     28,    NO_LED, 29,     NO_LED,  }
    }, {
    // LED Index to Physical Position
    {0, 0},  {15, 0},  {30, 0},  {45, 0},  {60, 0},  {75, 0},  {90, 0},
    {0, 16}, {15, 16}, {30, 16}, {45, 16}, {60, 16}, {75, 16},
    {0, 32}, {15, 32}, {30, 32}, {45, 32}, {60, 32}, {75, 32},
            {15, 48}, {30, 48}, {45, 48}, {60, 48}, {75, 48}, {90, 48},
    {0, 64}, {15, 64}, {30, 64}, {45, 64},           {75, 64}
    }, {
    // LED Index to Flag
    4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4,
        1, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
    }
    };
#endif  //RGB_MATRIX_ENABLE

#elif TEST_RIGHT
    /*
    * test RIGHT
    */
    const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

        [_QWERTY] = LAYOUT(
        KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  RGB_MOD,
        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
        KC_SPC,           KC_RCMD, KC_ROPT, KC_PRGM, KC_LEFT, KC_DOWN, RGB_RGB
        ),
        [_FN] = LAYOUT(
        _______, _______, _______, _______, _______, _______, KC_BSPC,
        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______
        )
    };

#ifdef RGB_MATRIX_ENABLE
    const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = { // original working code NOT memory optimised
        // /*  RIGHT SIDE */
        { 0,   D_11, E_11, F_11 }, //30
        { 0,   D_10, E_10, F_10 },
        { 0,   D_9,  E_9,  F_9 },
        { 0,   D_8,  E_8,  F_8 },
        { 0,   D_7,  E_7,  F_7 },
        { 0,   D_6,  E_6,  F_6 },
        { 0,   D_1,  E_1,  F_1 },

        { 0,   A_11, B_11, C_11 }, //37
        { 0,   A_10, B_10, C_10 },
        { 0,   A_9,  B_9,  C_9 },
        { 0,   A_8,  B_8,  C_8 },
        { 0,   A_7,  B_7,  C_7 },
        { 0,   A_6,  B_6,  C_6 },
        { 0,   A_1,  B_1,  C_1 },
        { 0,   A_4,  B_4,  C_4 },

        { 0,   J_11,  K_11,  L_11 }, //45
        { 0,   J_10,  K_10,  L_10 },
        { 0,   J_9,  K_9,  L_9 },
        { 0,   J_8,  K_8,  L_8 },
        { 0,   J_7,  K_7,  L_7 },
        { 0,   J_6,  K_6,  L_6 },
        { 0,   J_1,  K_1,  L_1 },
        { 0,   J_4,  K_4,  L_4 },
        { 0,   J_2,  K_2,  L_2 },
        { 0,   J_3,  K_3,  L_3 },

        { 0,   G_11,  H_11,  I_11 }, //55
        { 0,   G_10,  H_10,  I_10 },
        { 0,   G_9,  H_9,  I_9 },
        { 0,   G_8,  H_8,  I_8 },
        { 0,   G_7,  H_7,  I_7 },
        { 0,   G_6,  H_6,  I_6 },
        { 0,   G_1,  H_1,  I_1 },
        { 0,   G_4,  H_4,  I_4 },
        { 0,   G_2,  H_2,  I_2 },
        { 0,   G_3,  H_3,  I_3 },
        { 0,   G_5,  H_5,  I_5 } //65
    };

    led_config_t g_led_config = { {
        // Key Matrix to LED Index
        // position in list = key order.  No = LED list position above

        { 30,     31,     32,     33,    34,     35,     36,     NO_LED },
        { 37,     38,     39,     40,    41,     42,     43,     44     },
        { 45,     46,     47,     48,    49,     50,     51,     NO_LED },
        { 55,     56,     57,     58,    59,     60,     61,     NO_LED },
        { 62,     NO_LED, 63,     64,    65,     54,     53,     52     }
        }, {
        // LED Index to Physical Position
                    {105, 0},  {119, 0},  {134, 0},  {149, 0},  {164, 0},  {179, 0},  {194, 0},
        {90, 16}, {105, 16}, {119, 16}, {134, 16}, {149, 16}, {164, 16}, {179, 16}, {194, 16},
        {90, 32}, {105, 32}, {119, 32}, {134, 32}, {149, 32}, {164, 32}, {179, 32},
                    {105, 48}, {119, 48}, {134, 48}, {149, 48}, {164, 48}, {179, 48},            {209, 48},
                            {119, 64}, {134, 64}, {149, 64}, {164, 64},            {194, 64}, {209, 64}, {224, 64}
        }, {
        // LED Index to Flag
        4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
        }
    };
#endif //RGB_MATRIX_ENABLE

#else  // PRODUCTION CODE
    const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_QWERTY] = LAYOUT(
        KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,        KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,
                KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
                KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
                KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
        MO(_FN),  KC_LCTL, KC_LOPT, KC_LCMD,          KC_SPC,               KC_SPC,           KC_RCMD, KC_ROPT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT
        ),
        [_FN] = LAYOUT(
        _______,  RGB_TOG, RGB_MOD, RGB_HUE, RGB_SAT, RGB_BRT, RGB_SPE,     _______, _______, _______, _______, _______, _______, KC_BSPC,
                _______, RGB_RGB, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        _______,  RESET,   _______, _______,          _______,              _______,          _______, _______, _______, _______, _______, _______
        )
    };

#ifdef RGB_MATRIX_ENABLE
    const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {

        /* Refer to IS31 manual for these locations
        *   driver
        *   |  R location (row_col) or (SWx_CSx)
        *   |  |       G location
        *   |  |       |       B location
        *   |  |       |       |
        *   {0, B_1,    A_1,    C_1}, */

        /*  LEFT SIDE */
        { 0,   A_5,  B_5,  C_5 }, //0
        { 0,   A_12, B_12, C_12 },
        { 0,   A_4,  B_4,  C_4 },
        { 0,   A_3,  B_3,  C_3 },
        { 0,   A_2,  B_2,  C_2 },
        { 0,   A_6,  B_6,  C_6 },
        { 0,   A_7,  B_7,  C_7 },

        { 0,   D_12, E_12, F_12 }, //7
        { 0,   D_4,  E_4,  F_4 },
        { 0,   D_3,  E_3,  F_3 },
        { 0,   D_2,  E_2,  F_2 },
        { 0,   D_6,  E_6,  F_6 },
        { 0,   D_7,  E_7,  F_7 },

        { 0,   G_12, H_12, I_12 }, //13
        { 0,   G_4,  H_4,  I_4 },
        { 0,   G_3,  H_3,  I_3 },
        { 0,   G_2,  H_2,  I_2 },
        { 0,   G_6,  H_6,  I_6 },
        { 0,   G_7,  H_7,  I_7 },

        { 0,   J_5,  K_5,  L_5 }, //19
        { 0,   J_12, K_12, L_12 },
        { 0,   J_4,  K_4,  L_4 },
        { 0,   J_3,  K_3,  L_3 },
        { 0,   J_2,  K_2,  L_2 },
        { 0,   J_6,  K_6,  L_6 },
        { 0,   J_7,  K_7,  L_7 },
        { 0,   J_8,  K_8,  L_8 },
        { 0,   J_9,  K_9,  L_9 },
        { 0,   J_11, K_11, L_11 },
        { 0,   J_10, K_10, L_10 }, //29

        /*  RIGHT SIDE */
        { 1,   D_11, E_11, F_11 }, //30
        { 1,   D_10, E_10, F_10 },
        { 1,   D_9,  E_9,  F_9 },
        { 1,   D_8,  E_8,  F_8 },
        { 1,   D_7,  E_7,  F_7 },
        { 1,   D_6,  E_6,  F_6 },
        { 1,   D_1,  E_1,  F_1 },

        { 1,   A_11, B_11, C_11 }, //37
        { 1,   A_10, B_10, C_10 },
        { 1,   A_9,  B_9,  C_9 },
        { 1,   A_8,  B_8,  C_8 },
        { 1,   A_7,  B_7,  C_7 },
        { 1,   A_6,  B_6,  C_6 },
        { 1,   A_1,  B_1,  C_1 },
        { 1,   A_4,  B_4,  C_4 },

        { 1,   J_11,  K_11,  L_11 }, //45
        { 1,   J_10,  K_10,  L_10 },
        { 1,   J_9,  K_9,  L_9 },
        { 1,   J_8,  K_8,  L_8 },
        { 1,   J_7,  K_7,  L_7 },
        { 1,   J_6,  K_6,  L_6 },
        { 1,   J_1,  K_1,  L_1 },
        { 1,   J_4,  K_4,  L_4 },
        { 1,   J_2,  K_2,  L_2 },
        { 1,   J_3,  K_3,  L_3 },

        { 1,   G_11,  H_11,  I_11 }, //55
        { 1,   G_10,  H_10,  I_10 },
        { 1,   G_9,  H_9,  I_9 },
        { 1,   G_8,  H_8,  I_8 },
        { 1,   G_7,  H_7,  I_7 },
        { 1,   G_6,  H_6,  I_6 },
        { 1,   G_1,  H_1,  I_1 },
        { 1,   G_4,  H_4,  I_4 },
        { 1,   G_2,  H_2,  I_2 },
        { 1,   G_3,  H_3,  I_3 },
        { 1,   G_5,  H_5,  I_5 } //65
    };

    led_config_t g_led_config = { {
        // Key Matrix to LED Index
        // position in list = key order.  No = LED list position above
        { 0,      1,       2,     3,     4,      5,      6,      NO_LED },
        { NO_LED, 7,       8,     9,     10,     11,     12,     NO_LED },
        { NO_LED, 13,     14,     15,    16,     17,     18,     NO_LED },
        { NO_LED, 20,     21,     22,    23,     24,     25,     NO_LED },
        { 19,     26,     27,     28,    NO_LED, 29,     NO_LED, NO_LED },

        { 30,     31,     32,     33,    34,     35,     36,     NO_LED },
        { 37,     38,     39,     40,    41,     42,     43,     44     },
        { 45,     46,     47,     48,    49,     50,     51,     NO_LED },
        { 55,     56,     57,     58,    59,     60,     61,     NO_LED },
        { 62,     NO_LED, 63,     64,    65,     54,     53,     52     }
        }, {
        // LED Index to Physical Position
        {0, 0},  {15, 0},  {30, 0},  {45, 0},  {60, 0},  {75, 0},  {90, 0},  {105, 0},  {119, 0},  {134, 0},  {149, 0},  {164, 0},  {179, 0},  {194, 0},
        {0, 16}, {15, 16}, {30, 16}, {45, 16}, {60, 16}, {75, 16}, {90, 16}, {105, 16}, {119, 16}, {134, 16}, {149, 16}, {164, 16}, {179, 16}, {194, 16},
        {0, 32}, {15, 32}, {30, 32}, {45, 32}, {60, 32}, {75, 32}, {90, 32}, {105, 32}, {119, 32}, {134, 32}, {149, 32}, {164, 32}, {179, 32},
                 {15, 48}, {30, 48}, {45, 48}, {60, 48}, {75, 48}, {90, 48}, {105, 48}, {119, 48}, {134, 48}, {149, 48}, {164, 48}, {179, 48},            {209, 48},
        {0, 64}, {15, 64}, {30, 64}, {45, 64},           {75, 64},                      {119, 64}, {134, 64}, {149, 64}, {164, 64},            {194, 64}, {209, 64}, {224, 64},
        }, {
        // LED Index to Flag
        4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4,
            1, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,

        4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
        }
    };
#endif //RGB_MATRIX_ENABLE

#endif // If TEST_LEFT elif TEST_RIGHT else production

#ifdef RGB_MATRIX_ENABLE
#define MAX_COLORS 18
int8_t color_index = 0;

/* RGB coolor config */
// struct color_rgb {
//     uint8_t red, green, blue;
// };

// const PROGMEM struct color_rgb color[MAX_COLORS] = {
//     {RGB_WHITE},
//     {RGB_RED},
//     {RGB_CORAL},
//     {RGB_ORANGE},
//     {RGB_GOLDENROD},
//     {RGB_GOLD},
//     {RGB_YELLOW},
//     {RGB_CHARTREUSE},
//     {RGB_GREEN},
//     {RGB_SPRINGGREEN},
//     {RGB_TURQUOISE},
//     {RGB_TEAL},
//     {RGB_CYAN},
//     {RGB_AZURE},
//     {RGB_BLUE},
//     {RGB_PURPLE},
//     {RGB_MAGENTA},
//     {RGB_PINK},
// };

/* HSV color config */
struct color_hsv {
    uint16_t h;
    uint8_t  s;
    uint8_t  v;
};

const PROGMEM struct color_hsv color[MAX_COLORS] = {
    {HSV_WHITE},
    {HSV_RED},
    {HSV_CORAL},
    {HSV_ORANGE},
    {HSV_GOLDENROD},
    {HSV_GOLD},
    {HSV_YELLOW},
    {HSV_CHARTREUSE},
    {HSV_GREEN},
    {HSV_SPRINGGREEN},
    {HSV_TURQUOISE},
    {HSV_TEAL},
    {HSV_CYAN},
    {HSV_AZURE},
    {HSV_BLUE},
    {HSV_PURPLE},
    {HSV_MAGENTA},
    {HSV_PINK}
};



// original working code - but NOT memory optimised
// struct {
//     uint8_t h, s, v;
// } color[] = {
//     {HSV_WHITE},
//     {HSV_RED},
//     {HSV_CORAL},
//     {HSV_ORANGE},
//     {HSV_GOLDENROD},
//     {HSV_GOLD},
//     {HSV_YELLOW},
//     {HSV_CHARTREUSE},
//     {HSV_GREEN},
//     {HSV_SPRINGGREEN},
//     {HSV_TURQUOISE},
//     {HSV_TEAL},
//     {HSV_CYAN},
//     {HSV_AZURE},
//     {HSV_BLUE},
//     {HSV_PURPLE},
//     {HSV_MAGENTA},
//     {HSV_PINK}
// };

#endif //RGB_MATRIX_ENABLE

// void set_output_user(uint8_t output) {
// #ifdef MODULE_ADAFRUIT_BLE
//   switch(output) {
//     case OUTPUT_USB:
//       led_set_output_usb();
//       break;
//     case OUTPUT_BLUETOOTH:
//       led_set_output_ble();
//       break;
//     default:
//       led_set_output_none();
//   }
// #endif
// }


// void keyboard_pre_init_user (void) {
    /*
    * Happens before most anything is started.
    * Good for hardware setup that you want running very early.
    */

// };

// void matrix_init_user (void) {
//     /*
//      * Happens midway through the firmware's startup process.
//      * Hardware is initialized, but features may not be yet.
//      */
// };

void keyboard_post_init_user (void) {
    /*
    * Happens at the end of the firmware's startup process.
    * This is where you'd want to put "customization" code, for the most part
    */
     // Customise these values to desired behaviour
    debug_enable=true;
    // debug_matrix=true;
    debug_keyboard=true;
    // debug_mouse=true;


};

// #ifdef RGB_MATRIX_ENABLE

// #ifndef MAX
//     #define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
// #endif

// #ifndef MIN
//     #define MIN(a,b) ((a) < (b)? (a): (b))
// #endif


// Deals with the messy details of incrementing an integer
// static uint8_t increment( uint8_t value, uint8_t step, uint8_t min, uint8_t max ) {
//     int16_t new_value = value;
//     new_value += step;
// return MIN( MAX( new_value, min ), max );
// }

// static uint8_t decrement( uint8_t value, uint8_t step, uint8_t min, uint8_t max ) {
// int16_t new_value = value;
//     new_value -= step;
// return MIN( MAX( new_value, min ), max );
// }


void freeRam (void) {
#ifdef CONSOLE_ENABLE
    extern int __heap_start, *__brkval;
    int v;
    dprintf("FREEMEM %ld\n", (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval));
#endif //CONSOLE_ENABLE
};

#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_color_increase(void) {

    freeRam();
    // uint8_t index = increment(color_index, 1, 0, MAX_COLORS);
    int8_t index =  ( color_index >= ( MAX_COLORS-1 ) ) ? 0 : ( color_index + 1) ;

    dprintf("UP max-colors: %d, color index: %d, index new: %d\n", MAX_COLORS, color_index, index);
    rgb_matrix_sethsv_noeeprom( pgm_read_word(&color[index].h),
                                pgm_read_byte(&color[index].s),
                                pgm_read_byte(&color[index].v));
    // rgb_matrix_set_color_all( pgm_read_byte(&color[index].red),
    //                             pgm_read_byte(&color[index].green),
    //                             pgm_read_byte(&color[index].blue));
    color_index = index;
    dprintf("UP new color index: %d,\n", color_index);

};

void rgb_matrix_color_decrease(void) {
    freeRam();
    // uint8_t index = decrement(color_index, 1, 0, MAX_COLORS);
    int8_t index = (color_index <= 0) ? ( MAX_COLORS - 1 ) : ( color_index - 1 );
    dprintf("DWN max-colors: %03d, color index: %03d, index new: %03d\n", MAX_COLORS, color_index, index);

    rgb_matrix_sethsv_noeeprom( pgm_read_word(&color[index].h),
                                pgm_read_byte(&color[index].s),
                                pgm_read_byte(&color[index].v));
    // rgb_matrix_set_color_all( pgm_read_byte(&color[index].red),
    //                             pgm_read_byte(&color[index].green),
    //                             pgm_read_byte(&color[index].blue));
    color_index = index;
    dprintf("DWN new color index: %d,\n", color_index);
};

#endif // RGB_MATRIX_ENABLE



#ifdef RGB_MATRIX_ENABLE
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /*
     * Called every time a key is pressed or released
     * return:
     *      True = QMK Core process key as normal
     *      False = QMK skips
     */



    // if (is_keyboard_master()) {
        switch (keycode) {
            case KC_RSFT:
            case KC_LSFT:
                if (record->event.pressed) {
                    shift_pressed = true;
                    // when keycode pressed
                } else {
                    // when keycode Shift is released
                    shift_pressed = false;
                }
                return true; // Skip all further processing of this key
            case RGB_SPE:
                if (record->event.pressed) {
                    // when keycode pressed
                    if (shift_pressed) {
                        rgb_matrix_decrease_speed_noeeprom();
                        // int speed = rgb_matrix_get_speed();
                        // rgb_matrix_set_speed_noeeprom(speed - 16);
                    } else {
                        rgb_matrix_increase_speed_noeeprom();
                        // int speed = rgb_matrix_get_speed();
                        // rgb_matrix_set_speed_noeeprom(speed + 16);
                    }
                } else {
                    // when keycode is released
                }
                return false; // Skip all further processing of this key
            case RGB_HUE:
                if (record->event.pressed) {
                    // when keycode pressed
                    if (shift_pressed) {
                        rgb_matrix_decrease_hue_noeeprom();
                    } else {
                        rgb_matrix_increase_hue_noeeprom();
                    }
                } else {
                    // when keycode is released
                }
                return false; // Skip all further processing of this key
            case RGB_SAT:
                if (record->event.pressed) {
                    // when keycode pressed
                    if (shift_pressed) {
                        rgb_matrix_decrease_sat_noeeprom();
                    } else {
                        rgb_matrix_increase_sat_noeeprom();
                    }
                } else {
                    // when keycode is released
                }
                return false; // Skip all further processing of this key
            case RGB_BRT:
                if (record->event.pressed) {
                    // when keycode pressed
                    if (shift_pressed) {
                        dprint("BRT down");
                        rgb_matrix_decrease_val_noeeprom();
                    } else {
                        dprint("BRT up");
                        rgb_matrix_increase_val_noeeprom();
                    }
                } else {
                    // when keycode is released
                }
                return false; // Skip all further processing of this key
            case RGB_RGB:
                if (record->event.pressed) {
                    // when keycode pressed
                    if (shift_pressed) {
                        dprintf("Color DWN: current %d\n", color_index);
                        rgb_matrix_color_decrease();
                    } else {
                        dprintf("Color UP: current %d\n", color_index);
                        rgb_matrix_color_increase();
                    }
                } else {
                    // when keycode is released
                }
                return false; // Skip all further processing of this key
            default:
                return true; // Process all other keycodes normally
        }
    // } else {
    //     return true;
    // }
    // return true;
}
#endif // RGB_MATRIX_ENABLE

#ifdef RGB_MATRIX_ENABLE
// void suspend_power_down_kb(void) {
//     /* turn off the RG matrix when the keyboard is idle */
//     if (is_keyboard_master()) {
//         rgb_matrix_set_suspend_state(true);
//     }
// };

// void suspend_wakeup_init_user(void) {
//     /* wake up RGB matrix with keayboard wake */
//     if (is_keyboard_master()) {
//         rgb_matrix_set_suspend_state(false);
//     }
// };


// layer_state_t layer_state_set_user(layer_state_t state) {
//     /*
//      * Called each time the layer is changed.  Put code to display Layer
//      * or change LED mode based on Layer here.
//      */
//     switch (get_highest_layer(state)) {
//     case _QWERTY: // default layer
//         rgb_matrix_set_color(6, 0x00,  0x00, 0xFF);
//         break;
//     case _FN:
//         #ifdef RGB_MATRIX_SOLID_COLOR
//         rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
//         #endif // RGB_MATRIX_SOLID_COLOR
//         rgb_matrix_set_color_all(0x00, 0x00, 0x00);
//         rgb_matrix_set_color(1, RGB_CORAL);
//         rgb_matrix_set_color(2, RGB_CORAL);
//         rgb_matrix_set_color(3, RGB_CORAL);
//         rgb_matrix_set_color(4, RGB_CORAL);
//         rgb_matrix_set_color(5, RGB_CORAL);
//         rgb_matrix_set_color(6, RGB_CORAL);
//         break;
//     default: //  for any other layers
//         rgb_matrix_set_color_all(0xFF,  0xFF, 0xFF);
//         break;
//     }
//   return state;
// };

// void rgb_matrix_indicators_user(void) {
//     if((host_keyboard_led_state().caps_lock) && (is_keyboard_master())) {
//         // rgb_matrix_set_color(13, 0xFF, 0xFF, 0xFF);
//     }
// }

#endif // RGB_MATRIX_ENABLE



#ifdef OLED_DRIVER_ENABLE

// static uint16_t info_timer;
#define LOGO_TIMEOUT 10000 /*  how long to display info scren in ms */

// static void render_logo(void) {
//     static const char PROGMEM logo[] = {
//         // 'applePie', 128x32px
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0,
//         0xf0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0x3c, 0x3c, 0xfe, 0xfe, 0xfe, 0xfe, 0x7e, 0x3e, 0xfe, 0xfe,
//         0xfe, 0xfe, 0xbe, 0x3c, 0x7c, 0xfc, 0xf8, 0xf8, 0xf8, 0xf0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xe0, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff,
//         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xff, 0xff,
//         0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
//         0xf0, 0xe0, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x13, 0x33, 0xf3, 0xf9, 0xf9, 0xfc, 0xfc,
//         0xf9, 0xf9, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf9, 0xf8, 0xf8, 0xf9, 0xf3,
//         0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf1, 0xf9, 0xf8, 0xfc, 0xf8, 0xf9, 0xf9, 0x73,
//         0x33, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x1f, 0x1f,
//         0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
//         0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x07, 0x01, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//     };

//     oled_write_raw_P(logo, sizeof(logo));
// };


// oled_rotation_t oled_init_user(oled_rotation_t rotation) {

//     // return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
//         return rotation;
// }


/*
 * OLED config guide:
 * https://beta.docs.qmk.fm/using-qmk/hardware-features/displays/feature_oled_driver
 */
void oled_task_user(void) {
    // Host Keyboard Layer Status
    // render_logo();

    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            if (is_keyboard_left()) {
                oled_write_P(PSTR("LEFT\n"), false);
            } else {
                oled_write_P(PSTR("RIGHT\n"), false);
            }
            break;
        case _FN:
            oled_write_P(PSTR("FN\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    };

    // Host Keyboard LED Status

    led_t led_state = host_keyboard_led_state();
    // led_write_ln_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_ln_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    // oled_write_ln_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    // Display battery level
    // static char batteryLevel[20] = {0};
    // printf("Batt: %lu", (unsigned long)adafruit_ble_read_battery_voltage());
    // snprintf(batteryLevel, sizeof(batteryLevel), "Batt: %lu", (unsigned long)adafruit_ble_read_battery_voltage());
    // oled_write_ln(batteryLevel, false);


    #ifdef RGB_MATRIX_ENABLE
        static char buffer[18] = {0};
        // snprintf(buffer, sizeof(buffer), "RGB Mode: %03d", rgb_matrix_get_mode());
        sprintf_P(buffer, PSTR("RGB Mode: %03d"), rgb_matrix_get_mode());
        oled_write_ln(buffer, false);

        // static char rgbStatusLine2[26] = {0};
        // snprintf(buffer, sizeof(buffer), "hue: %03d sat: %03d", rgb_matrix_get_hue(), rgb_matrix_get_sat());
        sprintf_P(buffer, PSTR("hue: %03d sat: %03d"), rgb_matrix_get_hue(), rgb_matrix_get_sat());
        oled_write_ln(buffer, false);

        // static char rgbStatusLine3[26] = {0};
        // snprintf(buffer, sizeof(buffer), "brt: %03d spd: %03d", rgb_matrix_get_val(), rgb_matrix_get_speed());
        sprintf_P(buffer, PSTR("brt: %03d spd: %03d"), rgb_matrix_get_val(), rgb_matrix_get_speed());
        oled_write_ln(buffer, false);
    #endif // RGB_MATRIX_ENABLE
};



// void oled_task_user(void) {
//     if (is_keyboard_master()) {
//         render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
//     } else {
//         render_logo();  // Renders a static logo
//         oled_scroll_left();  // Turns on scrolling
//     }
// }
#endif // OLED_DRIVER_ENABLE

void matrix_master_OLED_init(void) {
//     // render_logo();
//     // wait_ms(LOGO_TIMEOUT);
//     // oled_write_ln_P(PSTR(QMK_VERSION), false);
//     // oled_write_ln_P(PSTR(QMK_BUILDDATE), false);
//     // oled_write_ln_P(PSTR(QMK_KEYBOARD), false);
//     // oled_write_ln_P(PSTR(QMK_KEYMAP), false);
//     // wait_ms(LOGO_TIMEOUT);
};
