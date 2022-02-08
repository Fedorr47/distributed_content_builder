# CMakeList.txt : CMake project for DistribtutedSystem, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/DistribtutedSystem.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/DistribtutedSystem.hpp
)

add_subdirectory ("Agent")
add_subdirectory ("Content")
add_subdirectory ("Controller")
add_subdirectory ("Interfaces")
add_subdirectory ("Logger")
add_subdirectory ("Network")
add_subdirectory ("Queue")

# Add source to this project's executable.
add_executable (DistribtutedSystem ${SOURCE} ${HEADERS})

# TODO: Add tests and install targets if needed.
