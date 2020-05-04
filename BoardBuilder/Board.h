//
// Created by matiasfg on 4/27/20.
//

#ifndef PROGGAME_BOARD_H
#define PROGGAME_BOARD_H
#include <cstdlib>
#include <iostream>
#include "Tiles.h"
class Board {

    public:
        void setBoard() {

            std::cout << "Qual o numero de colunas do tabuleiro?" << std::endl;
            std::cin >> sizeCol;
            std::cin.ignore();
            std::cout << "Qual o numero de linhas do tabuleiro?" << std::endl;
            std::cin >> sizeRow;
            std::cin.ignore();
            boardTiles =  new Tiles*[sizeRow];
            for (int i=0; i<sizeRow; i++){
                boardTiles[i] = new Tiles[sizeCol];
            }
            for (int i =0; i<sizeRow; i++){
                for (int j =0; j<sizeCol; j++) {
                    boardTiles[i][j].setTile();
                }
            }
        }

        void print() {
            for (int j = 0; j < sizeCol; j++) {
                std::cout << "__";
            }
            std::cout << "\n";
            for (int i = 0; i < sizeRow; i++) {
                std::cout << "|";
                for (int j = 0; j < sizeCol; j++) {
                    std::cout << boardTiles[i][j].getChar();
                    std::cout << "|";
                }
                std::cout << "\n";
                for (int j = 0; j < sizeCol; j++) {
                    std::cout << "__";
                }
                std::cout << "\n";
            }
        }

        void putWord(){
            std::cout << "Em qual coluna voce vai por " << std::endl;
        };


    private:
        int sizeCol;
        int sizeRow;
        Tiles **boardTiles;
};


#endif //PROGGAME_BOARD_H
