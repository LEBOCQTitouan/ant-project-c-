//
// Created by Antoine Guespin on 14/12/2022.
//

#ifndef ANT_SIMULATION_RANDOMMAPFACTORY_H
#define ANT_SIMULATION_RANDOMMAPFACTORY_H

#include "WorldMap.h"
#include "WorldMapRandom.h"
#include "WorldMapFactory.h"

namespace AntWorld {
    class RandomMapFactory: public WorldMapFactory {

    private :
        int getRandom(int inf, int sup);

        Object * generateObject(int x,int y);
    public:
        AntWorld::WorldMap * generateMap() override;

    };
}

#endif //ANT_SIMULATION_RANDOMMAPFACTORY_H
