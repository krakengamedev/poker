#pragma once
#include <vector>
#include "Card_data.h"
#include <string>

class PokerPlayer
{
private:
	bool m_hasFolded;
	std::vector<CardData*> m_hand;
	int m_money;
	std::string m_name;
public:
	PokerPlayer(std::string p_name);
	int betMoney(int p_request);
	int getMoney();
	std::vector<CardData*> getHand();
	bool getFolded();
	void addCard(CardData* p_card);
	void printHand();
};

