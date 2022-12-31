#include <iostream>
#include "../../lib/model/include/ant/Ant.h"
#include "../../lib/model/include/ant/AntQueen.h"
#include "../../lib/model/include/clock/Clock.h"
#include "../../lib/model/include/world/WorldMapTile.h"
#include "../../lib/model/include/world/RandomMapFactory.h"

using namespace AntEntities;
using namespace AntClock;
using namespace AntWorld;

int main(int argc, char const *argv[]) {
    std::cout << "Hello world !" << std::endl;
    AntQueen antQueen;
    Clock *clock = Clock::getClockInstance();

    std::cout << antQueen.getAge() << std::endl;
    std::cout << antQueen.getEP() << std::endl;

    clock->tick();
    std::cout << antQueen.getAge() << std::endl;
    std::cout << antQueen.getEP() << std::endl;

    RandomMapFactory randomMapFactory;

    WorldMapTile *worldMapTile = randomMapFactory.generateMap();
    for (int x = 0; x < WorldMapTile::BOARD_HEIGHT; x++) {
        for (int y = 0; y < WorldMapTile::BOARD_WIDTH; y++) {
            switch (worldMapTile->getTile(x, y)->getObject()->getObjectType()) {
                case ObjectType::VOID:
                    std::cout << " ";
                    break;
                case ObjectType::ROCK:
                    std::cout << "#";
                    break;
                case ObjectType::FOOD:
                    std::cout << "F";
                    break;
                default:
                    std::cout << "a";
                    break;
            }

        }
        std::cout << std::endl;
    }
    return 0;
}
