//
// Created by matiasfg on 4/27/20.
// Camelo, nao estou conseguindo usar o arquivo source aqi. Mas essa funçao era pra estar no .cpp

#ifndef BOARDB_WORDS_H
#define BOARDB_WORDS_H

#include <string>

class Words{
public:
    void setWord(std::string str, int xInitial, int yInitial, char orienta);
    int getX1();
    int getY1();
    bool ishorizontal();
    void writeWord(std::string nomeArquivo);
    std::string getName();

private:
    int cordInitial[2];
    std::string name;
    char orient;
};


#endif //BOARDB_WORDS_H