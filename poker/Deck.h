#pragma once
#include "Card_data.h"
#include <vector>
#include <random>


int valueHand(std::vector<CardData*> p_hand);

bool checkCard(std::vector<CardData*> p_hand, CardType p_type, CardData* p_returnCard);

CardType checkTwoPair(std::vector<std::tuple<int, int>> p_sets);

CardType checkSets(std::vector<std::tuple<int, int>> p_sets, int p_value);


class Deck
{
public:
	std::vector<CardData*> m_deck;
	std::vector<CardData*> m_discard;

public:
	Deck();
	void shuffleDeck();
	void printDeck();
	CardData* drawCard();
	void discardHand(std::vector<CardData*>* p_hand);
};

