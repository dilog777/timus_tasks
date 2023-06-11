project(task_2012 VERSION ${PROJECT_VERSION})

file(GLOB_RECURSE SRC *.h *.hpp *.cpp)

add_executable(task_2012 ${SRC})
