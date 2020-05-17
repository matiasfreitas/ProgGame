//
// Created by matiasfg on 5/2/20.
//

#include "Tiles.h"

void Tiles::setTile(char charT, bool validT, bool emptiness)
{
        valid = validT;
        name = charT;
        empty = emptiness;
}

bool Tiles::getValid()
{
    return valid;
}

bool Tiles::getEmpty()
{
    return empty;
}

char Tiles::getChar()
{
    return name;
}
