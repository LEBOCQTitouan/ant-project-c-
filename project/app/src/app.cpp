#include <crow.h>

#include "../../lib/presenter/include/AntApiPresenter.h"

int main(int argc, char const *argv[])
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/").methods(crow::HTTPMethod::GET)([]()
     {
         AntApiPresenter& presenter = AntApiPresenter::getInstance();
         return presenter.expose();
     });

    app.port(18080).multithreaded().run();
    return 0;
}
