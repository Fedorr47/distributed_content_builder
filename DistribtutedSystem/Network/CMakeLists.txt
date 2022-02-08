# CMakeList.txt : CMake project for DistribtutedSystem, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/TestNetwork.cpp
   PARENT_SCOPE
)

set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/TestNetwork.hpp
   PARENT_SCOPE
)