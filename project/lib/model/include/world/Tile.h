//
// Created by Antoine Guespin on 13/12/2022.
//

#ifndef ANT_SIMULATION_TILE_H
#define ANT_SIMULATION_TILE_H

#include "object/Object.h"

namespace AntWorld {
    class Tile {

    private:
        Object *object;
    public:
        Tile();
        Tile(Object *object);

        Object *getObject();

        void setObject(Object *newObject);
    };
}


#endif //ANT_SIMULATION_TILE_H
