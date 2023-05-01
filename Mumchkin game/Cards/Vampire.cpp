//
// Created by gigib on 13/06/2022.
//

#include "Vampire.h"


Vampire::Vampire():Card("Vampire"){}

void Vampire::applyEncounter(Player &player, bool gang_checker) const
{
    if (player.getAttackStrength() >= force)
    {
        if(!gang_checker) {
            printWinBattle(player.getPlayerName(), "Vampire");
            player.levelUp();
        }
        player.addCoins(coins);
    }
    else
    {
        printLossBattle(player.getPlayerName(),"Vampire");
        player.damage(damage);
        player.vampire_decrease_force();
    }
}

void Vampire::print(std::ostream &os) const {
    printCardDetails(os,m_cardName);
    printMonsterDetails(os,Vampire::force ,Vampire::damage ,Vampire::coins,false);
    printEndOfCardDetails(os);
}