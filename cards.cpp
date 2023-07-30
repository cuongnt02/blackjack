#include"cards.h"
#include"game.h"

Card::Card()
{
    mSuit = Suit::NONE;
    mNumber = Number::ZERO;
    mSprite = NULL;
}

Card::Card(Suit suit, Number number)
{
    mSuit = suit;
    mNumber = number;
    mSprite = &cardSprites
    [static_cast<std::underlying_type<Suit>::type>(suit)]
    [static_cast<std::underlying_type<Number>::type>(number)];
}

Card::~Card()
{
    mSuit = Suit::NONE;
    mNumber = Number::ZERO;
    mSprite = NULL;
}

std::string Card::getName()
{
    return getNumber() + " " + getSuit();
}

std::string Card::getNumber()
{
    std::string number = "None";
    switch (mNumber)
    {
    case ACE:
        number = "Ace";
        break;
    case TWO:
        number =  "Two";
        break;
    case THREE:
        number =  "Three";
        break;
    case FOUR:
        number =  "Four";
        break;
    case FIVE:
        number =  "Five";
        break;
    case SIX:
        number =  "Six";
        break;
    case SEVEN:
        number =  "Seven";
        break;
    case EIGHT:
        number =  "Eight";
        break;
    case NINE:
        number =  "Nine";
        break;
    case TEN:
        number =  "Ten";
        break;
    case JACK:
        number =  "Jack";
        break;
    case QUEEN:
        number =  "Queen";
        break;
    case KING:
        number =  "King";
        break;
    default:
        break;

    }
    return number;
}

std::string Card::getSuit()
{
    std::string suit = "None";
    switch (mSuit)
    {
    case DIAMONDS:
        suit = "Diamonds";
        break;
    case HEARTS:
        suit = "Hearts";
        break;
    case CLUBS:
        suit = "Clubs";
        break;
    case SPADES:
        suit = "Spades";
        break;
    default:
        break;
    }
    return suit;
}

int Card::getValue(int numberOfCards)
{
    int value = 0;
    switch (mNumber)
    {
    
    case TWO:
    case THREE:
    case FOUR:
    case FIVE:
    case SIX:
    case SEVEN:
    case EIGHT:
    case NINE:
        value = static_cast<std::underlying_type<Number>::type>(mNumber) + 1;
        break;
    case TEN:
    case JACK:
    case QUEEN:
    case KING:
        value = 10;
        break;
    case ACE:
    {
        if (numberOfCards > 1)
        {
            value = 11;
        }
        else if (numberOfCards > 2)
        {
            value = 10;
        }
        else if (numberOfCards > 3)
        {
            value = 1;
        }
        else 
        {
            value = 0;
        }
    }
    default:
        break;
    }
    return value;
}

SDL_Rect* Card::getSprite()
{
    return mSprite;
}