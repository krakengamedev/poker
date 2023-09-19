#include <SFML/Graphics.hpp>
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
    for (int i = 0; i <= 2; i++) {
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

    std::vector<CardData*> hand;

    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Poker");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                hand.clear();
                for (int i = 0; i < 10; i++)
                {
                    hand.push_back(deck.drawCard());
                }
                std::cout << valueHand(hand) << std::endl;
                deck.discardHand(&hand);
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}