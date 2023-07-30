#ifndef CARDS
#define CARDS;
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
        std::string getSuit();
        std::string getNumber();
        std::string getName();
        int getValue(int numberOfCards = 2);
        SDL_Rect* getSprite();
    private:
        Suit mSuit;
        Number mNumber;
        SDL_Rect* mSprite;
};
#endif