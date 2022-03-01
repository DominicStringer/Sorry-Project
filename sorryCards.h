/*********************************
 * File Changes:
 *  Dominic - 3/1/2022
 * 
 * Description: 
 *
 * List of Contents:
 *  Card Class
 *  CardSorry Class
 *  Card1 Class
 *  Card2 Class
 *  Card3 Class
 *  Card4 Class
 *  Card5 Class
 *  Card7 Class
 *  Card8 Class
 *  Card10 Class
 *  Card11 Class
 *  Card12 Class
 *********************************/

class Card {
    private:
        int numInDeck;
};

class CardSorry : public Card {
    public:
        CardSorry() {numInDeck = 4;}
};

class Card1 : public Card {
    public:
        Card1() {numInDeck = 5;}
};

class Card2 : public Card {
    public:
        Card2() {numInDeck = 4;}
};

class Card3 : public Card {
    public:
        Card3() {numInDeck = 4;}
}

class Card4 : public Card {
    public:
        Card4() {numInDeck = 4;}
}

class Card5 : public Card {
    public:
        Card5() {numInDeck = 4;}
}

class Card7 : public Card {
    public:
        Card7() {numInDeck = 4;}
}

class Card8 : public Card {
    public:
        Card8() {numInDeck = 4;}
}

class Card10 : public Card {
    public:
        Card10() {numInDeck = 4;}
}

class Card11 : public Card {
    public:
        Card11() {numInDeck = 3;}
}

class Card12 : public Card {
    public:
        Card12() {numInDeck = 4;}
}
