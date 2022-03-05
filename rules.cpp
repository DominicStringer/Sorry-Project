/******************************************************************************
File Changes:
Connor Rajotte - 3/5/2022

Description:
Added a rulebook that displays from "rules.txt"

List of Contents:
Main


*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    char playGame;
    char str;

    cout << "Welcome to the game of Sorry" << endl;
    cout << "If you haven't played the game yet or would like to view the rules, press 'y'" << endl;
    cout << "Otherwise, press 'n'" << endl;
    cin >> playGame;
    
//error handling
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
    }
    else if(playGame == 'n')
    {
//gameplay stuff goes here
    }
}