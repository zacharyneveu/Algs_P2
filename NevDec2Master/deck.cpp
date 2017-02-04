#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "deck.h"
#include "card.h"
#include "d_node.h"

extern const int MAXLINE;

//the deconstructDeck function takes the linked list deck and converts it
//into a vector for use by the shuffle function
vector<node<card>> deck::deconstructDeck() {
	//vector of nodes to store deck for shuffle
	vector<node<card>> vectorDeck;

	//starting with head, add cards to back of vector
	vectorDeck.push_back(*head);

	//for loop iterates over all cards except for original head
	while(head->next!=NULL)
	{
		//advance head through linked list
		head = head->next;

		//starting with head, add cards to back of vector
		vectorDeck.push_back(*head);
	}
	return vectorDeck;
}

void deck::reconstructDeck(vector<node<card>> cards) {
	for (unsigned int i=0; i<cards.size()-1; i++)
	{
		cards[i].next = &cards[i+1];
	}
	cards[cards.size()-1].next=NULL;
}

//The shuffle function uses the random_shuffle function from the
//algorithms library to randomly re-order the deck of cards
void deck::shuffle() {
	//Create vector out of the deck
	vector<node<card>> deck = deconstructDeck();
	//call shuffle function on vector
	random_shuffle(deck.begin(), deck.end());
	//reconstruct deck from vector
	reconstructDeck(deck);
}

//Overloaded operator << displays the values stored in a card. 
ostream& operator<< (ostream& ostr, const deck& deck) {
	int lineMarker = 0;
	node<card> cardNode = *deck.head;

	if (deck.head == NULL) {
		return ostr;
	}

	//while the list isnt empty
	do {
		//print the card
		ostr << cardNode.nodeValue << " ";

		//if the line reaches the maximum number of cards add a line
		if (++lineMarker == MAXLINE) {
			ostr << endl;
			//reset counter
			lineMarker = 0;
		}
	} while (cardNode.next != NULL);

	return ostr;
}