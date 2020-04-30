#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include "BoardBuilder/Words.h"
#include "BoardBuilder/Board.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Words firstWord;
    firstWord.setWord("Matias", 15, 20, true);
    Board board;
    board.setBoard(20);
    board.print();


    return 0;
}
