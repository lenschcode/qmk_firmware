#pragma once

enum charybdis_keymap_layers {
    _COLEMAK = 0,
    _NUMNAV,
    _SYMBOLS,
    _FUNC
};

#define SPC_LAY LT(_NUMNAV, KC_SPC)
#define BSP_LAY LT(_SYMBOLS, KC_BSPC)
#define ESC_LAY LT(_FUNC, KC_ESC)
#define OS_SHFT OSM(MOD_LSFT)

#define MOD_LCMD MOD_LGUI
#define MOD_LOPT MOD_LALT
#define MOD_ROPT MOD_RALT

#define KC_AE RALT(KC_Q)//RALT(KC_A) -- for eurkey
#define KC_OE RALT(KC_P)//RALT(KC_O)
#define KC_UE RALT(KC_Y)//RALT(KC_U)
#define KC_SZ RALT(KC_S)