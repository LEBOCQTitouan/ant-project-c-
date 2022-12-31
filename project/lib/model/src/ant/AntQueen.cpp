//
// Created by Antoine Guespin on 14/12/2022.
//

#include "../../include/ant/AntQueen.h"
#include "../../include/clock/Clock.h"
#include <random>

namespace AntEntities {
    AntQueen::AntQueen() {
        this->geneticMarker = generateGeneticMarker();
        this->hp = MAX_HP;
        this->ep = MAX_EP;
        this->age = 0;
        AntClock::Clock::getClockInstance()->subscribe(this);
    }

    AntQueen::~AntQueen() {
//        AntClock::Clock::getClockInstance()->subscribe(this);
    }

    char AntQueen::generateGeneticMarker() {
        std::mt19937 mt(time(nullptr));
        return (char)(mt()%CHAR_MAX);
    }

    void AntQueen::getAction() {

    }

    void AntQueen::update() {
        this->age++;
        this->ep--;
    }
} // Ant