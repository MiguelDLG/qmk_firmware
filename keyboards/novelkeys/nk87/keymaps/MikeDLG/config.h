#pragma once

// Force RGB off: effect 0 = all LEDs off, brightness 0
#undef RGB_BACKLIGHT_EFFECT
#define RGB_BACKLIGHT_EFFECT 0
#undef RGB_BACKLIGHT_BRIGHTNESS
#define RGB_BACKLIGHT_BRIGHTNESS 0
#undef RGB_BACKLIGHT_EFFECT_SPEED
#define RGB_BACKLIGHT_EFFECT_SPEED 0

// Base tapping configuration
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// Per-key hold behavior
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Disable double-tap repeat for mod-taps
#define QUICK_TAP_TERM 0

// Performance optimizations for fast typing
#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 12

// Debounce
#define DEBOUNCE 5
