/*
	Name: pixel_mono_14pt.c
	Description: Monospaced bitmapped font designed to imitate the Windows 9x font.

	Copyright: Copyright (c) Patryk Mierzyński
	Author: Patryk Mierzyński
	Date: 04/08/2024

	µCNC is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version. Please see <http://www.gnu.org/licenses/>

	µCNC is distributed WITHOUT ANY WARRANTY;
	Also without the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See the GNU General Public License for more details.
*/

#include "../config.h"

#ifdef GUI_STYLE_WIN9X

#include "lvgl.h"

static const uint8_t bitmaps[] = {
0x00, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xcf, 0x3c, 0xf3, 0xcf, 0x30, 0x33, 0x0c, 0xc3, 0x30, 0xcc, 
0xff, 0xff, 0xf3, 0x30, 0xcc, 0x33, 0x0c, 0xc3, 0x30, 0xcc, 0xff, 0xff, 0xf3, 0x30, 0xcc, 0x33, 
0x0c, 0xc0, 0x0c, 0x03, 0x03, 0xf0, 0xfc, 0xcc, 0xf3, 0x3c, 0xc3, 0x30, 0x3c, 0x0f, 0x00, 0xf0, 
0x3c, 0x0c, 0xc3, 0x3c, 0xcf, 0x33, 0x3f, 0x0f, 0xc0, 0xc0, 0x30, 0x30, 0xcc, 0x3c, 0xcf, 0x33, 
0x33, 0x0c, 0xc0, 0x30, 0x0c, 0x0c, 0x03, 0x03, 0x00, 0xc0, 0x33, 0x0c, 0xcc, 0xcf, 0x33, 0xc3, 
0x30, 0xc0, 0x30, 0x0c, 0x0c, 0xc3, 0x30, 0xcc, 0x33, 0x03, 0x00, 0xc0, 0x30, 0x0c, 0x0c, 0xcf, 
0x33, 0xc3, 0x30, 0xcc, 0x33, 0x0c, 0x3c, 0xcf, 0x30, 0xff, 0x33, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 
0xcc, 0xcc, 0x33, 0xcc, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0xcc, 0xcf, 0x33, 0x0c, 0xcf, 
0x30, 0x0c, 0x03, 0x00, 0xc0, 0x30, 0xff, 0xff, 0xf0, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0x33, 0xcc, 
0xff, 0xf0, 0xf0, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x0c, 0x0c, 0x0c, 0x0c, 0x30, 0x30, 0x30, 
0x30, 0xc0, 0xc0, 0xc0, 0xc0, 0x3f, 0x0f, 0xcc, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc0, 
0xf0, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0x3f, 0x0f, 0xc0, 0x0c, 0x3f, 0xff, 0x0c, 
0x30, 0xc3, 0x0c, 0x30, 0xc3, 0x0c, 0x30, 0xc3, 0x0c, 0x30, 0x3f, 0x0f, 0xcc, 0x0f, 0x03, 0x00, 
0xc0, 0x30, 0x0c, 0x03, 0x03, 0x00, 0xc0, 0xc0, 0x30, 0x30, 0x0c, 0x0c, 0x03, 0x00, 0xff, 0xff, 
0xf0, 0x3f, 0x0f, 0xcc, 0x0f, 0x03, 0x00, 0xc0, 0x30, 0x0c, 0x03, 0x0f, 0x03, 0xc0, 0x0c, 0x03, 
0x00, 0xc0, 0x3c, 0x0f, 0x03, 0x3f, 0x0f, 0xc0, 0x03, 0x00, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc3, 
0x30, 0xcc, 0x33, 0x0c, 0xcc, 0x33, 0x0c, 0xff, 0xff, 0xf0, 0x30, 0x0c, 0x03, 0x00, 0xc0, 0xff, 
0xff, 0xfc, 0x03, 0x00, 0xc0, 0x30, 0x0f, 0xf3, 0xfc, 0xc0, 0xf0, 0x30, 0x0c, 0x03, 0x00, 0xc0, 
0x3c, 0x0f, 0x03, 0x3f, 0x0f, 0xc0, 0x3f, 0x0f, 0xcc, 0x0f, 0x03, 0xc0, 0x30, 0x0c, 0x03, 0x00, 
0xff, 0x3f, 0xcc, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0x3f, 0x0f, 0xc0, 0xff, 0xff, 0xf0, 
0x0c, 0x03, 0x03, 0x00, 0xc0, 0x30, 0x0c, 0x0c, 0x03, 0x00, 0xc0, 0x30, 0x30, 0x0c, 0x03, 0x00, 
0xc0, 0x30, 0x0c, 0x00, 0x3f, 0x0f, 0xcc, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0x3f, 0x0f, 
0xcc, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0x3f, 0x0f, 0xc0, 0x3f, 0x0f, 0xcc, 0x0f, 0x03, 
0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0x3f, 0xcf, 0xf0, 0x0c, 0x03, 0x00, 0xc0, 0x3c, 0x0f, 0x03, 0x3f, 
0x0f, 0xc0, 0xf0, 0x00, 0xf0, 0x33, 0x00, 0x00, 0x00, 0x33, 0xcc, 0x03, 0x03, 0x0c, 0x0c, 0x30, 
0x30, 0xc0, 0xc0, 0x30, 0x30, 0x0c, 0x0c, 0x03, 0x03, 0xff, 0xf0, 0x00, 0xff, 0xf0, 0xc0, 0xc0, 
0x30, 0x30, 0x0c, 0x0c, 0x03, 0x03, 0x0c, 0x0c, 0x30, 0x30, 0xc0, 0xc0, 0x3f, 0x0f, 0xcc, 0x0f, 
0x03, 0x00, 0xc0, 0x30, 0x0c, 0x03, 0x03, 0x00, 0xc0, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0x00, 0x00, 
0x0c, 0x03, 0x00, 0x0f, 0xf0, 0x3f, 0xc3, 0x00, 0xcc, 0x03, 0xc3, 0xcf, 0x0f, 0x3c, 0xcc, 0xf3, 
0x33, 0xcc, 0xcf, 0x33, 0x3c, 0x33, 0xf0, 0xcf, 0x30, 0x00, 0xc0, 0x00, 0xff, 0x03, 0xfc, 0x0c, 
0x03, 0x00, 0xc0, 0x30, 0x33, 0x0c, 0xc3, 0x30, 0xcc, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xff, 0xff, 
0xfc, 0x0f, 0x03, 0xc0, 0xf0, 0x30, 0xff, 0x3f, 0xcc, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 
0xff, 0x3f, 0xcc, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xff, 0x3f, 0xc0, 0x3f, 0x0f, 0xcc, 
0x0f, 0x03, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0xc0, 0x30, 0x0c, 0x0f, 
0x03, 0x3f, 0x0f, 0xc0, 0xfc, 0x3f, 0x0c, 0x33, 0x0c, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 
0x3c, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x33, 0x0c, 0xfc, 0x3f, 0x00, 0xff, 0xff, 0xfc, 0x03, 0x00, 
0xc0, 0x30, 0x0c, 0x03, 0x00, 0xff, 0x3f, 0xcc, 0x03, 0x00, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0xff, 
0xff, 0xf0, 0xff, 0xff, 0xfc, 0x03, 0x00, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0xff, 0x3f, 0xcc, 0x03, 
0x00, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0xc0, 0x30, 0x00, 0x3f, 0x0f, 0xcc, 0x0f, 0x03, 0xc0, 0x30, 
0x0c, 0x03, 0x00, 0xcf, 0xf3, 0xfc, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x3f, 0x0f, 0x3c, 0xcf, 0x30, 
0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xff, 0xff, 0xfc, 0x0f, 0x03, 0xc0, 
0xf0, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 0x30, 0xff, 0xf3, 0x0c, 0x30, 0xc3, 0x0c, 0x30, 0xc3, 0x0c, 
0x30, 0xc3, 0x0c, 0xff, 0xf0, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
0x03, 0xc3, 0xc3, 0xc3, 0xc3, 0x3c, 0x3c, 0xc0, 0xf0, 0x3c, 0x33, 0x0c, 0xcc, 0x33, 0x0f, 0x03, 
0xc0, 0xf0, 0x3c, 0x0c, 0xc3, 0x30, 0xc3, 0x30, 0xcc, 0x0f, 0x03, 0xc0, 0xf0, 0x30, 0xc0, 0x30, 
0x0c, 0x03, 0x00, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0xc0, 0x30, 0x0c, 
0x03, 0x00, 0xff, 0xff, 0xf0, 0xc0, 0xf0, 0x3f, 0x3f, 0xcf, 0xf3, 0xfc, 0xfc, 0xcf, 0x33, 0xcc, 
0xf3, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 0x30, 0xc0, 0xf0, 0x3f, 0x0f, 
0xc3, 0xf0, 0xfc, 0x3c, 0xcf, 0x33, 0xcc, 0xf3, 0x3c, 0x3f, 0x0f, 0xc3, 0xf0, 0xfc, 0x0f, 0x03, 
0xc0, 0xf0, 0x30, 0x3f, 0x0f, 0xcc, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 
0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0x3f, 0x0f, 0xc0, 0xff, 0x3f, 0xcc, 0x0f, 0x03, 0xc0, 
0xf0, 0x3c, 0x0f, 0x03, 0xff, 0x3f, 0xcc, 0x03, 0x00, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0xc0, 0x30, 
0x00, 0x3f, 0x0f, 0xcc, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 
0xcc, 0xf3, 0x3c, 0x3f, 0x0f, 0x3f, 0x0f, 0xc0, 0x0c, 0x03, 0xff, 0x3f, 0xcc, 0x0f, 0x03, 0xc0, 
0xf0, 0x3c, 0x0f, 0x03, 0xff, 0x3f, 0xcc, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 
0x30, 0x3f, 0x0f, 0xcc, 0x0f, 0x03, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0x3f, 0x0f, 0xc0, 0x0c, 0x03, 
0x00, 0xc0, 0x3c, 0x0f, 0x03, 0x3f, 0x0f, 0xc0, 0xff, 0xff, 0xf0, 0xc0, 0x30, 0x0c, 0x03, 0x00, 
0xc0, 0x30, 0x0c, 0x03, 0x00, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0xc0, 
0xf0, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 
0x3c, 0x0f, 0x03, 0x3f, 0x0f, 0xc0, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 0x33, 0x30, 0xcc, 
0x33, 0x0c, 0xc3, 0x30, 0xcc, 0x33, 0x0c, 0xc0, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0xc0, 0xf0, 0x3c, 
0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xcc, 0xf3, 0x3c, 0xcf, 0x33, 0xcc, 0xf3, 0x33, 0x30, 
0xcc, 0x33, 0x0c, 0xc0, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0x33, 0x0c, 0xc3, 0x30, 0xcc, 0x0c, 0x03, 
0x03, 0x30, 0xcc, 0x33, 0x0c, 0xcc, 0x0f, 0x03, 0xc0, 0xf0, 0x30, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 
0xc0, 0xf0, 0x33, 0x30, 0xcc, 0x33, 0x0c, 0xc0, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0xc0, 0x30, 0x0c, 
0x03, 0x00, 0xff, 0xff, 0xf0, 0x0c, 0x03, 0x00, 0xc0, 0x30, 0x30, 0x0c, 0x0c, 0x03, 0x03, 0x00, 
0xc0, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0xff, 0xff, 0xf0, 0xff, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 
0xcc, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x30, 0x30, 0x30, 0x30, 0x0c, 0x0c, 0x0c, 0x0c, 
0x03, 0x03, 0x03, 0x03, 0xff, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0xff, 0x0c, 0x03, 0x03, 
0x30, 0xcc, 0xc0, 0xf0, 0x30, 0xff, 0xff, 0xf0, 0xcc, 0x33, 0x3f, 0x0f, 0xc0, 0x0c, 0x03, 0x3f, 
0xcf, 0xfc, 0x0f, 0x03, 0xc0, 0xf0, 0x33, 0xfc, 0xff, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0xc0, 0x30, 
0x0f, 0xf3, 0xfc, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 0x3f, 0xf3, 0xfc, 0x3f, 0x0f, 0xcc, 
0x0f, 0x03, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0xc0, 0xf0, 0x33, 0xf0, 0xfc, 0x00, 0xc0, 0x30, 0x0c, 
0x03, 0x00, 0xc0, 0x33, 0xfc, 0xff, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 0x33, 0xfc, 0xff, 
0x3f, 0x0f, 0xcc, 0x0f, 0x03, 0xff, 0xff, 0xfc, 0x03, 0x00, 0xc0, 0xf0, 0x33, 0xf0, 0xfc, 0x33, 
0xcc, 0xcc, 0xff, 0xcc, 0xcc, 0xcc, 0xcc, 0x3f, 0xcf, 0xfc, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 
0x03, 0x3f, 0xcf, 0xf0, 0x0c, 0x03, 0x00, 0xc0, 0x3f, 0xf3, 0xfc, 0xc0, 0x30, 0x0c, 0x03, 0x00, 
0xc0, 0x30, 0x0c, 0xf3, 0x3c, 0xf0, 0xfc, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xf0, 
0xff, 0xff, 0xff, 0x33, 0x00, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0xcc, 0xc0, 0x30, 0x0c, 0x03, 
0x00, 0xc3, 0x30, 0xcc, 0xc3, 0x30, 0xf0, 0x3c, 0x0c, 0xc3, 0x30, 0xc3, 0x30, 0xcc, 0x0f, 0x03, 
0xff, 0xff, 0xff, 0xff, 0xf3, 0x3c, 0xcc, 0xcf, 0x33, 0xcc, 0xf3, 0x3c, 0xcf, 0x33, 0xcc, 0xf3, 
0x3c, 0xcf, 0x33, 0xcf, 0x33, 0xcf, 0x0f, 0xc3, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 
0x0f, 0x03, 0x3f, 0x0f, 0xcc, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 0x33, 0xf0, 
0xfc, 0xff, 0x3f, 0xcc, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xff, 0x3f, 0xcc, 0x03, 0x00, 
0xc0, 0x30, 0x0c, 0x03, 0x00, 0x3f, 0xcf, 0xfc, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0x3f, 
0xcf, 0xf0, 0x0c, 0x03, 0x00, 0xc0, 0x30, 0x0c, 0x03, 0xcf, 0x33, 0xcf, 0x0f, 0xc3, 0xc0, 0x30, 
0x0c, 0x03, 0x00, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0x3f, 0x0f, 0xcc, 0x0f, 0x03, 0x3c, 0x0f, 0x00, 
0xf0, 0x3c, 0xc0, 0xf0, 0x33, 0xf0, 0xfc, 0x30, 0xcf, 0xff, 0x30, 0xc3, 0x0c, 0x30, 0xc3, 0x0c, 
0x30, 0xc0, 0xc3, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc3, 0xf0, 0xf3, 
0xcc, 0xf3, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc0, 0xf0, 0x33, 0x30, 0xcc, 0x33, 0x0c, 0xc0, 0xc0, 
0x30, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xcc, 0xf3, 0x3c, 0xcf, 0x33, 0x33, 0x0c, 0xc3, 0x30, 0xcc, 
0xc0, 0xf0, 0x33, 0x30, 0xcc, 0x0c, 0x03, 0x00, 0xc0, 0x30, 0x33, 0x0c, 0xcc, 0x0f, 0x03, 0xc3, 
0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x3c, 0x3c, 0x30, 0x30, 0x30, 0x30, 0xc0, 0xc0, 0xff, 
0xff, 0xf0, 0x0c, 0x03, 0x03, 0x00, 0xc0, 0xc0, 0x30, 0x30, 0x0c, 0x0f, 0xff, 0xff, 0x0c, 0x33, 
0x0c, 0x30, 0xc3, 0x0c, 0xc3, 0x03, 0x0c, 0x30, 0xc3, 0x0c, 0x0c, 0x30, 0xff, 0xff, 0xff, 0xff, 
0xf0, 0xc3, 0x03, 0x0c, 0x30, 0xc3, 0x0c, 0x0c, 0x33, 0x0c, 0x30, 0xc3, 0x0c, 0xc3, 0x00, 0x3c, 
0xcf, 0x3c, 0xf3, 0x3c, };
static const lv_font_fmt_txt_glyph_dsc_t glyphs[] = {{ 0, 0, 0, 0, 0 },
{ 0, 192, 0, 0, 0, 18 },
{ 1, 192, 2, 18, 4, 0 },
{ 6, 192, 6, 6, 2, 12 },
{ 11, 192, 10, 18, 0, 0 },
{ 34, 192, 10, 20, 0, -2 },
{ 59, 192, 10, 18, 0, 0 },
{ 82, 192, 10, 18, 0, 0 },
{ 105, 192, 2, 4, 4, 14 },
{ 106, 192, 4, 18, 2, 0 },
{ 115, 192, 4, 18, 4, 0 },
{ 124, 192, 6, 6, 2, 12 },
{ 129, 192, 10, 10, 0, 4 },
{ 142, 192, 4, 4, 4, -2 },
{ 144, 192, 6, 2, 2, 8 },
{ 146, 192, 2, 2, 4, 0 },
{ 147, 192, 8, 18, 2, 0 },
{ 165, 192, 10, 18, 0, 0 },
{ 188, 192, 6, 18, 2, 0 },
{ 202, 192, 10, 18, 0, 0 },
{ 225, 192, 10, 18, 0, 0 },
{ 248, 192, 10, 18, 0, 0 },
{ 271, 192, 10, 18, 0, 0 },
{ 294, 192, 10, 18, 0, 0 },
{ 317, 192, 10, 18, 0, 0 },
{ 340, 192, 10, 18, 0, 0 },
{ 363, 192, 10, 18, 0, 0 },
{ 386, 192, 2, 10, 4, 4 },
{ 389, 192, 4, 12, 2, 2 },
{ 395, 192, 8, 14, 0, 2 },
{ 409, 192, 6, 6, 2, 6 },
{ 414, 192, 8, 14, 2, 2 },
{ 428, 192, 10, 18, 0, 0 },
{ 451, 256, 14, 16, 0, 0 },
{ 479, 192, 10, 18, 0, 0 },
{ 502, 192, 10, 18, 0, 0 },
{ 525, 192, 10, 18, 0, 0 },
{ 548, 192, 10, 18, 0, 0 },
{ 571, 192, 10, 18, 0, 0 },
{ 594, 192, 10, 18, 0, 0 },
{ 617, 192, 10, 18, 0, 0 },
{ 640, 192, 10, 18, 0, 0 },
{ 663, 192, 6, 18, 2, 0 },
{ 677, 192, 8, 18, 0, 0 },
{ 695, 192, 10, 18, 0, 0 },
{ 718, 192, 10, 18, 0, 0 },
{ 741, 192, 10, 18, 0, 0 },
{ 764, 192, 10, 18, 0, 0 },
{ 787, 192, 10, 18, 0, 0 },
{ 810, 192, 10, 18, 0, 0 },
{ 833, 192, 10, 20, 0, -2 },
{ 858, 192, 10, 18, 0, 0 },
{ 881, 192, 10, 18, 0, 0 },
{ 904, 192, 10, 18, 0, 0 },
{ 927, 192, 10, 18, 0, 0 },
{ 950, 192, 10, 18, 0, 0 },
{ 973, 192, 10, 18, 0, 0 },
{ 996, 192, 10, 18, 0, 0 },
{ 1019, 192, 10, 18, 0, 0 },
{ 1042, 192, 10, 18, 0, 0 },
{ 1065, 192, 4, 18, 2, 0 },
{ 1074, 192, 8, 18, 2, 0 },
{ 1092, 192, 4, 18, 4, 0 },
{ 1101, 192, 10, 6, 0, 12 },
{ 1109, 192, 10, 2, 0, 0 },
{ 1112, 192, 4, 4, 2, 14 },
{ 1114, 192, 10, 12, 0, 0 },
{ 1129, 192, 10, 16, 0, 0 },
{ 1149, 192, 10, 12, 0, 0 },
{ 1164, 192, 10, 16, 0, 0 },
{ 1184, 192, 10, 12, 0, 0 },
{ 1199, 192, 4, 16, 4, 0 },
{ 1207, 192, 10, 16, 0, -4 },
{ 1227, 192, 10, 16, 0, 0 },
{ 1247, 192, 2, 16, 4, 0 },
{ 1251, 192, 4, 18, 2, -2 },
{ 1260, 192, 10, 16, 0, 0 },
{ 1280, 192, 2, 16, 4, 0 },
{ 1284, 192, 10, 12, 0, 0 },
{ 1299, 192, 10, 12, 0, 0 },
{ 1314, 192, 10, 12, 0, 0 },
{ 1329, 192, 10, 16, 0, -4 },
{ 1349, 192, 10, 16, 0, -4 },
{ 1369, 192, 10, 12, 0, 0 },
{ 1384, 192, 10, 12, 0, 0 },
{ 1399, 192, 6, 16, 2, 0 },
{ 1411, 192, 10, 12, 0, 0 },
{ 1426, 192, 10, 12, 0, 0 },
{ 1441, 192, 10, 12, 0, 0 },
{ 1456, 192, 10, 12, 0, 0 },
{ 1471, 192, 8, 16, 2, -4 },
{ 1487, 192, 10, 12, 0, 0 },
{ 1502, 192, 6, 18, 2, 0 },
{ 1516, 192, 2, 18, 4, 0 },
{ 1521, 192, 6, 18, 2, 0 },
{ 1535, 192, 10, 4, 0, 12 },
};
static const lv_font_fmt_txt_cmap_t cmaps[] = { {
.range_start = 32, .range_length = 95, .glyph_id_start = 1,
.unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
} };
static const lv_font_fmt_txt_dsc_t font_dsc = {.glyph_bitmap = bitmaps,
.glyph_dsc = glyphs,
.cmaps = cmaps,
.kern_dsc = NULL,
.kern_scale = 0,
.cmap_num = 1,
.bpp = 1,
.kern_classes = 0,
.bitmap_format = 0,
};
const lv_font_t font_pixel_mono_14pt = {
.get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,
.get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,
.line_height = 22,
.base_line = 4,
.subpx = LV_FONT_SUBPX_NONE,
.underline_position = 0,
.underline_thickness = 0,
.dsc = &font_dsc
};

#endif

