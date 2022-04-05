/******************************************************************************
File Changes:
Connor Rajotte - 3/24/2022
Connor Rajotte - 4/5/2022

Description:
Created a player class
Moved player error checking from main

List of Contents:
Player Class


*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

class Player
{
    private:
        string name;
        int age;
        int playerNum;
    public:
        void setName(string name) { this->name = name; }
        void setAge(int age) { this->age = age; }
        void setOrder(int);
        void displayOrder(int playerNum) { this->playerNum = playerNum; }
        void display() { cout << "Player: " << name << ", age: " << age << ", Order: " << playerNum << endl; }
};

void Player::setOrder(int playerNum)
{
    int players;
    string name;
    int age;
    
    playerNum = players;
    
//error checking
    do
    {
        cout << "Enter the number of players between 2 and 4: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> players;
    } while(cin.fail() || (players > 4 || players < 2));
//players
    Player one;
    Player two;
    Player three;
    Player four;
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    bool check;
    cout << "Player 1 enter your name: ";
    cin >> name;
//error checking
    for(int x = 0; x < name.length(); x++)
    {
        while(isdigit(name[x]) == true)                     //new stuffs
        {
            cout << "name must not contain numbers" << endl;
            cin >> name;
        }
    }
    one.setName(name);
//error checking
    do
    {
        cout << "Player 1 enter an age between 6 and 80: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> age;
    } while(age < 6 || age >= 80);
    one.setAge(age);
    temp1 = age;
    if(players >= 2)
    {
        cout << "Player 2 enter your name: ";
        cin >> name;
//error checking
        for(int x = 0; x < name.length(); x++)
        {
            while(isdigit(name[x]) == true)                     //new stuffs
            {
                cout << "name must not contain numbers" << endl;
                cin >> name;
            }
        }
        two.setName(name);
//error checking
        do
        {
            cout << "Player 2 enter an age between 6 and 80: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> age;
        } while(age < 6 || age >= 80);
        two.setAge(age);
        temp2 = age;
        if(players >= 3)
        {
            cout << "Player 3 enter your name: ";
            cin >> name;
//error checking
            for(int x = 0; x < name.length(); x++)
            {
                while(isdigit(name[x]) == true)                     //new stuffs
                {
                    cout << "name must not contain numbers" << endl;
                cin >> name;
                }
            }
            three.setName(name);
//error checking
            do
            {
                cout << "Player 3 enter an age between 6 and 80: ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> age;
            } while(age < 6 || age >= 80);
            three.setAge(age);
            temp3 = age;
            if(players == 4)
            {
                cout << "Player 4 enter your name: ";
                cin >> name;
//error checking
                for(int x = 0; x < name.length(); x++)
                {
                    while(isdigit(name[x]) == true)                     //new stuffs
                    {
                        cout << "name must not contain numbers" << endl;
                        cin >> name;
                    }
                }
                four.setName(name);
//error checking
                do
                {
                    cout << "Player 4 enter an age between 6 and 80: ";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> age;
                } while(age < 6 || age >= 80);
                four.setAge(age);
                temp4 = age;
            }
        }
    }
    
//error checking order for 2 players
    if(players == 2)
    {
        if(temp1 <= temp2)
        {
            one.displayOrder(1);
            two.displayOrder(2);
        }
        else
        {
            one.displayOrder(2);
            two.displayOrder(1);
        }
    }
//error checking order for 3 players
    else if(players == 3)
    {
        if((temp1 <= temp2) && (temp2 <= temp3))
        {
            one.displayOrder(1);
            two.displayOrder(2);
            three.displayOrder(3);
        }
        else if((temp2 <= temp1) && (temp1 <= temp3))
        {
            one.displayOrder(2);
            two.displayOrder(1);
            three.displayOrder(3);
        }
        else if((temp1 <= temp3) && (temp3 <= temp2))
        {
            one.displayOrder(1);
            two.displayOrder(3);
            three.displayOrder(2);
        }
        else if((temp3 <= temp1) && (temp1 <= temp2))
        {
            one.displayOrder(3);
            two.displayOrder(1);
            three.displayOrder(2);
        }
        else if((temp2 <= temp3) && (temp3 <= temp1))
        {
            one.displayOrder(2);
            two.displayOrder(3);
            three.displayOrder(1);
        }
        else
        {
            one.displayOrder(3);
            two.displayOrder(2);
            three.displayOrder(1);
        }
    }
//error checking order for 4 players
    else if(players == 4)
    {
        if((temp1 <= temp2) && (temp2 <= temp3) && (temp3 <= temp4))
        {
            one.displayOrder(1);
            two.displayOrder(2);
            three.displayOrder(3);
            four.displayOrder(4);
        }
        else if((temp2 <= temp1) && (temp1 <= temp3) && (temp3 <= temp4))
        {
            one.displayOrder(2);
            two.displayOrder(1);
            three.displayOrder(3);
            four.displayOrder(4);
        }
        else if((temp1 <= temp3) && (temp3 <= temp2) && (temp2 <= temp4))
        {
            one.displayOrder(1);
            two.displayOrder(3);
            three.displayOrder(2);
            four.displayOrder(4);
        }
        else if((temp3 <= temp1) && (temp1 <= temp2) && (temp2 <= temp4))
        {
            one.displayOrder(2);
            two.displayOrder(3);
            three.displayOrder(1);
            four.displayOrder(4);
        }
        else if((temp2 <= temp3) && (temp3 <= temp1) && (temp1 <= temp4))
        {
            one.displayOrder(3);
            two.displayOrder(1);
            three.displayOrder(2);
            four.displayOrder(4);
        }
        else if((temp3 <= temp2) && (temp2 <= temp1) && (temp1 <= temp4))
        {
            one.displayOrder(3);
            two.displayOrder(2);
            three.displayOrder(1);
            four.displayOrder(4);
        }
        else if((temp1 <= temp2) && (temp2 <= temp4) && (temp4 <= temp3))
        {
            one.displayOrder(1);
            two.displayOrder(2);
            three.displayOrder(4);
            four.displayOrder(3);
        }
        else if((temp2 <= temp1) && (temp1 <= temp4) && (temp4 <= temp3))
        {
            one.displayOrder(2);
            two.displayOrder(1);
            three.displayOrder(4);
            four.displayOrder(3);
        }
        else if((temp1 <= temp3) && (temp3 <= temp4) && (temp4 <= temp2))
        {
            one.displayOrder(1);
            two.displayOrder(4);
            three.displayOrder(2);
            four.displayOrder(3);
        }
        else if((temp3 <= temp1) && (temp1 <= temp4) && (temp4 <= temp2))
        {
            one.displayOrder(2);
            two.displayOrder(4);
            three.displayOrder(1);
            four.displayOrder(3);
        }
        else if((temp2 <= temp3) && (temp3 <= temp4) && (temp4 <= temp1))
        {
            one.displayOrder(4);
            two.displayOrder(1);
            three.displayOrder(2);
            four.displayOrder(3);
        }
        else if((temp3 <= temp2) && (temp2 <= temp4) && (temp4 <= temp1))
        {
            one.displayOrder(4);
            two.displayOrder(2);
            three.displayOrder(1);
            four.displayOrder(3);
        }
        else if((temp1 <= temp4) && (temp4 <= temp2) && (temp2 <= temp3))
        {
            one.displayOrder(1);
            two.displayOrder(3);
            three.displayOrder(4);
            four.displayOrder(2);
        }
        else if((temp2 <= temp4) && (temp4 <= temp1) && (temp1 <= temp3))
        {
            one.displayOrder(3);
            two.displayOrder(1);
            three.displayOrder(4);
            four.displayOrder(2);
        }
        else if((temp1 <= temp4) && (temp4 <= temp3) && (temp3 <= temp2))
        {
            one.displayOrder(1);
            two.displayOrder(4);
            three.displayOrder(3);
            four.displayOrder(2);
        }
        else if((temp3 <= temp4) && (temp4 <= temp1) && (temp1 <= temp2))
        {
            one.displayOrder(3);
            two.displayOrder(4);
            three.displayOrder(1);
            four.displayOrder(2);
        }
        else if((temp2 <= temp4) && (temp4 <= temp3) && (temp3 <= temp1))
        {
            one.displayOrder(4);
            two.displayOrder(1);
            three.displayOrder(3);
            four.displayOrder(2);
        }
        else if((temp3 <= temp4) && (temp4 <= temp2) && (temp2 <= temp1))
        {
            one.displayOrder(4);
            two.displayOrder(3);
            three.displayOrder(1);
            four.displayOrder(2);
        }
        else if((temp4 <= temp1) && (temp1 <= temp2) && (temp2 <= temp3))
        {
            one.displayOrder(2);
            two.displayOrder(3);
            three.displayOrder(4);
            four.displayOrder(1);
        }
        else if((temp4 <= temp2) && (temp2 <= temp1) && (temp1 <= temp3))
        {
            one.displayOrder(3);
            two.displayOrder(2);
            three.displayOrder(4);
            four.displayOrder(1);
        }
        else if((temp4 <= temp1) && (temp1 <= temp3) && (temp3 <= temp2))
        {
            one.displayOrder(2);
            two.displayOrder(4);
            three.displayOrder(3);
            four.displayOrder(1);
        }
        else if((temp4 <= temp3) && (temp3 <= temp1) && (temp1 <= temp2))
        {
            one.displayOrder(3);
            two.displayOrder(4);
            three.displayOrder(2);
            four.displayOrder(1);
        }
        else if((temp4 <= temp2) && (temp2 <= temp3) && (temp3 <= temp1))
        {
            one.displayOrder(4);
            two.displayOrder(2);
            three.displayOrder(3);
            four.displayOrder(1);
        }
        else if((temp4 <= temp3) && (temp3 <= temp2) && (temp2 <= temp1))
        {
            one.displayOrder(4);
            two.displayOrder(3);
            three.displayOrder(2);
            four.displayOrder(1);
        }
        else
        {
//p.s. this is a joke, it is not possible to get to this
            cout << "Congratulations on breaking the game." << endl;
            exit(0);
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
}