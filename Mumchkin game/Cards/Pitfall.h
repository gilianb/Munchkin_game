//
// Created by gigib on 09/06/2022.
//

#ifndef MATAMHW4_PITFALL_H
#define MATAMHW4_PITFALL_H

#include "../utilities.h"
#include "Card.h"

class  Pitfall: public Card{
public:

    void applyEncounter(Player &player, bool gang_checker) const override;

    Pitfall();
    Pitfall(const Pitfall&) = default;
    Pitfall& operator=(const Pitfall& other) = default;
    ~Pitfall() override = default;

};


#endif //MATAMHW4_PITFALL_H
