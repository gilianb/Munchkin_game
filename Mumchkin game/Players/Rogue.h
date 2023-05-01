
#ifndef RUB_GI_HW4_ROGUE_H
#define RUB_GI_HW4_ROGUE_H

#include "Player.h"

class Rogue: public Player{
public:
    void addCoins(int increase_coins) override;
    void printInfo(std::ostream& os) const override;

    Rogue(): Player(){};
    Rogue(const std::string& name): Player(name,"Rogue"){};
    Rogue(const std::string& name,int player_number_i): Player(name,"Rogue",player_number_i){};
    Rogue & operator=(const Rogue& p2 ) = default;
    ~Rogue() override = default;
};

#endif //RUB_GI_HW4_ROGUE_H