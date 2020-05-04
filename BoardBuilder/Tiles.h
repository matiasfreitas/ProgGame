//
// Created by matiasfg on 5/2/20.
//

#ifndef BOARDB_TILES_H
#define BOARDB_TILES_H


class Tiles {
    public:
        void setTile(char charT  = ' ', bool validT = false, bool emptiness = true){
            valid = validT;
            name = charT;
            empty = emptiness;
        }
        void nowValid(){
            valid = true;
        }
        void nowCover(){
            valid = false;
            empty = false;
        }
        bool getValid(){
            return valid;
        }
        char getChar(){
            return name;
        }

    private:
        char name;
        bool valid;
        bool empty;
};


#endif //MATIASCAMELOSCRABBLE_TILES_H
