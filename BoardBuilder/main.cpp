#include "Board.h"
#include "Dictionary.h"
#include <iostream>
#define CHOICEPUTWORD "Voce quer por alguma palavra? 1 para sim"
#define THANKSBOARD "Obrigado pelo tabuleiro"
#define ENGANO "Algum erro ao criar a palavra"

int main()
{
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
                        break;
                }
                std::cin.ignore();
                while(!validaWord){
                        word = board.createWord();
                        validaWord = board.isValidaWord(word);
                        if(!validaWord){
                                std::cout << ENGANO << std::endl;
                        }
                }
                word.writeWord(board.getFilename());
                board.saveWord(word);
        }
        return 0;
}



