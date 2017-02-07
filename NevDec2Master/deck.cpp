//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file contains the implementations for the Deck class as defined in
//deck.h.  This class is used to create and manage a deck of card objects as a
//linked list

#include <cstdlib> //Included for random function
#include <time.h> //Included for random seeding
#include <iostream> //Standard input and output
#include "deck.h" //Definition of deck class
#include "card.h" //Definition of card class
#include "d_node.h" //Definition of linked list template class


//Constructor initializes deck with all cards in order
deck::deck() {
	//Begin function with empty list
	head = NULL;

	//Create pointer to current card
	node<card> * current = NULL;

	//Initialize the first card in the deck
	card * tempCard = new card((suit)0, (value)0);

	//Initialize the first node of the list with NULL next pointer
	head = new node<card>(*tempCard, NULL);

	//Set current node to head
	current = head;

	//Outer for loop iterates over suits
	for (int i = 0; i < 4; i++) {
		//Inner for loop iterates over values
		for (int j = 0; j < 13; j++) {
			//If statement doesn't trigger on the first loop, because the first
			//node has already been created.
			if (!(i == 0 && j == 0)) {
				//Create card to store in node with suit of i and value of j
				tempCard = new card((suit)(i), (value)(j));
				//Create a new node with the new card inside
				node<card> * temp = new node<card>(*tempCard, NULL);
				//link new node into list
				current->next = temp;
				//Advance current to the new node
				current = temp;
			}//ends if statement
		}//ends inner for loop
	}//ends outer for loop
}//End of constructor

void deck::shuffle() {

	//srand does random seeding based on curr time.  Troubles arise if srand is
	//called more than once per second (number generated will be the same)
	srand(time(NULL));

	//Iterate shuffle process 1000 times
	for (int j=0; j<1000; j++)
	{
	//Pick random integer i in range 0-51
	int i = (rand() %51)+1; //random int in range 1-51

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
