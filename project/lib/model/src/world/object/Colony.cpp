//
// Created by Antoine Guespin on 31/12/2022.
//

#include "../../../include/world/object/Colony.h"

namespace AntWorld {
    ObjectType Colony::getObjectType() {
        return COLONY;
    }

    Colony::~Colony() {
        delete antQueen;
    }

    Colony::Colony(AntEntities::AntQueen *antQueen) : antQueen(antQueen) {}


    Colony::Colony() : antQueen(new AntEntities::AntQueen()) {}
} // AntWorld