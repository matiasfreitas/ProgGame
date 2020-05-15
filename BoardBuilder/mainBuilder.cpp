#include "Board.h"
#include <iostream>
#include "globalDefB.h"

void mainBuilder(){
    BoardB board;
    board.setBoard();
    int Answer = 1;
    bool validaWord;
    Words word;
    while(true){
        validaWord = false;
        board.print();
        std::cout << CHOICEPUTWORD << std::endl;
        std::cin >> Answer;
        if(Answer != 1){
            std::cout << THANKSBOARD << std::endl;
            break;}
        std::cin.ignore();
        while(!validaWord){
            word = board.createWord();
            validaWord = board.isValidaWord(word);
        }
        word.writeWord(board.getFilename());
        board.saveWord(word);
    }
}



