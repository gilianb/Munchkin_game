//
// Created by gigib on 09/06/2022.
//
#include "Fairy.h"
#include "../Players/Wizard.h"
static const int FAIRY_HEAL=10;

Fairy::Fairy():Card("Fairy"){}

void Fairy::applyEncounter(Player &player, bool gang_checker) const {
    Wizard* p =dynamic_cast<Wizard*>(&player);
    if(p==nullptr){
        printFairyMessage(false);
    }
    else{
        player.heal(FAIRY_HEAL);
        printFairyMessage(true);
    }
}