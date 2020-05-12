#include "Board.h"
#include <iostream>

void mainBuilder(){
    Board board;
    board.setBoard();
    int Answer = 1;

    while(true){
        board.print();
        std::cout << "Você quer por alguma palavra? 1 para sim" << std::endl;
        std::cin >> Answer;
        std::cout << Answer;
        if(Answer != 1){ break;}
        std::cin.ignore();
        board.putWord();
    }


}



