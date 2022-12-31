//
// Created by Antoine Guespin on 13/12/2022.
//

#include <iostream>
#include "../../include/ant/Ant.h"

namespace AntEntities {


    void Ant::changeState(AntState::AntState *newState) {
        this->antState = newState;
    }

    int Ant::getHP() const {
        return hp;
    }

    int Ant::getAge() const {
        return age;
    }

    int Ant::getEP() const {
        return ep;
    }

    char Ant::getGeneticMarker() const {
        return geneticMarker;
    }

}