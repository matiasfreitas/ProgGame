//
// Created by matiasfg on 4/27/20.
//

#ifndef PROGGAME_BOARD_H
#define PROGGAME_BOARD_H
#include <cstdlib>
#include <iostream>
#include "Tiles.h"
#include <fstream>
#include "Words.h"
#define maxSizeBoard 20
#define minSizeBoard 2
#define minWord 3



class BoardB {

    public:
        void setBoard();
        void print();
        void putWord();
        Words createWord();
        bool isValidaWord(Words word);
        void saveWord(Words word);
        std::string getFilename();

    private:
        std::string nomeArq;
        int sizeCol;
        int sizeRow;
        Tiles **boardTiles;
};


#endif //PROGGAME_BOARD_H
