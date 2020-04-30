//
// Created by matiasfg on 4/27/20.
// Camelo, nao estou conseguindo usar o arquivo source aqi. Mas essa funçao era pra estar no .cpp

#ifndef BOARDB_WORDS_H
#define BOARDB_WORDS_H

#include <string>

class Words{
    public:
        void setWord(std::string str, int xInitial, int yInitial, bool orient){
            size = str.length();
            cordInitial[0] = xInitial;
            cordInitial[1] = yInitial;
            name = str;
            if  (orient){

                cordFinal[0] = xInitial + size ;
                cordFinal[1] = yInitial;
            }
            else{

                cordFinal[0] = xInitial;
                cordFinal[1] = yInitial + size;
            }
        }
        int getX1(){
            return cordInitial[0];
        }
        int getX2(){
            return cordFinal[0];
        }
        int getY1(){
            return cordInitial[1];
        }
        int getY2(){
            return cordFinal[1];
        }
    private:
        int size;
        int cordInitial[2];
        int cordFinal[2];
        std::string name;
        int nCoverd = 0;
};


#endif //BOARDB_WORDS_H
