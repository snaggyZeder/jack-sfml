#include "deck.h"
#include "card.h"
#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
Deck::Deck(sf::Image& Image) {
	for (int j = 0; j < MAX_SUITS; j++) {
		for (int k = 0; k < MAX_RANK; k++) {
			//создать карту и добавить её в вектор
			Card* temp_card=new Card(Image,static_cast<CardRank>(k), static_cast<CardSuits>(j));
			m_deck.push_back(temp_card);
		}
	}
}

void Deck::shuffle() {
	const int numberOfShuffles = 5;
	srand(time(0));
	for (int j = 0; j < numberOfShuffles; j++) {
		//тусуем колоду
		for (int i = 0; i < deck_size; i++) {
			//выбрали карту со случайным номером
			int randomCard = rand() % deck_size;
			//обменяли местами текущую и случайно выбранную карту
			std::swap(*m_deck[i], *m_deck[randomCard]);
		}
	}
}
void Deck::print_deck() {
	int size = m_deck.size();
	for (int i = 0; i < size; i++)
		(*m_deck[i]).print_card();
	//std::cout << m_deck[i];
//<< m_deck
}

Card* Deck::pop() {
	int lastCard = m_deck.size() - 1;
	Card* temp = m_deck[lastCard];
	m_deck.pop_back();
	return temp;
}


Card Deck::getCard(int i) {
	return *m_deck[i];
}