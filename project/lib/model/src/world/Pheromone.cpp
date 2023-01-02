//
// Created by Antoine Guespin on 13/12/2022.
//

#include "../../include/world/Pheromone.h"

namespace AntWorld {


    char Pheromone::getGeneticMarker() {
        return this->geneticMarker;
    }

    int Pheromone::getQuantity() {
        return this->quantity;
    }

    Pheromone::Pheromone(int quantity, char geneticMarker): quantity(quantity), geneticMarker(geneticMarker) {

    }

    void Pheromone::update() {
        this->quantity--;
    }
} // AntWorld