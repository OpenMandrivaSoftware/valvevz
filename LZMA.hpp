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
