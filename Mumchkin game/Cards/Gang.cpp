//
// Created by gigib on 19/06/2022.
//

#include "Gang.h"
#include "../Mtmchkin.h"
#include <fstream>
#include "Dragon.h"

using std::unique_ptr;
using std::shared_ptr;


void printPlayerDefeatAGang(const std::string &playerName){
    std::cout << "Player " << playerName << " has defeated Gang and rose 1 Level!" << std::endl;
}

Gang::Gang(std::vector<std::shared_ptr<Card>> tmp_array){
    m_size_of_gang=tmp_array.size();
    for(unsigned int i=0;i<m_size_of_gang;i++){
        shared_ptr<Card> tmp =tmp_array[i];
        m_gang.push_back(tmp);
    }
}


void Gang::applyEncounter(Player &player, bool gang_checker) const{
    unsigned int current_card=0;
    int player_hp=player.getPlayerHP();
    for(unsigned int i=0; i<m_gang.size(); i++) {
        if(player_hp==player.getPlayerHP()&&player.isPlayerInGame()){
            m_gang[current_card]->applyEncounter(player,true);
            current_card++;
        }
    }
    if(current_card!=m_size_of_gang){
        for(unsigned int i=current_card; i<m_gang.size(); i++) {
            if(m_gang[i]->getName()=="Vampire"){
                printLossBattle(player.getPlayerName(),"Vampire");
                player.damage(vampire_damage);
                player.vampire_decrease_force();
            }else if(m_gang[i]->getName()=="Goblin"){
                printLossBattle(player.getPlayerName(),"Goblin");
                player.damage(goblin_damage);
            }else{
                player.setPlayerHPToZero();
                printLossBattle(player.getPlayerName(),"Dragon");
            }
        }
    }else if(!player.isPlayerInGame()){
            return;
    }
    else{
        printPlayerDefeatAGang(player.getPlayerName());
        player.levelUp();
    }
}



