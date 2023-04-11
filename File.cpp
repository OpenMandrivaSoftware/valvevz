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
