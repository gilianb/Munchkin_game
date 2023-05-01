#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <sstream>
#include <iostream>
#include <string>
#include "Cards/Card.h"
#include "Players/Player.h"
#include "utilities.h"
#include <vector>
#include <memory>



class Mtmchkin{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string &fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
   /*
    * create a deck of cards
    *
    * */
    void create_deck(const std::string& fileName, std::ifstream& source);
    /*
       * create an array of Player and the LeaderBoard
       *
       * */
    void create_array_of_player();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    /*
       * update the LeaderBoard
       *
       * */
    void updateRank(Player& player);
    /*
       * return the rank of the player
       *
       * */

    int getRank(Player& player)const;

    template<typename T> void createPlayCard(int checker, int index) {
        if (checker == 1) {
            throw DeckFileFormatError(index);
        }
        m_card.push_back(std::unique_ptr<Card>(new T()));
        m_size_of_deck++;

    }

    template<class T> void createMonster(int checker,int index,std::vector<std::shared_ptr<Card>>& tmp_array){
        if (checker == 1) {
            tmp_array.push_back(std::unique_ptr<Card>(new T()));
        } else {
            m_card.push_back(std::unique_ptr<Card>(new T()));
            m_size_of_deck++;
        }
    }

    template<class T> void createGang(int& checker,int index,std::vector<std::shared_ptr<Card>>& tmp_array){
        if (checker==1) {
            throw DeckFileFormatError(index);
        }
        checker = 1;
    }

    template<class T> void createEndGang(int& checker,int index,std::vector<std::shared_ptr<Card>>& tmp_array){
        if (checker==0) {
            throw DeckFileFormatError(index);
        }
        m_card.push_back(std::unique_ptr<Card>(new T(tmp_array)));
        tmp_array.clear();
        checker = 0;
        m_size_of_deck++;
    }


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Mtmchkin()=default;
    Mtmchkin(const Mtmchkin&)=delete;
    Mtmchkin& operator=(const Mtmchkin& other) = delete;



private:
    std::vector<std::unique_ptr<Card>> m_card;
    int m_team_size;
    std::vector<std::shared_ptr<Player>> m_player;
    std::vector<std::shared_ptr<Player>> m_ranking;
    int m_number_of_rounds=0;
    int m_first=0;
    int m_last;
    int m_size_of_deck=0;
    int m_current_card=0;

};




#endif /* MTMCHKIN_H_ */