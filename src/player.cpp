#include"player.h"


Player::Player()
{
    m_hand_size = 0;
    std::fill_n(m_hand, 5, Card());
}

Player::~Player()
{
    m_hand_size = 0;
}

void Player::draw_card()
{
    int suit = rand() % 4;
    int number = rand() % 13;
    if (m_hand_size < 5)
    {
        m_hand[m_hand_size++] = Card(static_cast<Suit>(suit), static_cast<Number>(number));
    }    
}

void Player::draw_first_hand()
{
    draw_card();
    draw_card();
}

int Player::get_hand_value()
{
    int sum = 0;
    for (int i = 0; i < m_hand_size; i++)
    {
        sum += m_hand[i].get_value(m_hand_size);
    }
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
