//
// Created by matiasfg on 4/27/20.
//

#ifndef PROGGAME_PLAYER_H
#define PROGGAME_PLAYER_H
#include <string>
#include "Bag.h"
#include "Board.h"

class Player {
        private:
                int points;
                std::string hand;
        public:
                void printHand(int jogador);
                void playOrTrade(Bag bag, Board board);
                void trade(Bag bag);
                void play(Bag bag, Board board);
                void setPlayer(Bag bag);
                int getPoints();
};


#endif //PROGGAME_PLAYER_H