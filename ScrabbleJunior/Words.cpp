//
// Created by matiasfg on 4/27/20.
//

#include "Words.h"
#include <string>
#include <fstream>

void Words::setWord(std::string str, int xInitial, int yInitial,char orienta)
{
        cordInitial[0] = xInitial;
        cordInitial[1] = yInitial;
        name = str;
        orient = toupper(orienta);
}

int Words::getX1()
{
        return cordInitial[0];
}

int Words::getY1()
{
        return cordInitial[1];
}

std::string Words::getName()
{
        return name;
}

bool Words::ishorizontal()
{
        if (orient == 'H'){
                return true;
        }
        else{
                return false;
        }
}

void Words::writeWord(std::string nomeArquivo)
{
        std::ofstream file(nomeArquivo, std::ios::app);
        file << char(cordInitial[0] + 96) << char(cordInitial[1] + 64)
                    << " " << orient << " " << name << " " << "\n";
        file.close();
}