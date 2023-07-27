RGBLIGHT_STARTUP_ANIMATION = yes 	# enable startup animation

COMBO_ENABLE = yes 					# enable combo support
WPM_ENABLE = yes					# wpm calculation for oled
ENCODER_ENABLE = no					# encoder support

CUSTOM_RGB = yes					# rgb effects and custom layer states

# include all my custom files 
ifeq ($(strip $(COMBO_ENABLE)), yes)
	SRC += combos/combos.c
endif

ifeq ($(strip $(CUSTOM_RGB)), yes)
	SRC += rgb.c
endif