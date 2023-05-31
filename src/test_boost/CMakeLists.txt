file(GLOB_RECURSE SRC *.h *.hpp *.cpp)

add_executable(test_boost ${SRC})

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
