# MIT License 
# Copyright (c) 2022-Today Titouan Lebocq <lebocq.titouan@gmail.com>
#
# Main CMake Project file

# cmake requierement
cmake_minimum_required(VERSION 3.13.4, FATAL_ERROR)
# project informations
project(ant_simulation)
set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/bin)

# lib presenter
file(GLOB_RECURSE presenter_include project/lib/presenter/include/*.h)
file(GLOB_RECURSE presenter_source  project/lib/presenter/src/*.cpp)
add_library(presenter ${presenter_include} ${presenter_source})
# lib model
file(GLOB_RECURSE model_include project/lib/model/include/*.h)
file(GLOB_RECURSE model_source  project/lib/model/src/*.cpp)
add_library(model ${model_include} ${model_source})


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


# app
# setting a bin output for the project
add_executable(${PROJECT_NAME} project/app/src/app.cpp)
# Presenter lib
target_link_libraries(${PROJECT_NAME} presenter)
# Model lib
target_link_libraries(${PROJECT_NAME} model)

target_link_libraries(ant_simulation ${CONAN_LIBS})