//
// Created by matiasfg on 5/2/20.
//

#ifndef BOARDB_TILES_H
#define BOARDB_TILES_H


class TilesG {
        public:
                void setTile(char charT  = ' ', bool validT = false, bool emptiness = true);
                void nowValid();
                void nowCover();
                bool getValid();
                char getChar();
                bool getEmpty();

        private:
                char name = ' ';
                bool valid = false;
                bool empty = true;
};


#endif //MATIASCAMELOSCRABBLE_TILES_H