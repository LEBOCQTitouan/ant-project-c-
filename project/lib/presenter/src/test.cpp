#include "../include/test.hpp"
#include "crow.h"

void test() {


    crow::SimpleApp app; //define your crow application

    //define your endpoint at the root directory
    CROW_ROUTE(app, "/")([](){
        crow::json::wvalue x;
        x["message"] = "Hello, WorldMapRandom!";
        x["value"][0] = "Value 0";
        x["value"][1] = "Value 1";
        return x;


    });

    //set the port, set the app to run on multiple threads, and run the app
    app.port(18080).run();

}