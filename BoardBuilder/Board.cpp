//
// Created by matiasfg on 4/27/20.
//
#include <iostream>
#include "Board.h"
#include "Colors.h"
#include <string>
#include <algorithm>
#include "Words.h"
#define VERTICAL 'V'
#define HORIZONTAL 'H'
#include "Dictionary.h"

//Cria o tabuleiro e grava a primeira linha, com as caractericas dele, num ficheiro.
void BoardB::setBoard()
{
        listWords.setDictVector();
        std::cout << FILENAMEMESSAGE << std::endl;
        std::cin >> nomeArq;
        std::cin.ignore();

        while(!(maxSizeBoard >= sizeCol && sizeCol >= minSizeBoard)){
                std::cout << NCOLUNASMESSAGE << std::endl;
                std::cin >> sizeCol;
                std::cin.ignore();
        }
        sizeCol =  sizeCol + 2;
        //Soma dois para criar uma "borda" de espaços vazios no tabuleiro,
        //para saber mais facilmente se as palavras tão bem postas.

        while(!(maxSizeBoard >= sizeRow && sizeRow >= minSizeBoard)){
                std::cout << NLINHASMESSAGE << std::endl;
                std::cin >> sizeRow;
                std::cin.ignore();

        }
        sizeRow =  sizeRow + 2;

        //Alocando dinamicamente espaço para o vetor.
        boardTiles =  new Tiles*[sizeRow];
        for (int i=0; i<sizeRow; i++){
                boardTiles[i] = new Tiles[sizeCol];
        }

        //Cria as tiles com o padrão (vazias)
        for (int i =0; i<sizeRow; i++){
                for (int j =0; j<sizeCol; j++) {
                        boardTiles[i][j].setTile();
                }
        }

        std::ofstream file;
        file.open(nomeArq);
        file << sizeRow-2 << " x " << sizeCol-2 <<  "\n";
        file.close();
}


//Função para dar output do campo.
//Para mais informações sobre as cores ler READ ME.
void BoardB::print()
{
        setcolor(WHITE, BLACK_B);
        std::cout << " ";
        for (int i = 1; i < sizeCol-1; i++){
                std::cout << " ";
                std::cout << char(i + 96);
        }

        std::cout << "\n";

        for (int i = 1; i < sizeRow-1; i++) {
                setcolor(WHITE, BLACK_B);
                std::cout << " ";
                std::cout << char(i + 64);
                setcolor(BLACK, WHITE_B);
                for (int j = 1; j < sizeCol-1; j++) {
                        if (boardTiles[i][j].getValid()){
                                setcolor(GREEN, WHITE_B);
                        }else if (boardTiles[i][j].getEmpty()){
                                setcolor(RED, WHITE_B);
                        }
                        std::cout << boardTiles[i][j].getChar();
                        setcolor(BLACK, WHITE_B);
                        if (j != sizeCol - 2){
                            std::cout << " ";
                        }
                }
                std::cout << "\n";
        }

        setcolor(WHITE, BLACK_B);
}

//Cria a word e verifica se os paramentros são possiveis
Words BoardB::createWord()
{
        std::string horizontalHousesB = " abcdefghijklmnopqrst";
        std::string verticalHousesB = " ABCDEFGHIJKLMNOPQRST";
        int xInitial = 0;
        int yInitial = 0;
        char orient = ' ';
        char houseChar = ' ';
        std::string name = "";
        bool wordisvalid = false;

        while((name.length() > sizeCol && name.length() > sizeRow )
                    || name.length() < minWord || !listWords.isInDict(name) ){
                std::cout << PALAVRAMESSAGE << std::endl;
                std::cin >> name;
                std::cin.ignore();
                std::transform(name.begin(), name.end(), name.begin(), ::toupper);
        }

        while(xInitial>sizeCol || xInitial<1) {
                std::cout << CHOICECOLUNAMESSAGE << std::endl;
                std::cin >> houseChar;
                xInitial = horizontalHousesB.find(houseChar);
                std::cin.ignore();
        }

        while(yInitial>sizeCol || yInitial<1) {
                std::cout << CHOICELINHAMESSAGE << std::endl;
                std::cin >> houseChar;
                yInitial = verticalHousesB.find(houseChar);
                std::cin.ignore();
        }

        while(orient != HORIZONTAL && orient != VERTICAL){
                std::cout << CHOICEORIENTMESSAGE << std::endl;
                std::cin >> orient;
                std::cin.ignore();
                toupper(orient);
        }

        Words word;
        word.setWord(name, xInitial, yInitial, orient);
        return word;
}

bool BoardB::isValidaWord(Words word)
{
        bool validLoc = false;
        std::string name =  word.getName();

        if(word.ishorizontal()){

                //Verifica se tem alguma letras atrás da nova palavra.
                if(isChar(boardTiles[word.getY1()][word.getX1()-1].getChar())){
                        return validLoc;
                }

                //Verifica se as posições intermediaras da palavra são validas
                for (int i = 0; i < name.length(); i++) {
                        if (boardTiles[word.getY1()][word.getX1()+ i].getChar() != name[i]
                                    && isChar(boardTiles[word.getY1()][word.getX1() + i].getChar())) {
                                validLoc = false;
                                break;

                        //Verifica se as peças paralelas à palavra estão vazias.
                        }else if((isChar(boardTiles[word.getY1() + 1][word.getX1() + i].getChar())
                                    || isChar(boardTiles[word.getY1() - 1][word.getX1() + i].getChar()))){
                                if(boardTiles[word.getY1()][word.getX1()+ i].getChar() == name[i]){
                                        validLoc = true;
                                }else if(!isChar(boardTiles[word.getY1()+1][word.getX1()+ i -1].getChar())){
                                        validLoc = true;
                                }else{
                                        validLoc = false;
                                        break;
                                }
                        }else {
                            validLoc = true;
                        }
                }

        }else {
                //Verifica se tem alguma letras atrás da nova palavra
                if(isChar(boardTiles[word.getY1()-1][word.getX1()].getChar())){
                        return validLoc;
                }

                //verifica se as posições intermediaras da palavra são validas
                for (int i =  0; i < name.length(); i++) {
                        if (boardTiles[word.getY1() + i][word.getX1()].getChar() !=  name[i]
                                    && isChar(boardTiles[word.getY1() + i][word.getX1()].getChar())){
                                validLoc = false;
                                break;
                        }else if(isChar(boardTiles[word.getY1() + i][word.getX1() + 1].getChar())
                                    || isChar(boardTiles[word.getY1() + i][word.getX1() - 1].getChar())){
                                if(boardTiles[word.getY1() + i][word.getX1()].getChar() ==  name[i]){
                                        validLoc = true;
                                }else if(!isChar(boardTiles[word.getY1()+ i -1][word.getX1()+1].getChar())){
                                        validLoc = true;
                                }else{
                                        validLoc = true;
                                }
                        } else {
                                validLoc = true;
                        }
                }
        }

        return validLoc;
}

//Guarda a palavra no board
void BoardB::saveWord(Words word)
{
        std::string name = word.getName();
        if (word.ishorizontal()) {
                boardTiles[word.getY1()][word.getX1()].setTile(name[0], true, true);
                for (int i = 1; i <= name.length(); i++) {
                        boardTiles[word.getY1()][word.getX1() + i].setTile(name[i], false, true);
                }
        } else {
                boardTiles[word.getY1()][word.getX1()].setTile(name[0], true, true);
                for (int i = 1; i <= name.length(); i++) {
                        boardTiles[word.getY1() + i][word.getX1()].setTile(name[i], false, true);
                }
        }
}


std::string BoardB::getFilename()
{
        return nomeArq;
}

bool BoardB::isChar(char Let)
{
        std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        if(alphabet.find(Let) == -1){
                return false;
        }else{
                return true;
        }
}
