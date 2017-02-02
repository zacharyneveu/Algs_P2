//Some includes
#include <iostream>
#include <string>

enum suit {CLUB, DIAMOND, HEART, SPADE};
enum value {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
			NINE, TEN, JACK, QUEEN, KING};

class card {
private:
	enum suit suit;
	enum value value;
	card * next;
public:
	card(enum suit suit, enum value value);

	void setSuit(enum suit suit);
	void setValue(enum value value);
	enum suit getSuit();
	enum suit getValue();

	friend ostream& operator<< (ostream& ostr, const card &card);
};