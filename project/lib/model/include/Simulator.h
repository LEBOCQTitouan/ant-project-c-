//
// Created by Antoine Guespin on 01/01/2023.
//

#ifndef ANT_SIMULATION_SIMULATOR_H
#define ANT_SIMULATION_SIMULATOR_H

#include "world/WorldMap.h"
#include "clock/Clock.h"
#include "world/WorldMapFactory.h"
#include "action/SimulatorSequencer.h"

namespace AntSimulator {

    class Simulator {
    private:
        AntWorld::WorldMap *worldMap;
        AntSimulator::SimulatorSequencer sequencer;

    public:
        void turn();

        void initSimulation(AntWorld::WorldMapFactory *worldMapFactory);

        AntWorld::WorldMap *getWorldMap() const;
    };

} // AntSimulator

#endif //ANT_SIMULATION_SIMULATOR_H
