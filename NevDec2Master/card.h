//Some includes
#include <iostream>
#include <string>

//enumeration for the card suits
enum suit {CLUB, DIAMOND, HEART, SPADE};

//enumeration for the card face value
enum value {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
			NINE, TEN, JACK, QUEEN, KING};

class card {
private:
	enum suit suit;
	enum value value;
public:
	card(enum suit suit, enum value value);

	void setSuit(enum suit suit);
	void setValue(enum value value);
	enum suit getSuit();
	enum suit getValue();

	friend ostream& operator<< (ostream& ostr, const card &card);
};