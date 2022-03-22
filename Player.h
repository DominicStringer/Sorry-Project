/*********************************
 * File Changes:
 *  Connor - 3/22/2022
 * 
 * Description: Player Class
 *
 * List of Contents:
 *  Player Class
 *   
 *********************************/
#include <iostream>
#include <fstream>
#include <string>
#include "board.h"

using namespace std;

class Player
{
    private:
        string name;
        int age;
    public:
        void setName(string name) { this->name = name; }
        void setAge(int age) { this->age = age; }
        void display() { cout << "Player : " << name << " age: " << age << endl; }
};