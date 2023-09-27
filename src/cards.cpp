#include"cards.h"
#include"game.h"

Card::Card()
{
    m_suit = Suit::NONE;
    m_number = Number::ZERO;
    m_sprite = NULL;
}

Card::Card(Suit suit, Number number)
{
    m_suit = suit;
    m_number = number;
    m_sprite = &card_sprites
    [static_cast<std::underlying_type<Suit>::type>(suit)]
    [static_cast<std::underlying_type<Number>::type>(number)];
}

Card::~Card()
{
    m_suit = Suit::NONE;
    m_number = Number::ZERO;
    m_sprite = NULL;
}

std::string Card::get_name()
{
    return get_number() + " " + get_suit();
}

std::string Card::get_number()
{
    std::string number = "None";
    switch (m_number)
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

std::string Card::get_suit()
{
    std::string suit = "None";
    switch (m_suit)
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

int Card::get_value(int hand_size)
{
    int value = 0;
    switch (m_number)
    {
    
    case TWO:
    case THREE:
    case FOUR:
    case FIVE:
    case SIX:
    case SEVEN:
    case EIGHT:
    case NINE:
        value = static_cast<std::underlying_type<Number>::type>(m_number) + 1;
        break;
    case TEN:
    case JACK:
    case QUEEN:
    case KING:
        value = 10;
        break;
    case ACE:
    {
        if (hand_size > 1)
        {
            value = 11;
        }
        else if (hand_size > 2)
        {
            value = 10;
        }
        else if (hand_size > 3)
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

SDL_Rect* Card::get_sprite()
{
    return m_sprite;
}
