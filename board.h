/*********************************
 * File Changes:
 *  Dominic - 3/1/2022
 *  Dominic - 3/22/2022
 * 
 * Description: The Sorry Board Class with Function Declarations
 *
 * List of Contents:
 *  Board Class
 *   
 *********************************/

#ifndef BOARD
#define BOARD

#include <iostream>
#include <string.h>
using namespace std;

class Board {
    private:
        int boardTiles[60];
        int playerTiles[60];
    public:
        Board();
        int doEvents(int playerNum, int current, int move);
        int loopLanded(int landed);
        int onEnemy(int playerNum, int landed);
        bool onSelf(int playerNum, int landed);
        bool onSlider(int landed);
        bool inSafety(int playerNum, int current, int move);
        void displayBoard();
};

#endif
