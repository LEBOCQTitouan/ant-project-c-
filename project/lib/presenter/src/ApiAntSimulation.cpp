//
// Created by lebocqt on 13/12/22.
//

#include "crow.h"
#include "../include/ApiAntSimulation.h"

void ApiAntSimulation::expose() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });

    app.port(18080).multithreaded().run();
}
