//
// Created by matiasfg on 05/05/20.
//

#ifndef MATIASCAMELOSCRABBLE_COLORS_H
#define MATIASCAMELOSCRABBLE_COLORS_H
        #ifdef linux
                #include <iostream>
                #include <string>
                #include <sstream>
                #include <unistd.h>
                #define BLACK "\u001b[30m"
                #define RED "\033[0;31m"
                #define GREEN "\033[0;32m"
                #define BLUE "\033[0;34m"
                #define MAGENTA "\033[0;35m"
                #define CYAN "\033[0;36m"
                #define YELLOW "\033[1;33m"
                #define WHITE "\u001b[37m"
                #define BLACK_B "\u001b[0m"
                #define RED_B "\033[0;41m"
                #define GREEN_B "\033[0;42m"
                #define YELLOW_B "\033[0;43m"
                #define BLUE_B "\033[0;44m"
                #define MAGENTA_B "\033[0;45m"
                #define CYAN_B "\033[0;46m"
                #define WHITE_B "\u001b[47m"
        #endif

        #ifdef _WIN32
                #include <iostream>
                #include <ctime>
                #include <cstdlib>
                #include <windows.h>
                #define BLACK 0
                #define BLUE 1
                #define GREEN 2
                #define CYAN 3
                #define RED 4
                #define MAGENTA 5
                #define YELLOW 14
                #define WHITE 15
                #define BLACK_B 0
                #define RED_B 4
                #define GREEN_B 2
                #define YELLOW_B 14
                #define BLUE_B 1
                #define MAGENTA_B 5
                #define CYAN_B 3
                #define WHITE_B 15

        #endif
        #ifdef linux
                void gotoxy(int x, int y);
                void clrscr(void);
                void setcolor(std::string color, std::string background_color);

        #endif
        #ifdef _WIN32
                void clrscr();
                void gotoxy(int x, int y);
                void setcolor(unsigned int color, unsigned int background_color);
        #endif

#endif