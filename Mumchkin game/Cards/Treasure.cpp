//
// Created by gigib on 13/06/2022.
//

#include "Treasure.h"
static const int COINS_TREASURE=10;

Treasure::Treasure(): Card("Treasure"){}

void Treasure::applyEncounter(Player &player, bool gang_checker) const {
    player.addCoins(COINS_TREASURE);
    printTreasureMessage();
}