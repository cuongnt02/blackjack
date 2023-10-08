#include"deck.h"

Deck::Deck() {
    m_top = 0;
    m_deck_size = 52;
    m_cards = new Card[m_deck_size];
    for (int i = 0; i < m_deck_size; i++) {
        Card card = Card();
        m_cards[i] = card;
    }
}

Deck::~Deck() {
    m_top = 0;
    delete[] m_cards;
}

void Deck::reset() {
    Deck::~Deck();
    Deck();
}

void Deck::push(Card card) {
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

Card Deck::pop() {
    if (!is_empty()) {
        Card card = m_cards[m_top - 1];
        m_top--;
        return card;
    }
    return Card();
}

int Deck::get_top() {
    return m_top;
}

void Deck::shuffle() {
    for (int i = 0 ;i < m_deck_size - 1; i++) {
        int j = rand() % (m_deck_size - 1 - i) + i;
        Card temp = m_cards[i];
        m_cards[i] = m_cards[j];
        m_cards[j] = temp;
    }
}
