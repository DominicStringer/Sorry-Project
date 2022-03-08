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

void Board::displayBoard() {
    for (int i = 0; i < 4; ++i)
        cout << "[ ] [ ] [ ] [ ]" << endl;
}
