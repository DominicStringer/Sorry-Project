/******************************************************************************
File Changes:
Connor Rajotte - 3/24/2022 - Created file
Connor Rajotte - 4/5/2022 - Moved player error checking from main
Connor Rajotto - 4/9/2022 - Added colors to player profile and added child classes

Description: contains player class

List of Contents:
Player class

*******************************************************************************/
#include <iostream>
#include <string>

#include <time.h>

using namespace std;

class Player
{
    protected:
        string name;
        int age;
        int playerNum;
        string color;
        
        bool win1;
        bool win2;
        bool win3;
        bool win4;
    public:
        void setName(string name) { this->name = name; }
        void setAge(int age) { this->age = age; }
        int setOrder(int);
        void displayOrder(int playerNum) { this->playerNum = playerNum; }
        void displayColor(string color) { this->color = color; }
        void display() { cout << "Player: " << name << ", age: " << age << ", Order: " << playerNum << ", Color: " << color << endl; }
        
        void setValues(int one, int two, int three, int four) { win1 = one; win2 = two; win3 = three; win4 = four; }
        void winDisplay()
        {
            if(win1 == true)
            {
                cout << "Player 1 wins!";
            }
            else if(win2 == true)
            {
                cout << "Player 2 wins!";
            }
            else if(win3 == true)
            {
                cout << "Player 3 wins!";
            }
            else
            {
                cout << "Player 4 wins!";
            }
        }
};



int Player::setOrder(int playerNum)
{
    int players;
    string name;
    int age;
    
    Board Sorry;
    
    playerNum = players;
    
//*error checking*/
    do
    {
        cout << endl;
        cout << "Enter the number of players between 2 and 4: ";
        cout << endl << endl << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> players;
    } while(cin.fail() || (players > 4 || players < 2));
    
    Sorry.displayBoard();
/*players*/
    Player one;
    Player two;
    Player three;
    Player four;
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    bool check;
    
    cout << endl;
    cout << "Player 1 enter your name: ";
    cout << endl << endl << endl;
    cin >> name;
    
/*error checking*/
    for(int x = 0; x < name.length(); x++)
    {
        while(isdigit(name[x]) == true)                     /*new stuffs*/
        {
            cout << endl;
            cout << "name must not contain numbers" << endl;
            cout << endl << endl << endl;
            cin >> name;
        }
    }
    one.setName(name);
    
    Sorry.displayBoard();
    
/*error checking*/
    do
    {
        cout << endl;
        cout << "Player 1 enter an age between 6 and 80: ";
        cout << endl << endl << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> age;
    } while(age < 6 || age >= 80);
    one.setAge(age);
    temp1 = age;
    
    Sorry.displayBoard();
    
    if(players >= 2)
    {
        cout << endl;
        cout << "Player 2 enter your name: ";
        cout << endl << endl << endl;
        cin >> name;
        
/*error checking*/
        for(int x = 0; x < name.length(); x++)
        {
            while(isdigit(name[x]) == true)                     /*new stuffs*/
            {
                cout << endl;
                cout << "name must not contain numbers" << endl;
                cout << endl << endl << endl;
                cin >> name;
            }
        }
        two.setName(name);
        
        Sorry.displayBoard();
        
/*error checking*/
        do
        {
            cout << endl;
            cout << "Player 2 enter an age between 6 and 80: ";
            cout << endl << endl << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> age;
        } while(age < 6 || age >= 80);
        two.setAge(age);
        temp2 = age;
        
        Sorry.displayBoard();
        
        if(players >= 3)
        {
            cout << endl;
            cout << "Player 3 enter your name: ";
            cout << endl << endl << endl;
            cin >> name;
            
/*error checking*/
            for(int x = 0; x < name.length(); x++)
            {
                while(isdigit(name[x]) == true)                     /*new stuffs*/
                {
                    cout << endl;
                    cout << "name must not contain numbers" << endl;
                    cout << endl << endl << endl;
                    cin >> name;
                }
            }
            three.setName(name);
            
            Sorry.displayBoard();
            
/*error checking*/
            do
            {
                cout << endl;
                cout << "Player 3 enter an age between 6 and 80: ";
                cout << endl << endl << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> age;
            } while(age < 6 || age >= 80);
            three.setAge(age);
            temp3 = age;
            
            Sorry.displayBoard();
            
            if(players == 4)
            {
                cout << endl;
                cout << "Player 4 enter your name: ";
                cout << endl << endl << endl;
                cin >> name;
                
/*error checking*/
                for(int x = 0; x < name.length(); x++)
                {
                    while(isdigit(name[x]) == true)                     /*new stuffs*/
                    {
                        cout << endl;
                        cout << "name must not contain numbers" << endl;
                        cout << endl << endl << endl;
                        cin >> name;
                    }
                }
                four.setName(name);
                
                Sorry.displayBoard();
                
/*error checking*/
                do
                {
                    cout << endl;
                    cout << "Player 4 enter an age between 6 and 80: ";
                    cout << endl << endl << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> age;
                } while(age < 6 || age >= 80);
                four.setAge(age);
                temp4 = age;
                
                Sorry.displayBoard();
            }
        }
    }
    
/*error checking order for 2 players*/
    if(players == 2)
    {
        if(temp1 <= temp2)
        {
            one.displayOrder(1);
            two.displayOrder(2);
            
            one.displayColor("green");
            two.displayColor("red");
        }
        else
        {
            one.displayOrder(2);
            two.displayOrder(1);
            
            one.displayColor("red");
            two.displayColor("green");
        }
    }
    
/*error checking order for 3 players*/
    else if(players == 3)
    {
        if((temp1 <= temp2) && (temp2 <= temp3))
        {
            one.displayOrder(1);
            two.displayOrder(2);
            three.displayOrder(3);
            
            one.displayColor("green");
            two.displayColor("red");
            three.displayColor("blue");
        }
        else if((temp2 <= temp1) && (temp1 <= temp3))
        {
            one.displayOrder(2);
            two.displayOrder(1);
            three.displayOrder(3);
            
            one.displayColor("red");
            two.displayColor("green");
            three.displayColor("blue");
        }
        else if((temp1 <= temp3) && (temp3 <= temp2))
        {
            one.displayOrder(1);
            two.displayOrder(3);
            three.displayOrder(2);
            
            one.displayColor("green");
            two.displayColor("blue");
            three.displayColor("red");
        }
        else if((temp3 <= temp1) && (temp1 <= temp2))
        {
            one.displayOrder(3);
            two.displayOrder(1);
            three.displayOrder(2);
            
            one.displayColor("blue");
            two.displayColor("green");
            three.displayColor("red");
        }
        else if((temp2 <= temp3) && (temp3 <= temp1))
        {
            one.displayOrder(2);
            two.displayOrder(3);
            three.displayOrder(1);
            
            one.displayColor("red");
            two.displayColor("blue");
            three.displayColor("green");
        }
        else
        {
            one.displayOrder(3);
            two.displayOrder(2);
            three.displayOrder(1);
            
            one.displayColor("blue");
            two.displayColor("red");
            three.displayColor("green");
        }
    }
    
/*error checking order for 4 players*/
    else if(players == 4)
    {
        if((temp1 <= temp2) && (temp2 <= temp3) && (temp3 <= temp4))
        {
            one.displayOrder(1);
            two.displayOrder(2);
            three.displayOrder(3);
            four.displayOrder(4);
            
            one.displayColor("green");
            two.displayColor("red");
            three.displayColor("blue");
            four.displayColor("yellow");
        }
        else if((temp2 <= temp1) && (temp1 <= temp3) && (temp3 <= temp4))
        {
            one.displayOrder(2);
            two.displayOrder(1);
            three.displayOrder(3);
            four.displayOrder(4);
            
            one.displayColor("red");
            two.displayColor("green");
            three.displayColor("blue");
            four.displayColor("yellow");
        }
        else if((temp1 <= temp3) && (temp3 <= temp2) && (temp2 <= temp4))
        {
            one.displayOrder(1);
            two.displayOrder(3);
            three.displayOrder(2);
            four.displayOrder(4);
            
            one.displayColor("green");
            two.displayColor("blue");
            three.displayColor("red");
            four.displayColor("yellow");
        }
        else if((temp3 <= temp1) && (temp1 <= temp2) && (temp2 <= temp4))
        {
            one.displayOrder(2);
            two.displayOrder(3);
            three.displayOrder(1);
            four.displayOrder(4);
            
            one.displayColor("red");
            two.displayColor("blue");
            three.displayColor("green");
            four.displayColor("yellow");
        }
        else if((temp2 <= temp3) && (temp3 <= temp1) && (temp1 <= temp4))
        {
            one.displayOrder(3);
            two.displayOrder(1);
            three.displayOrder(2);
            four.displayOrder(4);
            
            one.displayColor("blue");
            two.displayColor("green");
            three.displayColor("red");
            four.displayColor("yellow");
        }
        else if((temp3 <= temp2) && (temp2 <= temp1) && (temp1 <= temp4))
        {
            one.displayOrder(3);
            two.displayOrder(2);
            three.displayOrder(1);
            four.displayOrder(4);
            
            one.displayColor("blue");
            two.displayColor("red");
            three.displayColor("green");
            four.displayColor("yellow");
        }
        else if((temp1 <= temp2) && (temp2 <= temp4) && (temp4 <= temp3))
        {
            one.displayOrder(1);
            two.displayOrder(2);
            three.displayOrder(4);
            four.displayOrder(3);
            
            one.displayColor("green");
            two.displayColor("red");
            three.displayColor("yellow");
            four.displayColor("blue");
        }
        else if((temp2 <= temp1) && (temp1 <= temp4) && (temp4 <= temp3))
        {
            one.displayOrder(2);
            two.displayOrder(1);
            three.displayOrder(4);
            four.displayOrder(3);
            
            one.displayColor("red");
            two.displayColor("green");
            three.displayColor("yellow");
            four.displayColor("blue");
        }
        else if((temp1 <= temp3) && (temp3 <= temp4) && (temp4 <= temp2))
        {
            one.displayOrder(1);
            two.displayOrder(4);
            three.displayOrder(2);
            four.displayOrder(3);
            
            one.displayColor("green");
            two.displayColor("yellow");
            three.displayColor("red");
            four.displayColor("blue");
        }
        else if((temp3 <= temp1) && (temp1 <= temp4) && (temp4 <= temp2))
        {
            one.displayOrder(2);
            two.displayOrder(4);
            three.displayOrder(1);
            four.displayOrder(3);
            
            one.displayColor("red");
            two.displayColor("yellow");
            three.displayColor("green");
            four.displayColor("blue");
        }
        else if((temp2 <= temp3) && (temp3 <= temp4) && (temp4 <= temp1))
        {
            one.displayOrder(4);
            two.displayOrder(1);
            three.displayOrder(2);
            four.displayOrder(3);
            
            one.displayColor("yellow");
            two.displayColor("green");
            three.displayColor("red");
            four.displayColor("blue");
        }
        else if((temp3 <= temp2) && (temp2 <= temp4) && (temp4 <= temp1))
        {
            one.displayOrder(4);
            two.displayOrder(2);
            three.displayOrder(1);
            four.displayOrder(3);
            
            one.displayColor("yellow");
            two.displayColor("red");
            three.displayColor("green");
            four.displayColor("blue");
        }
        else if((temp1 <= temp4) && (temp4 <= temp2) && (temp2 <= temp3))
        {
            one.displayOrder(1);
            two.displayOrder(3);
            three.displayOrder(4);
            four.displayOrder(2);
            
            one.displayColor("green");
            two.displayColor("blue");
            three.displayColor("yellow");
            four.displayColor("red");
        }
        else if((temp2 <= temp4) && (temp4 <= temp1) && (temp1 <= temp3))
        {
            one.displayOrder(3);
            two.displayOrder(1);
            three.displayOrder(4);
            four.displayOrder(2);
            
            one.displayColor("blue");
            two.displayColor("green");
            three.displayColor("yellow");
            four.displayColor("red");
        }
        else if((temp1 <= temp4) && (temp4 <= temp3) && (temp3 <= temp2))
        {
            one.displayOrder(1);
            two.displayOrder(4);
            three.displayOrder(3);
            four.displayOrder(2);
            
            one.displayColor("green");
            two.displayColor("yellow");
            three.displayColor("blue");
            four.displayColor("red");
        }
        else if((temp3 <= temp4) && (temp4 <= temp1) && (temp1 <= temp2))
        {
            one.displayOrder(3);
            two.displayOrder(4);
            three.displayOrder(1);
            four.displayOrder(2);
            
            one.displayColor("blue");
            two.displayColor("yellow");
            three.displayColor("green");
            four.displayColor("red");
        }
        else if((temp2 <= temp4) && (temp4 <= temp3) && (temp3 <= temp1))
        {
            one.displayOrder(4);
            two.displayOrder(1);
            three.displayOrder(3);
            four.displayOrder(2);
            
            one.displayColor("yellow");
            two.displayColor("green");
            three.displayColor("blue");
            four.displayColor("red");
        }
        else if((temp3 <= temp4) && (temp4 <= temp2) && (temp2 <= temp1))
        {
            one.displayOrder(4);
            two.displayOrder(3);
            three.displayOrder(1);
            four.displayOrder(2);
            
            one.displayColor("yellow");
            two.displayColor("blue");
            three.displayColor("green");
            four.displayColor("red");
        }
        else if((temp4 <= temp1) && (temp1 <= temp2) && (temp2 <= temp3))
        {
            one.displayOrder(2);
            two.displayOrder(3);
            three.displayOrder(4);
            four.displayOrder(1);
            
            one.displayColor("red");
            two.displayColor("blue");
            three.displayColor("yellow");
            four.displayColor("green");
        }
        else if((temp4 <= temp2) && (temp2 <= temp1) && (temp1 <= temp3))
        {
            one.displayOrder(3);
            two.displayOrder(2);
            three.displayOrder(4);
            four.displayOrder(1);
            
            one.displayColor("blue");
            two.displayColor("red");
            three.displayColor("yellow");
            four.displayColor("green");
        }
        else if((temp4 <= temp1) && (temp1 <= temp3) && (temp3 <= temp2))
        {
            one.displayOrder(2);
            two.displayOrder(4);
            three.displayOrder(3);
            four.displayOrder(1);
            
            one.displayColor("red");
            two.displayColor("yellow");
            three.displayColor("blue");
            four.displayColor("green");
        }
        else if((temp4 <= temp3) && (temp3 <= temp1) && (temp1 <= temp2))
        {
            one.displayOrder(3);
            two.displayOrder(4);
            three.displayOrder(2);
            four.displayOrder(1);
            
            one.displayColor("blue");
            two.displayColor("yellow");
            three.displayColor("red");
            four.displayColor("green");
        }
        else if((temp4 <= temp2) && (temp2 <= temp3) && (temp3 <= temp1))
        {
            one.displayOrder(4);
            two.displayOrder(2);
            three.displayOrder(3);
            four.displayOrder(1);
            
            one.displayColor("yellow");
            two.displayColor("red");
            three.displayColor("blue");
            four.displayColor("green");
        }
        else if((temp4 <= temp3) && (temp3 <= temp2) && (temp2 <= temp1))
        {
            one.displayOrder(4);
            two.displayOrder(3);
            three.displayOrder(2);
            four.displayOrder(1);
            
            one.displayColor("yellow");
            two.displayColor("blue");
            three.displayColor("red");
            four.displayColor("green");
        }
        else
        {
/*p.s. this is a joke, it is not possible to get to this*/
            cout << "Congratulations on breaking the game." << endl;
            return -1;
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
            else
            {
                cout << endl;
            }
        }
        else
        {
            cout << endl << endl;
        }
    }
    else
    {
        cout << endl << endl << endl;
    }
/*timer for 4 seconds*/
    clock_t start_time = clock();
    while (clock() < start_time + 4000000)
        {}
    return players;
}

/*child classes to declare winner*/
class winner1: public Player
{
    public:
        bool winCheck() { return win1 = true; }
};

class winner2: public Player
{
    public:
        bool winCheck() { return win2 = true; }
};

class winner3: public Player
{
    public:
        bool winCheck() { return win3 = true; }
};

class winner4: public Player
{
    public:
        bool winCheck() { return win4 = true; }
};