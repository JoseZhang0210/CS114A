using namespace std;
#ifndef CARD_H
#define CARD_H

class Card
{
	
	public:
		Card(int initial_face, int initial_suit);
		string get_card();
	private:
		int current_suit;
		int current_face;
		string suits[4] = { "Clubs", "Spade", "Heart", "Diamond" };
		string faces[13] = { "1","2","3","4","5","6","7","8","9","10","Jack","Queen","King" };
};

#endif