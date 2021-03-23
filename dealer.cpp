#include "dealer.h"
#include <iostream>
void Dealer::play(Deck& fDeck) {
	//äèëåð áåðåò êàðòû, ïîêà íå íàáåðåò 17 î÷êîâ èëè áîëüøå
	//ïîêà ñ÷åò ìåíüøå 17
	std::cout << std::endl;
	std::cout << "DEALER MOVE";
	std::cout << std::endl;
	do {
		//áåðåì êàðòó
		takeOneCard(fDeck);
	} while (calculateScore() < 17);
	printHand();
	std::cout << "Dealer score is " << calculateScore() << std::endl;
}