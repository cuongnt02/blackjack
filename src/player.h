#ifndef PLAYER
#define PLAYER
#include<SDL.h>
#include"cards.h"
#include<algorithm>

class Player {
    public:
        Player();
        ~Player();
        void draw_first_hand();
        void draw_card();
        int get_hand_value();
        Card* get_hand();
        int get_hand_size();
    private:
        Card m_hand[5];
        int m_hand_size;
};

#endif
