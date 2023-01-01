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


    int Ant::getX() const {
        return x;
    }

    int Ant::getY() const {
        return y;
    }

    void Ant::setX(int newX) {
        Ant::x = newX;
    }

    void Ant::setY(int newY) {
        Ant::y = newY;
    }


}