# valvevz
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.14)

project(valvevz
	VERSION 1.0
	DESCRIPTION "Decompresses Valve's \".zip.vz\" files."
)

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
