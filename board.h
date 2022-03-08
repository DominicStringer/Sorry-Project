/*********************************
 * File Changes:
 *  Dominic - 3/1/2022
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
        string rules;
    public:
        Board(string rules = "standard");
        /* checkSpecialEvents */
        /* landedOnEnemy */
        /* landedOnSelf */
        /* landedOnSlider */
        /* ranOverSafetyZone */
        void displayBoard();
};

#endif
