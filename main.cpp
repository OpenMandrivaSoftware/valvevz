#include "File.hpp"
#include "LZMA.hpp"
#include "VZ.hpp"

#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>

#include <7zCrc.h>

static void printTimestamp(const std::time_t timestamp) {
	const std::tm *tmp = std::gmtime(&timestamp);
	std::cout << "Timestamp: " << std::put_time(tmp, "%F %T") << std::endl;
}

int main(int argc, char **argv) {
	if (argc != 4 || strcmp(argv[1], "--decompress") != 0) {
		std::cout << "Usage: valvevz --decompress <in> <out>" << std::endl;
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
		std::cout << "Failed to read footer!" << std::endl;
		return 3;
	}

	if (!footer) {
		std::cout << "Invalid footer!" << std::endl;
		return 4;
	}

	if (!inFile.seek(0)) {
		return 5;
	}

	vz::Header header;
	if (inFile.read(&header, sizeof(header)) != sizeof(header)) {
		std::cout << "Failed to read header!" << std::endl;
		return 6;
	}

	if (!header) {
		std::cout << "Invalid header!" << std::endl;
		return 7;
	}

	printTimestamp(header.timestamp);

	std::vector< uint8_t > lzma(lzmaSize);
	if (inFile.read(lzma.data(), lzma.size()) != lzma.size()) {
		std::cout << "Failed to read LZMA data!" << std::endl;
		return 8;
	}

	std::vector< uint8_t > data(footer.size);

	if (!lzma::decompress(data.data(), data.size(), lzma.data(), lzma.size())) {
		std::cout << "Failed to uncompress LZMA data!" << std::endl;
		return 9;
	}

	CrcGenerateTable();

	if (CrcCalc(data.data(), data.size()) != footer.crc) {
		std::cout << "Unmatching CRC!" << std::endl;
		return 10;
	}

	File outFile(argv[3], true);
	if (!outFile) {
		return 11;
	}

	if (outFile.write(data.data(), data.size()) != data.size()) {
		std::cout << "Failed to write data to file!" << std::endl;
		return 12;
	}

	return 0;
}
