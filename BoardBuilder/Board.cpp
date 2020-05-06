//
// Created by matiasfg on 4/27/20.
//

#include "Board.h"
#include "Colors.h"

void Board::setBoard() {

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

void Board::print() {
    for (int i = 0; i < sizeRow; i++) {
        setcolor(WHITE_B, BLACK);
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

void Board::putWord() {
    int xInitial;
    std::cout << "Em qual coluna voce vai por?" << std::endl;
    std::cin >> xInitial;;
    std::cin.ignore();
    std::cout << "Em qual linha voce vai por?" << std::endl;
    std::cin >> sizeRow;
    std::cin.ignore();
}
