#pragma once
#include "card.h"
#include "deck.h"
#include <vector>
#include <SFML/Graphics.hpp>
class Hand {

protected:
	std::vector<Card*> m_hand;
public:
	enum GameStatus {
		GAME_CONTINUE,
		GAME_WIN,
		GAME_LOSE,
		MAX_STATUS
	};
	//Hand();
	void takeOneCard(Deck&);
	void printHand();
	int calculateScore();
	GameStatus checkGameStatus();
	void drawHand(sf::RenderWindow&);
};