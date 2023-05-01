//
// Created by gigib on 19/06/2022.
//

#ifndef MATAMHW4_GANG_H
#define MATAMHW4_GANG_H

#include "Card.h"
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Gang: public Card {
public:

    void applyEncounter(Player &player, bool gang_checker) const override;

    Gang(std::vector<std::shared_ptr<Card>> tmp_array);

    Gang(const Gang &) = default;

    Gang &operator=(const Gang &other) = default;

    ~Gang() override = default;

private:
    std::vector<std::shared_ptr<Card>> m_gang;
    unsigned int m_size_of_gang=0;
    static const int vampire_damage = 10;
    static const int goblin_damage = 10;


};



#endif //MATAMHW4_GANG_H