//
// Created by matiasfg on 4/27/20.
//

#include "Words.h"
#include <string>
#include <fstream>

#define VERTICAL 'V'
#define HORIZONTAL 'H'

void Words::setWord(std::string str, int xInitial, int yInitial,char orienta) { // Grava as informações da palavra
    cordInitial[0] = xInitial;
    cordInitial[1] = yInitial;
    name = str;
    orient = toupper(orienta);
}

int Words::getX1() {
    return cordInitial[0];
}

int Words::getY1() {
    return cordInitial[1];
}
std::string Words::getName() {
    return name;
}
bool Words::ishorizontal() { // Retorna verdade se é horizontal.
    if (orient == HORIZONTAL){
        return true;
    }
    else{
        return false;
    }
}

void Words::writeWord(std::string nomeArquivo){
    std::ofstream file(nomeArquivo, std::ios::app); // escreve no fim do arquivo a palavra
    file << char(cordInitial[0] + 96) << char(cordInitial[1] + 64) << " " << orient << " " << name << " " << "\n"; //soma o index no array com uma constante para determinar a coordenada em letras
    file.close(); // Fecha o arquivo
}


