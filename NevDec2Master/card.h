//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file contains the definition of the card class.  This class holds objects
//with two data members: suit and value.  The implementations for the member
//functions defined in this class can be found in card.cpp.

#ifndef CARD_H
#define CARD_H

//Some includes
#include <iostream>
#include <string>
//Return the face Value of this card

using namespace std;

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

	//Returns a string representation of a card object
	string toString() const;
	
	//converts a card to a string representation, for printing to ostream
	friend ostream& operator<< (ostream& ostr, const card &card);
};

#endif
