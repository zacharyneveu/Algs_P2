#include "card.h"
#include "deck.h"

#include <iostream>

int main() {
	cout << "Initializing the deck" << endl;
	deck theDeck();

	cout << "Printing the deck:\n";
	cout << deck << endl << endl;

	//Shuffle the deck
	deck.shuffle();
	cout << "Printing the shuffled deck:";
	cout << deck << endl << endl;
}