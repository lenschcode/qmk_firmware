RGBLIGHT_STARTUP_ANIMATION = yes 	# enable startup animation

COMBO_ENABLE = yes 					# enable combo support
WPM_ENABLE = yes					# wpm calculation for oled
ENCODER_ENABLE = no					# encoder support
BOOTMAGIC_ENABLE = yes

CUSTOM_RGB = yes					# rgb effects and custom layer states
OS_DETECTION_ENABLE = yes			# allow to change keyboard layout based on os

# include all my custom files 
INTROSPECTION_KEYMAP_C = combos/combos.c
# ifeq ($(strip $(COMBO_ENABLE)), yes)
# 	SRC += combos/combos.c
# endif

ifeq ($(strip $(CUSTOM_RGB)), yes)
	SRC += rgb.c
endif