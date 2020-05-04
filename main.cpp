#include <iostream>
#include "BoardBuilder/mainBuilder.cpp"
#include "ScrabbleJunior/mainGaming.cpp"
int main() {
    int choice;
    while(true){
        std::cout << "1 para construir, 0 para jogar" << std::endl;
        std::cin >> choice;
        std::cin.ignore();
        if(choice == 1){
            construction();
            break;
        }
        else if(choice == 0){
            gaming();
            break;
        }
        else{
            std::cout << "Nao consegui entender" << std::endl;
        }
    }
    return 0;
}
