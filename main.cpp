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
#include "Board.h"

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
    
    players = p.setOrder(0);
    
/*player interaction*/
    int pawn;
    int pawn2;
    int card;
    int split1;
    int split2;
    
    bool win1 = false;
    bool win2 = false;
    bool win3 = false;
    bool win4 = false;
    
    Board Sorry;
    cout << endl;
    
    while((win1 == false) && (win2 == false) && (win3 == false) && (win4 == false))
    {
/*player 1*/
        do
        {
            cout << "Player 1 select your pawn:";
            cin >> pawn;
        } while(pawn != 1 && pawn != 2 && pawn != 3);
        
        card = cardSelection();
        
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
                cout << "Both pawn movements must equal seven: ";
                cin >> split1;
                cout << "Both pawn movements must equal seven: ";
                cin >> split2;
            }
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
            //Sorry.doMove(pawn, split1);
            Sorry.movePawn(pawn2, split2);
            //Sorry.doMove(pawn2, split2);
        }
        else
        {
            Sorry.movePawn(pawn, card);
            //Sorry.doMove(pawn, card);
        }
        
        Sorry.displayBoard();
        
/*win checking*/
        if(win1 == true)
        {
            break;
        }
        
/*player 2*/
        do
        {
            cout << "Player 2 select your pawn:";
            cin >> pawn;
        } while(pawn != 1 && pawn != 2 && pawn != 3);
        
        card = cardSelection();
        
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
                cout << "Both pawn movements must equal seven: ";
                cin >> split1;
                cout << "Both pawn movements must equal seven: ";
                cin >> split2;
            }
        }
        
/*error checking*/
        if(card == 1)
        {
            cout << "You moved pawn " << pawn << ", " << card << " tile" << endl;
        }
        else if(card == 13)
        {
            cout << "You moved pawn " << pawn << ", " << split1 << " tiles" << endl;
            cout << "You moved pawn " << pawn2 << ", " << split2 << " tiles" << endl;
        }
        else
        {
            cout << "You moved pawn " << pawn << ", " << card << " tiles" << endl;
        }
    
/*displaying to board*/
        pawn += 2;
        pawn2 += 2;
        
        if(card == 13)
        {
            Sorry.movePawn(pawn, split1);
            //Sorry.doMove(pawn, split1);
            Sorry.movePawn(pawn2, split2);
            //Sorry.doMove(pawn2, split2);
        }
        else
        {
            Sorry.movePawn(pawn, card);
            //Sorry.doMove(pawn, card);
        }
        Sorry.displayBoard();
        
/*win checking*/
        if(win2 == true)
        {
            break;
        }
        
        if(players == 3 || players == 4)
        {
/*player 3*/
            do
            {
                cout << "Player 3 select your pawn:";
                cin >> pawn;
            } while(pawn != 1 && pawn != 2 && pawn != 3);
            
            card = cardSelection();
            
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
                    cout << "Both pawn movements must equal seven: ";
                    cin >> split1;
                    cout << "Both pawn movements must equal seven: ";
                    cin >> split2;
                }
            }
            
/*error checking*/
            if(card == 1)
            {
                cout << "You moved pawn " << pawn << ", " << card << " tile" << endl;
            }
            else if(card == 13)
            {
                cout << "You moved pawn " << pawn << ", " << split1 << " tiles" << endl;
                cout << "You moved pawn " << pawn2 << ", " << split2 << " tiles" << endl;
            }
            else
            {
                cout << "You moved pawn " << pawn << ", " << card << " tiles" << endl;
            }
            
/*displaying to board*/
            pawn += 5;
            pawn2 += 5;
            
            if(card == 13)
            {
                Sorry.movePawn(pawn, split1);
                //Sorry.doMove(pawn, split1);
                Sorry.movePawn(pawn2, split2);
                //Sorry.doMove(pawn2, split2);
            }
            else
            {
                Sorry.movePawn(pawn, card);
                //Sorry.doMove(pawn, card);
            }
            Sorry.displayBoard();
            
/*win checking*/
            if(win3 == true)
            {
                break;
            }
            
            if(players == 4)
            {
/*player 4*/
                do
                {
                    cout << "Player 4 select your pawn:";
                    cin >> pawn;
                } while(pawn != 1 && pawn != 2 && pawn != 3);
                
                card = cardSelection();
                
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
                        cout << "Both pawn movements must equal seven: ";
                        cin >> split1;
                        cout << "Both pawn movements must equal seven: ";
                        cin >> split2;
                    }
                }
                
/*error checking*/
                if(card == 1)
                {
                    cout << "You moved pawn " << pawn << ", " << card << " tile" << endl;
                }
                else if(card == 13)
                {
                    cout << "You moved pawn " << pawn << ", " << split1 << " tiles" << endl;
                    cout << "You moved pawn " << pawn2 << ", " << split2 << " tiles" << endl;
                }
                else
                {
                    cout << "You moved pawn " << pawn << ", " << card << " tiles" << endl;
                }
            
/*displaying to board*/
                pawn += 8;
                pawn2 += 8;
                
                if(card == 13)
                {
                    Sorry.movePawn(pawn, split1);
                    //Sorry.doMove(pawn, split1);
                    Sorry.movePawn(pawn2, split2);
                    //Sorry.doMove(pawn2, split2);
                }
                else
                {
                    Sorry.movePawn(pawn, card);
                    //Sorry.doMove(pawn, card);
                }
                Sorry.displayBoard();
                
/*win checking*/
                if(win4 == true)
                {
                    break;
                }
            }
        }
    }
    
    if(win1 == true)
    {
        one.winCheck();
        one.winDisplay();
    }
    else if(win2 == true)
    {
        two.winCheck();
        two.winDisplay();
    }
    else if(win3 == true)
    {
        three.winCheck();
        three.winDisplay();
    }
    else
    {
        four.winCheck();
        four.winDisplay();
    }
    
}