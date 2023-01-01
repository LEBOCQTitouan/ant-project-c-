//
// Created by Antoine Guespin on 13/12/2022.
//

#ifndef ANT_SIMULATION_ANT_H
#define ANT_SIMULATION_ANT_H

#include "state/AntState.h"
#include "../clock/TimedElement.h"
#include "../world/Pheromone.h"
#include "../world/WorldMap.h"

#include <map>


namespace AntSimulator {
    class AntAction;
}
namespace AntEntities {


    typedef enum {
        QUEEN,
        WORKER,
        SOLDIER,
        SCOUT,
    } AntType;


    class Ant : public AntClock::TimedElement {
    protected:
        char geneticMarker;
        AntState::AntState *antState;
        int hp; // Health Point
        int ep; // Eat Point
        int age = 0;
        std::map<AntWorld::Direction, AntWorld::Pheromone> pheromoneList;
        int x;
        int y;
    public:
        void changeState(AntState::AntState *newState);

        int getHP() const;

        int getAge() const;

        int getEP() const;

        char getGeneticMarker() const;

        virtual std::vector<AntSimulator::AntAction *> * getActionList() = 0;

        void setX(int x);

        void setY(int y);

        int getX() const;

        int getY() const;

        virtual AntType getAntType() = 0;
    };

}


#endif //ANT_SIMULATION_ANT_H
