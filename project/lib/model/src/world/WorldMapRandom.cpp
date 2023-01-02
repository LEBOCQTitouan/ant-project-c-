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
    /**
     * Return the pheromone map of the neighbour tiles (diagonal included) of tile at the given position
     * return only the pheromone if the case is not blocked
     * @param x
     * @param y
     * @return
     */
    std::map<AntWorld::Direction, std::vector<Pheromone *>> WorldMapRandom::getPheromoneMap(int x, int y, bool needToBeDiscovered) {
        std::map<AntWorld::Direction, std::vector<Pheromone *>> pheromoneMap;
        for(int i = -1; i < 2; i++){
            for(int j = -1; j < 2; j++){
                if(i == 0 && j == 0) continue;
                int tileX = x + i;
                int tileY = y + j;
                if(tileX < 0 || tileX >= BOARD_HEIGHT || tileY < 0 || tileY >= BOARD_WIDTH) continue;
                if(needToBeDiscovered && !tiles[tileX][tileY]->isDiscovered()) continue;
                if(tiles[tileX][tileY]->getAnt().size() >= tiles[tileX][tileY]->getObject()->maxAnts()) continue;
                pheromoneMap[AntWorld::getDirectionWithOffset(i,j)] = tiles[tileX][tileY]->getPheromoneList();
            }
        }
        return pheromoneMap;



    }


} // AntWorld