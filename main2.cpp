#include <iostream>
#include "board.h"

int main() {
    int pawnNum = 0;
    int move = 0;
    Board sorry;
    do
    {
        sorry.displayBoard(-4);
        cin >> pawnNum;
        cin >> move;
        sorry.movePawn(pawnNum, move);
    } while (true);
}
