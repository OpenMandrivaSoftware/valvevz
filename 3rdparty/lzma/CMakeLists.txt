add_library(lzma OBJECT
	"7zCrc.c"
	"7zCrc.h"
	"7zCrcOpt.c"
	"7zTypes.h"
	"Compiler.h"
	"CpuArch.c"
	"CpuArch.h"
	"LzmaDec.c"
	"LzmaDec.h"
	"Precomp.h"
)

target_include_directories(lzma
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}
)
