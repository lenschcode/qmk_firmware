/*
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Publicw License as published by
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

#include "quantum.h"

// clang-format off
#ifdef RGB_MATRIX_ENABLE
/**
 * \brief LEDs index.
 *
 * ╭────────────────────╮                 ╭────────────────────╮
 *    2   3   8   9  12                     30  27  26  21  20
 * ├────────────────────┤                 ├────────────────────┤
 *    1   4   7  10  13                     31  28  25  22  19
 * ├────────────────────┤                 ├────────────────────┤
 *    0   5   6  11  14                     32  29  24  23  18
 * ╰────────────────────╯                 ╰────────────────────╯
 *                   15  16  17     33  34  XX
 *                 ╰────────────╯ ╰────────────╯
 *
 * Note: the LED config simulates 36 LEDs instead of the actual 35 to prevent
 * confusion when testing LEDs during assembly when handedness is not set
 * correctly.  Those fake LEDs are bound to the physical top-left corner.
 */
led_config_t g_led_config = { {
    /* Key Matrix to LED index. */
    // Left split.
    {      0,      1,      2,      3,      4 }, // Top row
    {      5,      6,      7,      8,      9 }, // Middle row
    {     10,     11,     12,     13,     14 }, // Bottom row
    { NO_LED, NO_LED, NO_LED,     15,     16 }, // Thumb cluster
    // Right split.
    {     17,     18,     19,     20,     21}, // Top row
    {     22,     23,     24,     25,     26}, // Middle row
    {     26,     28,     29,     30,     31}, // Bottom row
    {     32,     33, NO_LED, NO_LED, NO_LED }, // Thumb cluster
}, {
    /* LED index to physical position. */
    // Left split arrangement
    /* first  row */ {   0,   0 }, {  18,   0 }, {  36,   0 }, {  54,   0 }, {  72,   0 },
    /* second row */ {   0,  21 }, {  18,  21 }, {  36,  21 }, {  54,  21 }, {  72,  21 },
    /* thirt  row */ {   0,  42 }, {  18,  42 }, {  36,  42 }, {  54,  42 }, {  72,  42 },
    /* thumb      */                                                       {  72,  64 }, { 90,  64 },

    // Right split arrangement
    /* first  row */               { 152,   0 }, { 170,   0 }, { 188,   0 }, { 206,   0 }, { 224,   0 }, 
    /* second row */               { 152,  21 }, { 170,  21 }, { 188,  21 }, { 206,  21 }, { 224,  21 }, 
    /* third  row */               { 152,  42 }, { 170,  42 }, { 188,  42 }, { 206,  42 }, { 224,  42 },
    /* thumbs     */ { 134,  64 }, { 152,  64 }, 
}, {
    /* LED index to flag. */
    // Left split.
    /* index=0  */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 1
    /* index=3  */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 2
    /* index=6  */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=9  */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=12 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=15 */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, // Thumb cluster
    // Right split.
    /* index=18 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 10
    /* index=21 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 9
    /* index=24 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=27 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=30 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=33 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // Thumb cluster
} };
#endif
// clang-format on
