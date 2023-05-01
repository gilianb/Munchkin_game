
#include "Rogue.h"

void Rogue::addCoins(int increase_coins){

    Player::addCoins(2*increase_coins);
}

void Rogue::printInfo(std::ostream& os) const {
    Player::printInfo(os);
}
