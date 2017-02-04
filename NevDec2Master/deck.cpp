#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "deck.h"
#include "card.h"


//the deconstructDeck function takes the linked list deck and converts it
//into a vector for use by the shuffle function
vector<node<card>> deck::deconstructDeck() {
	//vector of nodes to store deck for shuffle
	vector<node<card>> vectorDeck;

	//starting with head, add cards to back of vector
	vectorDeck.push_back(*head);

	//for loop iterates over all cards except for original head
	for (int i=1; i<52; i++)
	{
		//advance head through linked list
		head = head->next;

		//starting with head, add cards to back of vector
		vectorDeck.push_back(*head);
	}
	return vectorDeck;
}

//The shuffle function uses the random_shuffle function from the
//algorithms library to randomly re-order the deck of cards
void deck::shuffle() {
	//Create vector out of the deck
	vector<node> deck = deconstructDeck();
	//call shuffle function on vector
	random_shuffle(deck.begin(), deck.end());
	//reconstruct deck from vector
	reconstructDeck(deck);
}
