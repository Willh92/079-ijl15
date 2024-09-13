/*
 This file is part of GMS-83-DLL.

 GMS-83-DLL is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 GMS-83-DLL is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with Foobar. If not, see <https://www.gnu.org/licenses/>.
 */

#include "logger.h"

void Log(const char* format, ...)
{
	char buf[1024] = { 0 };

	va_list args;
	va_start(args, format);
	vsprintf_s(buf, format, args);

	OutputDebugString(buf);

	va_end(args);
}