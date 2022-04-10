/*********************************
 * File Changes:
 *  Dominic - 3/1/2022
 *  Dominic - 3/22/2022
 *  Dominic - 4/4/2022
 *  Dominic - 4/6/2022
 *  Dominic - 4/7/2022
 *  Dominic - 4/8/2022
 *  Dominic - 4/9/2022
 *  Dominic - 4/10/2022
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
        int pawnTiles[104];
        Pawn pawn[12];
    public:
        Board() {
            for (int i = 0; i < 60; ++i) {
                boardTiles[i] = 0;
            }

            for (int i = 0; i < 104; ++i) {
                pawnTiles[i] = -3;
            }
        
            for (int i = 0; i < 12; ++i) {
                Pawn newPawn;
                pawn[i] = newPawn;
                pawnTiles[getStartingPos(i)] = i;
                pawn[i].setPos(getStartingPos(i));
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
        
        #define GREEN "\033[32m"
        #define YELLOW "\033[33m"
        #define BLUE "\033[34m"
        #define RED "\033[31m"
        #define WHITE "\033[37m"
        void displayBoard(int card = 0) {
            ifstream fin(BOARD_FILE);
            int i = 0;
            int currentTile = 0;
            bool prnt = true;
            char buffer = '0';
            string color = WHITE;
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
                        color = RED;
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
                        color = BLUE;
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
                        color = GREEN;
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
                        color = YELLOW;
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
                        color = WHITE;
                        break;
                }

                /* Display Cards */
                switch (i)
                {
                    case 193:
                        prntCardRow(card, 1);
                        prnt = false;
                        break;
                    case 297:
                        prntCardRow(card, 2);
                        prnt = false;
                        break;
                    case 375:
                        prntCardRow(card, 3);
                        prnt = false;
                        break;
                    case 196:
                    case 300:
                    case 378:
                        prnt = true;
                        break;
                }

                currentTile = getTileFromi(i);
                if (currentTile >= 0)
                {
                if (pawnTiles[currentTile] != -3)
                    {
                        prntPawn(pawnTiles[currentTile], color);
                        prnt = false;
                    }
                }
                switch (i) {
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
                    case 455:
                    case 489:
                    case 497:
                    case 503:
                    case 513:
                    case 525:
                    case 527:
                    case 529:
                    case 535:
                    case 546:
                    case 554:
                    case 620:
                    case 656:
                    case 664:
                    case 712:
                    case 738:
                    case 776:
                    case 778:
                    case 780:
                    case 788:
                    case 814:
                    case 820:
                    case 822:
                    case 824:
                    case 864:
                    case 890:
                    case 938:
                    case 946:
                    case 982:
                    case 1048:
                    case 1054:
                    case 1065:
                    case 1071:
                    case 1073:
                    case 1075:
                    case 1087:
                    case 1097:
                    case 1105:
                    case 1111:
                    case 1122:
                    case 1164:
                    case 1174:
                    case 1182:
                    case 1188:
                    case 1199:
                    case 1207:
                    case 1211:
                    case 1215:
                    case 1219:
                    case 1223:
                    case 1229:
                    case 1239:
                    case 1247:
                    case 1253:
                    case 1266:
                    case 1344:
                    case 1357:
                    case 1361:
                    case 1363:
                    case 1365:
                    case 1367:
                    case 1369:
                    case 1373:
                    case 1377:
                    case 1381:
                    case 1385:
                    case 1389:
                    case 1391:
                    case 1393:
                    case 1395:
                    case 1399:
                    case 1403:
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

        bool isWon(int playerNum)
        {
            if (pawn[(playerNum - 1) * 3].getStatus() == 3 &&
                pawn[((playerNum - 1) * 3) + 1].getStatus() == 3 &&
                pawn[((playerNum - 1) * 3) + 2].getStatus() == 3)
            {
                return true;
            }
            return false;
        }

        bool swap(int swappingPawn, int swappedPawn)
        {
            bool moved = false;
            if (pawn[swappingPawn].getStatus() == 1 && pawn[swappedPawn].getStatus() == 1)
            {
                int bufferPos = pawn[swappingPawn].getPos();
                pawn[swappingPawn].setPos(pawn[swappedPawn].getPos());
                pawn[swappedPawn].setPos(bufferPos);
                pawnTiles[pawn[swappingPawn].getPos()] = swappingPawn;
                pawnTiles[pawn[swappedPawn].getPos()] = swappedPawn;
                moved = true;
            }
            return moved;
        }

        bool sorry(int sorryPawn, int removedPawn)
        {
            bool moved = false;
            if (pawn[sorryPawn].getStatus() == 0 && pawn[removedPawn].getStatus() == 1)
            {
                pawnTiles[pawn[sorryPawn].getPos()] = -3;
                pawn[sorryPawn].setPos(pawn[removedPawn].getPos());
                pawn[removedPawn].setPos(getStartingPos(removedPawn));
                pawnTiles[pawn[sorryPawn].getPos()] = sorryPawn;
                pawnTiles[getStartingPos(removedPawn)] = removedPawn;
                moved = true;
            }
            return moved;
        }

        bool movePawn(int pawnNum, int move)
        {
            bool moved = false;
            int safe = 0;
            int landed = 0;
            switch (pawn[pawnNum].getStatus()) 
                {
                case 0:
                    landed = getStart(pawnNum) + move - 1;
                    if (move > 0)
                    {
                        landed = loopLanded(landed);
                        moved = doMove(pawnNum, landed);
                        if (moved)
                        {
                            pawn[pawnNum].setStatus(1);
                        }
                    }
                break;
                case 1:
                    landed = pawn[pawnNum].getPos() + move;
                    landed = loopLanded(landed);
                    safe = inSafety(pawnNum, move);
                    if (!safe)
                        moved = doMove(pawnNum, landed);
                    if (safe > 0)
                        if (!onSelf(pawnNum, safe))
                        {
                            if (safe < getSafetyPos(pawnNum) + 5)
                            {
                                pawn[pawnNum].setStatus(2);
                                pawnTiles[pawn[pawnNum].getPos()] = -3;
                                pawn[pawnNum].setPos(safe);
                                pawnTiles[safe] = pawnNum;
                                moved = true;
                            }
                            else
                            {
                                pawn[pawnNum].setStatus(3);
                                pawnTiles[pawn[pawnNum].getPos()] = -3;
                                pawn[pawnNum].setPos(getHomePos(pawnNum));
                                pawnTiles[getHomePos(pawnNum)] = pawnNum;
                                moved = true;
                            }
                        }
                    break;
                case 2:
                    landed = pawn[pawnNum].getPos() + move;
                    if (landed < getSafetyPos(pawnNum)) 
                    {
                        landed = getSafety(pawnNum) - (getSafetyPos(pawnNum) - 1) + landed;
                        landed = loopLanded(landed);
                        moved = doMove(pawnNum, landed);
                        if (move)
                        {
                            pawn[pawnNum].setStatus(1);
                        }
                    }
                    else if (landed < getSafetyPos(pawnNum) + 5 && !onSelf(pawnNum, landed))
                    {
                        moved = doMove(pawnNum, landed);
                    }
                    else if (landed == getSafetyPos(pawnNum) + 5)
                    {
                        pawn[pawnNum].setStatus(3);
                        pawnTiles[pawn[pawnNum].getPos()] = -3;
                        pawn[pawnNum].setPos(getHomePos(pawnNum));
                        pawnTiles[getHomePos(pawnNum)] = pawnNum;
                    }
                    break;
            }
            return moved;
        }
        bool doMove(int pawnNum, int landed) {
            bool moved = false;
            if (!onSelf(pawnNum, landed)) {
                if (onEnemy(pawnNum, landed)) {
                    pawn[pawnTiles[landed]].setStatus(0);
                    pawn[pawnTiles[landed]].setPos(getStartingPos(pawnTiles[landed]));
                    pawnTiles[getStartingPos(pawnTiles[landed])] = pawnTiles[landed];
                    pawnTiles[landed] = -3;
                }
                if (onSlider(landed)) {
                    while (!onSliderEnd(landed)) {
                        landed++;
                        landed = loopLanded(landed);
                        if (onEnemy(pawnNum, landed)) {
                            pawn[pawnTiles[landed]].setStatus(0);
                            pawn[pawnTiles[landed]].setPos(getStartingPos(pawnTiles[landed]));
                            pawnTiles[getStartingPos(pawnTiles[landed])] = pawnTiles[landed];
                            pawnTiles[landed] = -3;
                        }
                    }
                  
                }
                pawnTiles[pawn[pawnNum].getPos()] = -3;
                pawn[pawnNum].setPos(landed);
                pawnTiles[landed] = pawnNum;
                moved = true;
            }
            return moved;
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
            if (landed < 60)
            {
                if (boardTiles[landed] == 1)
                    {
                    return 1;
                    }
            }
            return 0;    
        }
        
        bool onSliderEnd(int landed) {
            if (boardTiles[landed] == 2)
                return 1;
            return 0;
        }
        
        int inSafety(int pawnNum, int move) {
            int safety = getSafety(pawnNum);
            int current = pawn[pawnNum].getPos();
            int landed = 0;

            while (move != 0)
            {
                if (current == safety && move > 0)
                {
                    if (move < 7)
                    {
                        landed = move + getSafetyPos(pawnNum) - 1;
                    }
                    else
                    {
                        landed = -1;
                    }
                }
                if (move > 0)
                {
                    ++current;
                    current = loopLanded(current);
                    --move;
                }
                else
                {
                    --current;
                    ++move;
                }
            }
            return landed;
        }
        
        int loopLanded(int landed) {
            if (landed > 59)
                landed -= 60;
            if (landed < 0)
                landed += 60;
            return landed;
        }
        
        int getSafety(int pawnNum) {
            int safety = 0;
            switch(pawnNum / 3) {
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
        
        int getStart(int pawnNum) {
            int start = 0;
            switch (pawnNum / 3) {
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

        int getStartingPos(int pawnNum) {
            int pos = -1;
            switch (pawnNum) {
            case 0:
                pos = 60;
                break;
            case 1:
                pos = 61;
                break;
            case 2:
                pos = 62;
                break;
            case 3:
                pos = 71;
                break;
            case 4:
                pos = 72;
                break;
            case 5:
                pos = 73;
                break;
            case 6:
                pos = 82;
                break;
            case 7:
                pos = 83;
                break;
            case 8:
                pos = 84;
                break;
            case 9:
                pos = 93;
                break;
            case 10:
                pos = 94;
                break;
            case 11:
                pos = 95;
                break;
            }
            return pos;
        }

        int getSafetyPos(int pawnNum) 
        {
            int pos = -1;
            switch (pawnNum / 3) 
            {
                case 0:
                    pos = 63;
                    break;
                case 1:
                    pos = 74;
                    break;
                case 2:
                    pos = 85;
                    break;
                case 3:
                    pos = 96;
                    break;
            }
            return pos;
        }

        int getHomePos(int pawnNum) 
        {
            int pos = -1;
            switch (pawnNum)
            {
                case 0:
                    pos = 68;
                    break;
                case 1:
                    pos = 69;
                    break;
                case 2:
                    pos = 70;
                    break;
                case 3:
                    pos = 79;
                    break;
                case 4:
                    pos = 80;
                    break;
                case 5:
                    pos = 81;
                    break;
                case 6:
                    pos = 90;
                    break;
                case 7:
                    pos = 91;
                    break;
                case 8:
                    pos = 92;
                    break;
                case 9:
                    pos = 101;
                    break;
                case 10:
                    pos = 102;
                    break;
                case 11:
                    pos = 103;
                    break;
            }
            return pos;
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
                    tile = 27;
                    break;
                case 174:
                    tile = 28;
                    break;
                case 176:
                    tile = 29;
                    break;
                case 180:
                    tile = 30;
                    break;
                case 206:
                    tile = 14;
                    break;
                case 284:
                    tile = 31;
                    break;
                case 310:
                    tile = 13;
                    break;
                case 364:
                    tile = 32;
                    break;
                case 388:
                    tile = 12;
                    break;
                case 454:
                    tile = 33;
                    break;
                case 488:
                    tile = 11;
                    break;
                case 534:
                    tile = 34;
                    break;
                case 545:
                    tile = 10;
                    break;
                case 617:
                    tile = 35;
                    break;
                case 653:
                    tile = 9;
                    break;
                case 709:
                    tile = 36;
                    break;
                case 735:
                    tile = 8;
                    break;
                case 785:
                    tile = 37;
                    break;
                case 811:
                    tile = 7;
                    break;
                case 861:
                    tile = 38;
                    break;
                case 887:
                    tile = 6;
                    break;
                case 943:
                    tile = 39;
                    break;
                case 979:
                    tile = 5;
                    break;
                case 1053:
                    tile = 40;
                    break;
                case 1064:
                    tile = 4;
                    break;
                case 1110:
                    tile = 41;
                    break;
                case 1121:
                    tile = 3;
                    break;
                case 1187:
                    tile = 42;
                    break;
                case 1198:
                    tile = 2;
                    break;
                case 1252:
                    tile = 43;
                    break;
                case 1263:
                    tile = 1;
                    break;
                case 1341:
                    tile = 44;
                    break;
                case 1354:
                    tile = 0;
                    break;
                case 1358:
                    tile = 59;
                    break;
                case 1362:
                    tile = 58;
                    break;
                case 1364:
                    tile = 57;
                    break;
                case 1366:
                    tile = 56;
                    break;
                case 1368:
                    tile = 55;
                    break;
                case 1370:
                    tile = 54;
                    break;
                case 1374:
                    tile = 53;
                    break;
                case 1378:
                    tile = 52;
                    break;
                case 1382:
                    tile = 51;
                    break;
                case 1386:
                    tile = 50;
                    break;
                case 1390:
                    tile = 49;
                    break;
                case 1392:
                    tile = 48;
                    break;
                case 1394:
                    tile = 47;
                    break;
                case 1396:
                    tile = 46;
                    break;
                case 1400:
                    tile = 45;
                    break;
                case 1070: /* GREEN START */
                    tile = 60;
                    break;
                case 1072:
                    tile = 61;
                    break;
                case 1074:
                    tile = 62;
                    break;
                case 1204: /* GREEN SAFETY */
                    tile = 63;
                    break;
                case 1208:
                    tile = 64;
                    break;
                case 1212:
                    tile = 65;
                    break;
                case 1216:
                    tile = 66;
                    break;
                case 1220:
                    tile = 67;
                    break;
                case 1086: /* GREEN HOME */
                    tile = 68;
                    break;
                case 1163:
                    tile = 69;
                    break;
                case 1228:
                    tile = 70;
                    break;
                case 324: /* RED START */
                    tile = 71;
                    break;
                case 402:
                    tile = 72;
                    break;
                case 502:
                    tile = 73;
                    break;
                case 316: /* RED SAFETY */
                    tile = 74;
                    break;
                case 394:
                    tile = 75;
                    break;
                case 494:
                    tile = 76;
                    break;
                case 551:
                    tile = 77;
                    break;
                case 661:
                    tile = 78;
                    break;
                case 819: /* RED HOME*/
                    tile = 79;
                    break;
                case 821:
                    tile = 80;
                    break;
                case 823:
                    tile = 81;
                    break;
                case 524: /* BLUE START */
                    tile = 84;
                    break;
                case 526:
                    tile = 83;
                    break;
                case 528:
                    tile = 82;
                    break;
                case 340: /* BLUE SAFETY */
                    tile = 89;
                    break;
                case 344:
                    tile = 88;
                    break;
                case 348:
                    tile = 87;
                    break;
                case 352:
                    tile = 86;
                    break;
                case 356:
                    tile = 85;
                    break;
                case 334: /* BLUE HOME */
                    tile = 90;
                    break;
                case 412:
                    tile = 91;
                    break;
                case 512:
                    tile = 92;
                    break;
                case 1096: /* YELLOW START */
                    tile = 95;
                    break;
                case 1173:
                    tile = 94;
                    break;
                case 1238:
                    tile = 93;
                    break;
                case 935: /* YELLOW SAFETY */
                    tile = 100;
                    break;
                case 1045:
                    tile = 99;
                    break;
                case 1102:
                    tile = 98;
                    break;
                case 1179:
                    tile = 97;
                    break;
                case 1244:
                    tile = 96;
                    break;
                case 775: /* YELLOW HOME */
                    tile = 101;
                    break;
                case 777:
                    tile = 102;
                    break;
                case 779:
                    tile = 103;
                    break;
            }
            return tile;
        }
        void prntPawn(int pawnID, string color) {
            switch (pawnID / 3) {
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
            switch(pawnID % 3) {
                case 0:
                    cout << "①";
                    break;
                case 1:
                    cout << "②";
                    break;
                case 2:
                    cout << "③";
                    break;
            }
            cout << color;
        }
        void prntCardRow(int cardID, int rowNum)
        {
            if (rowNum == 1)
            {
                switch (cardID)
                {
                    case 0:
                        cout << "   ";
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 11:
                    case 12:
                        cout << " f ";
                        break;
                    case -4:
                        cout << " b ";
                        break;
                    case 14:
                        cout << " s ";
                        break;  
                }
            }
            else if (rowNum == 2)
            {
                switch(cardID)
                {
                    case 0:
                        cout << "   ";
                        break;
                    case 1:
                        cout << " 1 ";
                        break;
                    case 2:
                        cout << " 2 ";
                        break;
                    case 3:
                        cout << " 3 ";
                        break;
                    case -4:
                        cout << " 4 ";
                        break;
                    case 5:
                        cout << " 5 ";
                        break;
                    case 7:
                        cout << " 7 ";
                        break;
                    case 8:
                        cout << " 8 ";
                        break;
                    case 10:
                        cout << "1 0";
                        break;
                    case 11:
                        cout << "1 1";
                        break;
                    case 12:
                        cout << "1 2";
                        break;
                    case 14:
                        cout << " s ";
                        break;
                }
            }
            else if (rowNum == 3)
            {
                switch (cardID)
                {
                    case 0:
                        cout << "   ";
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 5:
                    case 8:
                    case 12:
                        cout << " f ";
                        break;
                    case -4:
                        cout << " b ";
                        break;
                    case 7:
                        cout << "s p";
                        break;
                    case 10:
                        cout << "b 1";
                        break;
                    case 11:
                        cout << "s w";
                        break;
                    case 14:
                        cout << " s ";
                }
            }
        }
};

#endif
