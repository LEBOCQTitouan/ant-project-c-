//
// Created by lebocqt on 30/12/22.
//

#ifndef ANT_SIMULATION_ANTAPIPRESENTER_H
#define ANT_SIMULATION_ANTAPIPRESENTER_H

#include <string>
#include <crow.h>

class AntApiPresenter {
public:
    static AntApiPresenter& getInstance();
    crow::json::wvalue expose();

private:
    // singleton
    AntApiPresenter();
    AntApiPresenter(const AntApiPresenter&) = delete;
    AntApiPresenter& operator=(const AntApiPresenter&) = delete;
    // json factory
    std::string makeAntWorldJSON();
};


#endif //ANT_SIMULATION_ANTAPIPRESENTER_H
