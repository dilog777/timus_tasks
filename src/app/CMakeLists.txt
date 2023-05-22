add_executable(helloworld main.cpp)

set_target_properties(helloworld PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)

if (MSVC)
	target_compile_options(helloworld PRIVATE /W4)
else ()
	target_compile_options(helloworld PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

target_include_directories(helloworld PRIVATE
	../library
)

target_link_libraries(helloworld PRIVATE
	helloworld_lib
)
