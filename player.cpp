#include"player.h"


Player::Player()
{
    mTurn = false;
    mChip = 0;
    mNumberOfCards = 0;
    std::fill_n(mHand, 5, Card());
}

Player::~Player()
{
    mTurn = false;
    mChip = 0;
    mNumberOfCards = 0;
}

void Player::drawCard()
{
    int suit = rand() % 4;
    int number = rand() % 13;
    if (mNumberOfCards < 5)
    {
        mHand[mNumberOfCards++] = Card(static_cast<Suit>(suit), static_cast<Number>(number));
    }    
}

void Player::setTurn(bool isTurn)
{
    mTurn = isTurn;
}

void Player::drawFirstHand()
{
    drawCard();
    drawCard();
}

int Player::getHandValue()
{
    int sum = 0;
    for (int i = 0; i < mNumberOfCards; i++)
    {
        sum += mHand[i].getValue(mNumberOfCards);
    }
    return sum;
}

Card* Player::getHand()
{
    return mHand;
}

int Player::getNumberOfCards()
{
    return mNumberOfCards;
}