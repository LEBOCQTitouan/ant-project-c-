//
// Created by Antoine Guespin on 01/01/2023.
//

#ifndef ANT_SIMULATION_SIMULATORSEQUENCER_H
#define ANT_SIMULATION_SIMULATORSEQUENCER_H

#include <vector>
#include "AntAction.h"

namespace AntSimulator {

    class SimulatorSequencer {
        std::vector<std::vector<AntAction *>*> actions;
        int index = 0;
    public:

        SimulatorSequencer();

        void addAntAction(AntAction *action);

        void executeActions(AntWorld::WorldMap *worldMap);
    };


} // AntSimulator

#endif //ANT_SIMULATION_SIMULATORSEQUENCER_H
