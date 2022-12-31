//
// Created by Antoine Guespin on 13/12/2022.
//

#ifndef ANT_SIMULATION_ANT_H
#define ANT_SIMULATION_ANT_H

#include "state/AntState.h"
#include "../clock/TimedElement.h"

namespace AntEntities {
    class Ant : public AntClock::TimedElement {
    protected:
        char geneticMarker;
        AntState::AntState *antState;
        int hp; // Health Point
        int ep; // Eat Point
        int age = 0;
    public:
        void changeState(AntState::AntState *newState);

        int getHP() const;

        int getAge() const;

        int getEP() const;

        char getGeneticMarker() const;

        virtual void getAction() = 0;
    };
}


#endif //ANT_SIMULATION_ANT_H
