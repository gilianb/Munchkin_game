#include "Wizard.h"

void Wizard::heal(int increase_hp) {
    Player::heal(2*increase_hp);
}

void Wizard::printInfo(std::ostream& os) const {
    Player::printInfo(os);
}
