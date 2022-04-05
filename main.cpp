/******************************************************************************
File Changes:
Connor Rajotte - 3/5/2022
Connor Rajotte - 3/22/2022
Connor Rajotte - 3/31/2022
Connor Rajotte - 4/5/2022

Description:
Added a rulebook that displays from "rules.txt"
Added code for player storing
fixed error checking and added new isdigit() to check for numbers in names
moved player error checking and intro to separate header files

List of Contents:
Main


*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

#include "Intro.h"
#include "Player.h"

using namespace std;

int main()
{
//variables
    int players;
    Intro i;
//calling classes
    Player p;
    i.intro();
    
    p.setOrder(0);
//player interaction
    cout << endl;
    cout << "Player 1 what do you want to do?" << endl;
    
    return 0;
}