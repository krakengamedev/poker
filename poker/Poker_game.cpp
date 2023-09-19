#include "Poker_game.h"

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

void PokerGame::dealCards(int p_handSize)
{
	m_deck.shuffleDeck();
	for (int i = 0; i < m_players.size(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			m_players[i].addCard(m_deck.drawCard());
		}
		m_players[i].printHand();
	}
}

void PokerGame::bettingRound()
{
}

bool PokerGame::checkBet(int currentBet)
{
	for (int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].getBet() != currentBet)
		{
			return false;
		}
	}
	return true;
}
