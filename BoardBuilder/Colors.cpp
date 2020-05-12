//
// Created by matiasfg on 05/05/20.
//

#include "Colors.h"
#ifdef linux

void gotoxy(int x, int y){
    std::ostringstream oss;
    oss << "\033[" << y << ";" << x << "H";
    std::cout << oss.str();
}

void clrscr(void) {
    std::cout << "\033[2J";
    gotoxy(0, 0);
}

void setcolor(std::string color, std::string background_color) { std::cout << color << background_color; }


#endif
#ifdef defined(_WIN32) || defined(WIN32)
void setcolor(unsigned int color, unsigned int background_color) {
    std::HANDLE hCon = GetStdHandle(std::STD_OUTPUT_HANDLE);
    if (background_color == BLACK){
        SetConsoleTextAttribute(hCon, color);
    }
    else{
        SetConsoleTextAttribute(hCon, color | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
    }
}

void gotoxy(int x, int y) {
    std::COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(std::STD_OUTPUT_HANDLE), coord);
}

void clrscr() {
    std::COORD coordScreen = {0, 0};
    std::DWORD cCharsWritten;
    std::DWORD dwConSize;
    std::HANDLE hCon = GetStdHandle(std::STD_OUTPUT_HANDLE);
    std::CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hCon, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hCon, std::TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
    GetConsoleScreenBufferInfo(hCon, &csbi);
    FillConsoleOutputAttribute(hCon, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
    SetConsoleCursorPosition(hCon, coordScreen);
}
#endif