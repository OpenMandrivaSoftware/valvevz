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

#include <cstddef>

#include <bits/types/FILE.h>

class File {
public:
	File(const char *path, const bool write);
	~File();

	constexpr explicit operator bool() const { return m_handle != nullptr; };

	size_t pos() const;

	bool seek(const size_t pos);
	bool rseek(const size_t pos);

	size_t read(void *dst, const size_t size);
	size_t write(const void *src, const size_t size);

private:
	File(const File &) = delete;
	File &operator=(const File &) = delete;

	FILE *m_handle;
};
