#include "Board.h"
#include "Bag.h"
#include "Player.h"
#include <iostream>
#define CHOICEPUTWORD "Voce quer por alguma palavra? 1 para sim"
#define THANKSBOARD "Obrigado pelo tabuleiro"
#define ENGANO "Algum erro ao criar a palavra"

void mainGame(){ // Main do jogo
    Board board; // Cria o board
    Bag bag;
    Player *players;
    int nPlayers;
    board.setFilename();
    board.setBoard();
    bag.setBagTiles(board);
    while(nPlayers>0 && nPlayers<5)
        std::cout << "Quantos jogadores hoje? 1 a 4";
        std::cin >> nPlayers;
        std::cin.ignore();
    players = new Player[nPlayers];
    for (int j =0; j<[nPlayers; j++) {
        players[j].setPlayer();
    }
    int turn = 0;
    while(true){
        board.print();
        players[turn].printHand();
        players[turn].PlayOrTrade();
        turn = turn + 1;
        if(turn == nPlayers){
            turn = 0;
        }


    }


}



