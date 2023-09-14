#pragma once
#include <string>

enum CardType
{
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
	ACE,
	LASTCARD
};

enum HandValue
{
	HIGH_CARD = 0,
	PAIR = 14,
	TWO_PAIR = 28,
	THREE_OF_A_KIND = 42,
	STRAIGHT = 56,
	FLUSH = 70,
	FULL_HOUSE = 84,
	FOUR_OF_A_KIND = 98,
	STRAIGHT_FLUSH = 112,
	ROYAL_FLUSH = 126
};

enum CardSuit
{
	HEARTS,
	DIAMONDS,
	CLUBS,
	SPADES,
	LASTSUIT
};

std::string cardTypeToString(CardType l_cardType)
{
	switch (l_cardType)
	{
	case TWO:
		return "two";
	case THREE:
		return "three";
	case FOUR:
		return "four";
	case FIVE:
		return "five";
	case SIX:
		return "six";
	case SEVEN:
		return "seven";
	case EIGHT:
		return "eight";
	case NINE:
		return "nine";
	case TEN:
		return "ten";
	case JACK:
		return "jack";
	case QUEEN:
		return "queen";
	case KING:
		return "king";
	case ACE:
		return "ace";
	default:
		return "invalid card type";
	}
}

std::string cardSuitToString(CardSuit l_cardSuit)
{
	switch (l_cardSuit)
	{
	case HEARTS:
		return "hearts";
	case DIAMONDS:
		return "diamonds";
	case CLUBS:
		return "clubs";
	case SPADES:
		return "spades";
	}
}

struct CardData
{
	CardType m_type;
	CardSuit m_suit;
	CardData(CardType p_type, CardSuit p_suit):
		m_type(p_type), m_suit(p_suit)
	{}
};