//
// Created by Antoine Guespin on 13/12/2022.
//

#ifndef ANT_SIMULATION_WORLDMAPRANDOM_H
#define ANT_SIMULATION_WORLDMAPRANDOM_H

#include <vector>
#include "Tile.h"
#include "object/Object.h"
#include "../ant/Ant.h"
#include "WorldMap.h"

namespace AntWorld {

    class WorldMapRandom : public WorldMap {

    public:
        std::vector<AntEntities::Ant *> * getAntList() override;
        Tile *getTile(int x, int y) override;
        void setTiles(Tile ***tiles);

    private:
        Tile ***tiles;

    };

} // AntWorld

#endif //ANT_SIMULATION_WORLDMAPRANDOM_H
