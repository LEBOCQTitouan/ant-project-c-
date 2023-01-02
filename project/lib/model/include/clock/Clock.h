//
// Created by Antoine Guespin on 13/12/2022.
//

#ifndef ANT_SIMULATION_CLOCK_H
#define ANT_SIMULATION_CLOCK_H


#include <vector>
#include "TimedElement.h"

namespace AntClock {
    class Clock {
    private:
        Clock() = default;
        std::vector<TimedElement*> timedElements;
        static Clock *clock;
    public:
        void tick();

        void subscribe(TimedElement *timedElement);

        static Clock *getClockInstance();
    };

}


#endif //ANT_SIMULATION_CLOCK_H
