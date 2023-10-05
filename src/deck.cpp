#include"deck.h"

Deck::Deck() {
    m_top = 0;
    m_deck_size = 52;
    m_cards = new Card*[m_deck_size];
    for (int i = 0; i < m_deck_size; i++) {
        m_cards[i] = new Card();
    }
}

Deck::~Deck() {
    m_top = 0;
    for (int i = 0; i < m_deck_size; i++) {
        delete m_cards[i];
    }
    delete[] m_cards;
}

void Deck::init() {
    Deck::~Deck();
    Deck();
}

void Deck::push(Card* card) {
    if (m_top < m_deck_size) {
        m_cards[m_top] = card;
        m_top++;
    }
}

bool Deck::is_empty() {
    return m_top == 0;
}

bool Deck::is_full() {
    return m_top == m_deck_size - 1;
}

Card* Deck::pop() {
    if (!is_empty())
        return m_cards[m_top--];
    return NULL;
}



