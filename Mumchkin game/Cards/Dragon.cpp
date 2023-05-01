//
// Created by gigib on 12/06/2022.
//

#include "Dragon.h"

Dragon::Dragon():Card("Dragon"){}

void Dragon::applyEncounter(Player &player, bool gang_checker) const{
    if (player.getAttackStrength() >= force){
        if(!gang_checker) {
            printWinBattle(player.getPlayerName(), "Dragon");
            player.levelUp();
        }
        player.addCoins(coins);
    }
    else{
        player.setPlayerHPToZero();
        printLossBattle(player.getPlayerName(),"Dragon");
    }
}

void Dragon::print(std::ostream &os) const {
    printCardDetails(os,m_cardName);
    printMonsterDetails(os,Dragon::force ,Dragon::damage ,Dragon::coins , true );
    printEndOfCardDetails(os);
}