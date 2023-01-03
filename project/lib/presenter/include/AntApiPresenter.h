//
// Created by lebocqt on 30/12/22.
//

#ifndef ANT_SIMULATION_ANTAPIPRESENTER_H
#define ANT_SIMULATION_ANTAPIPRESENTER_H

#include <string>
#include <crow.h>

#include "../../model/include/Simulator.h"
#include "../../model/include/world/RandomMapFactory.h"

class AntApiPresenter {
public:
    static AntApiPresenter& getInstance();
    crow::json::wvalue expose();

private:
    // singleton
    AntApiPresenter();
    AntApiPresenter(const AntApiPresenter&) = delete;
    AntApiPresenter& operator=(const AntApiPresenter&) = delete;
    std::mutex m;
    // json factory
    std::string makeAntWorldJSON();
    // ant simulation data
    AntSimulator::Simulator *sim;
    crow::json::wvalue getJSONRepr();
    crow::json::wvalue getJSONRepr(AntWorld::Tile *t);
    crow::json::wvalue getJSONRepr(AntEntities::Ant *a);
};


#endif //ANT_SIMULATION_ANTAPIPRESENTER_H
