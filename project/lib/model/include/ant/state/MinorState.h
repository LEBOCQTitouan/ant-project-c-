//
// Created by Antoine Guespin on 13/12/2022.
//

#ifndef ANT_SIMULATION_MINORSTATE_H
#define ANT_SIMULATION_MINORSTATE_H

#include "AntState.h"

namespace AntState {

    class MinorState  : public AntState {
    public:
        EnumAntState getState() final;
    };

} // AntState

#endif //ANT_SIMULATION_MINORSTATE_H
