
#ifndef RUB_GI_HW4_WIZARD_H
#define RUB_GI_HW4_WIZARD_H

#include "Player.h"

class  Wizard: public Player{
public:
    void heal(int increase_hp) override ;
    void printInfo(std::ostream&) const override;

    Wizard(): Player(){};
    Wizard(const std::string& name): Player(name,"Wizard"){};
    Wizard(const std::string& name,int player_number_i): Player(name,"Wizard",player_number_i){};
    Wizard & operator=(const Wizard& p2 ) = default;
    ~Wizard() override = default;
};

#endif //RUB_GI_HW4_WIZARD_H
