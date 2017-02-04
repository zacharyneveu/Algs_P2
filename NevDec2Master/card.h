#ifndef CARD_H
#define CARD_H

//Some includes
//Return the face Value of this card

//enumeration for the card suits
typedef enum suit {CLUB, DIAMOND, HEART, SPADE} Suit;

//enumeration for the card face value
typedef enum value {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
			NINE, TEN, JACK, QUEEN, KING} Value;

class card {
private:
	Suit suit;
	Value value;
public:
	//constructor for card
	card(Suit suit, Value value);

	//Set the Suit value of this card
	void setSuit(Suit suit);

	//Sets the face Value of this card
	void setValue(Value value);

	//Returns the Suit of this card
	Suit getSuit() const;

	//Return the face Value of this card
	Value getValue() const;

	//converts a card to a string representation, for printing to ostream
	friend ostream& operator<< (ostream& ostr, const card &card);
};

#endif