//
// Created by Antoine Guespin on 01/01/2023.
//

#ifndef ANT_SIMULATION_PROCREATE_H
#define ANT_SIMULATION_PROCREATE_H

#include <stdexcept>

#include "AntAction.h"
#include "../ant/AntQueen.h"

namespace AntSimulator {
    class Procreate : public AntAction {
    private:
        AntEntities::AntQueen *antQueen;
        AntEntities::AntType antType;

    public:
        Procreate(AntEntities::AntQueen *antQueen, AntEntities::AntType antType);

        void execute(AntWorld::WorldMap *worldMap) override;
    };

}


#endif //ANT_SIMULATION_PROCREATE_H
