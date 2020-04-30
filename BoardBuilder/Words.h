//
// Created by matiasfg on 4/27/20.
//

#ifndef PROGGAME_WORDS_H
#define PROGGAME_WORDS_H


class Words {
    //delete
    public:
        int tamanho;
        int coordenadas[2];
        char orientacao;
        words(int aTamanho, int aCoordenadas[2], char aOrientacao){
            tamanho = aTamanho;
            coordenadas = aCoordenadas;
            orientatacao = aOrientacao;
        }

        int preenchimento[tamanho];

};


#endif //PROGGAME_WORDS_H
