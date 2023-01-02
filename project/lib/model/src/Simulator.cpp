//
// Created by Antoine Guespin on 01/01/2023.
//

#include "../include/Simulator.h"
#include "../include/world/WorldMapFactory.h"
#include "../include/action/AntAction.h"
#include "../include/ant/Ant.h"
namespace AntSimulator {


    void Simulator::initSimulation(AntWorld::WorldMapFactory *worldMapFactory) {
        worldMap = worldMapFactory->generateMap();



    }

    AntWorld::WorldMap *Simulator::getWorldMap() const {
        return worldMap;
    }

    void Simulator::turn() {
        auto antList = worldMap->getAntList();
        for(auto ant: *antList) {
            for(auto antAction : *ant->getActionList()) {
                sequencer.addAntAction(antAction);
            }
        }

        sequencer.executeActions(worldMap);
        AntClock::Clock::getClockInstance()->tick();


    }
} // AntSimulator