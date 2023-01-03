//
// Created by Antoine Guespin on 13/12/2022.
//

#include "../../../include/ant/state/DeadState.h"

namespace AntState {
    EnumAntState DeadState::getState() {
        return DEAD;
    }

    void DeadState::update() {

    }

    DeadState::DeadState(AntEntities::Ant *pAnt) : AntState(pAnt) {

    }
} // AntState