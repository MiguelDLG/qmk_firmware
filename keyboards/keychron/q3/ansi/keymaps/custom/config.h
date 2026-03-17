/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

#pragma once

// Base tapping configuration
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// Permissive hold only for space (NAV layer), not home row mods
#define PERMISSIVE_HOLD_PER_KEY

// Disable double-tap repeat for mod-taps
#define QUICK_TAP_TERM 0

// Performance optimizations for fast typing
#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 12

// Debounce
#define DEBOUNCE 5

// Force RGB off
#undef RGB_MATRIX_DEFAULT_MODE
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_NONE
#undef RGB_MATRIX_DEFAULT_VAL
#define RGB_MATRIX_DEFAULT_VAL 0
