//
// Created by Antoine Guespin on 31/12/2022.
//

#include "../../../include/world/object/Colony.h"

namespace AntWorld {
    ObjectType Colony::getObjectType() {
        return COLONY;
    }

    int Colony::maxAnts() {
        return 100;
    }

} // AntWorld