//
// Created by matiasfg on 4/27/20.
//
#include <iostream>
#include "Player.h"
#include <string>
#include "Bag.h"
#include "Board.h"
#define SIZEHAND 7

void Player::setPlayer(Bag bag)
{
        for (int i = 0; i < SIZEHAND;i++ ) {
                hand = hand + bag.tradeTile();
        }
}

void Player::printHand(int jogador)
{
        std::cout << "Essa e sua mao jogador " << jogador << std::endl;
        std::cout << hand << std::endl;
};

bool Player::playOrTrade(Bag bag, Board board)
{
        bool gameContinue = true;
        int choice;
        std::cout << "Quer jogar ou trocar? 1 para trocar, qualquer coisa para jogar" << std::endl;
        std::cin >> choice;

        if(choice == 1){
                trade(bag);
        }else{
                int contador = 0;

                while(contador < 2){
                        if(board.getNwords()==1){
                                play(bag, board);
                                break;
                        }else if(board.getNwords()>1){
                                play(bag, board);
                        }else{
                                gameContinue = false;
                        }

                        contador++;

                        if (contador ==1){
                                std::cout << hand << std::endl;
                                std::cout << "Segunda peça" << std::endl;
                        }
               }
               while(contador>0){
                   hand = bag.tradeTile() + hand;
                   contador --;
               }
        }

        return gameContinue;
};

void Player::play(Bag bag, Board board)
{
        std::string horizontalHouses = " abcdefghijklmnopqrst";
        std::string verticalHouses = " ABCDEFGHIJKLMNOPQRST";
        char colName;
        char rowName;
        int indexCol = -1;
        int indexRow = -1;
        int indexHand = -1;

        while(indexHand == -1){
                indexRow = -1;
                indexHand = -1;
                indexCol = -1;

                while(indexCol < 0 || board.getSizeCol() < indexCol){
                        std::cout << "Escolha a coluna pra por" << std::endl;
                        std::cin >> colName;
                        indexCol = horizontalHouses.find(colName);
                }
                while(indexRow < 0  || board.getSizeRow() <  indexRow) {
                        std::cout << "Escolha a linha pra por" << std::endl;
                        std::cin >> rowName;
                        indexRow = verticalHouses.find(rowName);
                }
                if(board.getTiles(indexCol, indexRow).getValid()) {
                        indexHand = hand.find(board.getTiles(indexCol, indexRow).getChar());
                        if (indexRow == -1) {
                                std::cout << "Nao consegui achar a peca na sua mao" << std::endl;
                        }else{
                                hand.erase (indexHand,1);
                                points = points + board.toFill(indexCol, indexRow);
                        }
                } else{
                        int choice;
                        std::cout << "Lugar invalido" << std::endl;
                        std::cout << "Tem certeza que consegue jogar nessa rodada? "
                                     "1 para não, qualquer coisa para sim" << std::endl;
                        std::cin >> choice;
                        if(choice == 1){
                                break;
                        }
                }
        }

}



void Player::trade(Bag bag)
{
        char tileTrade;
        int indexTrade;
        std::cout << hand << std::endl;

        for(int i = 0; i<2; i++){

                indexTrade = -1;

                while(indexTrade == -1){
                        std::cout << "Escolha qual trocar." << std::endl;
                        std::cin >> tileTrade;
                        tileTrade = toupper(tileTrade);
                        indexTrade = hand.find(tileTrade);
                }

                hand = hand.substr(0,indexTrade-1) +
                        bag.tradeTile(std::string(1,hand[indexTrade]))+ hand.substr(indexTrade+1);

                std::cout << "Agora essa e sua mao" << std::endl;
                std::cout << hand << std::endl;
        }
}