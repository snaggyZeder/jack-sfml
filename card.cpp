#include "card.h"
#include <SFML/Graphics.hpp>
#include <iostream>
float Card::cardWidth = 73.15;
float Card::cardHeight = 98.5;



Card::Card(sf::Image& image,CardRank f_rank, CardSuits f_suit) {
 m_rank = f_rank;
 m_suit = f_suit;
 std::cout << m_rank << std::endl;
 std::cout << m_rank << std::endl;
 x = 10;
 y = 10;
 
 cardTexture.loadFromImage(image);
 cardSprite.setTexture(cardTexture);
 int textureX, textureY;
 if (m_suit == CARD_HEARTS) textureY = cardHeight;
 else
 if (m_suit == CARD_DIAMONDS) textureY = cardHeight * 3;
 else
 if (m_suit == CARD_SPADES) textureY = cardHeight*2;
 else
 if (m_suit == CARD_CLUBS) textureY = 0;
 textureX = cardWidth * m_rank;
 cardSprite.setTextureRect(sf::IntRect(textureX, textureY, cardWidth, cardHeight));

}
void Card::print_card() {
 //вывод достоинства
 if (m_rank == CARD_2) std::cout << 2;
 else
 if (m_rank == CARD_3) std::cout << 3;
 else
 if (m_rank == CARD_4) std::cout << 4;
 else
 if (m_rank == CARD_5) std::cout << 5;
 else
 if (m_rank == CARD_6) std::cout << 6;
 else
 if (m_rank == CARD_7) std::cout << 7;
 else
 if (m_rank == CARD_8) std::cout << 8;
 else
 if (m_rank == CARD_9) std::cout << 9;
 else
 if (m_rank == CARD_10) std::cout << 10;
 else
 if (m_rank == CARD_J) std::cout << 'J';
 else
 if (m_rank == CARD_Q) std::cout << 'Q';
 else
 if (m_rank == CARD_K) std::cout << 'K';
 else
 if (m_rank == CARD_A) std::cout << 'A';
 //вывод масти
 if (m_suit == CARD_DIAMONDS) std::cout << 'D' << std::endl;
 else
 if (m_suit == CARD_HEARTS) std::cout << 'H' << std::endl;
 else
 if (m_suit == CARD_SPADES) std::cout << 'S' << std::endl;
 else
 if (m_suit == CARD_CLUBS) std::cout << 'C' << std::endl;
}
int Card::get_score() {
 if (m_rank == CARD_2) return 2;
 else
 if (m_rank == CARD_3) return 3;
 else
 if (m_rank == CARD_4) return 4;
 else
 if (m_rank == CARD_5) return 5;
 else
 if (m_rank == CARD_6) return 6;
 else
 if (m_rank == CARD_7) return 7;
 else
 if (m_rank == CARD_8) return 8;
 else
 if (m_rank == CARD_9) return 9;
 else
 if (m_rank == CARD_10) return 10;
 else
 if (m_rank == CARD_J) return 10;
 else
 if (m_rank == CARD_Q) return 10;
 else
 if (m_rank == CARD_K) return 10;
 else
 if (m_rank == CARD_A) return 1;
}
CardRank Card::get_rank() {
 return m_rank;
}
CardSuits Card::get_suit() {
 return m_suit;
}
std::ostream& operator<<(std::ostream& out, Card& fCard) {
 if (fCard.get_rank() == CARD_2) out << 2;
 else
 if (fCard.get_rank() == CARD_3) out << 3;
 else
 if (fCard.get_rank() == CARD_4) out << 4;
 else
 if (fCard.get_rank() == CARD_5) out << 5;
 else
 if (fCard.get_rank() == CARD_6) out << 6;
 else
 if (fCard.get_rank() == CARD_7) out << 7;
 else
 if (fCard.get_rank() == CARD_8) out << 8;
 else
 if (fCard.get_rank() == CARD_9) out << 9;
 else
 if (fCard.get_rank() == CARD_10) out << 10;
 else
 if (fCard.get_rank() == CARD_J) out << 'J';
 else
 if (fCard.get_rank() == CARD_Q) out << 'Q';
 else
 if (fCard.get_rank() == CARD_K) out << 'K';
 else
 if (fCard.get_rank() == CARD_A) out << 'A';
 //вывод масти
 if (fCard.get_suit() == CARD_DIAMONDS) out << 'D' << std::endl;
 else
 if (fCard.get_suit() == CARD_HEARTS) out << 'H' << std::endl;
 else
 if (fCard.get_suit() == CARD_SPADES) out << 'S' << std::endl;
 else
 if (fCard.get_suit() == CARD_CLUBS) out << 'C' << std::endl;
 return out;
}

sf::Sprite& Card::getSprite() { return cardSprite; }

void Card::drawCard(sf::RenderWindow& window) {
 cardSprite.setPosition(x, y);
 window.draw(getSprite());//выводим спрайт

}