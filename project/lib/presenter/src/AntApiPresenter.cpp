//
// Created by lebocqt on 30/12/22.
//

#include "../include/AntApiPresenter.h"

AntApiPresenter::AntApiPresenter() {}

crow::json::wvalue AntApiPresenter::expose() {
    crow::json::wvalue json({
        {"map", "{Tiles:[[{type:'rock'}, {type:'tile', content:[{type:ant}]}], [{type:'tile', content:[{type:food}]}, {type:'tile', content:[{type:food}, {type:ant}]}]]}"}
    });
    // json["message2"] = "Hello, World.. Again!";
    return json;
}

AntApiPresenter& AntApiPresenter::getInstance()
{
    static AntApiPresenter instance;
    return instance;
}

std::string AntApiPresenter::makeAntWorldJSON() {
    std::string json = "{";
    return json + "}";
}
