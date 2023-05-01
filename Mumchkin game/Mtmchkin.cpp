//
// Created by gigib on 07/06/2022.
//

#include "Mtmchkin.h"
#include <fstream>
#include <algorithm>
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Exception.h"
#include "Cards/Gang.h"

using std::unique_ptr;
using std::shared_ptr;
using std::ifstream;
using std::cin;
using std::cerr;
using std::endl;
using std::string;

static const int    MinimumDeckSize=5,
                    MaxTeamSize=6,
                    MinTeamSize=2,
                    maxStringLength=15;



bool validName(std::string const &str) {
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") ==
           std::string::npos&&str.length() <= maxStringLength;;
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

Mtmchkin::Mtmchkin(const std::string &fileName):m_team_size(0){
    //start of the game
    printStartGameMessage();
    //convertion from file to card Array
    ifstream source(fileName);
    if (!source) {
        throw DeckFileNotFound();
    }
    //create deck of card
    try {
        create_deck(fileName, source);
    }
    catch (std::exception &e){
        throw;
    }

    //asking for team size
    printEnterTeamSizeMessage();
    bool validInput= false;
    string tmp;
    while(!validInput){
        validInput=true;
        if(!std::getline(cin, tmp) || !is_number(tmp)||tmp.length()!=1 ||std::stoi(tmp)<MinTeamSize || std::stoi(tmp)>MaxTeamSize){
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            validInput= false;
            continue;
        }
       m_team_size=std::stoi(tmp);
    }

    //asking each player for its name and its class
    m_last=m_team_size-1;
    create_array_of_player();
}



void Mtmchkin::playRound(){
    m_number_of_rounds++;
    printRoundStartMessage(getNumberOfRounds());
    for(int i=0; i<m_team_size; i++){
        if (m_player[i]->isPlayerInGame()){
            printTurnStartMessage(m_player[i]->getPlayerName());
            m_card[m_current_card]->applyEncounter(*m_player[i],false);
            updateRank(*m_player[i]);
            m_current_card++;
            m_current_card=(m_current_card%m_size_of_deck);
        }
        if(isGameOver()) {
            printGameEndMessage();
            return;
        }
    }
}


int Mtmchkin::getNumberOfRounds() const{
    return m_number_of_rounds;
}



bool Mtmchkin::isGameOver() const{
    for (int i=0;i<m_team_size;i++){
        if (m_player[i]->isPlayerInGame()) {
            return false;
        }
    }
    return true;
}

void Mtmchkin::updateRank(Player& player){
    if (player.getLevel() == 10) {
        shared_ptr<Player> to_move = m_ranking[getRank(player)];
        m_ranking.erase(m_ranking.begin()+getRank(player));
        m_ranking.insert(m_ranking.begin()+m_first, to_move);
        if(m_first<m_last){
            m_first++;
        }
    }
    if (player.isKnockedOut()) {
        shared_ptr<Player> to_move = m_ranking[getRank(player)];
        m_ranking.erase(m_ranking.begin()+getRank(player));
        m_ranking.insert(m_ranking.begin()+m_last, to_move);
        if(m_last>m_first) {
            m_last--;
        }
    }

}
int Mtmchkin::getRank(Player& player) const {
    int rank=0;
    while(m_ranking[rank]->getPlayerName()!=player.getPlayerName()||
        m_ranking[rank]->getPlayerCoins()!=player.getPlayerCoins()||
        m_ranking[rank]->getAttackStrength()!=player.getAttackStrength()||
        m_ranking[rank]->getLevel()!=player.getLevel()||
        m_ranking[rank]->getPlayerHP()!=player.getPlayerHP()||
        m_ranking[rank]->get_player_number_i()!=player.get_player_number_i()){
        rank++;
    }
    return rank;
}



void Mtmchkin::printLeaderBoard() const{
    printLeaderBoardStartMessage();
    for(int i=0;i<m_team_size;i++) {
        std::cout << i+1 << "          ";
        m_ranking[i]->printInfo(std::cout);
        std::cout<< endl;
    }
}


void Mtmchkin::create_deck(const string& fileName, ifstream& source) {
    int gang_checker=0;
    std::vector<std::shared_ptr<Card>> tmp_array;
    string tmp;
    int index_of_line = 1;
    while (std::getline(source, tmp)) {
        try {
            if (tmp == "Gang") {
                createGang<Gang>(gang_checker,index_of_line,tmp_array);

            }else if (tmp == "EndGang") {
                createEndGang<Gang>(gang_checker,index_of_line,tmp_array);

            }else if (tmp == "Barfight") {
                createPlayCard<Barfight>(gang_checker, index_of_line);

            } else if (tmp == "Dragon") {
                createMonster<Dragon>(gang_checker,index_of_line,tmp_array);

            } else if (tmp == "Fairy") {
                createPlayCard<Fairy>(gang_checker, index_of_line);

            } else if (tmp == "Goblin") {
                createMonster<Goblin>(gang_checker,index_of_line,tmp_array);

            } else if (tmp == "Merchant") {
                createPlayCard<Merchant>(gang_checker, index_of_line);

            } else if (tmp == "Pitfall") {
                createPlayCard<Pitfall>(gang_checker, index_of_line);

            } else if (tmp == "Treasure") {
                createPlayCard<Treasure>(gang_checker, index_of_line);

            } else if (tmp == "Vampire") {
                createMonster<Vampire>(gang_checker,index_of_line,tmp_array);

            }else {
                throw DeckFileFormatError(index_of_line);
            }
            if (gang_checker == 1) {
                index_of_line++;
                continue;
            }
        }
        catch (DeckFileFormatError &e) {
            throw ;
        }
        catch (std::bad_alloc &e) {
            throw;
        }
        index_of_line++;
    }
    if(gang_checker==1){
        throw DeckFileFormatError(index_of_line);
    }
    if(m_size_of_deck<MinimumDeckSize){
        throw DeckFileInvalidSize();
    }
}


void  Mtmchkin::create_array_of_player(){
    for (int i=0;i<m_team_size;i++) {
        std::string tmp_name;
        std::string tmp_class;
        printInsertPlayerMessage();
        bool checker=true;
        while (checker){
            (std::getline(cin, tmp_name, ' '));
            (std::getline(cin, tmp_class));
            if (!(validName(tmp_name))){
                 printInvalidName();
                 continue;
            }else if( ((tmp_class != "Rogue") && (tmp_class != "Wizard") && (tmp_class != "Fighter"))){
              printInvalidClass();
                continue;
            }
            checker=false;
        }
        if (tmp_class=="Rogue"){
            m_player.push_back(unique_ptr<Player>(new Rogue(tmp_name,i)));
        }
        else if(tmp_class=="Wizard") {
            m_player.push_back(unique_ptr<Player>(new Wizard(tmp_name,i)));
        }
        else if (tmp_class=="Fighter"){
            m_player.push_back(unique_ptr<Player>(new Fighter(tmp_name,i)));
        }
        m_ranking.push_back(m_player[i]);
    }
}