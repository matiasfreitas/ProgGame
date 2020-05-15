#include "Board.h"
#include <iostream>

void mainBuilder(){
    BoardB board;
    board.setBoard();
    int Answer = 1;
    bool validaWord;
    Words word;
    while(true){
        validaWord = false;
        board.print();
        std::cout << "Voce quer por alguma palavra? 1 para sim" << std::endl;
        std::cin >> Answer;
        if(Answer != 1){
            std::cout << "Obrigado pelo tabuleiro" << std::endl;
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



