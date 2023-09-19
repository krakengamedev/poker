#include "Poker_player.h"
#include <iostream>
#include "Poker_game.h"
#include "Deck.h"

PokerPlayer::PokerPlayer(std::string p_name):
    m_name(p_name), m_hasFolded(false)
{
}

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

void PokerPlayer::printHand()
{
    std::cout << std::endl << std::endl << "Player " << m_name << "'s hand: " << std::endl;
    for (int i = 0; i < m_hand.size(); i++)
    {
        CardData* l_card = m_hand[i];
        std::cout << "The " << cardTypeToString(l_card->m_type) << " of " << cardSuitToString(l_card->m_suit) << std::endl;
    }
    std::cout << valueHand(m_hand) << std::endl;
}

int PokerPlayer::getBet()
{
    return m_bet;
}

void PokerPlayer::resetBet()
{
    m_bet = 0;
}
