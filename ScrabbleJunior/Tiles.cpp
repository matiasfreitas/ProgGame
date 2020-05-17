//
// Created by matiasfg on 5/2/20.
//

#include "Tiles.h"

void TilesG::setTile(char charT, bool validT, bool emptiness)
{
        valid = validT;
        name = charT;
        empty = emptiness;
}

void TilesG::nowValid()
{
        valid = true;
}

void TilesG::nowCover()
{
        valid = false;
        empty = false;
}

bool TilesG::getValid()
{
        return valid;
}

bool TilesG::getEmpty()
{
        return empty;
}

char TilesG::getChar()
{
        return name;
}