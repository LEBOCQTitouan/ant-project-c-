//
// Created by Antoine Guespin on 01/01/2023.
//

#include "../../include/action/Procreate.h"
#include "../../include/ant/AntWorker.h"
#include "../../include/ant/AntScout.h"
#include "../../include/ant/AntSoldier.h"

namespace AntSimulator {

    Procreate::Procreate(AntEntities::AntQueen *antQueen, AntEntities::AntType antType) : antQueen(antQueen),
                                                                                          antType(antType) {}


    void Procreate::execute(AntWorld::WorldMap *worldMap) {
        AntEntities::Ant *ant = nullptr;
        switch (antType) {
            case AntEntities::AntType::WORKER:
                ant = new AntEntities::AntWorker();
                break;
            case AntEntities::AntType::SCOUT:
                ant = new AntEntities::AntScout();
                break;
            case AntEntities::AntType::SOLDIER:
                ant = new AntEntities::AntSoldier();
                break;
            case AntEntities::QUEEN:
                throw std::invalid_argument("Cannot procreate a queen");
        }
        ant->setX(antQueen->getX());
        ant->setY(antQueen->getY());
        ant->setPheromoneMap(
                worldMap->getPheromoneMap(ant->getX(), ant->getY(), ant->getAntType() != AntEntities::AntType::SCOUT));
        worldMap->getTile(antQueen->getX(), antQueen->getY())->addAnt(ant);
    }

} // AntSimulator