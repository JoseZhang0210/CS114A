using namespace std;
#ifndef DECK_OF_CARD_H
#define DECK_OF_CARD_H

class DeckOfCard
{

public:
	DeckOfCard();//creates a vecter<card*> stores 52 Card objects 
	void shuffle();
	string draw();
private:
	int currentCard;
	Card* deck[52];
};

#endif