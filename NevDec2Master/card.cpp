// Contains methods for the card class

#include "card.h"
#include <iostream>
#include <string>

using namespace std;

//constructor for the card class
card::card(Suit suit, Value value) {
	this->suit = suit;
	this->value = value;
}

//constructor for the card class
card::card(const card &card) {
	this->suit = card.suit;
	this->value = card.value;
}

//Set the Suit value of this card
void card::setSuit(Suit suit) {
	this->suit = suit;
}

//Sets the face Value of this card
void card::setValue(Value suit) {
	this->value = value;
}

//Returns the Suit of this card
Suit card::getSuit() const {
	return suit;
}

//Return the face Value of this card
Value card::getValue() const {
	return value;
}

//Overloaded operator << displays the values stored in a card. 
ostream& operator<< (ostream& ostr, const card& card)
{
	//convert the value to a string
	switch (card.getValue()) {
	case ACE:
		ostr << "A";
	case TWO:
		ostr << "2";
	case THREE:
		ostr << "3";
	case FOUR:
		ostr << "4";
	case FIVE:
		ostr << "5";
	case SIX:
		ostr << "6";
	case SEVEN:
		ostr << "7";
	case EIGHT:
		ostr << "8";
	case NINE:
		ostr << "9";
	case TEN:
		ostr << "10";
	case JACK:
		ostr << "J";
	case QUEEN:
		ostr << "Q";
	case KING:
		ostr << "K";
	default:
		//unreachable code
		break;
	}

	//convert the suit to a string
	switch (card.getSuit()) {
	case CLUB:
		ostr << "♣";
	case HEART:
		ostr << "♥";
	case DIAMOND:
		ostr << "♦";
	case SPADE:
		ostr << "♠";
	default:
		//unreachable code
		break;
	}

	return ostr;
}
