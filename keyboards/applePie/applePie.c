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

#include "applepie.h"


// #ifdef SSD1306OLED
// void led_set_kb(uint8_t usb_led) {
//     // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
//     led_set_user(usb_led);
// }
// #endif

// void matrix_init_kb(void) {

//     // // green led on
//     // DDRD |= (1<<5);
//     // PORTD &= ~(1<<5);

//     // // orange led on
//     // DDRB |= (1<<0);
//     // PORTB &= ~(1<<0);

// 	matrix_init_user();
// };

// #ifdef RGB_MATRIX_ENABLE
// void rgb_matrix_indicators_kb(void) {
//     rgb_matrix_set_color(13, red, green, blue);
// }
// #ENDIF // RGB_MATRIC_ENABLE



#ifdef BLUETOOTH
    /*
     * all host comms is via Slave (Master).
     * Master(left) USB is for flashing only
     */

void matrix_init_kb() {
    // auto detect output on init
    set_output(OUTPUT_AUTO);
    // set_output(OUTPUT_BLUETOOTH);
    // set_output(OUTPUT_USB);
}
#endif // BLUETOOTH

bool is_keyboard_master(void) {
    return(is_keyboard_left());
    // return true;
}

bool should_process_keypress(void) {
    // return !(is_keyboard_master());
    return true;
}

// bool should_process_keypress(void) {
//     /*
//      * returning true allows both halves to process keypress
//      * config.h has SPLIT_TRANSPORT_MIRROR which forces standard keys to Slave (aka right)
//      * with !SPLIT_MODS_ENABLE && should_process_keypress Master (left) can process MOD keys
//      */
//     // return !(is_keyboard_master());
//     return true;
// }

