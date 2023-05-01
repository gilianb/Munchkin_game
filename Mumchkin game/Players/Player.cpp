//
// Created by gigib on 02/05/2022.
//

#include "Player.h"
#include "../utilities.h"
static const int MAX_LEVEL =10;

void Player::printInfo(std::ostream& os) const {
    printPlayerDetails(os , m_name, m_job, m_level, m_force, m_HP, m_coins);
}


void Player::levelUp() {

    if (m_level<MAX_LEVEL){
        m_level++;
    }
}

int Player::getLevel() const {
    return m_level;
}

void Player::buff(int increase_force)  {
    if(increase_force<=0){
        return;
    }
    m_force=m_force+increase_force;
}

void Player::heal(int increase_hp) {
    if(increase_hp<=0) {
        return;
    }
    if (m_HP + increase_hp >= MAX_HP_DEFAULT) {
        m_HP = MAX_HP_DEFAULT;
    } else {
        m_HP +=increase_hp;
    }
}

void Player::damage(int decrease_hp){
    if(m_HP-decrease_hp<=0){
        m_HP = 0;
    } else {
        m_HP = m_HP - decrease_hp;
    }
}

bool Player::isKnockedOut() const {
    return  (m_HP<=0);
}

void Player::addCoins(int increase_coins) {
    if(increase_coins<=0){
        return;
    }
    m_coins+=increase_coins;
}

bool Player::pay(int decrease_coins) {
    bool no_coins = true;
    if(decrease_coins<=0){
        return no_coins;
    }

    if(m_coins-decrease_coins>=0){
        m_coins = m_coins - decrease_coins;
    } else {
        no_coins = false;
    }
    return no_coins;
}

int Player::getAttackStrength() const{
    return m_level +m_force;
}


bool Player::isPlayerInGame() const{
    if (isKnockedOut()||(getLevel()==10)){
        return false;
    }
    return true;
}

std::string Player::getPlayerName() const {
    return m_name;
}

int  Player::getPlayerCoins() const{
    return m_coins;
}

void Player::setPlayerHPToZero(){
    m_HP=0;
}

std::ostream &operator<<(std::ostream &os, const Player & p1) {
    p1.printInfo(os);
    return os;
}

void Player::vampire_decrease_force(){
    if (m_force>0){
        m_force--;
    }
}

int Player::getPlayerHP()const{
    return m_HP;
}

int Player::get_player_number_i()const{
    return m_player_number_i;
}