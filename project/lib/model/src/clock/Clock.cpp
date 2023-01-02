//
// Created by Antoine Guespin on 13/12/2022.
//

#include "../../include/clock/Clock.h"

namespace AntClock {
    Clock *Clock::clock = nullptr;

    void Clock::tick() {
        for (auto timedElement: timedElements) {
            timedElement->update();
        }
    }

    void Clock::subscribe(TimedElement *timedElement) {
        this->timedElements.push_back(timedElement);
    }


    Clock *Clock::getClockInstance() {
        if (clock == nullptr) {
            clock = new Clock;
        }
        return clock;
    }


}

