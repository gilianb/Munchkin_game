//
// Created by gigib on 09/06/2022.
//
#include "Pitfall.h"
#include "../Players/Rogue.h"
static const int PITFALLS_DAMAGE=10;

Pitfall::Pitfall():Card("Pitfall"){}

void Pitfall::applyEncounter(Player &player, bool gang_checker) const {
    Rogue* p =dynamic_cast<Rogue*>(&player);
    if(p==nullptr){
        player.damage(PITFALLS_DAMAGE);
        printPitfallMessage(false);
    }
    else{
        printPitfallMessage(true);
    }
}

