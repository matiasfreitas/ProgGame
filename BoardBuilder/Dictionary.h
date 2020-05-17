//
// Created by matia on 16/05/2020.
//

#ifndef MATIASCAMELOSCRABBLE_DICTIONARY_H
#define MATIASCAMELOSCRABBLE_DICTIONARY_H
#include <string>
#include <vector>

class Dictionary{
        private:
                std::vector<std::string> string_vec;
                std::string filename = "C:/Users/matia/OneDrive/Imagens/Documentos/MatiasCameloScrabble/BoardBuilder/WORDS.TXT";
        public:
                void setDictVector();
                void printDict();
                bool isInDict(std::string word);
};

#endif //MATIASCAMELOSCRABBLE_DICTIONARY_H
