#include "game.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
	RenderWindow window(sf::VideoMode(1024, 800), "SFML Works!");
	window.setFramerateLimit(60);

	Game my_game;

	while (window.isOpen() && my_game.isRunning())
	{
		// Îáðàáàòûâàåì î÷åðåäü ñîáûòèé â öèêëå
		Event event;
		while (window.pollEvent(event))
		{
			// Ïîëüçîâàòåëü íàæàë íà «êðåñòèê» è õî÷åò çàêðûòü îêíî?
			if (event.type == Event::Closed)
				// òîãäà çàêðûâàåì åãî
				window.close();
			else if (event.type == Event::KeyReleased)
				my_game.processInput(event.key.code);
		}
		my_game.update();
		window.clear(Color(250, 220, 100, 0));
		window.draw(my_game);
		window.display();
	}
}