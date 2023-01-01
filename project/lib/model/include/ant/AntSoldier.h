//
// Created by Antoine Guespin on 14/12/2022.
//

#ifndef ANT_SIMULATION_ANTSOLDIER_H
#define ANT_SIMULATION_ANTSOLDIER_H

#include "Ant.h"

namespace AntEntities {

    class AntSoldier: public Ant {
        AntType getAntType() override;
        void update() override;
        std::vector<AntSimulator::AntAction *> * getActionList() override;
    };

} // Ant

#endif //ANT_SIMULATION_ANTSOLDIER_H
