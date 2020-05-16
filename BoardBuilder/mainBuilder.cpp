#include "Board.h"
#include "Dictionary.h"
#include <iostream>
#define CHOICEPUTWORD "Voce quer por alguma palavra? 1 para sim"
#define THANKSBOARD "Obrigado pelo tabuleiro"
#define ENGANO "Algum erro ao criar a palavra"

void mainBuilder(){ // Main do jogo
    BoardB board; // Cria o board
    board.setBoard(); // Determina o tamanho e nome dele
    int Answer = 1; // Enquanto variavel for 1, vai pondo novas palavras
    bool validaWord; // Cria variavel verificar se e possivel aquela palavra no tabuleiro
    Words word; // Classe pra guardar informações básicas de cada palavra
    while(true){
        validaWord = false;
        board.print();
        std::cout << CHOICEPUTWORD << std::endl; // Pergunta se quer por a palavra, 1 para sim, qualquer coisa para não
        std::cin >> Answer;
        if(Answer != 1){  // Se for não, quebra o ciclo while
            std::cout << THANKSBOARD << std::endl;
            break;}
        std::cin.ignore();
        while(!validaWord){ // Enquanto não for valida fica rodando isso
            word = board.createWord(); // Cria a palavra e retorna ela
            validaWord = board.isValidaWord(word); // Verifica se ela está em boa posição
            if(!validaWord){
                std::cout << ENGANO << std::endl; //Avisa se não tiver
            }
        }
        word.writeWord(board.getFilename()); // Escreve no arquivo
        board.saveWord(word); // salva na estrutura de dados
    }
}



