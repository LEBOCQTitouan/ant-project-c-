//
// Created by Antoine Guespin on 13/12/2022.
//

#include "../../include/world/WorldMapTile.h"

namespace AntWorld {

    Tile* WorldMapTile::getTile(int x, int y) {
        return &tiles[x][y];
    }
} // AntWorld