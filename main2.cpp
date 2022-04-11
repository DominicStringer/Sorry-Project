#include <iostream>
#include "board.h"
using namespace std;

int main() {
    Board Sorry;
    Sorry.movePawn(3,1);
    cout << "BEFORE" << endl;
    Sorry.displayBoard(10);
    Sorry.sorry(0, 3);
    cout << "AFTER" << endl;
    Sorry.displayBoard(10);
    return 0;
}
