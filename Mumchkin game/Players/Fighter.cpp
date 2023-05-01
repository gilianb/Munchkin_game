#include "Fighter.h"

int Fighter::getAttackStrength() const{
    return m_level+2*m_force;
}

void Fighter::printInfo(std::ostream& os) const {
    Player::printInfo(os);
}