//
// Created by matiasfg on 4/27/20.
//

#include "Words.h"
#include <string>

void Words::setWord(std::string str, int xInitial, int yInitial, bool orient) {
    size = str.length();
    cordInitial[0] = xInitial;
    cordInitial[1] = yInitial;
    name = str;
}

int Words::getX1() {
    return cordInitial[0];
}

int Words::getY1() {
    return cordInitial[1];
}

