#include "Poker_player.h"


int PokerPlayer::betMoney(int p_request)
{
    if (p_request > m_money)
    {
        p_request = m_money;
    }
    m_money -= p_request;
    return p_request;
}

int PokerPlayer::getMoney()
{
    return m_money;
}

std::vector<CardData*> PokerPlayer::getHand()
{
    return m_hand;
}

bool PokerPlayer::getFolded()
{
    return m_hasFolded;
}

void PokerPlayer::addCard(CardData* p_card)
{
    m_hand.push_back(p_card);
}
