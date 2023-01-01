//
// Created by Antoine Guespin on 14/12/2022.
//

#ifndef ANT_SIMULATION_WORLDMAP_H
#define ANT_SIMULATION_WORLDMAP_H

#include "Tile.h"
namespace AntEntities {
    class Ant;
}
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

    class WorldMap {


    public:
        static const int BOARD_WIDTH = 211;
        static const int BOARD_HEIGHT = 201;

        virtual Tile *getTile(int x, int y) = 0;
        virtual std::vector<AntEntities::Ant *> * getAntList() = 0;


    };

}

#endif //ANT_SIMULATION_WORLDMAP_H
