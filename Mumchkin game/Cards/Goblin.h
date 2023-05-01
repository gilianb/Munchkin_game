//
// Created by Ruben on 08/06/2022.
//

#ifndef UNTITLED_GOBLIN_H
#define UNTITLED_GOBLIN_H
#include "Card.h"


class Goblin: public Card{
public:

    void print(std::ostream& out) const override;
    void applyEncounter(Player &player, bool gang_checker) const override;

    Goblin();
    Goblin(const Goblin&) = default;
    Goblin& operator=(const Goblin& other) = default;
    ~Goblin() override = default;

private:
    static const int force=6;
    static const int coins=2;
    static const int damage=10;

};



#endif //UNTITLED_GOBLIN_H