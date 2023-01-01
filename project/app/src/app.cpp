#include <iostream>
#include "../../lib/model/include/ant/Ant.h"
#include "../../lib/model/include/ant/AntQueen.h"
#include "../../lib/model/include/clock/Clock.h"
#include "../../lib/model/include/world/WorldMapRandom.h"
#include "../../lib/model/include/world/RandomMapFactory.h"
#include "../../lib/model/include/Simulator.h"

using namespace AntWorld;

void displayAntNB(const AntSimulator::Simulator &sim) {
    std::cout << "NOMBRE DE PETIT ARNAUUDDD TROP KAWAI <3 :" << sim.getWorldMap()->getAntList()->size() << std::endl;
}

void displayMap(const AntSimulator::Simulator &sim) {
    auto worldMapTile = sim.getWorldMap();
    for (int x = 0; x < WorldMapRandom::BOARD_HEIGHT; x++) {
        for (int y = 0; y < WorldMapRandom::BOARD_WIDTH; y++) {
            switch (worldMapTile->getTile(x, y)->getObject()->getObjectType()) {
                case ObjectType::VOID:
                    std::cout << " ";
                    break;
                case ObjectType::ROCK:
                    std::cout << "#";
                    break;
                case ObjectType::COLONY:
                    std::cout << "C";
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
}

int main(int argc, char const *argv[]) {


    auto *simulator = new AntSimulator::Simulator();
    simulator->initSimulation(new AntWorld::RandomMapFactory);
    displayMap(*simulator);
    displayAntNB(*simulator);
    for(int i = 0; i < 200; i++) {
        simulator->turn();
        displayAntNB(*simulator);
    }

    return 0;
}
