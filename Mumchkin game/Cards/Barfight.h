//
// Created by gigib on 09/06/2022.
//

#ifndef MATAMHW4_BARFIGHT_H
#define MATAMHW4_BARFIGHT_H
#include "../utilities.h"
#include "Card.h"

class  Barfight: public Card{
public:

    void applyEncounter(Player &player, bool gang_checker) const override;

    Barfight();
    Barfight(const Barfight&) = default;
    Barfight& operator=(const Barfight& other) = default;
    ~Barfight() override = default;

};




#endif //MATAMHW4_BARFIGHT_H
