#include <iostream>
#include <cstdlib>
#include <ctime>
#include "1093315_Card.h"
#include "1093315_DeckOfCard.h"
using namespace std;

Card::Card(int initial_face, int initial_suit)
{
	current_suit = initial_suit;
	current_face = initial_face;
}

string Card::get_card()
{
	return (faces[current_face] + '_' + suits[current_suit]);
}

DeckOfCard::DeckOfCard()
{
	currentCard = 0;
	
	//making a array stores 52 Card objects
	for(int i=0;i<4;i++)
		for (int j = 0;j < 13;j++)
		{
			deck[(i*13+j)] = new Card(j, i);
		}
}

void DeckOfCard::shuffle()
{
	srand(time(NULL));
	for (int i = 0;i < 52;i++)
	{
		swap(deck[i], deck[(rand()%52)]);
	}
}

string DeckOfCard::draw()
{
	
		return (deck[currentCard++]->get_card());
}

int main()
{
	DeckOfCard test;
	test.shuffle();
	for (int i = 0;i < 52;i++)
	{
		cout<<test.draw();
		if (i < 51)
			cout << ", ";
	}
}

