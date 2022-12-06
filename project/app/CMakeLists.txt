# MIT License 
# Copyright (c) 2022-Today Titouan Lebocq <lebocq.titouan@gmail.com>
#

# setting a bin output for the project
add_executable(${PROJECT_NAME} src/app.cpp)
# linking with libraries
# Presenter
target_link_libraries(${PROJECT_NAME} presenter)
# Model
target_link_libraries(${PROJECT_NAME} model)