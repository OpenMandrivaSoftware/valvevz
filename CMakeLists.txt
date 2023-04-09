cmake_minimum_required(VERSION 3.14)

project(valvevz)

set(LZMA_SDK_PATH "3rdparty/lzma")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(valvevz
	"main.cpp"

	"File.cpp"
	"File.hpp"

	"LZMA.cpp"
	"LZMA.hpp"

	"VZ.hpp"

	"${LZMA_SDK_PATH}/LzmaDec.c"
	"${LZMA_SDK_PATH}/LzmaDec.h"
)

target_include_directories(valvevz
	PRIVATE
		${LZMA_SDK_PATH}
)

install(
	TARGETS valvevz
	RUNTIME DESTINATION bin
)
