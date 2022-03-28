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

#include "pawn.h"
#include <iostream>
#include <string.h>
using namespace std;

class Board {
    private:
        int boardTiles[60];
        int playerTiles[60];
        Pawn pawn[12];
    public:
        Board();
        int movePawn(int pawnNum, int move);
        bool onEnemy(int pawnNum, int landed);
        bool onSelf(int pawnNum, int landed);
        bool onSlider(int landed);
        bool inSafety(int pawnNum, int current, int move);
        int loopLanded(int landed);
        int getSafetyEntry(int pawnNum);
        void displayBoard();
};

#endif
