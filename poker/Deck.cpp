#include "Deck.h"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <tuple>
#include <array>

Deck::Deck()
{
	for (int suitInt = 0; suitInt != LASTSUIT; suitInt++)
	{
		for (int cardInt = 0; cardInt != LASTCARD; cardInt++)
		{
			m_deck.push_back(new CardData(static_cast<CardType>(cardInt), static_cast<CardSuit>(suitInt)));
		}
	}
}

void Deck::shuffleDeck()
{
	srand(std::time(NULL));
	for (int k = m_deck.size() - 1; k > 0; --k) {
		int r = rand() % (k + 1);
		std::swap(m_deck[k], m_deck[r]);
	}
}

void Deck::printDeck()
{
	for (int i = 0; i < m_deck.size(); i++)
	{
		std::cout << m_deck[i]->m_suit << "   " << m_deck[i]->m_type << std::endl;
	}
	std::cout << "Size: " << m_deck.size() << std::endl;
}

CardData* Deck::drawCard()
{
	if (m_deck.size() <= 1)
	{
		for (int i = 0; i < m_discard.size(); i++)
		{
			m_deck.push_back(m_discard[i]);
		}
		m_discard.clear();
		shuffleDeck();
	}
	CardData* card = m_deck[m_deck.size() - 1];
	m_deck.pop_back();
	return card;
}

void Deck::discardHand(std::vector<CardData*>* p_hand)
{
	for (int i = 0; i < p_hand->size(); i++)
	{
		m_discard.push_back((*p_hand)[i]);
	}
	(*p_hand).clear();
}


int valueHand(std::vector<CardData*> p_hand)
{
	std::vector<std::tuple<int, int>> l_sets;
	std::array<int, 4> l_suit_counts;

	for (int i = 0; i < p_hand.size(); i++)
	{
		// Vector to hold all the possible pairs, 3 of a kinds, and 4 of a kind
		CardData* l_currentCard = p_hand[i];

		l_suit_counts[l_currentCard->m_suit]++;

		//set checking
		bool l_foundMatch = false;
		for (int j = 0; j < l_sets.size(); j++)
		{
			//Search through the existing cards and find any type matches
			if (std::get<0>(l_sets[j]) == l_currentCard->m_type)
			{
				//increment existing card count if it exists
				std::get<1>(l_sets[j])++;
				l_foundMatch = true;
			}
		}
		if (l_foundMatch == false)
		{
			//Add a new card type if it doesn't already exist
			l_sets.push_back(std::tuple<int, int>(l_currentCard->m_type, 1));
		}
	}

	//Flag vars
	int l_longestStraight = 0;
	CardType l_startingCard;
	CardSuit l_straightSuit;
	bool l_sameSuitStraight = true;
	bool l_skipped_flag = false;

	//straight checking (loop through all the cards and keep track of the max straight found)
	for (int i = 0; i < LASTCARD; i++)
	{
		CardData* l_card = new CardData(CardType::NINE, CardSuit::CLUBS);
		if (checkCard(p_hand, (CardType)i, l_card))
		{
			if (l_longestStraight == 0)
			{
				//start tracking a new straight
				l_skipped_flag = false;
				l_longestStraight = 1;
				l_startingCard = l_card->m_type;
				l_straightSuit = l_card->m_suit;
			}
			else
			{
				//Continue tracking and increment
				if (l_skipped_flag == false)
				{
					l_longestStraight++;
					if (l_card->m_suit != l_straightSuit)
					{
						l_sameSuitStraight = false;
					}
					if (l_longestStraight >= 5)
					{
						//break out if a straight is found
						i = LASTCARD;
					}
				}
			}

		}
		else
		{
			//Reset the flag variables
			l_longestStraight = 0;
			l_sameSuitStraight = true;
			l_skipped_flag = true;
		}
	}

	//check the hand for sets
	CardType l_four_set = checkSets(l_sets, 4);
	CardType l_three_set = checkSets(l_sets, 3);
	CardType l_two_set = checkSets(l_sets, 2);
	CardType l_two_pair = checkTwoPair(l_sets);
	CardType l_high_card = checkSets(l_sets, 1);

	std::cout << "This hand is a ";

	//increment through the hands to find the best one the player has, and value it
	if (l_longestStraight >= 5 && l_startingCard >= (LASTCARD - l_longestStraight) && l_sameSuitStraight)
	{
		std::cout << "royal flush" << std::endl;
		return ROYAL_FLUSH;
	}
	else if (l_longestStraight >= 5 && l_sameSuitStraight)
	{
		std::cout << "straight flush" << std::endl;
		return STRAIGHT_FLUSH + l_startingCard + 5;
	}
	else if (l_four_set != LASTCARD)
	{
		std::cout << "4 of a kind" << std::endl;
		return FOUR_OF_A_KIND + l_four_set;
	}
	else if (l_three_set != LASTCARD && l_two_set != LASTCARD)
	{
		std::cout << "full house" << std::endl;
		return FULL_HOUSE + l_three_set;
	}
	else if (l_suit_counts[0] >= 5 || l_suit_counts[1] >= 5 || l_suit_counts[2] >= 5 || l_suit_counts[3] >= 5)
	{
		std::cout << "flush" << std::endl;
		return FLUSH;
	}
	else if (l_longestStraight >= 5)
	{
		std::cout << "straight" << std::endl;
		return STRAIGHT + l_startingCard + 5;
	} 
	else if (l_three_set != LASTCARD)
	{
		std::cout << "3 of a kind" << std::endl;
		return THREE_OF_A_KIND + l_three_set;
	}
	else if (l_two_pair != LASTCARD)
	{
		std::cout << "2 pair" << std::endl;
		return TWO_PAIR + l_two_pair;
	}
	else if (l_two_set != LASTCARD)
	{
		std::cout << "pair" << std::endl;
		return PAIR + l_two_set;
	}
	else
	{
		std::cout << "high card" << std::endl;
		return HIGH_CARD + l_high_card;
	}
}

bool checkCard(std::vector<CardData*> p_hand, CardType p_type, CardData* p_returnCard)
{
	for (int i = 0; i < p_hand.size(); i++)
	{
		if (p_hand[i]->m_type == p_type)
		{
			p_returnCard->m_suit = p_hand[i]->m_suit;
			p_returnCard->m_type = p_hand[i]->m_type;
			return true;
		}
	}
	return false;
}

CardType checkSets(std::vector<std::tuple<int, int>> p_sets, int p_value)
{
	CardType output = LASTCARD;
	for (int i = 0; i < p_sets.size(); i++)
	{
		if (std::get<1>(p_sets[i]) == p_value && ((CardType)std::get<0>(p_sets[i]) > output || output == LASTCARD))
		{
			output = (CardType)std::get<0>(p_sets[i]);
		}
	}
	return output;
}

CardType checkTwoPair(std::vector<std::tuple<int, int>> p_sets)
{
	CardType output = LASTCARD;
	bool l_two = false;
	for (int i = 0; i < p_sets.size(); i++)
	{
		if (std::get<1>(p_sets[i]) >= 2 && ((CardType)std::get<0>(p_sets[i]) > output || output == LASTCARD))
		{
			if (output != LASTCARD)
			{
				l_two = true;
			}
			output = (CardType)std::get<0>(p_sets[i]);
		}
	}
	if (l_two)
	{
		return output;
	}	
	else
	{
		return LASTCARD;
	}
}


