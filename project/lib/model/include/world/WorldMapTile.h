//
// Created by Antoine Guespin on 13/12/2022.
//

#ifndef ANT_SIMULATION_WORLDMAPTILE_H
#define ANT_SIMULATION_WORLDMAPTILE_H

#include "Tile.h"
#include "object/Object.h"

namespace AntWorld {

    class WorldMapTile {

    public:
        Tile * getTile(int x, int y);
        static const int BOARD_WIDTH = 211;
        static const int BOARD_HEIGHT = 201;
    private:
        Tile tiles[BOARD_HEIGHT][BOARD_WIDTH];
    };

} // AntWorld

#endif //ANT_SIMULATION_WORLDMAPTILE_H
