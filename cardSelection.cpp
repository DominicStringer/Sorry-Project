/******************************************************************************
File Changes:
Connor Rajotte - 4/8/2022 - Created file

Description: random number generator for selecting cards

List of Contents:
cardSelection function

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int cardSelection()
{
    int num;
    int choice;
    srand(time(NULL));
    num = rand()%41+1;
    
    if(num >= 1 && num <= 5)
    {
        return 1;
    }
    
    else if(num >= 6 && num <= 9)
    {
        return 2;
    }
    
    else if(num >= 10 && num <= 13)
    {
        return 3;
    }
    
    else if(num >= 14 && num <= 17)
    {
        return -4;
    }
    
    else if(num >= 18 && num <= 21)
    {
        return 5;
    }
    
    else if(num >= 22 && num <= 25)
    {
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
        return 8;
    }
    
    else if(num >= 30 && num <= 33)
    {
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
        return 11;
    }
    
    else if(num >= 38 && num <= 41)
    {
        return 12;
    }
    
    return num;
}