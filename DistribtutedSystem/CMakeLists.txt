# CMakeList.txt : CMake project for DistribtutedSystem, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/DistribtutedSystem.hpp
)

set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/DistribtutedSystem.cpp
)

add_subdirectory ("Agent")
add_subdirectory ("Content")
add_subdirectory ("Controller")
add_subdirectory ("Interfaces")
add_subdirectory ("Logger")
add_subdirectory ("Network")
add_subdirectory ("Queue")

include_directories(./Agent/)
include_directories(./Content/)
include_directories(./Controller/)
include_directories(./Interfaces/)
include_directories(./Logger/)
include_directories(./Network/)
include_directories(./Queue/)

# Add source to this project's executable.
add_executable (DistribtutedSystem ${HEADERS} ${SOURCE} )

# TODO: Add tests and install targets if needed.
