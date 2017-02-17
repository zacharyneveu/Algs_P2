//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file includes the declaration of the Deck class. This class is used to
//create and manage a deck of cards as a linked list.  Implementations for this
//class can be found in deck.cpp

#include "card.h" //user defined class with card class
#include "d_node.h" //declaration of linked list template class

using namespace std;

class deck
{
private:
	//Head holds top card of deck
    node<card> *head;

	//bottom holds bottom card of deck
	node<card> *bottom;

public:
    //default constructor for deck
    deck();

	//Constructor to manually create pile of cards as deck
	deck(node<card> *head);

    //default destructor for deck
    ~deck();

    //The shuffle function picks a random card from the deck and places it on top.
    //This process is repeated 1000 times.
    void shuffle();

	//Deal function returns the top card of the deck and removes it
	node<card> deal();

	//Replace function is passed a card and returns it to the bottom of the
	//deck.
	void replace(node<card> *newBottom);

	//Add at top is passed a pointer to a card, and adds the card to the top
	//of the deck, allocating memory for it.
	void addTop(node<card> *newTop);

	//Traverse function moves through the deck by a specified number of cards and
	//returns a pointer to the card at that position.
	node<card>* traverse(int cardNumber);

    //Overloaded << operator that prints a deck to the output stream
    friend ostream& operator<< (ostream& ostr, const deck &deck);
};
