//
// Created by Antoine Guespin on 01/01/2023.
//

#include "../../include/action/SimulatorSequencer.h"


namespace AntSimulator {
    void SimulatorSequencer::executeActions(AntWorld::WorldMap *worldMap) {
        for (auto &action: *actions[index]) {
            action->execute(worldMap);
        }
        actions.push_back(new std::vector<AntAction *>);
        index++;
    }


    void SimulatorSequencer::addAntAction(AntAction *action) {
        actions[index]->push_back(action);
    }

    SimulatorSequencer::SimulatorSequencer() {
        actions.push_back(new std::vector<AntAction *>);
    }

}
// AntSimulator