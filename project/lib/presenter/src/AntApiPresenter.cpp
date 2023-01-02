//
// Created by lebocqt on 30/12/22.
//

#include "../include/AntApiPresenter.h"

AntApiPresenter::AntApiPresenter() {
    sim = new AntSimulator::Simulator();
    sim->initSimulation(new AntWorld::RandomMapFactory);
}

crow::json::wvalue AntApiPresenter::expose() {
    crow::json::wvalue json({
        {"tiles", getJSONRepr()}
    });
    return json;
}

AntApiPresenter& AntApiPresenter::getInstance()
{
    static AntApiPresenter instance;
    return instance;
}

std::string AntApiPresenter::getJSONRepr() {
    std::string tiles = "";
    AntWorld::WorldMap* worldMapTile = sim->getWorldMap();
    for (int x = 0; x < AntWorld::WorldMapRandom::BOARD_HEIGHT; x++) {
        tiles += "[";
        for (int y = 0; y < AntWorld::WorldMapRandom::BOARD_WIDTH; y++) {
            tiles += getJSONRepr(worldMapTile->getTile(x, y));
        }
        tiles += "]";
        if (x != AntWorld::WorldMapRandom::BOARD_HEIGHT - 1) {
            tiles += ",";
        }
    }
    return "[" + tiles + "]";
}

std::string AntApiPresenter::getJSONRepr(AntWorld::Tile *t) {
    switch (t->getObject()->getObjectType()) {
        case AntWorld::ObjectType::ROCK:
            return "{type:0}";
        case AntWorld::ObjectType::COLONY:
            return "{type:1}";
        default:
            return "{type:2}";
    }
}