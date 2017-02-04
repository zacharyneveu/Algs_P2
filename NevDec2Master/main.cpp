#include "card.h"
#include "deck.h"

#include <iostream>

//define the maximum number of cards that should be printed to a line.

int main() {
	card newCard((enum suit)1, (value)2);
	//defines the maximum cards printed to a line
	cout << "printing a card:" << endl;
	cout << newCard << endl;

	cout << "Initializing the deck" << endl;
	deck theDeck;

	cout << "Printing the deck:\n";
	cout << theDeck << endl << endl;

	//Shuffle the deck
	theDeck.shuffle();

	cout << "Printing the shuffled deck:";
	cout << theDeck << endl << endl;

	system("pause");
}