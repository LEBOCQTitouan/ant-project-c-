//
// Created by Antoine Guespin on 01/01/2023.
//

#ifndef ANT_SIMULATION_ANTACTION_H
#define ANT_SIMULATION_ANTACTION_H

#include "../world/WorldMap.h"

namespace AntSimulator {
    class AntAction {
    public:
        virtual void execute(AntWorld::WorldMap *worldMap) = 0;
    };

}
#endif //ANT_SIMULATION_ANTACTION_H
