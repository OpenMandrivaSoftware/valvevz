add_library(lzma OBJECT
	"7zTypes.h"
	"Compiler.h"
	"LzmaDec.c"
	"LzmaDec.h"
	"Precomp.h"
)

target_include_directories(lzma
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}
)
