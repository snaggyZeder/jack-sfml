#pragma once
#include <iostream>
#include "card.h"
#include "player.h"
#include "dealer.h"
#include "deck.h"
#include "hand.h"
#include <SFML/Graphics.hpp>
class Game {
private:
	int m_playerWon;
	int m_dealerWon;
	int m_draw;
public:
	Game();
	void play(sf::RenderWindow&, sf::Image&);
	void increase_playerWon();
	void increase_dealerWon();
	void playersdraw();
	int get_m_playerWon();
	int get_m_dealerWon();
	int get_m_draw();
};