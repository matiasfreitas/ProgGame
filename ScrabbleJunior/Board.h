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
#define minWord 2

#define FILENAMEMESSAGE "Nome do arquivo a criar?"
#define NCOLUNASMESSAGE "Qual o numero de colunas do tabuleiro?"
#define NLINHASMESSAGE "Qual o numero de linhas do tabuleiro?"
#define PALAVRAMESSAGE "Qual palavra voce vai por?"
#define CHOICECOLUNAMESSAGE "Em qual coluna voce vai por?"
#define CHOICELINHAMESSAGE "Em qual linha voce vai por?"
#define CHOICEORIENTMESSAGE "H para por na horizontal, V para Vertical"
#define CHOICEPUTWORD "Voce quer por alguma palavra? 1 para sim"
#define THANKSBOARD "Obrigado pelo tabuleiro"


class Board {

public:
    bool setBoard();
    void print();
    Words createWord();
    bool isValidaWord(Words word);
    void saveWord(Words word);
    std::string getFilename();
    void setFilename();
    int getSizeCol();
    int getSizeRow();
    Tiles getTiles(int x, int y);
    int getNwords();
    bool isChar(char Let);
private:
    std::string nomeArq;
    int sizeCol;
    int sizeRow;
    int nWords = 0;
    Tiles **boardTiles;
};


#endif //PROGGAME_BOARD_H
