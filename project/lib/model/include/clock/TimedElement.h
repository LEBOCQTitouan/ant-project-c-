//
// Created by Antoine Guespin on 13/12/2022.
//

#ifndef ANT_SIMULATION_TIMEDELEMENT_H
#define ANT_SIMULATION_TIMEDELEMENT_H

namespace AntClock {
    class TimedElement {
    public:
        virtual void update() = 0;
    };
}


#endif //ANT_SIMULATION_TIMEDELEMENT_H
