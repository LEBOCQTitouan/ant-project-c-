//
// Created by Antoine Guespin on 14/12/2022.
//

#include "../../include/ant/AntSoldier.h"

namespace AntEntities {


    AntType AntSoldier::getAntType() {
        return AntType::SOLDIER;
    }


    void AntSoldier::update() {
        this->age++;
        this->ep--;
    }

    /**
     * Les éclaireurs sont des ouvrières spécialisées qui ne restent « mineures » que les deux premiers jours de leur vie. Elles explorent alors de nouvelles cases autour de la colonie en se déplaçant au hasard. Les soldats et les ouvrières ne peuvent pas pénétrer dans un territoire inexploré à moins qu’un éclaireur ne l’ait préalablement exploré.
     * @return
     */
    std::vector<AntSimulator::AntAction *> * AntSoldier::getActionList() {
        return nullptr;
    }


} // Ant