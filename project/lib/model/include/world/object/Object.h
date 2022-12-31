//
// Created by Antoine Guespin on 13/12/2022.
//

#ifndef ANT_SIMULATION_OBJECT_H
#define ANT_SIMULATION_OBJECT_H


namespace AntWorld {
    typedef enum {
        ROCK,
        FOOD,
        VOID,
        COLONY
    } ObjectType;

    class Object {
    public:
        virtual ObjectType getObjectType() = 0;
    };

}
#endif //ANT_SIMULATION_OBJECT_H
