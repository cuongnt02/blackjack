#ifndef PLAYER
#define PLAYER
#include<SDL.h>
#include"cards.h"
#include<algorithm>
class Player {
    public:
        Player();
        ~Player();
        void drawFirstHand();
        void drawCard();
        int getHandValue();
        void setTurn(bool isTurn);
        Card* getHand();
        int getNumberOfCards();
    private:
        int mChip;
        Card mHand[5];
        int mNumberOfCards;
        bool mTurn;
};

#endif