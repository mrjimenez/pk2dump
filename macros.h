/*
 * Copyright (c) 2010 Marcelo Roberto Jimenez <mroberto@cpti.cetuc.puc-rio.br>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef MACROS_H
#define MACROS_H

#define DECLARE_ERROR_VARS \
	int x_err = 0; \
	int x_aux = 0; \
	int x_line = 0; \
	const char *x_msg = NULL;

#define TEST_FOR_ERROR(cond, loop, label, str) \
	if (cond) { \
		x_err = 1; \
		x_aux = (int)loop; \
		x_line = __LINE__; \
		x_msg = str; \
		goto label; \
	}

#define CHECK_FOR_ERROR \
	do { \
		if (x_err) { \
			fprintf(stderr, "Error(%s:%d): %s, aux = %d.\n", \
				__FILE__, x_line, x_msg, x_aux); \
		} \
	} while(0);

#endif /* MACROS_H */

