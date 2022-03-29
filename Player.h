/******************************************************************************
File Changes:
Connor Rajotte - 3/24/2022

Description:
Created a player class

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
        void setOrder(int playerNum) { this->playerNum = playerNum; }
        void display() { cout << "Player: " << name << ", age: " << age << ", Order: " << playerNum << endl; }
};