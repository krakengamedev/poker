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
	
public:
	void dealCards(int p_handSize);
	void bettingRound();
	bool checkBet(int currentBet);

};

std::string cardTypeToString(CardType l_cardType);

std::string cardSuitToString(CardSuit l_cardSuit);
