#include "../../lib/presenter/include/AntApiPresenter.h"

int main(int argc, char const *argv[])
{
    crow::App<>* app = new crow::App<>{};

    CROW_ROUTE((*app), "/")([]()
    {
        AntApiPresenter& presenter = AntApiPresenter::getInstance();
        crow::response response(presenter.expose());

        response.code = 200;

        return response;

    });

    app->port(18080).multithreaded().run();
    return 0;
}
