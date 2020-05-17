//
// Created by matiasfg on 4/27/20.
//
#include <algorithm>
#include <string>
#include "Bag.h"
#include <iostream>

void Bag::setBagTiles(Board board)
{       int shuffleVar;
        for (int i =0; i<board.getSizeRow(); i++){
                for (int j =0; j<board.getSizeCol(); j++) {
                        if(board.isChar(board.getTiles(i, j).getChar())){
                                bagTiles = bagTiles + board.getTiles(i, j).getChar();
                        }
                }
        }
        shuffleVar = rand() % 1000 + 1;
        srand(shuffleVar);

        bagTiles = bagTiles + bagTiles;
        random_shuffle(bagTiles .begin(), bagTiles .end());
        shuffleVar--;
}

std::string Bag::tradeTile(std::string tileReceive)
{
        random_shuffle(bagTiles .begin(), bagTiles .end());
        std::string tiletogive = std::string(1, bagTiles.back());
        bagTiles.pop_back();
        bagTiles = bagTiles + tileReceive;
        random_shuffle(bagTiles .begin(), bagTiles .end());
        return tiletogive;
}

int Bag::sizeBag()
{
        return bagTiles.length();
}