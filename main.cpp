/******************************************************************************
File Changes:
Connor Rajotte - 3/5/2022
Connor Rajotte - 3/22/2022

Description:
Added a rulebook that displays from "rules.txt"
Added code for player storing

List of Contents:
Main


*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
//#include "board.h"
#include "Player.h"

using namespace std;

int main()
{
    char playGame;
    char str;
    
    int players;
    string name;
    int age;
    int playerNum;

    cout << "Welcome to the game of Sorry!" << endl;
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
    
    
    cout << "Enter the number of players: ";
    cin >> players;
//error checking
    while(cin.fail() || (players > 4 || players < 2))
    {
        cout << "Number of players must be between 1 and 5: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> players;
    }
//players
    Player one;
    Player two;
    Player three;
    Player four;
    cout << "Player 1 enter your name: ";
    cin >> name;
    one.setName(name);
    cout << "Player 1 enter your age: ";
    cin >> age;
    one.setAge(age);
    if(players >= 2)
    {
        cout << "Player 2 enter your name: ";
        cin >> name;
        two.setName(name);
        cout << "Player 2 enter your age: ";
        cin >> age;
        two.setAge(age);
        if(players >= 3)
        {
            cout << "Player 3 enter your name: ";
            cin >> name;
            three.setName(name);
            cout << "Player 3 enter your age: ";
            cin >> age;
            three.setAge(age);
            if(players == 4)
            {
                cout << "Player 4 enter your name: ";
                cin >> name;
                four.setName(name);
                cout << "Player 4 enter your age: ";
                cin >> age;
                four.setAge(age);
            }
        }
    }
    one.display();
    if(players >= 2)
    {
        two.display();
        if(players >= 3)
        {
            three.display();
            if(players == 4)
            {
                four.display();
            }
        }
    }
    return 0;
}