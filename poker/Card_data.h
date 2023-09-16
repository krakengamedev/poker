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

struct CardData
{
	CardType m_type;
	CardSuit m_suit;
	CardData(CardType p_type, CardSuit p_suit):
		m_type(p_type), m_suit(p_suit)
	{}
};