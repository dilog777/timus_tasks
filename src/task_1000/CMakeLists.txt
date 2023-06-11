project(task_1000 VERSION ${PROJECT_VERSION})

file(GLOB_RECURSE SRC *.h *.hpp *.cpp)

add_executable(task_1000 ${SRC})
