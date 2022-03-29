/*********************************
 * File Changes:
 *  Dominic - 3/3/2022
 * 
 * Description: Dummy Main for Board Class and Functions
 *
 * List of Contents:
 *  Card Class
 *  CardSorry Class
 *  Card1 Class
 *  Card2 Class
 *  Card3 Class
 *  Card4 Class
 *  Card5 Class
 *  Card7 Class
 *  Card8 Class
 *  Card10 Class
 *  Card11 Class
 *  Card12 Class
 *********************************/

#include "board.h"
#include <iostream>
using namespace std;

int main() {
    Board Sorry;
    Sorry.displayBoard();
    cout << Sorry.movePawn(0, 10) << endl;
    cout << Sorry.movePawn(1, 10) << endl;
    cout << Sorry.movePawn(0, 10) << endl;
}
