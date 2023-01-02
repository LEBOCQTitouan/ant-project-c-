//
// Created by Antoine Guespin on 01/01/2023.
//

#ifndef ANT_SIMULATION_MOVE_H
#define ANT_SIMULATION_MOVE_H
#include "AntAction.h"
#include "../ant/Ant.h"
#include "../world/Direction.h"


namespace AntSimulator {

    class Move : public AntAction {

    private:
        AntWorld::Direction direction;
        AntEntities::Ant *ant;
        static AntWorld::Direction getOppositeDirection(AntWorld::Direction direction);

    public:
        Move(AntEntities::Ant *ant, AntWorld::Direction direction);
        void execute(AntWorld::WorldMap *worldMap) override;
        Move getOppositeAction();

    };
}


#endif //ANT_SIMULATION_MOVE_H
