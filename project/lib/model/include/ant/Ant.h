//
// Created by Antoine Guespin on 13/12/2022.
//

#ifndef ANT_SIMULATION_ANT_H
#define ANT_SIMULATION_ANT_H

#include "../clock/TimedElement.h"
#include "../world/Pheromone.h"
#include "../world/WorldMap.h"

#include <map>

namespace AntState {


    typedef enum {
        LARVA,
        MINOR,
        ADULT,
        DEAD,
    } EnumAntState;


    class AntState {
    protected:
        AntEntities::Ant *ant;
    public:
        AntState(AntEntities::Ant *ant) : ant(ant) {}

        virtual EnumAntState getState() = 0;

        virtual void update() = 0;

    };

}


namespace AntSimulator {
    class AntAction;
    class Move;
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
        std::map<AntWorld::Direction, std::vector<AntWorld::Pheromone *>> pheromoneMap;
        std::vector<AntSimulator::Move *> moveList;
        int x;
        int y;
    public:
        void changeState(AntState::AntState *newState);

        int getHP() const;

        int getAge() const;

        int getEP() const;

        char getGeneticMarker() const;

        virtual std::vector<AntSimulator::AntAction *> *getActionList() = 0;

        void setX(int x);

        void setY(int y);

        int getX() const;

        int getY() const;

        virtual AntType getAntType() = 0;

        void setPheromoneMap(std::map<AntWorld::Direction, std::vector<AntWorld::Pheromone *>> newPheromoneMap);
    };

}


#endif //ANT_SIMULATION_ANT_H
