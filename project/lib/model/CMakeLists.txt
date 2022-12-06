# MIT License 
# Copyright (c) 2022-Today Titouan Lebocq <lebocq.titouan@gmail.com>
#

file(GLOB_RECURSE model_include include/*)
file(GLOB_RECURSE model_source src/*)
add_library(model ${model_include} ${model_source})