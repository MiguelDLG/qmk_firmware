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

// Permissive hold only for space (NAV layer), not home row mods
#define PERMISSIVE_HOLD_PER_KEY

// Enable tap-then-hold key repeat for mod-taps
#define QUICK_TAP_TERM 175
#define QUICK_TAP_TERM_PER_KEY

// Performance optimizations for fast typing
#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 12

// Debounce
#define DEBOUNCE 5
