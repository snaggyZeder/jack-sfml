#pragma once
#include "hand.h"
#include "deck.h"
class Dealer : public Hand {
public:
	void play(Deck&);
};

