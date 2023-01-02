//
// Created by Antoine Guespin on 13/12/2022.
//

#include "../../../include/world/object/Rock.h"
#include "../../../include/world/object/Void.h"

namespace AntWorld {
    ObjectType Void::getObjectType() {
        return ObjectType::VOID;
    }
}