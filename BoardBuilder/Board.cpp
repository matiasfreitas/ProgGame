//
// Created by matiasfg on 4/27/20.
//
#include <iostream>
#include "Board.h"
#include "Colors.h"
#include <string>
#include <algorithm>
#include "Words.h"
#define VERTICAL 'V'
#define HORIZONTAL 'H'
#include "Dictionary.h"

void BoardB::setBoard() { // Cria o tabuleiro e grava a primeira linha, com as caractericas dele, num ficheiro
    listWords.setDictVector();
    std::cout << FILENAMEMESSAGE << std::endl;
    std::cin >> nomeArq;
    std::cin.ignore();
    while(!(maxSizeBoard >= sizeCol && sizeCol >= minSizeBoard)){ // Pegunta o tamanho do tabuleiro de um dos lados num loop até ser de um tamanho permitido
        std::cout << NCOLUNASMESSAGE << std::endl;
        std::cin >> sizeCol;
        std::cin.ignore();
    }
    sizeCol =  sizeCol + 2; // Somado dois para criar uma borda de espaços vazios no tabuleiro para saber mais fácil se as palavras tão bem postas
    while(!(maxSizeBoard >= sizeRow && sizeRow >= minSizeBoard)){
        std::cout << NLINHASMESSAGE << std::endl;
        std::cin >> sizeRow;
        std::cin.ignore();

    }
    sizeRow =  sizeRow + 2;
    boardTiles =  new Tiles*[sizeRow];  //Alocando dinamicamente espaço para o vetor
    for (int i=0; i<sizeRow; i++){
        boardTiles[i] = new Tiles[sizeCol];
    }
    for (int i =0; i<sizeRow; i++){ //Setando as tiles para o padrão vazio
        for (int j =0; j<sizeCol; j++) {
            boardTiles[i][j].setTile();
        }
    }
    std::ofstream file;
    file.open(nomeArq);
    file << sizeRow-2 << " X " << sizeCol-2 <<  "\n"; // salvando o arquivo
    file.close();
}

void BoardB::print() { // Função pra printar o board com cores se estiver vazio, preenchido e se é possível naquela rodada por uma peça.
    setcolor(WHITE, BLACK_B);
    std::cout << " ";
    for (int i = 1; i < sizeCol-1; i++){ // printando a borda de cima
        std::cout << " ";
        std::cout << char(i + 96);
    }
    std::cout << "\n";
    for (int i = 1; i < sizeRow-1; i++) {
        setcolor(WHITE, BLACK_B);
        std::cout << " ";
        std::cout << char(i + 64); // printando a borda do lado
        setcolor(BLACK, WHITE_B);
        for (int j = 1; j < sizeCol-1; j++) {
            if (boardTiles[i][j].getValid()){
                setcolor(GREEN, WHITE_B); //escolhendo a cor do espaço de acordo com as caracteristicas dele
            }
            else if (boardTiles[i][j].getEmpty()){
                setcolor(RED, WHITE_B);
            }
            std::cout << boardTiles[i][j].getChar();
            setcolor(BLACK, WHITE_B);
            if (j != sizeCol - 2){
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    setcolor(WHITE, BLACK_B);
}

Words BoardB::createWord(){ // Cria a word e verifica se os paramentros são possiveis
    std::string horizontalHousesB = " abcdefghijklmnopqrst";
    std::string verticalHousesB = " ABCDEFGHIJKLMNOPQRST";
    int xInitial = 0;
    int yInitial = 0;
    char orient = ' ';
    char houseChar = ' ';
    std::string name = "";
    bool wordisvalid = false;
    while((name.length() > sizeCol && name.length() > sizeRow ) || name.length() < minWord || !listWords.isInDict(name) ){ //Se a palavra tem um tamanho correto
        std::cout << PALAVRAMESSAGE << std::endl;
        std::cin >> name;
        std::cin.ignore();
        std::transform(name.begin(), name.end(),name.begin(), ::toupper);
    }
    while(xInitial>sizeCol || xInitial<1) { //Se a palavra tem uma coluna valida
        std::cout << CHOICECOLUNAMESSAGE << std::endl;
        std::cin >> houseChar;
        xInitial = horizontalHousesB.find(houseChar);
        std::cin.ignore();
    }
    while(yInitial>sizeCol || yInitial<1) { //Se a palavra tem uma linha valida
        std::cout << CHOICELINHAMESSAGE << std::endl;
        std::cin >> houseChar;
        yInitial = verticalHousesB.find(houseChar);
        std::cin.ignore();
    }
    while(orient != HORIZONTAL && orient != VERTICAL){ //Se a palavra tem uma orientação valida
        std::cout << CHOICEORIENTMESSAGE << std::endl;
        std::cin >> orient;
        std::cin.ignore();
        toupper(orient);
    }
    Words word;
    word.setWord(name, xInitial, yInitial, orient); // escreve as informações capturadas
    return word;
}

bool BoardB::isValidaWord(Words word) {
    bool validLoc = false;
    std::string name =  word.getName();
    if(word.ishorizontal()){ //Se for horizontal, roda assim
        if(isChar(boardTiles[word.getY1()][word.getX1()-1].getChar())){ // Verifica se tem alguma letras atrás da nova palavra. Se tiver, localização invalida
            return validLoc;
        }
        for (int i = 0; i < name.length(); i++) {  //verifica se as posições intermediaras da palavra são validas
            if (boardTiles[word.getY1()][word.getX1()+ i].getChar() != name[i]
                && isChar(boardTiles[word.getY1()][word.getX1() + i].getChar())) { // verifica se o espaço não é vazio ou igual a da peça
                validLoc = false;
                break;
            }else if((isChar(boardTiles[word.getY1() + 1][word.getX1() + i].getChar())
                      || isChar(boardTiles[word.getY1() - 1][word.getX1() + i].getChar()))){ // verifica se as peças paralelas a ela tão vazias
                if(boardTiles[word.getY1()][word.getX1()+ i].getChar() == name[i]){// se tiver vazio,  verifica se é um cruzamento.
                    validLoc = true;
                }else if(!isChar(boardTiles[word.getY1()+1][word.getX1()+ i -1].getChar())){
                    validLoc = true;
                }
                else{ // se não for um cruzamento, retorna false
                    validLoc = false;
                    break;
                }
            }else { // Só retorna true se todas forem true
                validLoc = true;
            }
        }
    }else {
        if(isChar(boardTiles[word.getY1()-1][word.getX1()].getChar())){ // Verifica se tem alguma letras atrás da nova palavra. Se tiver, localização invalida
            return validLoc;
        }//Se for vertical, roda assim
        for (int i =  0; i < name.length(); i++) { //verifica se as posições intermediaras da palavra são validas
            if (boardTiles[word.getY1() + i][word.getX1()].getChar() !=  name[i]
                && isChar(boardTiles[word.getY1() + i][word.getX1()].getChar())){ // verifica se o espaço não é vazio ou igual a da peça
                validLoc = false;
                break;
            }else if(isChar(boardTiles[word.getY1() + i][word.getX1() + 1].getChar())
                     || isChar(boardTiles[word.getY1() + i][word.getX1() - 1].getChar())){ // verifica se as peças paralelas a ela tão vazias
                if(boardTiles[word.getY1() + i][word.getX1()].getChar() ==  name[i]){ // se não tiver vazio,  verifica se é um cruzamento.
                    validLoc = true;
                }else if(!isChar(boardTiles[word.getY1()+ i -1][word.getX1()+1].getChar())){
                    validLoc = true;
                }
                else{ // se não for um cruzamento, retorna false
                    validLoc = true;
                }
            } else { // Só retorna true se todas forem true
                validLoc = true;
            }
        }
    }
    return validLoc;
}

void BoardB::saveWord(Words word) { // salva a palavra no board
    std::string name = word.getName();
    if (word.ishorizontal()) {
        boardTiles[word.getY1()][word.getX1()].setTile(name[0], true, true); //seta a primeira de cada palavra como valida
        for (int i = 1; i <= name.length(); i++) {
            boardTiles[word.getY1()][word.getX1() + i].setTile(name[i], false, true); //seta o restante como invalida e vazia.
        }
    } else {
        boardTiles[word.getY1()][word.getX1()].setTile(name[0], true, true); //seta a primeira de cada palavra como valida
        for (int i = 1; i <= name.length(); i++) {
            boardTiles[word.getY1() + i][word.getX1()].setTile(name[i], false, true); //seta o restante como invalida e vazia.
        }
    }
}

std::string BoardB::getFilename() {
    return nomeArq;
}

bool BoardB::isChar(char Let){
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if(alphabet.find(Let) == -1){
        return false;
    }
    else{
        return true;
    }
}
