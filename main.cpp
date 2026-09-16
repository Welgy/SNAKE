
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <ncurses.h>
#include <vector>
using namespace std;

int main()
{
    initscr();
    cbreak();   
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    int X = 5, Y = 1;
    srand(time(0));
    int xr = rand() % 23, yr = rand() % 10;
    bool stop = false;
    int flag2 = 1;
    vector <int> fullX = {2, 3, 4, 5};
    vector <int> fullY = {1, 1, 1, 1};
    while(stop == false){
        if(X == 24 || X == 0 || Y == 0 || Y == 11){
                break;
            }
            for(int i = 0; i < fullX.size() - 1; i++){
                if(X == fullX[i] && Y == fullY[i]){
                    stop = true;
                    break;
                }
            }
        int ch = getch();
        if (ch != ERR) {
            if(ch == 259){
                flag2 = 4;
            }
            else if(ch == 258){
                flag2 = 2;
            }
            else if(ch == KEY_LEFT){
                flag2 = 3;
            }
            else if(ch == KEY_RIGHT){
                flag2 = 1;
            }
    }
            if(X - 1 == xr && Y - 1 == yr){
                xr = rand() % 23;
                yr = rand() % 10;
                fullX.push_back(X);
                fullY.push_back(Y);
            }
            else {
                fullX.push_back(X);
                fullX.erase(fullX.begin());
                fullY.push_back(Y);
                fullY.erase(fullY.begin());
            }
        clear();
       for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 25; j++) {
        bool isSnake = false;
        for (int k = 0; k < fullY.size(); k++) {
            if (fullY[k] == i && fullX[k] == j) {
                isSnake = true;
                break;
            }
        }
        if (isSnake == true)                    mvaddch(i, j, 'O');
        else if (i == 0)                mvaddch(i, j, '_');
        else if (i == 11)               mvaddch(i, j, '-');
        else if (j == 0 || j == 24)     mvaddch(i, j, '|');
        else if (xr == j - 1 && yr == i - 1)    mvaddch(i, j, 'Q');
        else                            mvaddch(i, j, ' ');
    }
}
    if(flag2 == 1){
         X++;
         refresh();
    napms(100);
    }
    else if(flag2 == 2){
         Y++;
         refresh();
    napms(200);
    }
    else if(flag2 == 3){
         X--;
         refresh();
    napms(100);
    }
    else if(flag2 == 4){
         Y--;
         refresh();
    napms(200);
    }
    }
    endwin();
    return 0;
}