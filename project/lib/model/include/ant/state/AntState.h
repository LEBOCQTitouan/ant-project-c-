//
// Created by Antoine Guespin on 13/12/2022.
//

#ifndef ANT_SIMULATION_ANTSTATE_H
#define ANT_SIMULATION_ANTSTATE_H


namespace AntState {


    typedef enum {
        LARVA,
        MINOR,
        ADULT,
        DEAD,
    } EnumAntState;


    class AntState {
    public:
        virtual EnumAntState getState() = 0;
    };

}

#endif //ANT_SIMULATION_ANTSTATE_H
