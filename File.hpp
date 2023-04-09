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
