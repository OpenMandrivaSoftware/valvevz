#pragma once

#include <7zTypes.h>

namespace lzma {
	bool decompress(Byte *dst, SizeT dstSize, const Byte *src, SizeT srcSize);

	static constexpr const char *resText(const SRes res) {
		switch (res) {
			case SZ_OK:
				return "SZ_OK";
			case SZ_ERROR_DATA:
				return "SZ_ERROR_DATA";
			case SZ_ERROR_MEM:
				return "SZ_ERROR_MEM";
			case SZ_ERROR_CRC:
				return "SZ_ERROR_CRC";
			case SZ_ERROR_UNSUPPORTED:
				return "SZ_ERROR_UNSUPPORTED";
			case SZ_ERROR_PARAM:
				return "SZ_ERROR_PARAM";
			case SZ_ERROR_INPUT_EOF:
				return "SZ_ERROR_INPUT_EOF";
			case SZ_ERROR_OUTPUT_EOF:
				return "SZ_ERROR_OUTPUT_EOF";
			case SZ_ERROR_READ:
				return "SZ_ERROR_READ";
			case SZ_ERROR_WRITE:
				return "SZ_ERROR_WRITE";
			case SZ_ERROR_PROGRESS:
				return "SZ_ERROR_PROGRESS";
			case SZ_ERROR_FAIL:
				return "SZ_ERROR_FAIL";
			case SZ_ERROR_THREAD:
				return "SZ_ERROR_THREAD";
			case SZ_ERROR_ARCHIVE:
				return "SZ_ERROR_ARCHIVE";
			case SZ_ERROR_NO_ARCHIVE:
				return "SZ_ERROR_NO_ARCHIVE";
		}

		return "unknown error";
	}
}
