# MIT License 
# Copyright (c) 2022-Today Titouan Lebocq <lebocq.titouan@gmail.com>
#

file(GLOB_RECURSE presenter_include include/*)
file(GLOB_RECURSE presenter_source src/*)
add_library(presenter ${presenter_include} ${presenter_source})