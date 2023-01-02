//
// Created by Antoine Guespin on 01/01/2023.
//

#include "../../include/action/Move.h"
#include "../../include/world/Direction.h"

namespace AntSimulator {
    void Move::execute(AntWorld::WorldMap *worldMap) {
        int newX = ant->getX();
        int newY = ant->getY();
        switch (direction) {
            case AntWorld::Direction::NORTH:
                newX--;
                break;
            case AntWorld::Direction::EAST:
                newY++;
                break;
            case AntWorld::Direction::SOUTH:
                newX++;
                break;
            case AntWorld::Direction::WEST:
                newY--;
                break;
            case AntWorld::NORTH_EAST:
                newX--;
                newY++;
                break;
            case AntWorld::SOUTH_EAST:
                newX++;
                newY++;
                break;
            case AntWorld::SOUTH_WEST:
                newX++;
                newY--;
                break;
            case AntWorld::NORTH_WEST:
                newX--;
                newY--;
                break;
        }
        AntWorld::Tile *oldTile = worldMap->getTile(ant->getX(),ant->getY());
        AntWorld::Tile *newTile = worldMap->getTile(newX,newY);
        oldTile->removeAnt(ant);
        ant->setX(newX);
        ant->setY(newY);
        ant->setPheromoneMap(worldMap->getPheromoneMap(newTile->getX(), newTile->getY(), ant->getAntType() != AntEntities::AntType::SCOUT));
        newTile->addAnt(ant);
    }

    Move::Move(AntEntities::Ant *ant, AntWorld::Direction direction) : ant(ant),
                                                                          direction(direction) {}

    Move Move::getOppositeAction() {
        return {ant, getOppositeDirection(direction)};
    }


    AntWorld::Direction Move::getOppositeDirection(AntWorld::Direction direction) {
        return (AntWorld::Direction) ((direction + 4) % 8);
    }

}


