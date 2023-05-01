//
// Created by Ruben on 08/06/2022.
//

#ifndef UNTITLED_TREASURE_H
#define UNTITLED_TREASURE_H
#include "Card.h"


class Treasure: public Card{
public:

    void applyEncounter(Player &player, bool gang_checker) const override;

    Treasure();
    Treasure(const Treasure&) = default;
    Treasure& operator=(const Treasure& other) = default;
    ~Treasure() override = default;

};

#endif //UNTITLED_TREASURE_H