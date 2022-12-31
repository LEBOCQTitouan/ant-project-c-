//
// Created by Antoine Guespin on 31/12/2022.
//

#ifndef ANT_SIMULATION_COLONY_H
#define ANT_SIMULATION_COLONY_H

#include "Object.h"
#include "../../ant/AntQueen.h"

namespace AntWorld {

    class Colony: public Object {
    private:
        AntEntities::AntQueen *antQueen;

    public:
        Colony(AntEntities::AntQueen *antQueen);
        Colony();

        virtual ~Colony();

        ObjectType getObjectType() override;
    };

} // AntWorld

#endif //ANT_SIMULATION_COLONY_H
