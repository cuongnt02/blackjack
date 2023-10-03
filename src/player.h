#ifndef PLAYER
#define PLAYER
#include<SDL.h>
#include"cards.h"
#include<algorithm>

class Player {
    public:
        Player();
        ~Player();
        bool draw_first_hand();
        void draw_card();
        void draw_card_auto();
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
