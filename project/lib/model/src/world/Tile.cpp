//
// Created by Antoine Guespin on 13/12/2022.
//

#include <iostream>
#include <algorithm>
#include "../../include/world/Tile.h"

namespace AntWorld {


    Object *Tile::getObject() {
        return object;
    }

    void Tile::setObject(Object *newObject) {
        this->object = newObject;
    }

    Tile::Tile(int x, int y, Object *object) : x(x), y(y),object(object) {

    }


    void Tile::addAnt(AntEntities::Ant *ant) {
        this->antList.push_back(ant);
    }

    void Tile::removeAnt(AntEntities::Ant *ant) {
        std::remove(this->antList.begin(), this->antList.end(), ant);
    }

#include <stdexcept>  }

    int Tile::getX() const {
        return x;
    }

    void Tile::setX(int x) {
        Tile::x = x;
    }

    int Tile::getY() const {
        return y;
    }

    void Tile::setY(int y) {
        Tile::y = y;
    }

    std::vector<AntEntities::Ant *> Tile::getAnt() {
        return antList;
    }
} // AntWorldModel