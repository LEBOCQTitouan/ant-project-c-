# MIT License 
# Copyright (c) 2022-Today Titouan Lebocq <lebocq.titouan@gmail.com>
#

# setting a bin output for the project
add_executable(${PROJECT_NAME} src/app.cpp)
# linking with libraries
# target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/project/lib/presenter/include/)
# target_link_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/project/lib/presenter/include/)
target_include_directories(${PROJECT_NAME} PUBLIC ../lib/presenter/include/)
target_link_directories(${PROJECT_NAME} PRIVATE ../lib/presenter/include/)
target_link_libraries(${PROJECT_NAME} presenter)