//
// Created by matiasfg on 4/27/20.
//
#include <iostream>
#include <fstream>
#include "Board.h"
#include "Colors.h"
#include <string>
#include <algorithm>

void Board::setBoard() {
    std::cout << "Nome do arquivo a criar?" << std::endl;
    std::cin >> nomeArq;
    std::cin.ignore();
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
        std::cout << char(i + 65);
        std::cout << " ";
        setcolor(BLACK, WHITE_B);
        for (int j = 0; j < sizeCol; j++) {
            if (!boardTiles[i][j].getempty()){
                setcolor(RED, WHITE_B);
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


void Board::putWord() {
    int xInitial;
    int yInitial;
    char orient;
    std::string word = " ";
    bool validLoc = false;
    while (!validLoc){
        while(word.length()>sizeCol || word.length()>sizeRow){
            std::cout << "Qual palavra voce vai por?" << std::endl;
            std::cin >> word;
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
        if(orient == 'H') {
            for (int i = xInitial + 1; i < sizeRow + xInitial; i++) {
                if (boardTiles[i][yInitial].getChar() != word[0] || boardTiles[i][yInitial + 1].getChar() != ' '  ||
                    boardTiles[i][yInitial - 1].getChar() != ' ') {
                    std::cout << "Tivemos problemas com o registro da palavra. Mude ela ou a localização" << std::endl;
                    validLoc = false;
                    break;
                } else {
                    validLoc = true;
                }
            }
        } else {
            for (int i = yInitial + 1; i < sizeRow + yInitial; i++) {
                if (boardTiles[xInitial][i].getChar() != word[0] || boardTiles[xInitial + 1][i].getChar() != ' ' ||
                    boardTiles[xInitial - 1][i].getChar() != ' ') {
                    std::cout << "Tivemos problemas com o registro da palavra. Mude ela ou a localização" << std::endl;
                    validLoc = false;
                    break;
                } else {

                    validLoc = true;
                }
            }
        }

    }
    std::cin.ignore();
    std::fstream file (nomeArq, std::ios::app);
    file << char(xInitial + 97) << char(yInitial + 65) << " " << orient << " " << word << " " << "\n";
    file.close();
    if(orient == 'H'){
        boardTiles[xInitial][yInitial].setTile(word[0], true, true);
        for (int i=xInitial+1; i<sizeRow + xInitial; i++){
            boardTiles[i][yInitial].setTile(word[0], false, true);
        }
    }
    else{
        boardTiles[xInitial][yInitial].setTile(word[0], true, true);
        for (int i=yInitial+1; i<sizeRow + xInitial; i++){
            boardTiles[xInitial][i].setTile(word[0], false, true);
        }
    }

}
