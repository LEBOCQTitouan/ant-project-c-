//
// Created by Antoine Guespin on 13/12/2022.
//

#ifndef ANT_SIMULATION_FOOD_H
#define ANT_SIMULATION_FOOD_H

#include "Object.h"

namespace AntWorld {
    class Food : public Object {
        ObjectType getObjectType() override {
            return ObjectType::FOOD;
        }
    };
}


#endif //ANT_SIMULATION_FOOD_H
