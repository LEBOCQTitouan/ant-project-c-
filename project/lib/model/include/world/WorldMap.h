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

    class WorldMap {


    public:
        static const int BOARD_WIDTH = 50;
        static const int BOARD_HEIGHT = 50;

        virtual Tile *getTile(int x, int y) = 0;
        virtual std::vector<AntEntities::Ant *> * getAntList() = 0;
        virtual std::map<AntWorld::Direction, std::vector<Pheromone *>> getPheromoneMap(int x, int y, bool needToBeDiscovered) = 0;

    };

}

#endif //ANT_SIMULATION_WORLDMAP_H
