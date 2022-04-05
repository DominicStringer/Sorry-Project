/*********************************
 * File Changes:
 *  Dominic - 3/1/2022
 *  Dominic - 3/22/2022
 *  Dominic - 4/4/22
 * 
 * Description: The Sorry Board Class with Function Declarations
 *
 * List of Contents:
 *  Board Class
 *   
 *********************************/

#ifndef BOARD
#define BOARD

#define BOARD_FILE "board.txt"

#include "pawn.h"
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

class Board {
    private:
        int boardTiles[60];
        int pawnTiles[60];
        Pawn pawn[12];
    public:
        Board() {
            for (int i = 0; i < 60; ++i) {
                boardTiles[i] = 0;
                pawnTiles[i] = -3;
            }
        
            for (int i = 0; i < 12; ++i) {
                Pawn newPawn;
                pawn[i] = newPawn;
            }

            /* 1: Slider Start
             * 2: Slider End */
        
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
        bool movePawn(int pawnNum, int move) {
            bool moved = false;
            int landed =  pawn[pawnNum].getPos() + move;
            int safe = 0;
            landed = loopLanded(landed);
            switch (pawn[pawnNum].getStatus()) {
                case 0:
                    pawn[pawnNum].setPos(getStart(pawnNum));
                    landed = pawn[pawnNum].getPos() + move - 1;
                    landed = loopLanded(landed);
                case 1:
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
                    break;
            }
            return moved;
        }
        bool doMove(int pawnNum, int landed) {
            bool moved = false;
            if (!onSelf(pawnNum, landed)) {
                if (onEnemy(pawnNum, landed)) {
                    pawn[pawnTiles[landed]].setStatus(0);
                    pawnTiles[landed] = -3;
                }
                if (onSlider(landed)) {
                    while (!onSliderEnd(landed)) {
                        landed++;
                        landed = loopLanded(landed);
                        if (onEnemy(pawnNum, landed)) {
                            pawn[pawnTiles[landed]].setStatus(0);
                            pawnTiles[landed] = -3;
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
        
        bool onSafeSelf(int pawnNum, int landed) {
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
        
        bool onEnemy(int pawnNum, int landed) {
            if (pawnTiles[landed] != -3 && pawnTiles[landed] / 3 != pawnNum / 3)
                return 1;
            return 0;
        }
        
        bool onSelf(int pawnNum, int landed) {
            if (pawnNum / 3 == pawnTiles[landed] / 3)
                return 1;
            return 0;
        }

        bool onSlider(int landed) {
            if (boardTiles[landed] == 1)
                return 1;
            return 0;    
        }
        
        bool onSliderEnd(int landed) {
            if (boardTiles[landed] == 2)
                return 1;
            return 0;
        }
        
        int inSafety(int playerNum, int landed, int current) {
            int safety = getSafety(playerNum);
            if (landed > safety && current < safety) {
                if (landed < safety + 5)
                    return (safety + 5) - landed;
                return -1;
            }
            return 0;
        }
        
        int loopLanded(int landed) {
            if (landed > 59)
                landed -= 60;
            return landed;
        }
        
        int getSafety(int playerNum) {
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
        
        int getStart(int playerNum) {
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
        
        void displayBoard() {
            ifstream fin(BOARD_FILE);
            int i = 0;
            int k = 0;
            int currentTile = 0;
            bool prnt = true;
            char buffer = '0';
            while (fin.get(buffer)) {
                /* Color Control */
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
                switch (i) {
                    case 134:
                    case 138:
                    case 142:
                    case 144:
                    case 146:
                    case 148:
                    case 152:
                    case 156:
                    case 160:
                    case 164:
                    case 168:
                    case 170:
                    case 172:
                    case 174:
                    case 176:
                    case 180:
                    case 206:
                    case 284:
                    case 310:
                    case 364:
                    case 388:
                        currentTile = getTileFromi(i);
                        /* if (pawnTiles[currentTile] != -3) { */
                        if (true) {
                            switch (pawnTiles[currentTile] / 3) {
                                case 0:
                                    cout << GREEN;
                                    break;
                                case 1:
                                    cout << RED;
                                    break;
                                case 2:
                                    cout << BLUE;
                                    break;
                                case 3:
                                    cout << YELLOW;
                                    break;
                            }
                            cout << WHITE;
                            switch(pawnTiles[currentTile] % 3) {
                                case 0:
                                    cout << "①" << WHITE;
                                    break;
                                case 1:
                                    cout << "②" << WHITE;
                                    break;
                                case 2:
                                    cout << "③" << WHITE;
                                    break;
                            }
                            prnt = false;
                        }
                        ++k;
                        break;
                    case 316: /* RED SAFETY */
                    case 394:
                        cout << "■";
                        prnt = false;
                        break;
                    case 324: /* RED START */
                    case 402:
                        cout << "■";
                        prnt = false;
                        break;
                    case 334: /* BLUE HOME */
                    case 412:
                        cout << "■";
                        prnt = false;
                        break;
                    case 340: /* BLUE SAFETY */
                    case 344:
                    case 348:
                    case 352:
                    case 356:
                        cout << "■";
                        prnt = false;
                        break;
                    case 137:
                    case 141:
                    case 143:
                    case 145:
                    case 147:
                    case 151:
                    case 155:
                    case 159:
                    case 163:
                    case 167:
                    case 169:
                    case 171:
                    case 173:
                    case 175:
                    case 179:
                    case 183:
                    case 209:
                    case 287:
                    case 311:
                    case 319:
                    case 325:
                    case 335:
                    case 343:
                    case 347:
                    case 351:
                    case 355:
                    case 359:
                    case 365:
                    case 389:
                    case 397:
                    case 403:
                    case 413:
                        prnt = true;
                        break;
                }
                if (prnt)
                   cout << buffer;
                ++i;
            }
            cout << endl;
            fin.close();
        }
        int getTileFromi(int i) {
            int tile = -1;
            switch (i) {
                case 134:
                    tile = 15;
                    break;
                case 138:
                    tile = 16;
                    break;
                case 142:
                    tile = 17;
                    break;
                case 144:
                    tile = 18;
                    break;
                case 146:
                    tile = 19;
                    break;
                case 148:
                    tile = 20;
                    break;
                case 152:
                    tile = 21;
                    break;
                case 156:
                    tile = 22;
                    break;
                case 160:
                    tile = 23;
                    break;
                case 164:
                    tile = 24;
                    break;
                case 168:
                    tile = 25;
                    break;
                case 170:
                    tile = 26;
                    break;
                case 172:
                    tile = 28;
                    break;
                case 174:
                    tile = 29;
                    break;
                case 176:
                    tile = 30;
                    break;
                case 180:
                    tile = 14;
                    break;
                case 206:
                    tile = 31;
                    break;
                case 284:
                    tile = 13;
                    break;
                case 310:
                    tile = 32;
                    break;
            }
            return tile;
        }
};

#endif
