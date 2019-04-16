cmake_minimum_required (VERSION 3.0)

project (wali)
set(CMAKE_PROJECT_NAME "wali")

set(CMAKE_EXPORT_COMPILE_COMMANDS CACHE BOOL YES)
set(CMAKE_CXX_STANDARD CACHE STRING 14)
set(CMAKE_CXX_STANDARD_REQUIRED CACHE BOOL ON)
set(CMAKE_CXX_FLAGS CACHE STRING "-Wall -Wextra")

find_package(LLVM REQUIRED CONFIG 5)
find_library(LLVM_LIBRARY NAMES llvm REQUIRED)
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIB_PATH} ${LLVM_LIBRARY_DIRS})

add_subdirectory(Source)
