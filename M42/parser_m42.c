/*
	Name: parser_m42.c
	Description: Implements a parser extension for Marlin M42 for µCNC.
		This is only a partial implementation. Only the state S of the pin will be definable

	Copyright: Copyright (c) João Martins
	Author: João Martins
	Date: 18/01/2022

	µCNC is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version. Please see <http://www.gnu.org/licenses/>

	µCNC is distributed WITHOUT ANY WARRANTY;
	Also without the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See the	GNU General Public License for more details.
*/

#include "../../cnc.h"
#include <stdint.h>
#include <stdbool.h>

#ifdef ENABLE_PARSER_MODULES

#if (UCNC_MODULE_VERSION > 010700)
#error "This module is not compatible with the current version of µCNC"
#endif

// if all conventions changes this must be updated
#define PWM0_ID 24
#define DOUT0_ID 46

// this ID must be unique for each code
#define M42 EXTENDED_MCODE(42)

bool m42_parse(void *args);
bool m42_exec(void *args);

CREATE_EVENT_LISTENER(gcode_parse, m42_parse);
CREATE_EVENT_LISTENER(gcode_exec, m42_exec);

// this just parses and acceps the code
bool m42_parse(void *args)
{
	gcode_parse_args_t *ptr = (gcode_parse_args_t *)args;
	if (ptr->word == 'M' && ptr->code == 42)
	{
		if (ptr->cmd->group_extended != 0)
		{
			// there is a collision of custom gcode commands (only one per line can be processed)
			*(ptr->error) = STATUS_GCODE_MODAL_GROUP_VIOLATION;
			return true;
		}
		// tells the gcode validation and execution functions this is custom code M42 (ID must be unique)
		ptr->cmd->group_extended = M42;
		*(ptr->error) = STATUS_OK;
		return true;
	}

	// if this is not catched by this parser, just send back the error so other extenders can process it
	return false;
}

// this actually performs 2 steps in 1 (validation and execution)
bool m42_exec(void *args)
{
	gcode_exec_args_t *ptr = (gcode_exec_args_t *)args;
	if (ptr->cmd->group_extended == M42)
	{
		if (CHECKFLAG(ptr->cmd->words, (GCODE_WORD_S | GCODE_WORD_P)) != (GCODE_WORD_S | GCODE_WORD_P))
		{
			*(ptr->error) = STATUS_GCODE_VALUE_WORD_MISSING;
			return true;
		}

		if (ptr->words->p >= PWM0_ID && ptr->words->p < DOUT0_ID)
		{
			io_set_pwm(ptr->words->p, (uint8_t)CLAMP(0, ptr->words->s, 255));
		}

		if (ptr->words->p >= DOUT0_ID && ptr->words->p < (DOUT0_ID + 32))
		{
			io_set_output(ptr->words->p, (ptr->words->s != 0));
		}

		*(ptr->error) = STATUS_OK;
		return true;
	}

	return false;
}

#endif

DECL_MODULE(m42)
{
#ifdef ENABLE_PARSER_MODULES
	ADD_EVENT_LISTENER(gcode_parse, m42_parse);
	ADD_EVENT_LISTENER(gcode_exec, m42_exec);
#else
#warning "Parser extensions are not enabled. M42 code extension will not work."
#endif
}
