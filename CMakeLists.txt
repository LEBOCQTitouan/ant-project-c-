# MIT License 
# Copyright (c) 2022-Today Titouan Lebocq <lebocq.titouan@gmail.com>
#
# Main CMake Project file

# cmake requirement
cmake_minimum_required(VERSION 3.13.4, FATAL_ERROR)
# project informations
project(ant_simulation)
set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/bin)


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()



# project files
add_subdirectory(project)


target_link_libraries(ant_simulation ${CONAN_LIBS})