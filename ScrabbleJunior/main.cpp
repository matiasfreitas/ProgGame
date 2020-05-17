#include "Board.h"
#include "Bag.h"
#include "Player.h"
#include "Colors.h"
#include <iostream>
#define NJOGADORESMESSAGE "Quantos jogadores hoje? 2 a "
#define NJOGADORESMESSAGEREST " Jogadores"
#define MINBOARDMESSAGE "Tabuleiro pequeno demais"

void winner( Player *players, int nPlayers)
{       char aux;
        int maxPoints = 0;
        int indexWinner = 0;
        for (int j = 0; j < nPlayers; j++) {
                if(maxPoints < players[j].getPoints()){
                        maxPoints = players[j].getPoints();
                        indexWinner = j+1;
                }else if (maxPoints == players[j].getPoints()){
                        maxPoints = 0;
                        indexWinner = 0;
                }
        }
        if(indexWinner == 0){
                std::cout <<  "Tivemos um empate" << std::endl;
                std::cin >> aux;
                std::cin.ignore();
        }else{
                std::cout <<  "Jogador numero" << indexWinner << "foi o vencedor" << std::endl;
                std::cin >> aux;
                std::cin.ignore();
        }


}

int main()
{
        Board board;
        Bag bag;
        Player *players;
        int nPlayers = 0;
        board.setFilename();
        board.setBoard();
        bag.setBagTiles(board);
        if (bag.sizeBag()<28){
                std::cout << MINBOARDMESSAGE  << std::endl;
        }else{
                int maxPlayers = 4;

                if (maxPlayers>bag.sizeBag()/14){
                        maxPlayers = bag.sizeBag()/14;
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

                while(board.getNwords()>0){
                        clrscr();
                        board.print();
                        players[turn].printHand(turn+1);
                        players[turn].playOrTrade(bag, board);
                        turn = turn + 1;

                        if(turn == nPlayers){
                                turn = 0;
                        }
                }
                winner(players, nPlayers);
        
                
        }

        return 0;
}

