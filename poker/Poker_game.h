#pragma once
#include "Deck.h"
#include "Poker_player.h"
#include <vector>


class PokerGame
{
	Deck m_deck;
	std::vector<PokerPlayer> m_players;
	int player_index;
	
public:
	void dealCards(int p_handSize);
	void bettingRound();

};

