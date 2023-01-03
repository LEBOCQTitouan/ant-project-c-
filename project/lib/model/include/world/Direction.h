//
// Created by Antoine Guespin on 02/01/2023.
//

#ifndef ANT_SIMULATION_DIRECTION_H
#define ANT_SIMULATION_DIRECTION_H

#include <stdexcept>

namespace AntWorld {

    typedef enum {
        NORTH,
        NORTH_EAST,
        EAST,
        SOUTH_EAST,
        SOUTH,
        SOUTH_WEST,
        WEST,
        NORTH_WEST
    } Direction;

    static Direction getDirectionWithOffset(int x, int y) {
        if (x == 1 && y == 0) {
            return SOUTH;
        }
        if (x == 1 && y == 1) {
            return SOUTH_EAST;
        }
        if (x == 1 && y == -1) {
            return SOUTH_WEST;
        }
        if (x == -1 && y == 0) {
            return NORTH;
        }
        if (x == -1 && y == 1) {
            return NORTH_EAST;
        }
        if (x == -1 && y == -1) {
            return NORTH_WEST;
        }
        if (x == 0 && y == 1) {
            return EAST;
        }
        if (x == 0 && y == -1) {
            return WEST;
        }
        throw std::runtime_error("Valuer de direction incorrect");
    }
}
#endif //ANT_SIMULATION_DIRECTION_H
