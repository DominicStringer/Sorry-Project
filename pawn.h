/*********************************
 * File Changes:
 *  Dominic - 3/27/2022
 * 
 * Description: Pawn Class
 *
 * List of Contents:
 *  
 *********************************/

#include <iostream>
using namespace std;

#ifndef PAWN
#define PAWN

class Pawn {
    private:
        int status; /* 0 - in Start, 1 - on Board, 2 - in Safety, 3 - in Home */
        int position;
    public:
        Pawn() {position = 0; status = 0;}
        void setPos(int newPosition) {position = newPosition;}
        int getPos() {return position;}
        void setStatus(int newStatus) {status = newStatus;}
        int getStatus() {return status;}
};

#endif
