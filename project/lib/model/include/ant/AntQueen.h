//
// Created by Antoine Guespin on 14/12/2022.
//

#ifndef ANT_SIMULATION_ANTQUEEN_H
#define ANT_SIMULATION_ANTQUEEN_H

#include "Ant.h"
#include "../action/AntAction.h"


namespace AntEntities {

    class AntQueen: public Ant {

    private:
        static const int MAX_HP = 100;
        static const int MAX_EP = 100;
        int turnCounter = 0;
    public:
        AntQueen();
        ~AntQueen();
        static char generateGeneticMarker();
        std::vector<AntSimulator::AntAction *> * getActionList() override;
        void update() override;
        AntType getAntType() override;

    };

} // Ant

#endif //ANT_SIMULATION_ANTQUEEN_H
