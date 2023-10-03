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

int Card::get_value(int hand_size, int hand_value)
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
        switch (hand_size) {
            case 2:
                value = 11;
                break;
            case 3:
                value = 10; 
                if (hand_value < 21)
                    break;
            case 4:
            case 5:
                value = 1;
                break;
            default:
                break;
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
