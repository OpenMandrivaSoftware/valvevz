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

#include <array>
#include <cstdint>

namespace vz {
#pragma pack(push, 1)
struct Header {
	constexpr explicit operator bool() const { return magic == expectedMagic  && rev == expectedRev; };

	std::array< char, 2 > magic;
	char rev;
	uint32_t timestamp;

	static constexpr std::array< char, 2 > expectedMagic = { 'V', 'Z' };
	static constexpr char expectedRev = 'a';
};
#pragma pack(pop)

#pragma pack(push, 2)
struct Footer {
	constexpr explicit operator bool() const { return magic == expectedMagic; };

	uint32_t crc;
	uint32_t size;
	std::array< char, 2 > magic;

	static constexpr std::array< char, 2 > expectedMagic = { 'z', 'v' };
};
#pragma pack(pop)

static_assert(sizeof(Header) == 7);
static_assert(sizeof(Footer) == 10);

}
