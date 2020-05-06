//
// Created by matiasfg on 4/27/20.
// Camelo, nao estou conseguindo usar o arquivo source aqi. Mas essa funçao era pra estar no .cpp

#ifndef BOARDB_WORDS_H
#define BOARDB_WORDS_H

#include <string>

class Words{
public:
    void setWord(std::string str, int xInitial, int yInitial, bool orient);
    int getX1();
    int getY1();

private:
    int size;
    int cordInitial[2];
    std::string name;
    int nCoverd = 0;
};


#endif //BOARDB_WORDS_H