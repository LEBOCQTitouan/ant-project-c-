//
// Created by lebocqt on 30/12/22.
//

#include "../include/AntApiPresenter.h"

AntApiPresenter::AntApiPresenter() {
    sim = new AntSimulator::Simulator();
    sim->initSimulation(new AntWorld::RandomMapFactory);
}

crow::json::wvalue AntApiPresenter::expose() {
    m.lock();
    crow::json::wvalue json = getJSONRepr();
    sim->turn(); // TODO threading to dynamically refresh
    m.unlock();
    return json;
}

crow::json::wvalue AntApiPresenter::exposeStats() {
    m.lock();
    std::map<AntEntities::AntType, int> stats;
    for (auto ant : *sim->getWorldMap()->getAntList()) {
        if (stats.find(ant->getAntType()) == stats.end()) {
            stats.insert({ant->getAntType(), 1});
        } else {
            std::map<AntEntities::AntType , int>::iterator it = stats.find(ant->getAntType());
            if (it != stats.end())
                it->second++;
        }
    }
    m.unlock();
    crow::json::wvalue json = {};
    std::map<AntEntities::AntType, int>::iterator it;
    for (it = stats.begin(); it != stats.end(); it++)
    {
        std::string key = "";
        switch (it->first) {
            case AntEntities::QUEEN:
                key += "QUEEN";
                break;
            case AntEntities::WORKER:
                key += "WORKER";
                break;
            case AntEntities::SOLDIER:
                key += "SOLDIER";
                break;
            case AntEntities::SCOUT:
                key += "SCOUT";
                break;
        }
        json[key] = it->second;
    }
    return json;
}

AntApiPresenter& AntApiPresenter::getInstance()
{
    static AntApiPresenter instance;
    return instance;
}

crow::json::wvalue AntApiPresenter::getJSONRepr() {
    std::vector<crow::json::wvalue> tilesArray;

    AntWorld::WorldMap* worldMapTile = sim->getWorldMap();
    for (int x = 0; x < AntWorld::WorldMapRandom::BOARD_HEIGHT; x++) {
        std::vector<crow::json::wvalue> tilesCol = {};
        for (int y = 0; y < AntWorld::WorldMapRandom::BOARD_WIDTH; y++) {
            tilesCol.push_back(getJSONRepr(worldMapTile->getTile(x, y)));
        }
        crow::json::wvalue tilesColFinal = std::move(tilesCol);
        tilesArray.push_back(tilesColFinal);
    }

    crow::json::wvalue tilesFinal = std::move(tilesArray);
    crow::json::wvalue tiles({{"tiles", tilesFinal}});
    return tiles;
}

/**
 * This function is a bit weird by its shape and need to double the type attribution because of the array json conversion
 * @param t
 * @return
 */
crow::json::wvalue AntApiPresenter::getJSONRepr(AntWorld::Tile *t) {
    if (t->getAnt().empty()) {
        crow::json::wvalue tileJSON;
        tileJSON["type"] = t->getObject()->getObjectType();
        tileJSON["discovered"] = t->isDiscovered();
        return tileJSON;
    }

    std::vector<crow::json::wvalue> ants;
    for (AntEntities::Ant *a: t->getAnt()) {
        ants.push_back(getJSONRepr(a));
    }
    crow::json::wvalue antsFinal = std::move(ants);

    crow::json::wvalue tileJSON({{"ants", antsFinal}});
    tileJSON["type"] = t->getObject()->getObjectType();
    tileJSON["discovered"] = t->isDiscovered();
    return tileJSON;
}

crow::json::wvalue AntApiPresenter::getJSONRepr(AntEntities::Ant *a) {
    crow::json::wvalue ant;
    ant["colony"] = a->getGeneticMarker();
    ant["type"] = a->getAntType();
    return ant;
}