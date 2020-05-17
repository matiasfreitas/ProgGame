//
// Created by matiasfg on 5/2/20.
//

#ifndef BOARDB_TILES_H
#define BOARDB_TILES_H


class Tiles {
        public:
                void setTile(char charT  = ' ', bool validT = false, bool emptiness = true);
                bool getValid();
                char getChar();
                bool getEmpty();

        private:
                char name;
                bool valid;
                bool empty;
};


#endif //MATIASCAMELOSCRABBLE_TILES_H
