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
