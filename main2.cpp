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
    cout << endl;
    for (int i = 0; i < 4; ++i) 
    {
        switch (i) 
        {
            case 0:
                cout << GREEN;
                break;
            case 1:
                cout << RED;
                break;
            case 2:
                cout << BLUE;
                break;
            case 3:
                cout << YELLOW;
                break;
        }
        cout << "① ② ③ ";
    }
    cout << endl << endl;
    return 0;
}
