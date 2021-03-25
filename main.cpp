#include <iostream>
#include "card.h"
#include "deck.h"
#include "game.h"
#include "hand.h"
#include "player.h"
#include "dealer.h"
#include <SFML/Graphics.hpp>
using namespace sf;
int main() {

	sf::RenderWindow window(sf::VideoMode(1024, 800), "SFML Works!");
	Image image;
	image.loadFromFile("imagess/deck.png");
	Deck my_deck(image);
 
	my_deck.shuffle();
	/*my_deck.print_deck();*/
	Game my_game;
	
	while (window.isOpen())
	{
		window.clear(Color(250, 220, 100, 0));
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == sf::Event::Closed)
				// тогда закрываем его
				window.close();
		}


		
		my_game.play(window, image);
		/*std::cout << "do yo want another game?" << std::endl;
		 std::cout << " (enter your choice, y - yes, n - no) ";
		 std::cin >> choise;

		std::cout << "player wins:" << my_game.get_m_playerWon() << std::endl;
		std::cout << "dealer wins:" << my_game.get_m_dealerWon() << std::endl;
		std::cout << "draws:" << my_game.get_m_draw() << std::endl;

		my_deck.getCard(5).drawCard(window);*/
	 
		window.display();
	}
}