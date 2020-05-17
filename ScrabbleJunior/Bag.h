//
// Created by matiasfg on 4/27/20.
//

#ifndef PROGGAME_BAG_H
#define PROGGAME_BAG_H
#include "Board.h"

class Bag {
        private:
                std::string bagTiles;
        public:
                void setBagTiles(Board board);
                std::string tradeTile(std::string tileReceive = "");
                int sizeBag();
};


#endif //PROGGAME_BAG_H
