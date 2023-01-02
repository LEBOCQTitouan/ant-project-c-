//
// Created by Antoine Guespin on 14/12/2022.
//

#include <random>
#include "../../include/world/RandomMapFactory.h"
#include "../../include/world/object/Rock.h"
#include "../../include/world/object/Food.h"
#include "../../include/world/object/Colony.h"
#include "../../include/world/object/Void.h"

namespace AntWorld {


    WorldMap *RandomMapFactory::generateMap() {
        auto *worldMapTile = new WorldMapRandom();


        auto **tiles = new Tile **[WorldMapRandom::BOARD_HEIGHT];
        for (int x = 0; x < WorldMapRandom::BOARD_HEIGHT; x++) {
            tiles[x] = new Tile *[WorldMapRandom::BOARD_WIDTH];
            for (int y = 0; y < WorldMapRandom::BOARD_WIDTH; y++) {
                tiles[x][y] = new Tile(x, y, generateObject(x, y));
            }
        }
        worldMapTile->setTiles(tiles);
        auto antQueen = new AntEntities::AntQueen();
        antQueen->setX(WorldMapRandom::BOARD_HEIGHT / 2);
        antQueen->setY(WorldMapRandom::BOARD_WIDTH / 2);
        auto tile = worldMapTile->getTile(WorldMapRandom::BOARD_HEIGHT / 2, WorldMapRandom::BOARD_WIDTH / 2);
        tile->addAnt(antQueen);

        /**    for (int i = 0; i < WorldMapRandom::BOARD_HEIGHT * WorldMapRandom::BOARD_HEIGHT * 0.3; i++) {
                int x;
                int y;
                do {
                    x = getRandomX();
                    y = getRandomY();
                } while (worldMapTile->getTile(x, y)->getObject()->getObjectType() != ObjectType::VOID);
                worldMapTile->getTile(x, y)->setObject(new Rock());
            }
            for (int i = 0; i < WorldMapRandom::BOARD_HEIGHT * WorldMapRandom::BOARD_HEIGHT * 0.002; i++) {
                int x;
                int y;
                do {
                    x = getRandomX();
                    y = getRandomY();
                } while (worldMapTile->getTile(x, y)->getObject()->getObjectType() != ObjectType::VOID);
                worldMapTile->getTile(x, y)->setObject(new Food());
            }**/
        return worldMapTile;
    }

    /**
     * Retourn objet correspondant pour que la map soit générée comme ceci :
     * Les obstacles représentent 30 % de la surface totale et sont placés aléatoirement.
     * 50 % de ces obstacles sont des obstacles d’une case, 30 % des obstacles de deux cases voisines, 10 % des obstacles de trois cases voisines,
     * 5 % des obstacles de quatre cases voisines, 4 % des obstacles de cinq cases voisines et 1 % des obstacles de six cases voisines.
     * Obstacle = Rock()
     * Nourriture = Food()
     * @return
     */
    Object *RandomMapFactory::generateObject(int x, int y) {
        if (x == WorldMapRandom::BOARD_HEIGHT && y == WorldMapRandom::BOARD_WIDTH) {
            return new Colony();
        }

        int random = getRandom(0, 100);
        if (random < 30) {
            return new Rock();
        } else if (random < 32) {
            return new Food();
        } else {
            return new Void();
        }
    }

    int RandomMapFactory::getRandom(int inf, int sup) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(inf, sup);
        return dis(gen);
    }


}
