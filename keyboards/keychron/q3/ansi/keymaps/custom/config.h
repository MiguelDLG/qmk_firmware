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

// Pascal Getreuer's recommended home row mods configuration
// https://getreuer.info/posts/keyboards/achordion/index.html

// Tapping term: 200-250ms recommended with Chordal Hold
#define TAPPING_TERM 200

// Enable Chordal Hold - implements "opposite hands" rule
// Keys on the same hand produce taps, opposite hands can produce holds
#define CHORDAL_HOLD

// Enable Permissive Hold - works together with Chordal Hold
// Settles as hold when opposite-hand key is tapped (nested press)
#define PERMISSIVE_HOLD

// Disable quick tap for home row mods to prevent accidental repeats
#define QUICK_TAP_TERM 0
