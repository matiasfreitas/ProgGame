#include "Board.h"
#include "Bag.h"
#include "Player.h"
#include "Colors.h"
#include <iostream>
#define NJOGADORESMESSAGE "Quantos jogadores hoje? 2 a "
#define NJOGADORESMESSAGEREST " Jogadores"
#define MINBOARDMESSAGE "Tabuleiro pequeno demais"
int main(){ // Main do jogo
    Board board; // Cria o board
    Bag bag;
    Player *players;
    bool gameOn = true;
    int nPlayers = 0;
    board.setFilename();
    board.setBoard();
    bag.setBagTiles(board);
    if (bag.sizeBag()<28){
        std::cout << MINBOARDMESSAGE  << std::endl;
    }
    else{
        int maxPlayers = 4;
        if (maxPlayers>bag.sizeBag()/14){
            maxPlayers = bag.sizeBag()/4;
        }
        while(nPlayers<2 || nPlayers>maxPlayers){
            std::cout <<  NJOGADORESMESSAGE << maxPlayers << NJOGADORESMESSAGEREST << std::endl;
            std::cin >> nPlayers;
            std::cin.ignore();
        }
        players = new Player[nPlayers];
        for (int j =0; j<nPlayers; j++) {
            players[j].setPlayer(bag);
        }
        int turn = 0;
        while(gameOn){
            clrscr();
            board.print();
            players[turn].printHand(turn+1);
            gameOn = players[turn].playOrTrade(bag, board);
            turn = turn + 1;
            if(turn == nPlayers){
                turn = 0;
            }
        }
    }
    return 0;
}



