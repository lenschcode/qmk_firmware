#include QMK_KEYBOARD_H
#include "keycodes.h"

#define SPEED 200

// layer state to only change mode when layer changes
int layer;
bool caps;
bool mods;

/* 
*** available modes ***
--- single hue ---
RGB_MATRIX_SOLID_COLOR
RGB_MATRIX_BREATHING
RGB_MATRIX_PIXEL_FRACTAL
RGB_MATRIX_BAND_VAL
RGB_MATRIX_BAND_PINWHEEL_VAL
RGB_MATRIX_BAND_SPIRAL_VAL

--- rainbow ---
RGB_MATRIX_RAINBOW_MOVING_CHEVRON

*/
void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_GOLDENROD);
    rgb_matrix_set_speed_noeeprom(SPEED);
    
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // match effect speed to wpm
    // rgb_matrix_set_speed_noeeprom(40 + (get_current_wpm()/5));

    // only execute when the layer changes
    if(layer != get_highest_layer(layer_state|default_layer_state)){
        layer = get_highest_layer(layer_state|default_layer_state);

        // set different color on different layers
        switch(layer) {
            case _COLEMAK:
                rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
                rgb_matrix_sethsv_noeeprom(HSV_GOLDENROD);
                break;
            case _NUMNAV:
                rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
                rgb_matrix_set_speed_noeeprom(SPEED);
                rgb_matrix_sethsv_noeeprom(HSV_WHITE);
                break;
            case _SYMBOLS:
                rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
                rgb_matrix_set_speed_noeeprom(SPEED);
                rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
                break;
            case _FUNC:
                rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
                rgb_matrix_set_speed_noeeprom(SPEED);
                break;
            default:
                break;
        }
    } 

    // indicate active moddifiers
    if (mods != ((get_mods() | get_oneshot_mods()) == 0)){
        mods = (get_mods() | get_oneshot_mods()) == 0;
        if (!mods){
            rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
            rgb_matrix_set_speed_noeeprom(255);
        } else {
            layer = -1;
        }
    }

    // show that caps lock is activated
    if(caps != host_keyboard_led_state().caps_lock){
        caps = host_keyboard_led_state().caps_lock;

        if (caps) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
            rgb_matrix_sethsv_noeeprom(HSV_RED);
            rgb_matrix_set_speed_noeeprom(255);
            // RGB_MATRIX_INDICATOR_SET_COLOR(5, 255, 255, 255); // assuming caps lock is at led #5
        } else {
            // reset layer status to reapply the layer effects
            layer = -1;
            // RGB_MATRIX_INDICATOR_SET_COLOR(5, 0, 0, 0);
        }
    }
}

void shutdown_user(){
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_RED);
}