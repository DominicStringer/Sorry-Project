/******************************************************************************
File Changes:
Connor Rajotte - 4/5/2022 - Removed the intro code from main into its own file
Connor Rajotte - 4/7/2022 - Added exception handling to file i/o and added a function
Connor Rajotte - 4/8/2022 - Added board visibility

Description: File for introduction

List of Contents:
Explanation class
Intro class

*******************************************************************************/
#include <iostream>
#include <string>

#include "board.h"

using namespace std;

class Explanation
{
    private:
        char playGame;
    public:
        char display()
        {
            cout << "Welcome to the game of Sorry!" << endl;
            cout << "If you haven't played the game yet or would like to view the rules, press 'y'" << endl;
            cout << "Otherwise, press 'n'" << endl;
            cin >> playGame;
            
            return playGame;
        }
        
};

class Intro
{
    public:
        void intro();
};


void Intro::intro()
{
    char str;
    string error = "There was an error in the file.";
    char playGame;
    Explanation e;
    
    playGame = e.display();
    
/*error checking*/
    while(playGame != 'y' && playGame != 'n')
    {
        cout << "Enter a valid answer" << endl;
        cin >> playGame;
    }
    
/*rulebook*/
    if(playGame == 'y')
    {
        ifstream rule;
        try
        {
            rule.open("rules.txt");
        
            if(!rule.is_open())
            {
                throw(error);
            }
        }
        catch(string msg)
        {
            cout << msg;
        }
        
        while(!rule.eof() && rule.is_open())
        {
            cout << str;
            str = rule.get();
        }
        rule.close();

/*board display*/
        cout << endl << endl;
        Board Sorry;
        Sorry.displayBoard();
    }
    else if(playGame == 'n')
    {
/*board display*/
        Board Sorry;
        Sorry.displayBoard();
    }
}