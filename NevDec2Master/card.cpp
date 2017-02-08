//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file contains the implementations of the member functions in the card
//class as defined in card.h.  This class is used to store two data members:
//value and suit.

#include "card.h"
#include <iostream>
#include <string>

using namespace std;

//constructor for the card class
card::card(Suit suit, Value value) {
	this->suit = suit;
	this->value = value;
}

//Set the Suit value of this card
void card::setSuit(Suit suit) {
	this->suit = suit;
}

//Sets the face Value of this card
void card::setValue(Value value) {
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
	ostr << card.toString();
	return ostr;
}

//Returns a string representation of a card object
string card::toString() const {
	string result = "";

	switch (this->value) {
	case ACE:
		result += "A";
		break;
	case TWO:
		result += "2";
		break;
	case THREE:
		result += "3";
		break;
	case FOUR:
		result += "4";
		break;
	case FIVE:
		result += "5";
		break;
	case SIX:
		result += "6";
		break;
	case SEVEN:
		result += "7";
		break;
	case EIGHT:
		result += "8";
		break;
	case NINE:
		result += "9";
		break;
	case TEN:
		result += "10";
		break;
	case JACK:
		result += "J";
		break;
	case QUEEN:
		result += "Q";
		break;
	case KING:
		result += "K";
		break;
	default:
		//unreachable code
		break;
	}

	//convert the suit to a string
	switch (this->suit) {
	case CLUB:
		result += "C";
		break;
	case HEART:
		result += "H";
		break;
	case DIAMOND:
		result += "D";
		break;
	case SPADE:
		result += "S";
		break;
	default:
		//unreachable code
		break;
	}

	return result;
}
