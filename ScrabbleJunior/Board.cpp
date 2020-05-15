//
// Created by matiasfg on 4/27/20.
//
#include <iostream>
#include "Board.h"
#include "Colors.h"
#include <string>
#include <algorithm>
#include "Words.h"
#include "globalDef.h"
void Board::setBoard() {
    std::cout << "Nome do arquivo a criar?" << std::endl;
    std::cin >> nomeArq;
    std::cin.ignore();
    while(!(maxSizeBoard > sizeCol && sizeCol > minSizeBoard)){
        std::cout << "Qual o numero de colunas do tabuleiro?" << std::endl;
        std::cin >> sizeCol;
        std::cin.ignore();

    }
    sizeCol =  sizeCol + 2;
    while(!(maxSizeBoard > sizeRow && sizeRow > minSizeBoard)){
        std::cout << "Qual o numero de linhas do tabuleiro?" << std::endl;
        std::cin >> sizeRow;
        std::cin.ignore();

    }
    sizeRow =  sizeRow + 2;
    boardTiles =  new Tiles*[sizeRow];
    for (int i=0; i<sizeRow; i++){
        boardTiles[i] = new Tiles[sizeCol];
    }
    for (int i =0; i<sizeRow; i++){
        for (int j =0; j<sizeCol; j++) {
            boardTiles[i][j].setTile();
        }
    }
    std::ofstream file;
    file.open(nomeArq);
    file << sizeRow << " X " << sizeCol <<  "\n";
    file.close();
}

void Board::print() {
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
            if (boardTiles[i][j].getEmpty()){
                setcolor(RED, WHITE_B);
            }
            else if (boardTiles[i][j].getValid()){
                setcolor(GREEN, WHITE_B);
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
Words Board::createWord(){
    int xInitial;
    int yInitial;
    char orient;
    char houseChar;
    std::string name;
    while((name.length() > sizeCol && name.length() > sizeRow) || name.length() < minWord){
        std::cout << "Qual palavra voce vai por?" << std::endl;
        std::cin >> name;
        std::cin.ignore();
        std::transform(name.begin(), name.end(),name.begin(), ::toupper);
    }
    while(xInitial>sizeCol || yInitial>sizeRow){
        std::cout << "Em qual coluna voce vai por?" << std::endl;
        std::cin >> houseChar;
        xInitial = horizontalHouses.find(houseChar);
        std::cin.ignore();
        std::cout << "Em qual linha voce vai por?" << std::endl;
        std::cin >> houseChar;
        yInitial = verticalHouses.find(houseChar);
        std::cin.ignore();
    }
    while(orient != 'H' & orient != 'V'){
        std::cout << "H para por na horizontal, V para Vertical" << std::endl;
        std::cin >> orient;
        std::cin.ignore();
        toupper(orient);
    }
    Words word;
    word.setWord(name, xInitial, yInitial, orient);
    return word;
}

bool Board::validaWord(Words word) {
    bool validLoc = false;
    std::string name = word.getName();
    if(word.ishorizontal()){
        for (int i =  0; i <= name.length() ; i++) {
            if (boardTiles[word.getX1()][word.getY1() + i].getChar() != name[i] && boardTiles[word.getX1()][word.getY1() + i].getChar() != ' ') {
                validLoc = false;
            }else if(boardTiles[word.getX1()][word.getY1() + i].getChar() != ' ' || boardTiles[word.getX1()][word.getY1() + i].getChar() != ' '){
                validLoc = false;
            }else {
                validLoc = true;
            }
        }
    }else {
        for (int i =  0; i <= name.length() ; i++) {
            if (boardTiles[word.getX1() + i][word.getY1()].getChar() !=  name[i]  && boardTiles[word.getX1() + i][word.getY1()].getChar() != ' '){
                validLoc = false;
            }else if(boardTiles[word.getX1() + i][word.getY1()].getChar() != ' ' || boardTiles[word.getX1() + i][word.getY1()].getChar() != ' '){
                validLoc = false;
            } else {
                validLoc = true;
            }
        }
    }
    return validLoc;
}
void Board::saveWord(Words word) {
    std::string name = word.getName();
    if (word.ishorizontal()) {
        boardTiles[word.getX1()][word.getY1()].setTile(name[0], true, true);
        for (int i = 0; i <= name.length(); i++) {
            boardTiles[word.getX1()][word.getY1() + i].setTile(name[i], false, true);
        }
    } else {
        boardTiles[word.getX1()][word.getY1()].setTile(name[0], true, true);
        for (int i = 0; i <= name.length(); i++) {
            boardTiles[word.getX1() + i][word.getY1()].setTile(name[i], false, true);
        }
    }
}

std::string Board::getFilename(){
    return nomeArq;
}