//
// Created by Antoine Guespin on 13/12/2022.
//

#include "../../../include/ant/state/MinorState.h"
#include "../../../include/ant/state/AdultState.h"

namespace AntState {
    EnumAntState MinorState::getState() {
        return MINOR;
    }

    void MinorState::update() {
        if(ant->getAge() >= 2) {
            ant->changeState(new AdultState(ant));
        }
    }

    MinorState::MinorState(AntEntities::Ant *ant) : AntState(ant) {}
} // AntState