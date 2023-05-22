add_executable(test_boost test_version.cpp)

set_target_properties(test_boost PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)

if (MSVC)
	target_compile_options(test_boost PRIVATE /W4)
else ()
	target_compile_options(test_boost PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

target_include_directories(test_boost PRIVATE
	${Boost_INCLUDE_DIR}
	../library
)

target_link_libraries(test_boost PRIVATE
	${Boost_LIBRARIES}
	helloworld_lib
)

set_target_properties(test_boost PROPERTIES
	COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
)

add_test(test_boost test_boost)
