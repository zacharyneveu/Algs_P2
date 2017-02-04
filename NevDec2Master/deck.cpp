#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "deck.h"
#include "card.h"


//the deconstructDeck function takes the linked list deck and converts it
//into a vector for use by the shuffle function
vector<card> deck::deconstructDeck() {
	vector<card> vectorDeck;
	vectorDeck.push_back(*head);

}

//The shuffle function uses the random_shuffle function from the
//algorithms library to randomly re-order the deck of cards
void deck::shuffle() {
	//Create vector out of the deck
	vector<card> deck = deconstructDeck();
	//call shuffle function on vector
	random_shuffle(deck.begin(), deck.end());
	//reconstruct deck from vector
	reconstructDeck(deck);
}
