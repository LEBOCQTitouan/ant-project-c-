//
// Created by Antoine Guespin on 14/12/2022.
//

#include "../../include/ant/AntScout.h"

namespace AntEntities {


    AntType AntScout::getAntType() {
        return AntType::SCOUT;
    }

    void AntScout::update() {
        this->age++;
        this->ep--;
    }

    std::vector<AntSimulator::AntAction *> * AntScout::getActionList() {
        return nullptr;
    }


} // Ant