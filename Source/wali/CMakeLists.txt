cmake_minimum_required (VERSION 3.0)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

project (wali)
set(CMAKE_PROJECT_NAME "wali")

set(CMAKE_EXPORT_COMPILE_COMMANDS YES)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(WALI_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Hier wird der include Pfad des Projekts gesetzt, sodass man bsp. mit
#
#   #include <MyCoolLib/src1.h>
#
# die gewünschten Headerdateien inkludieren kann.
include_directories(
  ${WALI_SRC_DIR}/include
)

# Add the plang subdirectories
add_subdirectory(include)
add_subdirectory(lib)

# Hier wird ein ausführbares Programm erzeugt.
# Die nächsten beiden CMake Anweisungen 'add_executable' und
# 'target_link_libraries' können auch auskommentiert werden, falls nur die
# Bibliothek(en) erzeugt werden soll(en). Man kann falls nötige auch mehrere
# ausführbare Programme erzeugen, indem weiter Anweisungen dieser Art 
# hinzugefügt werde.
#add_executable(myprogram
#  main.cpp
#)

#target_link_libraries(wali
#  waliLib
#)
