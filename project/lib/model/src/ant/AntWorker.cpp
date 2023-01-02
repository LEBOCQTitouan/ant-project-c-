//
// Created by Antoine Guespin on 14/12/2022.
//

#include "../../include/ant/AntWorker.h"
#include <random>
#include "../../include/action/Move.h"
#include "../../include/clock/Clock.h"
#include "../../include/ant/state/MinorState.h"
#include <stdexcept>

namespace AntEntities {

    AntType AntWorker::getAntType() {
        return AntType::WORKER;
    }

    void AntWorker::update() {
        this->age++;
        this->ep--;
    }

    std::vector<AntSimulator::AntAction *> *AntWorker::getActionList() {
        auto *actionList = new std::vector<AntSimulator::AntAction *>();
        if (antState->getState() == AntState::MINOR) {
            return actionList;
        }
        // Ant Search Food
        try {
            auto move = new AntSimulator::Move(this, chooseRandomDirection());
            actionList->push_back(move);
            moveList.push_back(move);
            return actionList;
        } catch (std::exception &e) {
            return actionList;
        }


    }

    AntWorld::Direction AntWorker::chooseRandomDirection() {

        if(this->pheromoneMap.empty()) {
            throw std::runtime_error("No pheromone map");
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(0, this->pheromoneMap.size() - 1);

        auto it = pheromoneMap.begin();
        std::advance(it, dist(gen));
        return it->first;
    }


    AntWorker::AntWorker() {
        AntClock::Clock::getClockInstance()->subscribe(this);
        this->changeState(new AntState::MinorState(this));
    }

} // Ant