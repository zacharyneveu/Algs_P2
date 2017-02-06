#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <algorithm>
#include "deck.h"
#include "card.h"
#include "d_node.h"


//Constructor initializes deck with all cards in order
deck::deck() {
	head = NULL;
	node<card> * current = NULL;

	card * tempCard = new card((suit)0, (value)0);
	head = new node<card>(*tempCard, NULL);
	current = head;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			if (!(i == 0 && j == 0)) {
				tempCard = new card((suit)(i), (value)(j));
				node<card> * temp = new node<card>(*tempCard, NULL);
				current->next = temp;
				current = temp;
			}
		}
	}
}

void deck::shuffle() {

	//srand does random seeding based on curr time.  Troubles arise if srand is
	//called more than once per second (number generated will be the same)
	srand(time(NULL));

	//Iterate shuffle process 1000 times
	for (int j=0; j<1000; j++)
	{
	//Pick random integer i in range 0-51
	int i = (rand() %51)+1; //random int in range 1-51
	cout<<"i="<<i<<endl;

	//Traverse list to node i
	node<card> *currNode = head;
	node<card> *prevNode = NULL;

	//Advance i nodes through linked list
	for (int k=0; k<i; k++)
	{
		prevNode = currNode;
		currNode = currNode->next;
	}
	//delete node in original place
	prevNode->next = currNode->next;

	//copy node to beginning of list
	currNode->next = head;
	head = currNode;
	}
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
		cardNode = *cardNode.next;

		//if the line reaches the maximum number of cards add a line
		if (++lineMarker == 13) {
			ostr << endl;
			//reset counter
			lineMarker = 0;
		}
	} while (cardNode.next != NULL);

	ostr << cardNode.nodeValue << endl;

	return ostr;
}
