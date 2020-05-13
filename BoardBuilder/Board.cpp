//
// Created by matiasfg on 4/27/20.
//
#include <iostream>
#include "Board.h"
#include "Colors.h"
#include <string>
#include <algorithm>
#include "Words.h"


void Board::setBoard() {
    std::cout << "Nome do arquivo a criar?" << std::endl;
    std::cin >> nomeArq;
    std::cin.ignore();
    while(sizeCol>maxSizeBoard || sizeCol<minSizeBoard){
        std::cout << "Qual o numero de colunas do tabuleiro?" << std::endl;
        std::cin >> sizeCol;
        std::cin.ignore();
    }
    while(sizeRow>maxSizeBoard || sizeRow<minSizeBoard){
        std::cout << "Qual o numero de linhas do tabuleiro?" << std::endl;
        std::cin >> sizeRow;
        std::cin.ignore();
    }
    boardTiles =  new Tiles*[sizeRow];
    for (int i=0; i<sizeRow; i++){
        boardTiles[i] = new Tiles[sizeCol];
    }
    for (int i =0; i<sizeRow; i++){
        for (int j =0; j<sizeCol; j++) {
            boardTiles[i][j].setTile();
        }
    }
    std::fstream file;
    file.open (nomeArq);
    file << sizeRow << sizeCol <<  "\n";
    file.close();
}

void Board::print() {
    setcolor(WHITE, BLACK_B);
    std::cout << " ";
    for (int i = 0; i < sizeCol; i++){
        std::cout << " ";
        std::cout << char(i + 97);
    }
    std::cout << "\n";
    for (int i = 0; i < sizeRow; i++) {
        setcolor(WHITE, BLACK_B);
        std::cout << " ";
        std::cout << char(i + 65);
        setcolor(BLACK, WHITE_B);
        for (int j = 0; j < sizeCol; j++) {
            if (boardTiles[i][j].getEmpty()){
                setcolor(RED, WHITE_B);
            }
            else if (boardTiles[i][j].getValid()){
                setcolor(GREEN, WHITE_B);
            }
            std::cout << boardTiles[i][j].getChar();
            setcolor(BLACK, WHITE_B);
            if (j != sizeCol - 1){
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    setcolor(WHITE, BLACK_B);
}
Words Board::createWord(){
    int xInitial;
    int yInitial;
    char orient;
    std::string name = " ";
    while(name.length()>sizeCol || name.length()>sizeRow){
        std::cout << "Qual palavra voce vai por?" << std::endl;
        std::cin >> name;
        std::cin.ignore();
    }
    while(xInitial>sizeCol || yInitial>sizeRow){
        std::cout << "Em qual coluna voce vai por?" << std::endl;
        std::cin >> xInitial;
        std::cin.ignore();
        std::cout << "Em qual linha voce vai por?" << std::endl;
        std::cin >> yInitial;
        std::cin.ignore();
    }
    while(orient != 'H' & orient != 'V'){
        std::cout << "H para por na horizontal, V para Vertical" << std::endl;
        std::cin >> orient;
        std::toupper(orient);
        std::cin.ignore();
    }
    Words word;
    word.setWord(name, xInitial, yInitial, orient);
    return word;
}

bool Board::validaWord(Words word) {
    bool validLoc = false;
    std::string name = word.getName();
    if(word.ishorizontal()) {
        for (int i = word.getX1(); i  <= sizeRow + word.getX1(); i++) {
            if (boardTiles[i][word.getY1()].getChar() !=  name[i-sizeCol]  ||
                boardTiles[i][word.getY1()].getChar() != ' '){
                validLoc = false;

            }else if(boardTiles[i][word.getY1() + 1].getChar() != ' ' ||
                     boardTiles[i][word.getY1() - 1].getChar() != ' '){
                    validLoc = false;
            } else {
                validLoc = true;
            }
        }
    } else {
        for (int i = word.getY1() + 1; i <= sizeRow + word.getY1() + 1  ; i++) {
            if (boardTiles[word.getX1()][i].getChar() != name[i-sizeRow] ||
                boardTiles[word.getX1()][i].getChar() != ' ') {
                validLoc = false;
            }else if(boardTiles[word.getX1()][i].getChar() != ' ' ||
                     boardTiles[word.getX1()][i].getChar() != ' '){
                validLoc = false;
            }else {
                validLoc = true;
            }
        }
    }
    return validLoc;
}
void Board::saveWord(Words word) {
    std::string name = word.getName();
    if(word.ishorizontal()){
        boardTiles[word.getX1()][word.getY1()].setTile(name[0], true, true);
        for (int i=word.getX1()+1; i<sizeRow + word.getX1(); i++){
            boardTiles[i][word.getY1()].setTile(name[i-sizeRow], false, true);
        }
    }else {
        boardTiles[word.getX1()][word.getY1()].setTile(name[0], true, true);
        for (int i = word.getY1() + 1; i < sizeRow + word.getY1(); i++) {
            boardTiles[word.getX1()][i].setTile(name[i-sizeRow], false, true);
        }
    }
}

std::string Board::getFilename(){
    return nomeArq;
}