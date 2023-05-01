#ifndef EX4_Merchant_Source
#define EX4_Merchant_Source


#include "Merchant.h"
static const int    HEALTH_POTION=1,
                    FORCE_BOOST=2,
                    HEALTH_POTION_COST =5,
                    FORCE_BOOST_COST=10;

Merchant::Merchant():Card("Merchant"){}

void Merchant::applyEncounter(Player &player, bool gang_checker) const {
    std::string tmp;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getPlayerName(), player.getPlayerCoins());
    std::getline(std::cin, tmp);

    while(tmp != "0" && tmp != "1" && tmp != "2"){
        printInvalidInput();
        std::getline(std::cin, tmp);
    }
    int choice = std::stoi(tmp);
    if (failTransaction(choice,player.getPlayerCoins())) {
        printMerchantInsufficientCoins(std::cout);
        printMerchantSummary(std::cout, player.getPlayerName(), choice, 0);
        return;
    }

    if (choice==HEALTH_POTION){
        player.heal(1);
        player.pay(HEALTH_POTION_COST);
        printMerchantSummary(std::cout, player.getPlayerName(), choice, HEALTH_POTION_COST);
    }else if(choice==FORCE_BOOST){
        player.buff(1);
        player.pay(FORCE_BOOST_COST);
        printMerchantSummary(std::cout, player.getPlayerName(), choice, FORCE_BOOST_COST);
    }else {
        printMerchantSummary(std::cout, player.getPlayerName(), choice, 0);
    }
}


bool failTransaction(int choice, int coins) {
    if (choice == HEALTH_POTION) {
        if ((coins - HEALTH_POTION_COST) < 0)
            return true;
        else
            return false;
    }
    if (choice == FORCE_BOOST) {
        if ((coins - FORCE_BOOST_COST) < 0)
            return true;
        else
            return false;
    }
    return false;
}
#endif //EX4_Merchant_Source