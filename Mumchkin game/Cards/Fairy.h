//
// Created by gigib on 09/06/2022.
//

#ifndef MATAMHW4_FAIRY_H
#define MATAMHW4_FAIRY_H

#include "../utilities.h"
#include "Card.h"

class  Fairy: public Card{
public:

    void applyEncounter(Player &player, bool gang_checker) const override;

    Fairy();
    Fairy(const Fairy&) = default;
    Fairy& operator=(const Fairy& other) = default;
    ~Fairy() override = default;

};



#endif //MATAMHW4_FAIRY_H
