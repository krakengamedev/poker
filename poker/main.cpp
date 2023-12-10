#include "Deck.h"
#include "constants.h"
#include <iostream>
#include <vector>
#include "Poker_game.h"
#include "Poker_player.h"

int main()
{
    srand(time(0));
    Deck deck = Deck();
    deck.shuffleDeck();
    
    PokerGame game;
    for (int i = 0; i <= 2; i++) 
    {
        game.m_players.push_back(PokerPlayer(std::to_string(i)));
        std::cout << std::to_string(i) << std::endl;
    }

    game.dealCards(2);

    game.bettingRound(true);

    game.dealCards(3);

    game.bettingRound();

    game.dealCards(1);

    game.bettingRound();

    game.dealCards(1);

    game.bettingRound();

    return 0;
}