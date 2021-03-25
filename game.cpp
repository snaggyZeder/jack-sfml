#include "game.h"
#include "player.h"
#include "deck.h"
#include <SFML/Graphics.hpp>
Game::Game() {
	m_playerWon = 0; m_dealerWon = 0; m_draw = 0;
}
int Game::get_m_playerWon() { return m_playerWon; }
int Game::get_m_dealerWon() { return m_dealerWon; }
int Game::get_m_draw() { return m_draw; }
void Game::increase_playerWon() {
	m_playerWon++;
}
void Game::increase_dealerWon() {
	m_dealerWon++;
}
void Game::playersdraw() {
	m_draw++;
}



void Game::play(sf::RenderWindow& window,sf::Image& image) {
	
	Deck my_deck(image);//создаем колоду
	my_deck.shuffle();//тусуем колоду
	Player player1;//создаем игрока
	Dealer dealer;//создаем дилера
	Hand::GameStatus currentGameStatus = Hand::GAME_CONTINUE;
	
	
		

	player1.play(my_deck, window);

	currentGameStatus = player1.checkGameStatus();
	//проверяем как сыграл игрок
	//набрал 21 - выиграл сразу
	if (currentGameStatus == Hand::GAME_WIN) {
			std::cout << "Player1 win!" << std::endl;
			increase_playerWon();
			return ;
		}
	else
	//перебор - срызу проиграл
	if (currentGameStatus == Hand::GAME_LOSE) {
		std::cout << "Player1 lose!" << std::endl;
		increase_dealerWon();
		return;
	}
	else
		//игрок набрал меньше 21 очка, играет дилер
	if (currentGameStatus == Hand::GAME_CONTINUE) {
		//дилер набирает карты в руку
		dealer.play(my_deck);
		currentGameStatus = dealer.checkGameStatus();
		//проверяем, как сыграл дилер
		//если дилер набрал от 17 до 20 очков
	if (currentGameStatus == Hand::GAME_CONTINUE) {
			//вычисляем очки игрока и дилера
			int playerScore = player1.calculateScore();
			int dealerSCore = dealer.calculateScore();
			//у игрока больше очков - победил игрок
	if (playerScore > dealerSCore) {
		    std::cout << "Player1 win!" << std::endl;
		    increase_playerWon();
		    return;
				}
		    //у дилера больше - победил дилер
	if (dealerSCore > playerScore) {
			std::cout << "Dealer win!" << std::endl;
			increase_dealerWon();
			return;
				}
		    //поровну - ничья
	if (dealerSCore == playerScore) {
			std::cout << "Draw!" << std::endl;
			playersdraw();
			return;
				}
			}
	else
			//у дилера 21 очков - сразу выигрыш
	if (currentGameStatus == Hand::GAME_WIN) {
		std::cout << "Dealer win!" << std::endl;
		increase_dealerWon();
		return;
				}
	else
		   //у дилера перебор - сразу проигрыш
	if (currentGameStatus == Hand::GAME_LOSE) {
		std::cout << "Dealer lose!" << std::endl;
		increase_playerWon();
		return;
		 }
	}
}
