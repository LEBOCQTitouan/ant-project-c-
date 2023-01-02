//
// Created by Antoine Guespin on 13/12/2022.
//

#ifndef ANT_SIMULATION_DEADSTATE_H
#define ANT_SIMULATION_DEADSTATE_H

#include "../Ant.h"

namespace AntState {

    class DeadState : public AntState  {
    public:
        DeadState(AntEntities::Ant *pAnt);

        EnumAntState getState() final;
        void update() final;

    };

} // AntState

#endif //ANT_SIMULATION_DEADSTATE_H
