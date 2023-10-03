#ifndef CARDS
#define CARDS
#include<SDL.h>
#include<iostream>
enum Suit {
    DIAMONDS,
    HEARTS,
    CLUBS,
    SPADES,
    NONE
};

enum Number {
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ZERO
};

class Card {
    public:
        Card();
        Card(Suit suit, Number number);
        ~Card();
        std::string get_suit();
        std::string get_number();
        std::string get_name();
        int get_value(int hand_size = 2, int hand_value = 0);
        SDL_Rect* get_sprite();
    private:
        Suit m_suit;
        Number m_number;
        SDL_Rect* m_sprite;
};
#endif
