cmake_minimum_required (VERSION 2.6)
project (CppStaticAnalysis CXX)

message (STATUS "Build type: ${CMAKE_BUILD_TYPE}.")

set (PROJECT_EXEC "main")
set (CMAKE_CXX_FLAGS "-g -ggdb -std=c++11 -Wall -Wextra -Werror -pedantic")

set (SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
file (GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp")

add_executable ("${PROJECT_EXEC}" "${SRC_FILES}")
