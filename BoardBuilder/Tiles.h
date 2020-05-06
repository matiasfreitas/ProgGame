//
// Created by matiasfg on 5/2/20.
//

#ifndef BOARDB_TILES_H
#define BOARDB_TILES_H


class Tiles {
    public:
        void setTile(char charT  = ' ', bool validT = false, bool emptiness = true);
        void nowValid();
        void nowCover();
        bool getValid();
        char getChar();

    private:
        char name;
        bool valid;
        bool empty;
};


#endif //MATIASCAMELOSCRABBLE_TILES_H
