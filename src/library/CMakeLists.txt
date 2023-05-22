add_library(helloworld_lib lib.cpp)

set_target_properties(helloworld_lib PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)

if (MSVC)
	target_compile_options(helloworld_lib PRIVATE /W4)
else ()
	target_compile_options(helloworld_lib PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

target_include_directories(helloworld_lib PRIVATE
	"${CMAKE_CURRENT_BINARY_DIR}"
)

configure_file(version.h.in version.h)
