
#ifndef RUB_GI_HW4_FIGHTER_H
#define RUB_GI_HW4_FIGHTER_H

#include "Player.h"

class  Fighter: public Player{
public:
    int getAttackStrength() const override ;
    void printInfo(std::ostream& os) const override;

    Fighter(): Player(){};
    Fighter( const std::string& name): Player(name,"Fighter"){};
    Fighter( const std::string& name,int player_number_i): Player(name,"Fighter",player_number_i){};
    Fighter & operator=(const Fighter& p2 ) = default;
    ~Fighter() override = default;

};


#endif //RUB_GI_HW4_FIGHTER_H