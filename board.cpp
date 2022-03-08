/*********************************
 * File Changes:
 *  Dominic - 3/3/2022
 * 
 * Description: Sorry Board Functions
 *
 * List of Contents:
 *  
 *********************************/

#include "board.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

Board::Board(string rules) {
    for (int i = 0; i < 60; ++i) {
        boardTiles[i] = 0;
    }

    /* 1: Green Home
     * 2: Red Home
     * 3: Blue Home
     * 4: Yellow Home
     * 5: Slider Start
     * 6: Slider End */

    boardTiles[1] = 5;
    boardTiles[2] = 1; /* Green Home */
    boardTiles[4] = 6;
    boardTiles[9] = 5;
    boardTiles[13] = 6;
    boardTiles[16] = 5;
    boardTiles[17] = 2; /* Red Home */
    boardTiles[19] = 6;
    boardTiles[24] = 5;
    boardTiles[28] = 6;
    boardTiles[31] = 5;
    boardTiles[32] = 3; /* Blue Home */
    boardTiles[34] = 6;
    boardTiles[39] = 5;
    boardTiles[43] = 6;
    boardTiles[46] = 5;
    boardTiles[47] = 4; /* Yellow Home */
    boardTiles[49] = 6;
    boardTiles[54] = 5;
    boardTiles[58] = 6;
}

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define WHITE "\033[37m"

void Board::displayBoard() {
    ifstream fin("board.txt");
    char nextNextBuffer = '0';
    char nextBuffer = '0';
    char buffer = '0';
    char prevBuffer = '0';
    char prevPrevBuffer = '0';
    int count = 0;
    int wait = 0;
    while (fin.get(buffer)) {
        ++count;
        nextBuffer = fin.peek();
        fin.get();
        nextNextBuffer = fin.peek();
        fin.putback(nextBuffer);
        if ((buffer == '-' || buffer == '>' || buffer == 'o') && count <= 151) {
            cout << BLUE;
            cout << buffer;
            cout << WHITE;
        }
        else if ((buffer == -95 && prevBuffer == -106 && prevPrevBuffer == -30) || 
                 (nextBuffer == -95 && buffer == -106 && prevBuffer == -30) ||
                 (nextNextBuffer == -95 && nextBuffer == -106 && buffer == -30)) {
            if (wait == 0)
                cout << GREEN;
            cout << buffer;
            ++wait;
        }
        else
            cout << buffer;
        if (wait == 2) {
            cout << WHITE;
            wait = 0;
        }
        prevPrevBuffer = prevBuffer;
        prevBuffer = buffer;
    }
    char test[4] = "□";
    cout << GREEN;
    cout << test[0];
    cout << WHITE;
    cout << GREEN;
    cout << test[1];
    cout << WHITE;
    cout << GREEN;
    cout << test[2] << endl;
    fin.close();
}
