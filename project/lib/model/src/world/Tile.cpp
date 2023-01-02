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

    Tile::Tile(int x, int y, Object *object) : x(x), y(y), object(object) {

    }


    void Tile::addAnt(AntEntities::Ant *ant) {
        this->discovered = true;
        this->antList.push_back(ant);
    }

    void Tile::removeAnt(AntEntities::Ant *ant) {
        this->antList.erase(std::remove(this->antList.begin(), this->antList.end(), ant), this->antList.end());
    }


    int Tile::getX() const {
        return x;
    }

    void Tile::setX(int newX) {
        Tile::x = newX;
    }

    int Tile::getY() const {
        return y;
    }

    void Tile::setY(int newY) {
        Tile::y = newY;
    }

    std::vector<AntEntities::Ant *> Tile::getAnt() {
        return antList;
    }

    const std::vector<Pheromone *> &Tile::getPheromoneList() const {
        return pheromoneList;
    }

    void Tile::addPheromone(Pheromone *pheromone) {
        this->pheromoneList.push_back(pheromone);
    }

    void Tile::removePheromone(Pheromone *pheromone) {
        this->pheromoneList.erase(std::remove(this->pheromoneList.begin(), this->pheromoneList.end(), pheromone),
                                  this->pheromoneList.end());
    }

    bool Tile::isDiscovered() const {
        return discovered;
    }


} // AntWorldModel