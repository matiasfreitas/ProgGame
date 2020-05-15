//
// Created by matiasfg on 4/27/20.
//
#include <iostream>
#include "Board.h"
#include "Colors.h"
#include <string>
#include <algorithm>
#include "Words.h"
#include "globalDefB.h"

void BoardB::setBoard() {
    std::cout << FILENAMEMESSAGE << std::endl;
    std::cin >> nomeArq;
    std::cin.ignore();
    while(!(maxSizeBoard > sizeCol && sizeCol > minSizeBoard)){
        std::cout << NCOLUNASMESSAGE << std::endl;
        std::cin >> sizeCol;
        std::cin.ignore();

    }
    sizeCol =  sizeCol + 2;
    while(!(maxSizeBoard > sizeRow && sizeRow > minSizeBoard)){
        std::cout << NLINHASMESSAGE << std::endl;
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
    file << sizeRow-2 << " X " << sizeCol-2 <<  "\n";
    file.close();
}

void BoardB::print() {
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
Words BoardB::createWord(){
    int xInitial = 0;
    int yInitial = 0;
    char orient = ' ';
    char houseChar = ' ';
    std::string name = "";
    while((name.length() > sizeCol && name.length() > sizeRow) || name.length() < minWord){
        std::cout << PALAVRAMESSAGE << std::endl;
        std::cin >> name;
        std::cin.ignore();
        std::transform(name.begin(), name.end(),name.begin(), ::toupper);
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
    while(orient != HORIZONTAL & orient != VERTICAL){
        std::cout << CHOICEORIENTMESSAGE << std::endl;
        std::cin >> orient;
        std::cin.ignore();
        toupper(orient);
    }
    Words word;
    word.setWord(name, xInitial, yInitial, orient);
    return word;
}

bool BoardB::isValidaWord(Words word) {
    bool validLoc = false;
    std::string name =  word.getName() ;
    if(word.ishorizontal()){
        if(boardTiles[word.getY1()][word.getX1()-1].getChar() != ' '){
            return validLoc;
        }
        for (int i = 0; i <= name.length(); i++) {
            if (boardTiles[word.getY1()][word.getX1()+ i].getChar() != name[i] && boardTiles[word.getY1()][word.getX1() + i].getChar() != ' ') {
                validLoc = false;
                break;
            }else if((boardTiles[word.getY1() + 1][word.getX1() + i].getChar() != ' ' || boardTiles[word.getY1() - 1][word.getX1() + i].getChar() != ' ')){
                if(boardTiles[word.getY1()][word.getX1()+ i].getChar() == name[i]){
                    validLoc = true;
                }
                else{
                    validLoc = false;
                    break;
                }
            }else {
                validLoc = true;
            }
        }
    }else {
        if(boardTiles[word.getY1()-1][word.getX1()].getChar() != ' '){
            return validLoc;
        }
        for (int i =  0; i <= name.length(); i++) {
            if (boardTiles[word.getY1() + i][word.getX1()].getChar() !=  name[i]  && boardTiles[word.getY1() + i][word.getX1()].getChar() != ' '){
                validLoc = false;
                break;
            }else if((boardTiles[word.getY1() + i] [word.getX1() + 1].getChar() != ' ' || boardTiles[word.getY1() + i][word.getX1() - 1].getChar() != ' ')){
                if(boardTiles[word.getY1() + i][word.getX1()].getChar() ==  name[i]){
                    validLoc = true;
                }
                else{
                    validLoc = false;
                    break;
                }
            } else {
                validLoc = true;
            }
        }
    }
    return validLoc;
}
void BoardB::saveWord(Words word) {
    std::string name = word.getName();
    if (word.ishorizontal()) {
        boardTiles[word.getY1()][word.getX1()].setTile(name[0], true, true);
        for (int i = 0; i <= name.length(); i++) {
            boardTiles[word.getY1()][word.getX1() + i].setTile(name[i], false, true);
        }
    } else {
        boardTiles[word.getY1()][word.getX1()].setTile(name[0], true, true);
        for (int i = 0; i <= name.length(); i++) {
            boardTiles[word.getY1() + i][word.getX1()].setTile(name[i], false, true);
        }
    }
}

std::string BoardB::getFilename(){
    return nomeArq;
}