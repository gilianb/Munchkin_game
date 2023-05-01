#include "Card.h"
#include <utility>

Card::Card(std::string  name): m_cardName(std::move(name)) {}



void Card::print(std::ostream& os) const{
    printCardDetails(os,m_cardName);
    printEndOfCardDetails(os);
}

std::string Card::getName() const {
    return m_cardName;
}

std::ostream& operator<<(std::ostream& os, const Card& card1)
{
    card1.print(os);
    return os;
}

