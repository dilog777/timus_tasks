add_executable(test_google test_version.cpp)

set_target_properties(test_google PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)

if (MSVC)
	target_compile_options(test_google PRIVATE /W4)
else ()
	target_compile_options(test_google PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

target_include_directories(test_google PRIVATE
	../library
)

target_link_libraries(test_google PRIVATE
	GTest::gtest_main
	helloworld_lib
)

include(GoogleTest)
gtest_discover_tests(test_google)
