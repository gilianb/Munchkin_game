

#include <iostream>
#include <vector>
#include "../Mtmchkin.h"

int main(){
    try{
        Mtmchkin game("deck");
        while(!game.isGameOver()){
            game.playRound();
            game.printLeaderBoard();
        }
    }
    catch(std::exception &e){
        std::cout << e.what();
        return 1;
    }
    return 0;
}