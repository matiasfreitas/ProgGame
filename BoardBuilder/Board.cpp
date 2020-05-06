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
    std::cout << "Em qual coluna voce vai por?" << std::endl;
    std::cin >> xInitial;;
    std::cin.ignore();
    std::cout << "Em qual linha voce vai por?" << std::endl;
    std::cin >> sizeRow;
    std::cin.ignore();
}
