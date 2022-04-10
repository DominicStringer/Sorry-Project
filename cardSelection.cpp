/******************************************************************************
File Changes:
Connor Rajotte - 4/8/2022 - Created file

Description: random number generator for selecting cards

List of Contents:
cardSelection function

*******************************************************************************/
#include <iostream>
#include <string>

#include <time.h>

using namespace std;

int cardSelection()
{
    int num;
    int choice;
    srand(time(NULL));
    num = rand()%45+1;
    
    if(num >= 1 && num <= 5)
    {
        cout << "You drew a 1" << endl;
        return 1;
    }
    
    else if(num >= 6 && num <= 9)
    {
        cout << "You drew a 2" << endl;
        return 2;
    }
    
    else if(num >= 10 && num <= 13)
    {
        cout << "You drew a 3" << endl;
        return 3;
    }
    
    else if(num >= 14 && num <= 17)
    {
        cout << "You drew a 4" << endl;
        return -4;
    }
    
    else if(num >= 18 && num <= 21)
    {
        cout << "You drew a 5" << endl;
        return 5;
    }
    
    else if(num >= 22 && num <= 25)
    {
        cout << "You drew a 7" << endl;
        do
        {
            cout << "Do you want to move one pawn forward 7 tiles(1) or two pawns forward seven combined tiles(2)? ";
            cin >> choice;
            if(choice == 1)
            {
                return 7;
            }
            else
            {
                return 13;
            }
        } while(choice != 1 && choice != 2);
    }
    
    else if(num >= 26 && num <= 29)
    {
        cout << "You drew an 8" << endl;
        return 8;
    }
    
    else if(num >= 30 && num <= 33)
    {
        cout << "You drew a 10" << endl;
        do
        {
            cout << "do you want to move your pawn forward 10 tiles(1) or back 1 tile(2)? ";
            cin >> choice;
            if(choice == 1)
            {
                return 10;
            }
            else
            {
                return -1;
            }
        } while(choice != 1 && choice != 2);
    }
    
    else if(num >= 34 && num <= 37)
    {
        cout << "You drew an 11" << endl;
        return 11;
    }
    
    else if(num >= 38 && num <= 41)
    {
        cout << "You drew a 12" << endl;
        return 12;
    }
    
    else if(num >= 42 && num <= 45)
    {
        cout << "You drew a Sorry!" << endl;
        return 14;
    }
    
    return num;
}