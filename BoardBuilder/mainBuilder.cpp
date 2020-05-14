#include "Board.h"
#include <iostream>

void mainBuilder(){
    Board board;
    board.setBoard();
    int Answer = 1;
    bool validaWord = false;
    Words word;
    while(true){
        board.print();
        std::cout << "Você quer por alguma palavra? 1 para sim" << std::endl;
        std::cin >> Answer;
        if(Answer != 1){ break;}
        std::cin.ignore();

        while(!validaWord){
            word = board.createWord();
            validaWord = board.validaWord(word);
        }
        word.writeWord(board.getFilename());
        board.saveWord(word);
        delete &word;
    }


}



