//
// Created by Antoine Guespin on 13/12/2022.
//

#include <iostream>
#include "../../include/world/Tile.h"
#include "../../include/world/object/Void.h"

namespace AntWorld {


    Object *Tile::getObject() {
        return object;
    }

    void Tile::setObject(Object *newObject) {
        this->object = newObject;
    }

    Tile::Tile(Object *object) : object(object) {

    }

    Tile::Tile() : object(new Void()) {

    }
} // AntWorldModel