//
// Created by Antoine Guespin on 14/12/2022.
//

#include <stdexcept>
#include <random>
#include "../../include/ant/AntScout.h"
#include "../../include/ant/state/MinorState.h"
#include "../../include/action/Move.h"
#include "../../include/clock/Clock.h"

namespace AntEntities {


    AntType AntScout::getAntType() {
        return AntType::SCOUT;
    }

    void AntScout::update() {
        this->age++;
        this->ep--;
        antState->update();
    }


    /**
     * Les éclaireurs sont des ouvrières spécialisées qui ne restent « mineures » que les deux premiers jours de leur vie.
     * Elles explorent alors de nouvelles cases autour de la colonie en se déplaçant au hasard.
     * Les soldats et les ouvrières ne peuvent pas pénétrer dans un territoire inexploré à moins qu’un éclaireur ne l’ait préalablement exploré.
     * @return
     */
    std::vector<AntSimulator::AntAction *> *AntScout::getActionList() {
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

    AntWorld::Direction AntScout::chooseRandomDirection() {

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

    AntScout::AntScout() {
        AntClock::Clock::getClockInstance()->subscribe(this);
        this->changeState(new AntState::MinorState(this));
    }


} // Ant