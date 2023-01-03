//
// Created by Antoine Guespin on 13/12/2022.
//

#ifndef ANT_SIMULATION_TILE_H
#define ANT_SIMULATION_TILE_H

#include <vector>
#include "object/Object.h"
#include "../world/Direction.h"
#include "Pheromone.h"
#include <map>

namespace AntEntities {
    class Ant;
}

namespace AntWorld {
    class Tile {

    private:
        Object *object;
        std::vector<AntEntities::Ant *> antList;
        std::vector<Pheromone *> pheromoneList;
        bool discovered = false;
        int x;
        int y;
    public:
        Tile(int x, int y, Object *object);

        Object *getObject();

        void setObject(Object *newObject);

        void addAnt(AntEntities::Ant *pAnt);

        void removeAnt(AntEntities::Ant *ant);

        std::vector<AntEntities::Ant *> getAnt();

        int getX() const;

        void setX(int x);

        int getY() const;

        void setY(int y);


        const std::vector<Pheromone *> &getPheromoneList() const;

        void addPheromone(Pheromone *pheromone);

        void removePheromone(Pheromone *pheromone);

        bool isDiscovered() const;

    };
}


#endif //ANT_SIMULATION_TILE_H
