//
// Created by Antoine Guespin on 13/12/2022.
//

#include "../../../include/world/object/Rock.h"
#include "../../../include/world/object/Food.h"

namespace AntWorld {
    ObjectType Food::getObjectType() {
        return ObjectType::FOOD;
    }

    int Food::maxAnts() {
        return 12;
    }
}