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

/*//constructor for the card class
card::card(const card &card) {
	suit = card.suit;
	value = card.value;
}*/

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
		break;
	case TWO:
		ostr << "2";
		break;
	case THREE:
		ostr << "3";
		break;
	case FOUR:
		ostr << "4";
		break;
	case FIVE:
		ostr << "5";
		break;
	case SIX:
		ostr << "6";
		break;
	case SEVEN:
		ostr << "7";
		break;
	case EIGHT:
		ostr << "8";
		break;
	case NINE:
		ostr << "9";
		break;
	case TEN:
		ostr << "10";
		break;
	case JACK:
		ostr << "J";
		break;
	case QUEEN:
		ostr << "Q";
		break;
	case KING:
		ostr << "K";
		break;
	default:
		//unreachable code
		break;
	}

	//convert the suit to a string
	switch (card.getSuit()) {
	case CLUB:
		ostr << "C";
		break;
	case HEART:
		ostr << "H";
		break;
	case DIAMOND:
		ostr << "D";
		break;
	case SPADE:
		ostr << "S";
		break;
	default:
		//unreachable code
		break;
	}

	return ostr;
}

string card::toString() {
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
		result += "♣";
		break;
	case HEART:
		result += "♥";
		break;
	case DIAMOND:
		result += "♦";
		break;
	case SPADE:
		result += "♠";
		break;
	default:
		//unreachable code
		break;
	}

	return result;
}
