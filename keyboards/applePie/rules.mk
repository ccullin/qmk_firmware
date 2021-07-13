# MCU name
MCU = atmega32u4

# Bootloader selection

#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu
F_CPU = 8000000
ARCH = AVR8


# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no     # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = no       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output
RGB_MATRIX_ENABLE = no		# RGB Maxtrix support, specific chip to enable.
OLED_DRIVER_ENABLE = no

# APPLIEPIE DEBUG SETTINGS
CONSOLE_ENABLE = yes
DEBUG_ENABLE = yes
# COMMAND_ENABLE = yes# Commands for debug and configuration
# DEBUG_ACTION = yes


# APPLEPIE SPECIFICS
# SPLIT_KEYBOARD = yes
# OLED_DRIVER_ENABLE = yes
# RGB_MATRIX_ENABLE = yes
# RGB_MATRIX_DRIVER = IS31FL3737
# BLUETOOTH = AdafruitBLE
# NO_USB_STARTUP_CHECK = yes


SRC += $(LUFA_DIR)/adafruit_ble.cpp


# to save memory.  https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
EXTRAFLAGS += -flto
