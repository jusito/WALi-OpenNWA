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
