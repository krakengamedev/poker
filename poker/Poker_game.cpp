#include "Poker_game.h"

void PokerGame::dealCards(int p_handSize)
{
	for (int i = 0; i < m_players.size(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			m_players[j].addCard(m_deck.drawCard());
		}
	}
}

void PokerGame::bettingRound()
{
}
