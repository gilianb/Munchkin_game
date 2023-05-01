//
// Created by gigib on 02/05/2022.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <utility>

static const int    MAX_HP_DEFAULT=100,
                    FORCE_DEFAULT=5,
                    COINS_DEFAULT=10;
/*
 *  Player characteristics:
 *  Each player has characteristics:
 *  NAME  -
 *  JOB   -
 *  LEVEL -
 *  FORCE -
 *  HP    -
 *  COINS -
*/

class Player {
public:

    /*
     * Prints the player info:
     *
     * @return
     *      void
    */
    virtual void printInfo(std::ostream& os) const;

/*
     * up the player's level by one if possible :
     *
    */
    void  levelUp() ;

    /*
     * get the player's level :
     *
     *      return
     *          void
    */
    int  getLevel() const;


    /*
     * up the player's force by increase force :
     *  return
     *      void
    */
    void buff(int increase_force);

    /*
     * up the player's HP by increase_hp if possible :
     *
    */
    virtual void heal(int increase_hp) ;

    /*
        * decrease the player's hp  if possible :
        *
       */
    virtual void damage(int decrease_hp);

    /*
     * check if the player is knocked out
     *
     *  return
     *      true if hp =0
     *      or false if hp>0    */
    bool isKnockedOut() const;

    /*
     * up the player's coins by increase_coins :
     *
    */
    virtual void addCoins(int increase_coins);


    /*
     * check if it is possible for the player to pay :
     *
     *      return
     *      true if there is enough coins
     *      or false if there is not enough coins
    */
    bool pay(int decrease_coins);


    int getPlayerCoins()const;
    /*
     * get the player's force :
     *
     *
     *      return actual level
    */
    virtual int getAttackStrength() const;

    /*
     * helping functions
     */
    bool isPlayerInGame() const;
    std::string getPlayerName() const;
    int getPlayerHP()const;
    void setPlayerHPToZero();
    int get_player_number_i() const;
    void vampire_decrease_force();

    /*
     * C'tor to the "default player" -
    */
    Player( const std::string name, const std::string job,int player_number_i): m_name(name), m_job(job),m_player_number_i(player_number_i){}
    Player( const std::string name, const std::string job): m_name(name), m_job(job){}

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Player()= default;
    Player(const Player&) = default;
    virtual ~Player() = default;
    Player& operator=(const Player& other) = default;


protected:
    std::string m_name;
    std::string m_job;
    int m_player_number_i=0;
    int  m_level=1;
    int m_force=FORCE_DEFAULT;
    int m_HP=MAX_HP_DEFAULT;
    int m_coins=COINS_DEFAULT;
    friend std::ostream &operator<<(std::ostream &os, const Player & p1);


};




#endif //EX2_PLAYER_H