/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "common/scummsys.h"

namespace Common {

using scummvmExitFuncPtr = void (*)(int);

/**
 * A replacement for exit(). The function called to exit can be
 * overriden by using overrideScummvmExitFunc(). Makes it possible for
 * backends to clean up resources before calling the actual exit() or
 * a platform specific equivalent.
 *
 * @param rc Return code. Passed on to exit() or the function replacing it.
 */
NORETURN_PRE void scummvmExit(int rc = 0) NORETURN_POST;

/**
 * Override the function scummvmExit() calls to exit the program.
 *
 * @param func Pointer to a function of the form void f(int). The function
 * is passed a return code as its argument and should exit the program.
 */
void overrideScummvmExitFunc(scummvmExitFuncPtr func);

} // End of namespace Common
