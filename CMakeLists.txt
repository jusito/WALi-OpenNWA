cmake_minimum_required (VERSION 3.0)

project (wali)
set(CMAKE_PROJECT_NAME "wali")

if(NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS YES)
endif(NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
if(NOT DEFINED CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD 14)
endif(NOT DEFINED CMAKE_CXX_STANDARD)
if(NOT DEFINED CMAKE_CXX_STANDARD_REQUIRED)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif(NOT DEFINED CMAKE_CXX_STANDARD_REQUIRED)
if(NOT DEFINED CMAKE_CXX_FLAGS)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
endif(NOT DEFINED CMAKE_CXX_FLAGS)
if(NOT DEFINED CMAKE_CXX_EXTENSIONS)
set(CMAKE_CXX_EXTENSIONS OFF)
endif(NOT DEFINED CMAKE_CXX_EXTENSIONS)

if(DEFINED LLVM_MAIN_SRC_DIR)
  llvm_map_components_to_libnames(llvm_libs
    Support
    Core
  )
else()
  # Find an include llvm if we build out of tree
  find_package(LLVM REQUIRED CONFIG 8)
  find_library(LLVM_LIBRARY NAMES llvm REQUIRED)
  include_directories(${LLVM_INCLUDE_DIRS})
  link_directories(${LLVM_LIB_PATH} ${LLVM_LIBRARY_DIRS})
  llvm_map_components_to_libnames(llvm_libs
    Support
    Core
  )
endif()

add_subdirectory(Source)
