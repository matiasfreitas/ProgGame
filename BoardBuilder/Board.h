//
// Created by matiasfg on 4/27/20.
//

#ifndef PROGGAME_BOARD_H
#define PROGGAME_BOARD_H
#include <cstdlib>
#include <iostream>

class Board {

    public:
        void setBoard(int size) {
            sizeBoard = size;
            boardLetter = (char **)malloc(size * sizeof(char *));
            for (int i=0; i<size; i++){
                boardLetter[i] = (char *)malloc(size * sizeof(char));
            }
            boardOcup = (bool **)malloc(size * sizeof(bool *));
            for (int i=0; i<size; i++){
                boardOcup[i] = (bool *)malloc(size * sizeof(bool));
            }
            for (int i =0; i<size; i++){
                for (int j =0; j<size; j++) {
                    boardLetter[i][j] = 'A';
                    boardOcup[i][j] = false;
                }
            }
        }

        void print(){
            for (int j =0; j<sizeBoard; j++) {
                std::cout  << "__";
            }
            std::cout  << "\n";
            for (int i =0; i<sizeBoard; i++){
                std::cout  << "|";
                for (int j =0; j<sizeBoard; j++) {
                    std::cout  << boardLetter[i][j];
                    std::cout  << "|";
                }
                std::cout  << "\n";
                for (int j =0; j<sizeBoard; j++) {
                    std::cout  << "__";
                }
                std::cout  << "\n";
            }
        }


    private:
        int sizeBoard;
        bool **boardOcup;
        char **boardLetter;
};


#endif //PROGGAME_BOARD_H
