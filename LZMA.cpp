/*
valvevz

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "LZMA.hpp"

#include <cstdio>
#include <cstdlib>

#include <LzmaDec.h>

static void *Alloc(const ISzAllocPtr, const size_t size) { return malloc(size); }
static void Free(const ISzAllocPtr, void *address) { free(address); }

static constexpr ISzAlloc allocator = { Alloc, Free };

bool lzma::decompress(Byte *dst, SizeT dstSize, const Byte *src, SizeT srcSize) {
	const auto props = src;
	constexpr auto propsSize = LZMA_PROPS_SIZE;

	src += propsSize;
	srcSize -= propsSize;

	ELzmaStatus status;
	if (const auto ret = LzmaDecode(dst, &dstSize, src, &srcSize, props, propsSize, LZMA_FINISH_END, &status, &allocator); ret != SZ_OK) {
		printf("LzmaDecode() failed with %s\n", resText(ret));
		return false;
	}

	return true;
}
