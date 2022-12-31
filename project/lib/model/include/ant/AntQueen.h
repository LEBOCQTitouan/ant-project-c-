//
// Created by Antoine Guespin on 14/12/2022.
//

#ifndef ANT_SIMULATION_ANTQUEEN_H
#define ANT_SIMULATION_ANTQUEEN_H

#include "Ant.h"

namespace AntEntities {

    class AntQueen: public Ant {

    private:
        static const int MAX_HP = 100;
        static const int MAX_EP = 100;
    public:
        AntQueen();
        ~AntQueen();
        static char generateGeneticMarker();
        void getAction() override;
        void update() override;
    };

} // Ant

#endif //ANT_SIMULATION_ANTQUEEN_H
