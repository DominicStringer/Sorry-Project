/******************************************************************************
File Changes:
Connor Rajotte - 4/5/2022

Description:
removed the intro code from main into its own file

List of Contents:
Intro class


*******************************************************************************/
#include <iostream>
#include <string>

//#include "board.h"

using namespace std;

class Intro
{
    public:
        void intro();
};

void Intro::intro()
{
    char playGame;
    char str;
    
    cout << "Welcome to the game of Sorry!" << endl;
    cout << "If you haven't played the game yet or would like to view the rules, press 'y'" << endl;
    cout << "Otherwise, press 'n'" << endl;
    cin >> playGame;
    
//error checking
    while(playGame != 'y' && playGame != 'n')
    {
        cout << "Enter a valid answer" << endl;
        cin >> playGame;
    }
    
//rulebook
    if(playGame == 'y')
    {
        ifstream rule;
        rule.open("rules.txt");
        
        while(!rule.eof())
        {
            cout << str;
            str = rule.get();
            
        }
        rule.close();

//board display
        cout << endl << endl;
        //Board Sorry;
        //Sorry.displayBoard();
    }
    else if(playGame == 'n')
    {
//board display
        //Board Sorry;
        //Sorry.displayBoard();
    }
}