//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"

/*
 *  CardType:
 *  Each card has an type:
 *  BATTLE - Battle against a monster.
 *  BUFF - Increase your player's force by 'm_force' points of CardStats.
 *  HEAL - Increase your player's HP by 'm_heal' points  of CardStats (no more than maxHP points).
 *  TREASURE - Get 'm_profit' coins of CardStats.
*/

class Card {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    explicit Card(std::string  cardName);


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player,bool gang_checker) const=0;


    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    //virtual void printInfo() const=0;
    virtual void print(std::ostream& out) const;

    /*
     * operator<<, prints the following template: <name> <level> <Force> <Hp> <Coins> <Class>
     * @param out
     */
    friend std::ostream& operator<<(std::ostream& out, const Card& card);

    std::string getName() const;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    Card()=default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;


protected:
    std::string m_cardName;
};



#endif //EX2_Card_H