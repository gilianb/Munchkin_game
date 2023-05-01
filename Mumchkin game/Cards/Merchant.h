//
// Created by gigib on 10/06/2022.
//

#ifndef MATAMHW4_MERCHANT_H
#define MATAMHW4_MERCHANT_H
#include "../utilities.h"
#include "Card.h"

class  Merchant: public Card{
public:

    void applyEncounter(Player &player, bool gang_checker) const override;

    Merchant();
    Merchant(const Merchant&) = default;
    Merchant& operator=(const Merchant& other) = default;
    ~Merchant() override = default;
};

bool failTransaction(int choice, int coins);


#endif //MATAMHW4_MERCHANT_H
