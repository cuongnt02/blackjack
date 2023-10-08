#include"player.h"
#include "game.h"


Player::Player()
{
    m_hand_size = 0;
    std::fill_n(m_hand, 5, Card());
    m_curr_value = 0;
}

Player::~Player()
{
    m_hand_size = 0;
}

void Player::draw_card(Deck* deck)
{
    Card card = deck->pop();
    if (deck->get_top() < 10) {
        deck->reset();
        fill_deck(deck);
        shuffle_deck(deck);
    }
    if (m_hand_size < 5)
    {
        m_hand[m_hand_size++] = card;
    }    
}

void Player::draw_card_auto(Deck * deck) {
    while (m_hand_size < 5 && get_hand_value() < 16) {
        draw_card(deck);
    }
}

bool Player::draw_first_hand(Deck* deck)
{
    draw_card(deck);
    draw_card(deck);
    if (get_hand_value() == 21) return true;
    return false;
}

int Player::get_hand_value()
{
    int sum = 0;
    for (int i = 0; i < m_hand_size; i++)
    {
        sum += m_hand[i].get_value(m_hand_size, m_curr_value);
    }
    m_curr_value = sum;
    return sum;
}

Card* Player::get_hand()
{
    return m_hand;
}

int Player::get_hand_size()
{
    return m_hand_size;
}

int Player::get_current_value() {
    return m_curr_value;
}
