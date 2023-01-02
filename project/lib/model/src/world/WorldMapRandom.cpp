//
// Created by Antoine Guespin on 13/12/2022.
//

#include "../../include/world/WorldMapRandom.h"

namespace AntWorld {

    Tile* WorldMapRandom::getTile(int x, int y) {
        return tiles[x][y];
    }


    std::vector<AntEntities::Ant *> * WorldMapRandom::getAntList() {
        auto *antList = new std::vector<AntEntities::Ant *>();
        for(int x = 0; x < BOARD_HEIGHT; x++){
            for(int y = 0; y < BOARD_WIDTH; y++){
               for(auto ant : tiles[x][y]->getAnt()) {
                     antList->push_back(ant);
               }
            }
        }

        return antList;
    }

    void WorldMapRandom::setTiles(Tile ***tiles) {
        this->tiles = tiles;
    }


} // AntWorld