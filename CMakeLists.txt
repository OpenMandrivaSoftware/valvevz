cmake_minimum_required(VERSION 3.14)

project(valvevz)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("3rdparty/lzma")

add_executable(valvevz
	"main.cpp"

	"File.cpp"
	"File.hpp"

	"LZMA.cpp"
	"LZMA.hpp"

	"VZ.hpp"
)

target_link_libraries(valvevz
	PRIVATE
		lzma
)

install(
	TARGETS valvevz
	RUNTIME DESTINATION bin
)
