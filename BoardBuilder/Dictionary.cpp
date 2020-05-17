//
// Created by matia on 16/05/2020.
//
#include "Dictionary.h"
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <bits/stdc++.h>

void Dictionary::setDictVector()
{
        std::ifstream dict_file(filename);
        std::string line;
        while(std::getline(dict_file, line)){
                line = line;
                string_vec.push_back(line);
        }
}

bool Dictionary::isInDict(std::string word)
{
        std::transform(word.begin(), word.end(),word.begin(), ::tolower);
        bool isSameWord = false;
        int bottom = 0;
        int upper = string_vec.size();
        int indexSearch;
        while(bottom <= upper) {
                indexSearch = (bottom + upper)/2;
                if(string_vec[indexSearch]> word) {
                        upper = indexSearch - 1;
                } else if(string_vec[indexSearch]< word) {
                        bottom = indexSearch + 1;
                } else if(string_vec[indexSearch]== word){
                        isSameWord = true;
                        break;
                }
        }

        return isSameWord;
}

