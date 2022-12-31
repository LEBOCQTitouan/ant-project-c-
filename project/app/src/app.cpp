#include <iostream>
#include "../../lib/model/include/ant/Ant.h"
#include "../../lib/model/include/ant/AntQueen.h"
#include "../../lib/model/include/clock/Clock.h"

using namespace AntEntities;
using namespace AntClock;
int main(int argc, char const *argv[])
{
    std::cout<<"Hello world !"<<std::endl;
    AntQueen antQueen;
    Clock *clock = Clock::getClockInstance();

    std::cout<< antQueen.getAge()<<std::endl;
    std::cout<< antQueen.getEP()<<std::endl;

    clock->tick();
    std::cout<< antQueen.getAge()<<std::endl;
    std::cout<< antQueen.getEP()<<std::endl;
    return 0;
}
