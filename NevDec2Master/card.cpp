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
card::card(Suit suit, Value value)
{
    this->suit = suit;
    this->value = value;
}

//Copy Constructor
card::card(card *original)
{
	this->suit = original->suit;
	this->value = original->value;
}

//Set the Suit value of this card
void card::setSuit(Suit suit)
{
    this->suit = suit;
}

//Sets the face Value of this card
void card::setValue(Value value)
{
    this->value = value;
}

//Returns the Suit of this card
Suit card::getSuit() const
{
    return suit;
}

//Return the face Value of this card
Value card::getValue() const
{
    return value;
}

//Overloaded = operator assigns one card to another card
//= operator must be overloaded as member function
card card::operator= (const card &rhs)
{
	this->value = rhs.value;
	this->suit = rhs.suit;
	return this;
}

//Overloaded operator << displays the values stored in a card.
ostream& operator<< (ostream& ostr, const card& card)
{
    ostr << card.toString();
    return ostr;
}

//Returns a string representation of a card object
string card::toString() const
{
    string result = "";

    switch (this->value)
    {
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
    switch (this->suit)
    {
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

//getPoints updates the points the user has
void card::getPoints(int &points)
{
	switch (this->value)
	{
	case ACE:
		points += 10; //ace+=10 points
		break;
	case TWO:
		points = 0;
		break;
	case THREE:
		points = 0;
		break;
	case FOUR:
		points = 0;
		break;
	case FIVE:
		points = 0;
		break;
	case SIX:
		points = 0;
		break;
	case SEVEN:
		points /= 2;
		break;
	case EIGHT:	break;
	case NINE:	break;
	case TEN:	break;
	case JACK:
		points += 5;
		break;
	case QUEEN:
		points += 5;
		break;
	case KING:
		points += 5;
		break;
	}

}
