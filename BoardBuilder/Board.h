//
// Created by matiasfg on 4/27/20.
//

#ifndef PROGGAME_BOARD_H
#define PROGGAME_BOARD_H
#include <cstdlib>
#include <iostream>
#include "Tiles.h"
#include <fstream>

class Board {

    public:
        void setBoard();
        void print();
        void putWord();


    private:
        std::string nomeArq;
        int sizeCol;
        int sizeRow;
        Tiles **boardTiles;
};


#endif //PROGGAME_BOARD_H
