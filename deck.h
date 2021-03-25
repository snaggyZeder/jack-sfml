#pragma once
#include "card.h"
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
class Deck {
private:
	const int deck_size = 52;
	std::vector<Card*> m_deck;
	 
public:
	Deck(sf::Image&);
	void shuffle();//перетасовать колоду
	Card* pop();//взять верхнюю карту
	void print_deck();//печать колоду
	Card getCard(int);
};