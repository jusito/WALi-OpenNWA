cmake_minimum_required (VERSION 3.0)

project (wali)
set(CMAKE_PROJECT_NAME "wali")

set(CMAKE_EXPORT_COMPILE_COMMANDS YES)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

add_subdirectory(Source)
