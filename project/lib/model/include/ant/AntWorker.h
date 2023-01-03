//
// Created by Antoine Guespin on 14/12/2022.
//

#ifndef ANT_SIMULATION_ANTWORKER_H
#define ANT_SIMULATION_ANTWORKER_H

#include "Ant.h"

namespace AntEntities {

    class AntWorker: public Ant {
        AntType getAntType() override;
        void update() override;
        std::vector<AntSimulator::AntAction *> * getActionList() override;

        AntWorld::Direction chooseRandomDirection();

        public:
            AntWorker();
    };

} // Ant

#endif //ANT_SIMULATION_ANTWORKER_H
