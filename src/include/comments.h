/** \file
 * Copyright (c) 1999 Carlo Wood.  All rights reserved.
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef INDENT_COMMENTS_H
#define INDENT_COMMENTS_H

/* for RCSTAG_H */
#include "sys.h"

RCSTAG_H(comments, "$Id$");

/* For BOOLEAN */
#include "indent.h"

extern void
print_comment(int *paren_targ, BOOLEAN *pbreak_line);

#endif /* INDENT_COMMENTS_H */
