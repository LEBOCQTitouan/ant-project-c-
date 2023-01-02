//
// Created by Antoine Guespin on 31/12/2022.
//

#ifndef ANT_SIMULATION_VOID_H
#define ANT_SIMULATION_VOID_H

#include "Object.h"

namespace AntWorld {

    class Void: public Object {
        ObjectType getObjectType() override;
    };

} // AntWorld

#endif //ANT_SIMULATION_VOID_H
