//
// Created by matiasfg on 4/27/20.
//
#include <algorithm>
#include <string>
#include "Bag.h"
#include <iostream>
void Bag::setBagTiles(Board board){
    for (int i =0; i<board.getSizeRow(); i++){ //Setando as tiles para o padrão vazio
        for (int j =0; j<board.getSizeCol(); j++) {
            if(board.isChar(board.getTiles(i, j).getChar())){
                bagTiles = bagTiles + board.getTiles(i, j).getChar();
            }
        }
    }
    bagTiles = bagTiles + bagTiles;
    std::cout << bagTiles << std::endl;
    random_shuffle(bagTiles .begin(), bagTiles .end());
    std::cout << bagTiles << std::endl;
}