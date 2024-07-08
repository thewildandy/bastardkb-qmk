/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#ifdef VIA_ENABLE
/* VIA configuration. */
// Number of layers available in VIA -- max is 15, (depending on memory)
#    define DYNAMIC_KEYMAP_LAYER_COUNT 5
#endif // VIA_ENABLE

#ifndef __arm__
/* Disable unused features. */
#    define NO_ACTION_ONESHOT
#endif // __arm__

/* Charybdis-specific features. */

#ifdef POINTING_DEVICE_ENABLE
// Automatically enable the pointer layer when moving the trackball.  See also:
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif // POINTING_DEVICE_ENABLE

/* Handedness. */
#define MASTER_RIGHT

/* Rewire to fix the TRS port */
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN GP12

// To use the handedness pin, resistors need to be installed on the adapter PCB.
// If so, uncomment the following code, and undefine MASTER_RIGHT above.
// #define SPLIT_HAND_PIN GP15
// #define SPLIT_HAND_PIN_LOW_IS_LEFT  // High -> right, Low -> left.

/* VBUS detection. */
#define USB_VBUS_PIN GP19

/* SPI & PMW3360 settings. */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP23
#define POINTING_DEVICE_CS_PIN GP16

/* Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17

/**
 * Auto Shift
 * Use the shifted version of a key following a brief hold. Mod keys are not shifted, but they can be.
 * Many additional options available. See: https://docs.qmk.fm/features/auto_shift
 */ 
#define AUTO_SHIFT_TIMEOUT 175 // start around 175 and work down

// I only want this on A-Z for now, so disable everything else
#define NO_AUTO_SHIFT_SPECIAL
#define NO_AUTO_SHIFT_TAB
#define NO_AUTO_SHIFT_SYMBOLS
#define NO_AUTO_SHIFT_NUMERIC
