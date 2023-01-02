//
// Created by Antoine Guespin on 13/12/2022.
//

#ifndef ANT_SIMULATION_PHEROMONE_H
#define ANT_SIMULATION_PHEROMONE_H

#include "../clock/TimedElement.h"

namespace AntWorld {

class Pheromone: public AntClock::TimedElement {
    private:
        int quantity;
        char geneticMarker;
    public:
        Pheromone(int quantity, char geneticMarker);
        int getQuantity();
        char getGeneticMarker();
        void update() override;
    };

} // AntWorld

#endif //ANT_SIMULATION_PHEROMONE_H
