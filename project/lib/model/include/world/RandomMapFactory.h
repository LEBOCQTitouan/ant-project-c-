//
// Created by Antoine Guespin on 14/12/2022.
//

#ifndef ANT_SIMULATION_RANDOMMAPFACTORY_H
#define ANT_SIMULATION_RANDOMMAPFACTORY_H

#include "WorldMap.h"
#include "WorldMapTile.h"

namespace AntWorld {
    class RandomMapFactory {

    private :
        static int getRandomX();

        static int getRandomY();

    public:
        AntWorld::WorldMapTile * generateMap();
    };
}

#endif //ANT_SIMULATION_RANDOMMAPFACTORY_H
