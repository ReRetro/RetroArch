/*  SSNES - A Super Nintendo Entertainment System (SNES) Emulator frontend for libsnes.
 *  Copyright (C) 2010-2012 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2012 - Daniel De Matteis
 *
 *  Some code herein may be based on code found in BSNES.
 * 
 *  SSNES is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  SSNES is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with SSNES.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __SSNES_INPUT_LUTS_H
#define __SSNES_INPUT_LUTS_H

#include "../driver.h"
#include "../libsnes.hpp"
#include <stdint.h>

#if defined(__CELLOS_LV2__)
#include "../ps3/cellframework2/input/pad_input.h"

enum ps3_device_id
{
   PS3_DEVICE_ID_JOYPAD_CIRCLE = 0,
   PS3_DEVICE_ID_JOYPAD_CROSS,
   PS3_DEVICE_ID_JOYPAD_TRIANGLE,
   PS3_DEVICE_ID_JOYPAD_SQUARE,
   PS3_DEVICE_ID_JOYPAD_UP,
   PS3_DEVICE_ID_JOYPAD_DOWN,
   PS3_DEVICE_ID_JOYPAD_LEFT,
   PS3_DEVICE_ID_JOYPAD_RIGHT,
   PS3_DEVICE_ID_JOYPAD_SELECT,
   PS3_DEVICE_ID_JOYPAD_START,
   PS3_DEVICE_ID_JOYPAD_L1,
   PS3_DEVICE_ID_JOYPAD_L2,
   PS3_DEVICE_ID_JOYPAD_L3,
   PS3_DEVICE_ID_JOYPAD_R1,
   PS3_DEVICE_ID_JOYPAD_R2,
   PS3_DEVICE_ID_JOYPAD_R3,
   PS3_DEVICE_ID_LSTICK_LEFT,
   PS3_DEVICE_ID_LSTICK_RIGHT,
   PS3_DEVICE_ID_LSTICK_UP,
   PS3_DEVICE_ID_LSTICK_DOWN,
   PS3_DEVICE_ID_LSTICK_LEFT_DPAD,
   PS3_DEVICE_ID_LSTICK_RIGHT_DPAD,
   PS3_DEVICE_ID_LSTICK_UP_DPAD,
   PS3_DEVICE_ID_LSTICK_DOWN_DPAD,
   PS3_DEVICE_ID_RSTICK_LEFT,
   PS3_DEVICE_ID_RSTICK_RIGHT,
   PS3_DEVICE_ID_RSTICK_UP,
   PS3_DEVICE_ID_RSTICK_DOWN,
   PS3_DEVICE_ID_RSTICK_LEFT_DPAD,
   PS3_DEVICE_ID_RSTICK_RIGHT_DPAD,
   PS3_DEVICE_ID_RSTICK_UP_DPAD,
   PS3_DEVICE_ID_RSTICK_DOWN_DPAD,

   SSNES_LAST_PLATFORM_KEY
};

#elif defined(_XBOX)
#include "../360/xdk360_input.h"

enum xdk360_device_id
{
   XDK360_DEVICE_ID_JOYPAD_B = 0,
   XDK360_DEVICE_ID_JOYPAD_A,
   XDK360_DEVICE_ID_JOYPAD_Y,
   XDK360_DEVICE_ID_JOYPAD_X,
   XDK360_DEVICE_ID_JOYPAD_UP,
   XDK360_DEVICE_ID_JOYPAD_DOWN,
   XDK360_DEVICE_ID_JOYPAD_LEFT,
   XDK360_DEVICE_ID_JOYPAD_RIGHT,
   XDK360_DEVICE_ID_JOYPAD_BACK,
   XDK360_DEVICE_ID_JOYPAD_START,
   XDK360_DEVICE_ID_JOYPAD_LB,
   XDK360_DEVICE_ID_JOYPAD_LEFT_TRIGGER,
   XDK360_DEVICE_ID_LSTICK_THUMB,
   XDK360_DEVICE_ID_JOYPAD_RB,
   XDK360_DEVICE_ID_JOYPAD_RIGHT_TRIGGER,
   XDK360_DEVICE_ID_RSTICK_THUMB,
   XDK360_DEVICE_ID_LSTICK_LEFT,
   XDK360_DEVICE_ID_LSTICK_RIGHT,
   XDK360_DEVICE_ID_LSTICK_UP,
   XDK360_DEVICE_ID_LSTICK_DOWN,
   XDK360_DEVICE_ID_LSTICK_LEFT_DPAD,
   XDK360_DEVICE_ID_LSTICK_RIGHT_DPAD,
   XDK360_DEVICE_ID_LSTICK_UP_DPAD,
   XDK360_DEVICE_ID_LSTICK_DOWN_DPAD,
   XDK360_DEVICE_ID_RSTICK_LEFT,
   XDK360_DEVICE_ID_RSTICK_RIGHT,
   XDK360_DEVICE_ID_RSTICK_UP,
   XDK360_DEVICE_ID_RSTICK_DOWN,
   XDK360_DEVICE_ID_RSTICK_LEFT_DPAD,
   XDK360_DEVICE_ID_RSTICK_RIGHT_DPAD,
   XDK360_DEVICE_ID_RSTICK_UP_DPAD,
   XDK360_DEVICE_ID_RSTICK_DOWN_DPAD,

   SSNES_LAST_PLATFORM_KEY
};
#endif

extern uint64_t ssnes_default_keybind_lut[SSNES_FIRST_META_KEY];
extern uint64_t ssnes_platform_keybind_lut[SSNES_LAST_PLATFORM_KEY];
extern char ssnes_default_libsnes_keybind_name_lut[SSNES_FIRST_META_KEY][256];

const char *ssnes_input_find_platform_key_label(uint64_t joykey);
uint64_t ssnes_input_find_previous_platform_key(uint64_t joykey);
uint64_t ssnes_input_find_next_platform_key(uint64_t joykey);

// Sets custom default keybind names (some systems emulated by the emulator
// will need different keybind names for buttons, etc.)
void ssnes_input_set_default_keybind_names_for_emulator(void);

#endif

