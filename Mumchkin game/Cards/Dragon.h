//
// Created by Ruben on 08/06/2022.
//

#ifndef UNTITLED_DRAGON_H
#define UNTITLED_DRAGON_H
#include "Card.h"


class Dragon: public Card{
public:

    void applyEncounter(Player &player, bool gang_checker) const override;

    Dragon();
    Dragon(const Dragon&) = default;
    Dragon& operator=(const Dragon& other) = default;
    ~Dragon() override = default;
    void print(std::ostream& out) const override;

private:
    static const int force=25;
    static const int coins=1000;
    static const int damage=0;

};
#endif //UNTITLED_DRAGON_H