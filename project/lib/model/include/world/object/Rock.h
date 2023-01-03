//
// Created by Antoine Guespin on 13/12/2022.
//

#ifndef ANT_SIMULATION_ROCK_H
#define ANT_SIMULATION_ROCK_H

#include "Object.h"

namespace AntWorld {
    class Rock: public Object {
        ObjectType getObjectType() override;
        int maxAnts() override;
    };
}


#endif //ANT_SIMULATION_ROCK_H
