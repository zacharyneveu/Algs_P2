#include "card.h"
#include "deck.h"

#include <iostream>

//define the maximum number of cards that should be printed to a line.
const int MAXLINE = 13;

int main() {
	//defines the maximum cards printed to a line

	cout << "Initializing the deck" << endl;
	deck theDeck();

	cout << "Printing the deck:\n";
	cout << deck << endl << endl;

	//Shuffle the deck
	deck.shuffle();
	cout << "Printing the shuffled deck:";
	cout << deck << endl << endl;
}
