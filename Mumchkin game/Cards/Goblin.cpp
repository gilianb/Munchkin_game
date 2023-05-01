//
// Created by gigib on 13/06/2022.
//

#include "Goblin.h"

Goblin::Goblin():Card("Goblin"){
}

void Goblin::applyEncounter(Player &player,bool gang_checker) const
{
    if (player.getAttackStrength() >= force)
    {
        if(!gang_checker) {
            printWinBattle(player.getPlayerName(), "Goblin");
            player.levelUp();
        }
        player.addCoins(coins);
    }
    else
    {
        printLossBattle(player.getPlayerName(),"Goblin");
        player.damage(damage);
    }
}

void Goblin::print(std::ostream &os) const {
    printCardDetails(os,m_cardName);
    printMonsterDetails(os,Goblin::force ,Goblin::damage ,Goblin::coins,false );
    printEndOfCardDetails(os);
}
