#include "File.hpp"
#include "LZMA.hpp"
#include "VZ.hpp"

#include <cstdio>
#include <cstring>
#include <vector>

int main(int argc, char **argv) {
	if (argc != 4 || strcmp(argv[1], "--decompress") != 0) {
		printf("Usage: valvevz --decompress <in> <out>\n");
		return -1;
	}

	File inFile(argv[2], false);
	if (!inFile) {
		return 1;
	}

	if (!inFile.rseek(sizeof(vz::Footer))) {
		return 2;
	}

	const auto lzmaSize = inFile.pos() - sizeof(vz::Header);

	vz::Footer footer;
	if (inFile.read(&footer, sizeof(footer)) != sizeof(footer)) {
		printf("Failed to read footer!\n");
		return 3;
	}

	if (!footer) {
		printf("Invalid footer!\n");
		return 4;
	}

	if (!inFile.seek(0)) {
		return 5;
	}

	vz::Header header;
	if (inFile.read(&header, sizeof(header)) != sizeof(header)) {
		printf("Failed to read header!\n");
		return 6;
	}

	if (!header) {
		printf("Invalid header!\n");
		return 7;
	}

	std::vector< uint8_t > lzma(lzmaSize);
	if (inFile.read(lzma.data(), lzma.size()) != lzma.size()) {
		printf("Failed to read LZMA data!\n");
		return 8;
	}

	std::vector< uint8_t > data(footer.size);

	if (!lzma::decompress(data.data(), data.size(), lzma.data(), lzma.size())) {
		printf("Failed to uncompress LZMA data!\n");
		return 9;
	}

	File outFile(argv[3], true);
	if (!outFile) {
		return 10;
	}

	if (outFile.write(data.data(), data.size()) != data.size()) {
		printf("Failed to write data to file!\n");
		return 11;
	}

	return 0;
}
