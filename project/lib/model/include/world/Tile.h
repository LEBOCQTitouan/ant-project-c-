//
// Created by Antoine Guespin on 13/12/2022.
//

#ifndef ANT_SIMULATION_TILE_H
#define ANT_SIMULATION_TILE_H

#include <vector>
#include "object/Object.h"
namespace AntEntities {
    class Ant;
}

namespace AntWorld {
    class Tile {

    private:
        Object *object;
        std::vector<AntEntities::Ant *> antList;
        int x;
        int y;
    public:
        Tile(int x, int y,Object *object);

        Object *getObject();

        void setObject(Object *newObject);

        void addAnt(AntEntities::Ant *pAnt);

        void removeAnt(AntEntities::Ant *ant);

        std::vector<AntEntities::Ant *> getAnt();

        int getX() const;

        void setX(int x);

        int getY() const;

        void setY(int y);

    };
}


#endif //ANT_SIMULATION_TILE_H
