#include <iostream>
#include "BoardBuilder/mainBuilder.h"
#include "ScrabbleJunior/mainGaming.h"
int main() {
    int choice;
    while(true){
        std::cout << "1 para construir, 0 para jogar" << std::endl;
        std::cin >> choice;
        std::cin.ignore();
        if(choice == 1){
            mainBuilder();
            break;
        }
        else if(choice == 0){
            mainGame();
            break;
        }
        else{
            std::cout << "Nao consegui entender" << std::endl;
        }
    }
    return 0;
}
