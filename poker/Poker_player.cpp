#include "Poker_player.h"
#include <iostream>
#include "Poker_game.h"
#include "Deck.h"
#include <string>

PokerPlayer::PokerPlayer(std::string p_name):
    m_name(p_name), m_hasFolded(false), m_bet(0), m_money(100)
{
}

int PokerPlayer::betMoney(int p_request)
{
    if (p_request > m_money)
    {
        p_request = m_money;
    }
    m_money -= p_request;
    m_bet += p_request;
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
    valueHand(m_hand);
}

int PokerPlayer::getBet()
{
    return m_bet;
}

void PokerPlayer::resetBet()
{
    m_bet = 0;
}

int PokerPlayer::playTurn(int currentBet)
{
    if (m_hasFolded == false)
    {
        std::cout << "It is player " << m_name << "'s turn. Press any key and then enter when you are ready." << std::endl;
        std::string enter;
        std::cin >> enter;
        printHand();
        std::cout << "The pot bet is " << currentBet << " and your current bet is " << m_bet<< " and your current money is " << m_money << std::endl;
        std::cout << "press c to check, r to raise, or f to fold and press enter." << std::endl;
        std::string input;
        std::cin >> input;
        char ch = input[0];
        while (ch != 'c' && ch != 'r' && ch != 'f')
        {
            std::cout << "Invalid input, press c to call, r to raise, or f to fold and press enter." << std::endl;
            std::cin >> input;
            ch = input[0];
        }
        if (ch == 'c')
        {
            std::cout << "You call by putting " << currentBet - m_bet << " into the pot." << std::endl;
            betMoney(currentBet - m_bet);
            return currentBet;
        }
        else if (ch == 'r')
        {
            int betSize = 0;
            std::cout << "Enter the amount of money you intend to bet." << std::endl;
            std::cin >> betSize;
            while (betSize < currentBet - m_bet)
            {
                std::cout << "Enter a number that will raise the bet up to above the current bet." << std::endl;
                std::cin >> betSize;
            }
            int oldBet = m_bet;
            betSize = betMoney(betSize);
            std::cout << "You put " << betSize << " chips into the pot and raise the bet to " << currentBet + betSize << std::endl;
            return currentBet + betSize;
        }
        else if (ch == 'f')
        {
            std::cout << "You fold, and are no longer in the game." << std::endl;
            m_hasFolded = true;
            return currentBet;
        }
    }
}
