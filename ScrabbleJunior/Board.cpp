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
#include <sys/types.h>
#include <dirent.h>
#include <fstream>

void Board::setFilename(){
    std::string directory = ".";
    std::vector<std::string> listFiles;
    std::vector<std::string> listTXT;
    int index = 0;
    DIR* dirp = opendir(directory.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        listFiles.push_back(dp->d_name);
    }

    closedir(dirp);
    for (int i = 0; i < listFiles.size(); i++){
        if (listFiles[i].find(".txt") != std::string::npos){
            listTXT.push_back(listFiles[i]);
        }
    }
    for (int i = 0; i < listTXT.size(); i++){
        std::cout << i+1 << ". " << listTXT[i] << std::endl;
    }
    while(index<1 || index >listTXT.size()+1){
        std::cout << "Escolha um arquivo pelo numero" << std::endl;
        std::cin >> index;
        std::cin.ignore();
    }

    nomeArq = listTXT[index-1];
}

bool Board::setBoard() {
    bool sucess = true;
    std::string horizontalHousesB = " abcdefghijklmnopqrst";
    std::string verticalHousesB = " ABCDEFGHIJKLMNOPQRST";
    std::string name;
    std::string line;
    char cord[2];
    char orient;
    int xInitial;
    int yInitial;
    Words word;
    std::ifstream inFile;
    inFile.open(nomeArq);
    inFile >> sizeRow >> name >> sizeCol;
    sizeRow =  sizeRow + 2;
    sizeCol =  sizeCol + 2;
    boardTiles =  new Tiles*[sizeRow];  //Alocando dinamicamente espaço para o vetor
    for (int i=0; i<sizeRow; i++){
        boardTiles[i] = new Tiles[sizeCol];
    }
    for (int i =0; i<sizeRow; i++){ //Setando as tiles para o padrão vazio
        for (int j =0; j<sizeCol; j++) {
            boardTiles[i][j].setTile();
        }
    }
    while((inFile.peek()!=EOF) ){
        inFile >> cord >> orient >> name;
        xInitial = horizontalHousesB.find(cord[1]);
        yInitial = verticalHousesB.find(cord[0]);
        std::transform(name.begin(), name.end(), name.begin(), ::toupper);
        if((name.length() > sizeCol && name.length() > sizeRow) || name.length() < minWord){break;}
        else if(xInitial>sizeCol || xInitial<1){break;}
        else if((yInitial>sizeCol || yInitial<1)){break;}
        else if(orient != HORIZONTAL && orient != VERTICAL){break;}
        word.setWord(name, xInitial, yInitial, orient);
        sucess = isValidaWord(word);
        if(!sucess){
            break;
        }
        saveWord(word);
        nWords = nWords + 1;

    }
    inFile.close();
    return sucess;
}

void Board::print() { // Função pra printar o board com cores se estiver vazio, preenchido e se é possível naquela rodada por uma peça.
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
bool Board::isValidaWord(Words word) {
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

void Board::saveWord(Words word) { // salva a palavra no board
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

int Board::getSizeCol() {
    return sizeCol;
}

int Board::getSizeRow() {
    return sizeRow;
}

Tiles Board::getTiles(int x, int y) {
    return boardTiles[y][x];
}

int Board::getNwords() {
    return nWords;
}

bool Board::isChar(char Let){
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if(alphabet.find(Let) == -1){
        return false;
    }
    else{
        return true;
    }
}