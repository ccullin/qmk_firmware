/*
Copyright 2020 ccullin

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

#pragma once

#include "config_common.h"

// #include "analog.h" // for ADC battery monitor


/* USB Device descriptor parameter */
// #define VENDOR_ID    0xFEED
#define VENDOR_ID       0x03EB
#define PRODUCT_ID      0x2FFB
#define DEVICE_VER      0x0001

#define MANUFACTURER    orsm
#define PRODUCT         applepie10

// #define TEST_LEFT
// #define TEST_RIGHT





/*
 * KEY MATRIX
 */
#define DIODE_DIRECTION COL2ROW

#ifdef TEST_LEFT
    // // test LEFT
    #define MATRIX_COLS 7
    #define MATRIX_ROWS 5
    #define MATRIX_COL_PINS { F0, F1, F4, B6, B5, B4, D7 }
    #define MATRIX_ROW_PINS { F5, F6, F7, C7, C6 }
#elif TEST_RIGHT
    // // testing full right half
    #define MATRIX_COLS 8
    #define MATRIX_ROWS 5
    #define MATRIX_COL_PINS { F0, F1, F4, F5, F6, F7, C7, D3 }
    #define MATRIX_ROW_PINS { D5, D6, B5, B6, C6 }
#else // PRODUCTION
    // // production code
    #define MATRIX_COLS 8
    #define MATRIX_ROWS 10
    #define MATRIX_COL_PINS { F0, F1, F4, B6, B5, B4, D7, D7 }
    #define MATRIX_ROW_PINS { F5, F6, F7, C7, C6 }
    #define MATRIX_COL_PINS_RIGHT { F0, F1, F4, F5, F6, F7, C7, D3 }
    #define MATRIX_ROW_PINS_RIGHT { D5, D6, B5, B6, C6 }
#endif


/*
 * I2C - used for split comms, RGB and OLED
 */
#define USE_I2C
#define F_SCL 100000L //set I2C SCL frequency to 100KHz so TWBR is >10 per datasheet on 3.3V 8Mhz MCU


/*
 * HANDEDNESS
 */
#ifdef SPLIT_KEYBOARD
#define EE_HANDS // uses handedness assign in EEPROM
// #define MASTER_LEFT // assigns Left to the Master
// #define MASTER_RIGHT // assigns Right to the Master
// #define SPLIT_HAND_PIN D2 // High for LEFT
// #define SPLIT_USB_DETECT // not need to Atmel
// #define SPLIT_USB_TIMEOUT 2000
// #define SPLIT_MODS_ENABLE // transmit modifier state to slave
#define SPLIT_TRANSPORT_MIRROR // mirrors master matrix state to slave
#endif // SPLIT_KEYBOARD

/*
 * BLUETOOTH
 */
#ifdef BLUETOOTH
#define AdafruitBleResetPin D4 // is default but including for clarity
#define AdafruitBleCSPin    B4 // is default but including for clarity
#define AdafruitBleIRQPin   E6 // is default but including for clarity
#define AdafruitBleSpiClockSpeed 1000000UL
#define BATTERY_LEVEL_PIN D7  //bat_mon.  Is present but not support in v1
#endif // BLUETOOTH

/*
 * OLED
 */
#ifdef OLED_DRIVER_ENABLE
#define SSD1306OLED  // is default
#define OLED_DISPLAY_128X64 // sets up width and height
#define OLED_DISPLAY_ADDRESS 0x3C  // default but including for clarity 128x32
#define OLED_ROTATE180
#endif // OLED_DRIVER_ENABLE

/*
 * RGB MATRIX
 */
#ifdef RGB_MATRIX_ENABLE
// This is a 7-bit address, that gets left-shifted and bit 0
// set to 0 for write, 1 for read (as per I2C protocol)
// The address will vary depending on your wiring:
// 0b1010000 AD <-> GND
// 0b1011111 AD <-> VCC
// 0b1010101 AD <-> SCL
// 0b1011010 AD <-> SDA

#ifdef TEST_LEFT
    // // TEST LEFT
    #define DRIVER_ADDR_1 0b1010000
    // #define DRIVER_ADDR_2 DRIVER_ADDR_1  // addr2 dummy only required for original source
    #define DRIVER_COUNT 1
    #define DRIVER_1_LED_TOTAL 30
    #define DRIVER_LED_TOTAL 30
#elif TEST_RIGHT
    // // TEST RIGHT
    #define DRIVER_ADDR_1 0b1010101
    // #define DRIVER_ADDR_2 DRIVER_ADDR_1  // addr2 dummy only required for original source
    #define DRIVER_COUNT 1
    #define DRIVER_1_LED_TOTAL 36
    #define DRIVER_LED_TOTAL DRIVER_1_LED_TOTAL
#else
    // // PRODUCTION
    #define DRIVER_ADDR_1 0b1010000  // Left
    #define DRIVER_ADDR_2 0b1010101  // Right
    #define DRIVER_COUNT 2
    #define DRIVER_1_LED_TOTAL 30
    #define DRIVER_2_LED_TOTAL 36
    #define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)
#endif

// #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_DISABLE_WHEN_USB_SUSPENDED true // turns off animations if USB suspend
#define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#define RGB_DISABLE_TIMEOUT 60000 // number of milliseconds to wait until rgb automatically turns off

#define RGB_DEBUGGING_ONLY

#define RGB_MATRIX_LED_PROCESS_LIMIT 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#define RGB_MATRIX_LED_FLUSH_LIMIT 26

#define DISABLE_RGB_MATRIX_ALPHAS_MODS
#define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define DISABLE_RGB_MATRIX_BREATHING
#define DISABLE_RGB_MATRIX_BAND_SAT
#define DISABLE_RGB_MATRIX_BAND_VAL
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define DISABLE_RGB_MATRIX_CYCLE_ALL
#define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define DISABLE_RGB_MATRIX_DUAL_BEACON
#define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
#define DISABLE_RGB_MATRIX_RAINBOW_BEACON
#define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define DISABLE_RGB_MATRIX_RAINDROPS
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define DISABLE_RGB_MATRIX_TYPING_HEATMAP

#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define DISABLE_RGB_MATRIX_SPLASH
#define DISABLE_RGB_MATRIX_MULTISPLASH
#define DISABLE_RGB_MATRIX_SOLID_SPLASH
#define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH


#endif // RGB_MATRIX_ENABLE


/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
// #define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
// #define LOCKING_RESYNC_ENABLE

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is useful for the Windows task manager shortcut (ctrl+shift+esc).
 */
//#define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION



/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0
