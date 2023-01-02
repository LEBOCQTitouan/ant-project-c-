//
// Created by Antoine Guespin on 14/12/2022.
//

#include "../../include/ant/AntQueen.h"
#include "../../include/clock/Clock.h"
#include "../../include/action/Procreate.h"
#include "../../include/ant/state/AdultState.h"

namespace AntEntities {
    AntQueen::AntQueen() {
        this->geneticMarker = generateGeneticMarker();
        this->hp = MAX_HP;
        this->ep = MAX_EP;
        this->age = 0;
        this->antState = new AntState::AdultState(this);
        AntClock::Clock::getClockInstance()->subscribe(this);
    }

    AntQueen::~AntQueen() {
//        AntClock::Clock::getClockInstance()->subscribe(this);
    }

    char AntQueen::generateGeneticMarker() {
        std::mt19937 mt(time(nullptr));
        return (char) (mt() % CHAR_MAX);
    }


    std::vector<AntSimulator::AntAction *> *AntQueen::getActionList() {
        auto *actionList = new std::vector<AntSimulator::AntAction *>();
        turnCounter++;
        if (turnCounter % 12 == 0) {
            return actionList;
        }
        if (age == 0) {
            actionList->push_back(new AntSimulator::Procreate(this, AntType::SCOUT));
            return actionList;
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(0, 100);

        AntType antType;
        int random = dist(gen);
        if (random < 80) {
            antType = AntType::WORKER;
        } else if (random < 95) {
            antType = AntType::SCOUT;
        } else {
            antType = AntType::SOLDIER;
        }
        actionList->push_back(new AntSimulator::Procreate(this, antType));
        return actionList;
    }


    void AntQueen::update() {
        this->age++;
        antState->update();
    }

    AntType AntQueen::getAntType() {
        return AntType::QUEEN;
    }

} // Ant