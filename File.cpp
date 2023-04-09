#include "File.hpp"

#include <cerrno>
#include <cstdio>
#include <cstring>

File::File(const char *path, const bool write) : m_handle(std::fopen(path, write ? "wb" : "rb")) {
	if (!m_handle) {
		std::printf("Failed to open file at %s: %s\n", path, strerror(errno));
	}
}

File::~File() {
	if (m_handle) {
		std::fclose(m_handle);
	}
}

size_t File::pos() const {
	return std::ftell(m_handle);
}

bool File::seek(const size_t pos) {
	return std::fseek(m_handle, pos, SEEK_SET) == 0;
}

bool File::rseek(const size_t pos) {
	return std::fseek(m_handle, -pos, SEEK_END) == 0;
}

size_t File::read(void *dst, const size_t size) {
	return std::fread(dst, 1, size, m_handle);
}

size_t File::write(const void *src, const size_t size) {
	return std::fwrite(src, 1, size, m_handle);
}
