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
