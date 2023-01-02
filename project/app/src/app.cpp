#include "../../lib/presenter/include/AntApiPresenter.h"

int main(int argc, char const *argv[])
{
    crow::App<>* app = new crow::App<>{};

    CROW_ROUTE((*app), "/")([]()
    {
        AntApiPresenter& presenter = AntApiPresenter::getInstance();
        crow::response response(presenter.expose());
        response.add_header("Access-Control-Allow-Origin", "*");
        response.add_header("Access-Control-Allow-Headers", "Content-Type");
        response.code = 200;

        return response;

    });

    app->port(8080).multithreaded().run();
    return 0;
}
