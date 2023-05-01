//
// Created by gigib on 13/06/2022.
//

#ifndef MATAMHW4_VAMPIRE_H
#define MATAMHW4_VAMPIRE_H

#include "Card.h"

class Vampire: public Card{
public:

    void print(std::ostream& out) const override;
    void applyEncounter(Player &player, bool gang_checker) const override;

    Vampire();

    Vampire(const Vampire&) = default;
    Vampire& operator=(const Vampire& other) = default;
    ~Vampire() override = default;

private:
    static const int force=10;
    static const int damage=10;
    static const int coins=2;

};

#endif //MATAMHW4_VAMPIRE_H
