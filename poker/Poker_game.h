#pragma once
#include "Deck.h"
#include "Poker_player.h"
#include <vector>


class PokerGame
{
public:
	Deck m_deck;
	std::vector<PokerPlayer> m_players;
	int player_index;
	int m_currentBet = 0;
	
public:
	void dealCards(int p_handSize);
	void bettingRound(bool first = false);
	bool checkBet(int currentBet);

};

std::string cardTypeToString(CardType l_cardType);

std::string cardSuitToString(CardSuit l_cardSuit);
