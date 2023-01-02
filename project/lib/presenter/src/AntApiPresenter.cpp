//
// Created by lebocqt on 30/12/22.
//

#include "../include/AntApiPresenter.h"

AntApiPresenter::AntApiPresenter() {
    sim = new AntSimulator::Simulator();
    sim->initSimulation(new AntWorld::RandomMapFactory);
}

crow::json::wvalue AntApiPresenter::expose() {
    crow::json::wvalue json = getJSONRepr();
    sim->turn(); // TODO threading to dynamically refresh
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

crow::json::wvalue AntApiPresenter::getJSONRepr(AntWorld::Tile *t) {
    if (t->getAnt().empty()) {
        crow::json::wvalue tileJSON;

        switch (t->getObject()->getObjectType()) {
            case AntWorld::ObjectType::ROCK:
                tileJSON["type"] = 0;
                break;
            case AntWorld::ObjectType::COLONY:
                tileJSON["type"] = 1;
                break;
            default:
                tileJSON["type"] = 2;
                break;
        }

        return tileJSON;
    }

    std::vector<crow::json::wvalue> ants;
    for (AntEntities::Ant *a: t->getAnt()) {
        ants.push_back(getJSONRepr(a));
    }
    crow::json::wvalue antsFinal = std::move(ants);
    int tileType;
    switch (t->getObject()->getObjectType()) {
        case AntWorld::ObjectType::ROCK:
            tileType = 0;
            break;
        case AntWorld::ObjectType::COLONY:
            tileType = 1;
            break;
        default:
            tileType = 2;
            break;
    }

    crow::json::wvalue tileJSON({{"ants", antsFinal}});
    tileJSON["type"] = tileType;
    return tileJSON;
}

crow::json::wvalue AntApiPresenter::getJSONRepr(AntEntities::Ant *a) {
    crow::json::wvalue ant;
    ant["colony"] = a->getGeneticMarker();
    ant["type"] = a->getAntType();
    return ant;
}