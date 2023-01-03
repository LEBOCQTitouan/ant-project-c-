//
// Created by Antoine Guespin on 13/12/2022.
//

#include "../../../include/ant/state/AdultState.h"
#include "../../../include/ant/state/DeadState.h"

namespace AntState {


    EnumAntState AdultState::getState() {
        return EnumAntState::ADULT;
    }

    void AdultState::update() {
        if(ant->getAge() == 100) {
            ant->changeState(new DeadState(ant));
        }
    }

    AdultState::AdultState(AntEntities::Ant *pAnt): AntState(pAnt) {

    }
} // AntState