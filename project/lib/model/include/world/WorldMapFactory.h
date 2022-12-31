//
// Created by Antoine Guespin on 14/12/2022.
//

#ifndef ANT_SIMULATION_WORLDMAPFACTORY_H
#define ANT_SIMULATION_WORLDMAPFACTORY_H

#include "WorldMap.h"

namespace AntWorld {

    class WorldMapFactory {

    public:
        virtual WorldMap generateMap() = 0;

    };

}
#endif //ANT_SIMULATION_WORLDMAPFACTORY_H
