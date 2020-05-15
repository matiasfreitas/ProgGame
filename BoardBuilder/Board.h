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

#define FILENAMEMESSAGE "Nome do arquivo a criar?"
#define NCOLUNASMESSAGE "Qual o numero de colunas do tabuleiro?"
#define NLINHASMESSAGE "Qual o numero de linhas do tabuleiro?"
#define PALAVRAMESSAGE "Qual palavra voce vai por?"
#define CHOICECOLUNAMESSAGE "Em qual coluna voce vai por?"
#define CHOICELINHAMESSAGE "Em qual linha voce vai por?"
#define CHOICEORIENTMESSAGE "H para por na horizontal, V para Vertical"
#define CHOICEPUTWORD "Voce quer por alguma palavra? 1 para sim"
#define THANKSBOARD "Obrigado pelo tabuleiro"


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
