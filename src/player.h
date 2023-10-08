#ifndef PLAYER
#define PLAYER
#include<SDL.h>
#include"cards.h"
#include<algorithm>
#include"deck.h"

class Player {
    public:
        Player();
        ~Player();
        bool draw_first_hand(Deck* deck);
        void draw_card(Deck* deck);
        void draw_card_auto(Deck* deck);
        int get_hand_value();
        Card* get_hand();
        int get_hand_size();
        int get_current_value();
    private:
        Card m_hand[5];
        int m_hand_size;
        int m_curr_value;
};

#endif
