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