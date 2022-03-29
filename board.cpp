/*********************************
 * File Changes:
 *  Dominic - 3/3/2022
 *  Dominic - 3/22/2022
 *  Dominic - 3/27/2022
 *  Dominic - 3/28/2022
 * 
 * Description: Sorry Board Functions
 *
 * List of Contents:
 *   - Board()
 *   - movePawn()
 *   - onEnemy()
 *   - onSelf()
 *   - onSlider()
 *   - inSafety()
 *   - loopLanded()
 *   - getSafetyEntry()
 *   - displayBoard()
 *********************************/

#include "board.h"
#include "pawn.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

#define BOARD_FILE "board.txt"

Board::Board() {
    for (int i = 0; i < 60; ++i) {
        boardTiles[i] = 0;
        pawnTiles[i] = -3;
    }

    for (int i = 0; i < 12; ++i) {
        Pawn newPawn;
        pawn[i] = newPawn;
    }

    /* 1: Green Home
     * 2: Red Home
     * 3: Blue Home
     * 4: Yellow Home
     * 5: Slider Start
     * 6: Slider End */

    boardTiles[1] = 1;
    boardTiles[4] = 2;
    boardTiles[9] = 1;
    boardTiles[13] = 2;
    boardTiles[16] = 1;
    boardTiles[19] = 2;
    boardTiles[24] = 1;
    boardTiles[28] = 2;
    boardTiles[31] = 1;
    boardTiles[34] = 2;
    boardTiles[39] = 1;
    boardTiles[43] = 2;
    boardTiles[46] = 1;
    boardTiles[49] = 2;
    boardTiles[54] = 1;
    boardTiles[58] = 2;
}

bool Board::movePawn(int pawnNum, int move) {
    bool moved = false;
    int landed =  pawn[pawnNum].getPos() + move;
    int safe = 0;
    landed = loopLanded(landed);
    switch (pawn[pawnNum].getStatus()) {
        case 0:
            cout << "In Start" << endl;
            pawn[pawnNum].setPos(getStart(pawnNum));
            landed = pawn[pawnNum].getPos() + move;
            landed = loopLanded(landed);
        case 1:
            cout << "On Board" << endl;
            safe = inSafety(pawnNum, landed, pawn[pawnNum].getPos());
            if (!safe)
                moved = doMove(pawnNum, landed);
                pawn[pawnNum].setStatus(1);
            if (safe > 0)
                if (!onSafeSelf(pawnNum, landed)) {
                    pawn[pawnNum].setStatus(2);
                    pawn[pawnNum].setPos(safe);
                    moved = true;
                }
            break;
        case 2:
            cout << "In Safety" << endl;
            if (landed < 5 && !onSafeSelf(pawnNum, landed)) {
                /* Moved Forward */
            }
            else if (landed < 0) {
                /* Backed out */
            }
            else if (landed == 5) {
                /* Reached end */
            }
            break;
        case 3:
            cout << "In Home" << endl;
            break;
    }
    return moved;
}

bool Board::doMove(int pawnNum, int landed) {
    bool moved = false;
    if (!onSelf(pawnNum, landed)) {
        if (onEnemy(pawnNum, landed)) {
            pawn[pawnTiles[landed]].setStatus(0);
            pawnTiles[landed] = 0;
        }
        if (onSlider(landed)) {
            while (!onSliderEnd(landed)) {
                landed++;
                landed = loopLanded(landed);
                if (onEnemy(pawnNum, landed)) {
                    pawn[pawnTiles[landed]].setStatus(0);
                    pawnTiles[landed] = 0;
                }
            }
        }
        pawn[pawnNum].setStatus(1);
        pawn[pawnNum].setPos(landed);
        pawnTiles[landed] = pawnNum;
        moved = true;
    }
    return moved;
}

bool Board::onSafeSelf(int pawnNum, int landed) {
    switch (pawnNum % 3) {
        case 0:
            if (pawn[pawnNum + 1].getStatus() == 2 && pawn[pawnNum + 1].getPos() == pawn[pawnNum].getPos())
                return 1;
            else if (pawn[pawnNum + 2].getStatus() == 2 && pawn[pawnNum + 2].getPos() == pawn[pawnNum].getPos())
                return 1;
            break;
        case 1:
            if (pawn[pawnNum - 1].getStatus() == 2 && pawn[pawnNum - 1].getPos() == pawn[pawnNum].getPos())
                return 1;
            else if (pawn[pawnNum + 1].getStatus() == 2 && pawn[pawnNum + 1].getPos() == pawn[pawnNum].getPos())
                return 1;
            break;
        case 2:
            if (pawn[pawnNum - 2].getStatus() == 2 && pawn[pawnNum - 2].getPos() == pawn[pawnNum].getPos())
                return 1;
            else if (pawn[pawnNum - 1].getStatus() == 2 && pawn[pawnNum - 1].getPos() == pawn[pawnNum].getPos())
                return 1;
            break;
    }
    return 0;
}

bool Board::onEnemy(int pawnNum, int landed) {
    if (pawnTiles[landed] != -1 && pawnTiles[landed] / 3 != pawnNum / 3)
        return 1;
    return 0;
}

bool Board::onSelf(int pawnNum, int landed) {
    if (pawnNum / 3 == pawnTiles[landed] / 3)
        return 1;
    return 0;
}

bool Board::onSlider(int landed) {
    if (boardTiles[landed] == 1)
        return 1;
    return 0;    
}

bool Board::onSliderEnd(int landed) {
    if (boardTiles[landed] == 2)
        return 1;
    return 0;
}

int Board::inSafety(int playerNum, int landed, int current) {
    int safety = getSafety(playerNum);
    if (landed > safety && current < safety) {
        if (landed < safety + 5)
            return (safety + 5) - landed;
        return -1;
    }
    return 0;
}

int Board::loopLanded(int landed) {
    if (landed > 59)
        landed -= 60;
    return landed;
}

int Board::getSafety(int playerNum) {
    int safety = 0;
    switch(playerNum / 3) {
        case 0:
            safety = 2;
            break;
        case 1:
            safety = 17;
            break;
        case 2:
            safety = 32;
            break;
        case 3:
            safety = 47;
            break;
    }
    return safety;
}

int Board::getStart(int playerNum) {
    int start = 0;
    switch (playerNum / 3) {
        case 0:
            start = 4;
            break;
        case 1:
            start = 19;
            break;
        case 2:
            start = 34;
            break;
        case 3:
            start = 49;
            break;
    }
    return start;
}

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define WHITE "\033[37m"

void Board::displayBoard() {
    ifstream fin(BOARD_FILE);
    int i = 0;
    char buffer = '0';
    while (fin.get(buffer)) {
        switch (i) {
            case 137:
            case 163:
            case 210:
            case 312:
            case 390:
            case 490:
            case 546:
            case 657:
            case 738:
            case 814:
            case 890:
                cout << RED;
                break;
            case 232:
            case 330:
            case 408:
            case 508:
            case 570:
            case 943:
            case 1053:
            case 1110:
            case 1187:
            case 1252:
                cout << BLUE;
                break;
            case 310:
            case 388:
            case 488:
            case 544:
            case 652:
            case 983:
            case 1063:
            case 1120:
            case 1198:
            case 1262:
                cout << GREEN;
                break;
            case 680:
            case 769:
            case 830:
            case 920:
            case 1029:
            case 1092:
            case 1169:
            case 1234:
            case 1321:
            case 1361:
            case 1390:
                cout << YELLOW;
                break;
            case 148:
            case 175:
            case 229:
            case 288:
            case 366:
            case 456:
            case 535:
            case 617:
            case 708:
            case 763:
            case 785:
            case 860:
            case 947:
            case 1055:
            case 1112:
            case 1189:
            case 1254:
            case 1318:
            case 1341:
            case 1374:
            case 1399:
                cout << WHITE;
                break;
        }
        cout << buffer;
        ++i;
    }
    cout << endl;
    fin.close();
}
