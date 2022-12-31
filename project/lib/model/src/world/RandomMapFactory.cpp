//
// Created by Antoine Guespin on 14/12/2022.
//

#include <random>
#include <iostream>
#include "../../include/world/RandomMapFactory.h"
#include "../../include/world/object/Rock.h"
#include "../../include/world/object/Food.h"

namespace AntWorld {


    WorldMapTile *RandomMapFactory::generateMap() {
        auto *worldMapTile = new WorldMapTile();
        for (int i = 0; i < WorldMapTile::BOARD_HEIGHT * WorldMapTile::BOARD_HEIGHT * 0.3; i++) {
            int x;
            int y;
            do {
                x = getRandomX();
                y = getRandomY();
            } while (worldMapTile->getTile(x, y)->getObject()->getObjectType() != ObjectType::VOID);
            worldMapTile->getTile(x, y)->setObject(new Rock());
        }
        for (int i = 0; i < WorldMapTile::BOARD_HEIGHT * WorldMapTile::BOARD_HEIGHT * 0.002; i++) {
            int x;
            int y;
            do {
                x = getRandomX();
                y = getRandomY();
            } while (worldMapTile->getTile(x, y)->getObject()->getObjectType() != ObjectType::VOID);
            worldMapTile->getTile(x, y)->setObject(new Food());
        }
        return worldMapTile;
    }




    int RandomMapFactory::getRandomX() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, WorldMapTile::BOARD_HEIGHT - 1);
        return dis(gen);
    }

    int RandomMapFactory::getRandomY() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, WorldMapTile::BOARD_WIDTH - 1);
        return dis(gen);
    }

}
