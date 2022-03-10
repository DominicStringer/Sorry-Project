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
    int i = 0;
    char buffer = '0';
    while (fin.get(buffer)) {
        switch (i) {
            case 137:
            case 163:
            case 210:
            case 312:
            case 390:
            case 490:
            case 546:
            case 657:
            case 738:
            case 814:
            case 890:
                cout << RED;
                break;
            case 232:
            case 330:
            case 408:
            case 508:
            case 570:
                cout << BLUE;
                break;
            case 310:
            case 388:
            case 488:
            case 544:
            case 652:
                cout << GREEN;
                break;
            case 680:
            case 769:
            case 830:
            case 920:
                cout << YELLOW;
                break;
            case 148:
            case 175:
            case 229:
            case 288:
            case 366:
            case 456:
            case 535:
            case 617:
            case 708:
            case 763:
            case 785:
            case 860:
            case 943:
                cout << WHITE;
                break;
        }
        cout << buffer;
        ++i;
    }
    cout << endl;
    fin.close();
}
