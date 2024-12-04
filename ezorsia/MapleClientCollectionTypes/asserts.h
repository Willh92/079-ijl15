/*
 This file is part of GMS-83-DLL.

 GMS-83-DLL is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 GMS-83-DLL is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with Foobar. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#ifndef assert_size
#define assert_size(x, y) static_assert(x == y, "Static size assert failed.");
#endif

#ifndef member_at
#define member_at(T, offset, name) auto& name() { return *reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(this) + offset); }
#endif

#ifndef padding
#define padding(x) struct { unsigned char __padding##x[(x)]; };
#endif