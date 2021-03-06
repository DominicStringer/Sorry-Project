/******************************************************************************
File Changes:
Connor Rajotte - 3/5/2022 - Added a rulebook that displays from "rules.txt"
Connor Rajotte - 3/22/2022 - Added code for player storing
Connor Rajotte - 3/31/2022 - Fixed error checking and added new isdigit() to check for numbers in names
Connor Rajotte - 4/5/2022 - Moved player error checking and intro to separate header files
Connor Rajotte - 4/7/2022 - Added operator overloading example
Connor Rajotte - 4/8/2022 - Changed operator overloading to title and added core game loop with error checking
Connor Rajotte - 4/9/2022 - Added ability to win

Description: Main file

List of Contents:
Title class
Main

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

#include "Intro.h"
#include "Player.h"
#include "board.h"

using namespace std;

int cardSelection();

class Title
{
    private:
        string title;
    public:
        Title(string t) { title = t; }
        friend ostream& operator<<(ostream &os, const Title&);
};

ostream& operator<<(ostream &os, const Title &t)
{
    os << t.title << endl;
    os << "By Connor and Dominic" << endl;
    return os;
}

int main()
{
/*Title*/
    Title t("Sorry!");
    cout << t << endl;

/*variables*/
    int players;
    Intro i;
    Player p;
    winner1 one;
    winner2 two;
    winner3 three;
    winner4 four;
    
    i.intro();
    
    Board Sorry;
    
    players = p.setOrder(0);
    
    Sorry.displayBoard();
    
/*player interaction*/
    int pawn;
    int pawn2;
    int card;
    int split1;
    int split2;
    int swap;
    int pawnSwap;
    
    bool moveStart;
    
    bool win1 = false;
    bool win2 = false;
    bool win3 = false;
    bool win4 = false;
    
    
    while((win1 == false) && (win2 == false) && (win3 == false) && (win4 == false))
    {
/*player 1*/
        cout << "Green player, ";
        card = cardSelection();
        do
        {
            if(card == 7 || card == 13 || card == 10 || card == -1 || card == 11 || card == -2)
            {
                Sorry.displayBoard();
                cout << endl;
            }
            cout << "Player 1 select your pawn:" << endl << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> pawn;
        } while(pawn != 1 && pawn != 2 && pawn != 3);
        
        if(card == 13)
        {
            cout << "Player 1 select your second pawn: ";
            cin >> pawn2;
            cout << "How much do you want to move your first pawn? ";
            cin >> split1;
            cout << "How much do you want to move your second pawn? ";
            cin >> split2;
            while((split1 + split2) != 7)
            {
                cout << "Both pawn movements must equal seven" << endl;
                cout << "How much do you want to move your first pawn? ";
                cin >> split1;
                cout << "How much do you want to move your second pawn? ";
                cin >> split2;
            }
        }
        else if(card == 14)
        {
            Sorry.displayBoard(card);
            cout << endl;
            cout << "Which player do you want to swap pawns with: " << endl << endl;
            cin >> swap;
            Sorry.displayBoard(card);
            cout << endl;
            cout << "Which pawn do you want to swap with: " << endl << endl;
            cin >> pawnSwap;
        }
        else if(card == -2)
        {
            Sorry.displayBoard(card);
            cout << endl;
            cout << "Which player do you want to swap pawns with: " << endl << endl;
            cin >> swap;
            Sorry.displayBoard(card);
            cout << endl;
            cout << "Which pawn do you want to swap with: " << endl << endl;
            cin >> pawnSwap;
        }
        
/*printing out pawn movements*/
        if(card == 1)
        {
            cout << "You moved pawn " << pawn << ", " << card << " tile" << endl;
        }
        else if(card == 13)
        {
            cout << "You moved pawn " << pawn << ", " << split1 << " tiles" << endl;
            cout << "You moved pawn " << pawn2 << ", " << split2 << " tiles" << endl;
        }
        else if(card == 14)
        {
            cout << "You replaced your enemies pawn with pawn " << pawn << endl;
        }
        else if(card == -2)
        {
            cout << "You swapped your enemies pawn with pawn " << pawn << endl;
        }
        else
        {
            cout << "You moved pawn " << pawn << ", " << card << " tiles" << endl;
        }
        
        pawn --;
        pawn2 --;
        
/*moving pawns*/
        if(card == 13)
        {
            Sorry.movePawn(pawn, split1);
            Sorry.movePawn(pawn2, split2);
        }
        else if(card == 14)
        {
            pawnSwap = ((swap - 1) * 3 + pawnSwap) - 1;
            Sorry.sorry(pawn, pawnSwap);
        }
        else if(card == -2)
        {
            pawnSwap = ((swap - 1) * 3 + pawnSwap) - 1;
            Sorry.swap(pawn, pawnSwap);
        }
        else
        {
            moveStart = Sorry.movePawn(pawn, card);
            if(moveStart == false && card == -1)
            {
                cout << "You can't move backwards out of home" << endl;
                Sorry.movePawn(pawn, 10);
            }
            else if(moveStart == false && card == -4)
            {
                cout << "You can't move backwards out of home" << endl;
                Sorry.movePawn(pawn, 0);
            }
        }
        Sorry.displayBoard(card);
        
/*win checking*/
        win1 = Sorry.isWon(1);
        if(win1 == true)
        {
            break;
        }
        
/*player 2*/
        cout << "Red player, ";
        card = cardSelection();
        do
        {
            if(card == 7 || card == 13 || card == 10 || card == -1 || card == 11 || card == -2)
            {
                Sorry.displayBoard();
                cout << endl;
            }
            cout << "Player 2 select your pawn:" << endl << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> pawn;
        } while(pawn != 1 && pawn != 2 && pawn != 3);
        
        
        if(card == 13)
        {
            cout << "Player 2 select your second pawn: ";
            cin >> pawn2;
            cout << "How much do you want to move your first pawn? ";
            cin >> split1;
            cout << "How much do you want to move your second pawn? ";
            cin >> split2;
            while((split1 + split2) != 7)
            {
                cout << "Both pawn movements must equal seven" << endl;
                cout << "How much do you want to move your first pawn? ";
                cin >> split1;
                cout << "How much do you want to move your second pawn? ";
                cin >> split2;
            }
        }
        else if(card == 14)
        {
            Sorry.displayBoard(card);
            cout << endl;
            cout << "Which player do you want to swap pawns with: " << endl << endl;
            cin >> swap;
            Sorry.displayBoard(card);
            cout << endl;
            cout << "Which pawn do you want to swap with: " << endl << endl;
            cin >> pawnSwap;
        }
        else if(card == -2)
        {
            Sorry.displayBoard(card);
            cout << endl;
            cout << "Which player do you want to swap pawns with: " << endl << endl;
            cin >> swap;
            Sorry.displayBoard(card);
            cout << endl;
            cout << "Which pawn do you want to swap with: " << endl << endl;
            cin >> pawnSwap;
        }
        
/*printing out pawn movements*/
        if(card == 1)
        {
            cout << "You moved pawn " << pawn << ", " << card << " tile" << endl;
        }
        else if(card == 13)
        {
            cout << "You moved pawn " << pawn << ", " << split1 << " tiles" << endl;
            cout << "You moved pawn " << pawn2 << ", " << split2 << " tiles" << endl;
        }
        else if(card == 14)
        {
            cout << "You replaced your enemies pawn with pawn " << pawn << endl;
        }
        else if(card == -2)
        {
            cout << "You swapped your enemies pawn with pawn " << pawn << endl;
        }
        else
        {
            cout << "You moved pawn " << pawn << ", " << card << " tiles" << endl;
        }
    
        pawn += 2;
        pawn2 += 2;
        
/*moving pawns*/
        if(card == 13)
        {
            Sorry.movePawn(pawn, split1);
            Sorry.movePawn(pawn2, split2);
        }
        else if(card == 14)
        {
            pawnSwap = ((swap - 1) * 3 + pawnSwap) - 1;
            Sorry.sorry(pawn, pawnSwap);
        }
        else if(card == -2)
        {
            pawnSwap = ((swap - 1) * 3 + pawnSwap) - 1;
            Sorry.swap(pawn, pawnSwap);
        }
        else
        {
            moveStart = Sorry.movePawn(pawn, card);
            if(moveStart == false && card == -1)
            {
                cout << "You can't move backwards out of home" << endl;
                Sorry.movePawn(pawn, 10);
            }
            else if(moveStart == false && card == -4)
            {
                cout << "You can't move backwards out of home" << endl;
                Sorry.movePawn(pawn, 0);
            }
        }
        Sorry.displayBoard(card);
        
/*win checking*/
        win2 = Sorry.isWon(2);
        if(win2 == true)
        {
            break;
        }
        
        if(players == 3 || players == 4)
        {
/*player 3*/
            cout << "Blue player, ";
            card = cardSelection();
            do
            {
                if(card == 7 || card == 13 || card == 10 || card == -1 || card == 11 || card == -2)
                {
                    Sorry.displayBoard();
                    cout << endl;
                }
                cout << "Player 3 select your pawn:" << endl << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> pawn;
            } while(pawn != 1 && pawn != 2 && pawn != 3);
            
            
            if(card == 13)
            {
                cout << "Player 3 select your second pawn: ";
                cin >> pawn2;
                cout << "How much do you want to move your first pawn? ";
                cin >> split1;
                cout << "How much do you want to move your second pawn? ";
                cin >> split2;
                while((split1 + split2) != 7)
                {
                    cout << "Both pawn movements must equal seven" << endl;
                    cout << "How much do you want to move your first pawn? ";
                    cin >> split1;
                    cout << "How much do you want to move your second pawn? ";
                    cin >> split2;
                }
            }
            else if(card == 14)
            {
                Sorry.displayBoard(card);
                cout << endl;
                cout << "Which player do you want to swap pawns with: " << endl << endl;
                cin >> swap;
                Sorry.displayBoard(card);
                cout << endl;
                cout << "Which pawn do you want to swap with: " << endl << endl;
                cin >> pawnSwap;
            }
            else if(card == -2)
            {
                Sorry.displayBoard(card);
                cout << endl;
                cout << "Which player do you want to swap pawns with: " << endl << endl;
                cin >> swap;
                Sorry.displayBoard(card);
                cout << endl;
                cout << "Which pawn do you want to swap with: " << endl << endl;
                cin >> pawnSwap;
            }
            
/*printing out pawn movements*/
            if(card == 1)
            {
                cout << "You moved pawn " << pawn << ", " << card << " tile" << endl;
            }
            else if(card == 13)
            {
                cout << "You moved pawn " << pawn << ", " << split1 << " tiles" << endl;
                cout << "You moved pawn " << pawn2 << ", " << split2 << " tiles" << endl;
            }
            else if(card == 14)
            {
                cout << "You replaced your enemies pawn with pawn " << pawn << endl;
            }
            else if(card == -2)
            {
                cout << "You swapped your enemies pawn with pawn " << pawn << endl;
            }
            else
            {
                cout << "You moved pawn " << pawn << ", " << card << " tiles" << endl;
            }
            
            pawn += 5;
            pawn2 += 5;
            
/*moving pawns*/
            if(card == 13)
            {
                Sorry.movePawn(pawn, split1);
                Sorry.movePawn(pawn2, split2);
            }
            else if(card == 14)
            {
                pawnSwap = ((swap - 1) * 3 + pawnSwap) - 1;
                Sorry.sorry(pawn, pawnSwap);
            }
            else if(card == -2)
            {
                pawnSwap = ((swap - 1) * 3 + pawnSwap) - 1;
                Sorry.swap(pawn, pawnSwap);
            }
            else
            {
                moveStart = Sorry.movePawn(pawn, card);
                if(moveStart == false && card == -1)
                {
                    cout << "You can't move backwards out of home" << endl;
                    Sorry.movePawn(pawn, 10);
                }
                else if(moveStart == false && card == -4)
                {
                    cout << "You can't move backwards out of home" << endl;
                    Sorry.movePawn(pawn, 0);
                }
            }
            Sorry.displayBoard(card);
            
/*win checking*/
            win3 = Sorry.isWon(3);
            if(win3 == true)
            {
                break;
            }
            
            if(players == 4)
            {
/*player 4*/
                cout << "Yellow player, ";
                card = cardSelection();
                do
                {
                    if(card == 7 || card == 13 || card == 10 || card == -1 || card == 11 || card == -2)
                    {
                        Sorry.displayBoard();
                        cout << endl;
                    }
                    cout << "Player 4 select your pawn:" << endl << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> pawn;
                } while(pawn != 1 && pawn != 2 && pawn != 3);
                
                
                if(card == 13)
                {
                    cout << "Player 4 select your second pawn: ";
                    cin >> pawn2;
                    cout << "How much do you want to move your first pawn? ";
                    cin >> split1;
                    cout << "How much do you want to move your second pawn? ";
                    cin >> split2;
                    while((split1 + split2) != 7)
                    {
                        cout << "Both pawn movements must equal seven" << endl;
                        cout << "How much do you want to move your first pawn? ";
                        cin >> split1;
                        cout << "How much do you want to move your second pawn? ";
                        cin >> split2;
                    }
                }
                else if(card == 14)
                {
                    Sorry.displayBoard(card);
                    cout << endl;
                    cout << "Which player do you want to swap pawns with: " << endl << endl;
                    cin >> swap;
                    Sorry.displayBoard(card);
                    cout << endl;
                    cout << "Which pawn do you want to swap with: " << endl << endl;
                    cin >> pawnSwap;
                }
                else if(card == -2)
                {
                    Sorry.displayBoard(card);
                    cout << endl;
                    cout << "Which player do you want to swap pawns with: " << endl << endl;
                    cin >> swap;
                    Sorry.displayBoard(card);
                    cout << endl;
                    cout << "Which pawn do you want to swap with: " << endl << endl;
                    cin >> pawnSwap;
                }
                
/*printing out pawn movements*/
                if(card == 1)
                {
                    cout << "You moved pawn " << pawn << ", " << card << " tile" << endl;
                }
                else if(card == 13)
                {
                    cout << "You moved pawn " << pawn << ", " << split1 << " tiles" << endl;
                    cout << "You moved pawn " << pawn2 << ", " << split2 << " tiles" << endl;
                }
                else if(card == 14)
                {
                    cout << "You replaced your enemies pawn with pawn " << pawn << endl;
                }
                else if(card == -2)
                {
                    cout << "You swapped your enemies pawn with pawn " << pawn << endl;
                }
                else
                {
                    cout << "You moved pawn " << pawn << ", " << card << " tiles" << endl;
                }
                pawn += 8;
                pawn2 += 8;
                
/*moving pawns*/
                if(card == 13)
                {
                    Sorry.movePawn(pawn, split1);
                    Sorry.movePawn(pawn2, split2);
                }
                else if(card == 14)
                {
                    pawnSwap = ((swap - 1) * 3 + pawnSwap) - 1;
                    Sorry.sorry(pawn, pawnSwap);
                }
                else if(card == -2)
                {
                    pawnSwap = ((swap - 1) * 3 + pawnSwap) - 1;
                    Sorry.swap(pawn, pawnSwap);
                }
                else
                {
                    moveStart = Sorry.movePawn(pawn, card);
                    if(moveStart == false && card == -1)
                    {
                        cout << "You can't move backwards out of home" << endl;
                        Sorry.movePawn(pawn, 10);
                    }
                    else if(moveStart == false && card == -4)
                    {
                        cout << "You can't move backwards out of home" << endl;
                        Sorry.movePawn(pawn, 0);
                    }
                }
                Sorry.displayBoard(card);
                
/*win checking*/
                win4 = Sorry.isWon(4);
                if(win4 == true)
                {
                    break;
                }
            }
        }
    }
    
    if(win1 == true)
    {
        one.setValues(1, 0, 0, 0);
        one.winDisplay();
    }
    else if(win2 == true)
    {
        two.setValues(0, 1, 0, 0);
        two.winDisplay();
    }
    else if(win3 == true)
    {
        three.setValues(0, 0, 1, 0);
        three.winDisplay();
    }
    else
    {
        four.setValues(0, 0, 0, 1);
        four.winDisplay();
    }
}