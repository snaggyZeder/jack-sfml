#pragma once
#include "hand.h"
#include "deck.h"
#include <SFML/Graphics.hpp>
class Player :public Hand {
public:
	void play(Deck&, sf::RenderWindow&);
};
