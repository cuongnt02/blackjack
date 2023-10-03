#include "cards.h"
class Deck {
    public:
        Deck();
        ~Deck();
        Card* pop();
        void push(Card* card);
        void init();
        bool is_empty();
        bool is_full();

    private:
        Card** m_cards;
        int m_deck_size;
        int m_top;
};
