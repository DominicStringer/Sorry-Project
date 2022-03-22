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
    public:
        Board();
        int checkEvent(int current, int move);
        void landedOnEnemy();
        void landedOnSelf();
        void landedOnSlider();
        void goInSafety();
        void goOutOfHome();
        void returnHome();
        void goToEnd();
        void changeTile();
        void swap()
        void displayBoard();
};

#endif
