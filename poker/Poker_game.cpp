#include "Poker_game.h"
#include <iostream>

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
	std::cout << "Everyone is dealt " << p_handSize << " cards." << std::endl;
	m_deck.shuffleDeck();
	for (int i = 0; i < m_players.size(); i++)
	{
		for (int j = 0; j < p_handSize; j++)
		{
			m_players[i].addCard(m_deck.drawCard());
		}
	}
}

void PokerGame::bettingRound(bool first)
{
	int turns = m_players.size();
	int i = 0;
	if (first)
	{
		m_players[i].betMoney(1);
		std::cout << "Player " << i << " is the small blind." << std::endl;
		i++;
		m_players[i].betMoney(2);
		std::cout << "Player " << i << " is the big blind." << std::endl;
		i++;
		m_currentBet = 2;
	}
	
	while (checkBet(m_currentBet) == false || turns != 0)
	{
		if (i >= m_players.size())
		{
			i = 0;
		}
		m_currentBet = m_players[i].playTurn(m_currentBet);
		i++;
		turns--;
		if (turns < 0) {
			turns = 0;
		}
	}
	std::cout << "The betting round is over! Current bet is set at " << m_currentBet << std::endl;
}

bool PokerGame::checkBet(int currentBet)
{
	for (int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].getBet() != currentBet)
		{
			return false;
			std::cout << "The bet isn't equal." << std::endl;
		}
	}
	return true;
}
