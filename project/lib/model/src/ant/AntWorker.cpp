//
// Created by Antoine Guespin on 14/12/2022.
//

#include "../../include/ant/AntWorker.h"

namespace AntEntities {

    AntType AntWorker::getAntType() {
        return AntType::WORKER;
    }

    void AntWorker::update() {
        this->age++;
        this->ep--;
    }

    std::vector<AntSimulator::AntAction *> * AntWorker::getActionList() {
        return nullptr;
    }

} // Ant