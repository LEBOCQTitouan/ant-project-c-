#include "../../lib/presenter/include/ApiAntSimulation.h"

namespace std {
    int main(int argc, char const *argv[])
    {
        ApiAntSimulation api = ApiAntSimulation();
        api.expose();
        return 0;
    }
}
