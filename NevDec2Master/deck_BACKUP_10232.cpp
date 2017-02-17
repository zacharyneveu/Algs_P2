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

#define MAXLINEWIDTH 13 //defines the maximum cards that will be printed on line

//Constructor initializes deck with all cards in order
deck::deck()
{
	//Begin function with empty list
	head = NULL;

	//Create pointer to current card
	node<card> *current = NULL;

	//Initialize the first card in the deck
	card firstCard((suit)0, (value)0);
	//Initialize the first node of the list with NULL next pointer
	head = new node<card>(firstCard, NULL);

	//Set current node to head
	current = head;

	//Outer for loop iterates over suits
	for (int i = 0; i < 4; i++)
	{
		//Inner for loop iterates over values
		for (int j = 0; j < 13; j++)
		{
			//If statement doesn't trigger on the first loop, because the first
			//node has already been created.
			if (!(i == 0 && j == 0))
			{
				//Create card to store in node with suit of i and value of j
				card tempCard((suit)(i), (value)(j));
				//Create a new node with the new card inside
				node<card> *temp = new node<card>(tempCard, NULL);
				//link new node into list
				current->next = temp;
				//Advance current to the new node
				current = temp;
			}//ends if statement
		}//ends inner for loop
	}//ends outer for loop
}//End of constructor


//Constructor to manually create pile of cards as deck
deck::deck(bool fulldeck)
{
	if (fulldeck) {
		deck();
	}
	else {
		this->head == NULL;
	}
}

//Destructor destroys linked list, freeing memory locations
deck::~deck()
{
	if (this == NULL) {
		return;
	}
	if (this->head == NULL) {
		return;
	}
    //variables for iterating through list
    node<card> * currentNode = this->head;
    node<card> * nextNode = this->head;
    int counter = 0;

<<<<<<< HEAD

	//if the linked list isn't empty
	if(this->head!=NULL)
	{
		do
		{
			//get the next node in the list
			nextNode = currentNode->next;

			//debugging
			cout<<"Node Deleted: "<<counter<<", "<<currentNode->nodeValue<<endl;
			cout<<currentNode->next<<endl;

			//delete the node pointer
			delete currentNode;

			//add to the counter (debug)
			counter++;

			//set the current node to the next node
			currentNode = nextNode;
		}
		while (currentNode != NULL);
		//delete currentNode;
		//cout<<"Deleted final node"<<endl;
	}

	else //if list is empty
	{
		return;
	}
=======
    //while the linked list isn't empty
    do
    {
        //get the next node in the list
        nextNode = currentNode->next;

		//debugging
		cout << "Node Deleted: " << counter << ", " << currentNode << endl;
		cout << "Next Node: " << counter << ", " << currentNode->next << endl;

        //delete the node pointer
        delete currentNode;

        //add to the counter (debug)
        counter++;

        //set the current node to the next node
        currentNode = nextNode;
    }
    while (nextNode != NULL);

>>>>>>> b4d55b18f66f6d8441a558c583129374dc0ced54

    //debug statement to ensure that all the nodes were deleted
    cout << "Deleted " << counter << " nodes" << endl;
    system("pause");
} //End of destructor

//The shuffle function picks a random card from the deck and places it on top.
//This process is repeated 1000 times.
void deck::shuffle()
{
    //srand does random seeding based on curr time.  Troubles arise if srand is
    //called more than once per second (number generated will be the same)
    srand(time(NULL));

    //Iterate shuffle process 1000 times
    for (int j = 0; j < 1000; j++)
    {
        //Pick random integer i in range 0-51
        int i = (rand() % 51) + 1; //random int in range 1-51

        //Traverse list to node i
        node<card> *currNode = head;
        node<card> *prevNode = NULL;

        //Advance i nodes through linked list
        for (int k = 0; k < i; k++)
        {
            prevNode = currNode;
            currNode = currNode->next;
        }

        //delete node in original place
        prevNode->next = currNode->next;

        //copy node to beginning of list
        currNode->next = head;
        head = currNode;
    }//End of for loop

	//Traverse shuffled list to the end to get bottom pointer.  While this runs
	//in linear time, it does not noticeably effect run time of the program.
	node<card> *currNode = head;
	while(currNode->next!=NULL)
	{
		currNode = currNode->next;
	}
}//End of shuffle function

//Deal function returns the top card of the deck and removes it
//Returns node with card inside
node<card> * deck::deal()
{
	node<card> *temp = head;
	head = head->next;
	temp->next = NULL; //make sure temp is unlinked
	return temp;
}

//Replace function is passed a node<card> and returns it to the bottom of the
//deck.
void deck::replace(node<card> *newBottom)
{
	if (this->head == NULL) {
		this->head = newBottom;
		return;
	}
	node<card> *nextNode = this->head;
	while (nextNode->next != NULL) {
		nextNode = nextNode->next;
	}
	nextNode->next = newBottom;
	newBottom->next = NULL;
	return;
}

//Add at top is passed a pointer to a card, and adds the card to the top
//of the deck, allocating memory for it.
void deck::addTop(node<card> *newTop)
{
	if (this->head == NULL) {
		this->head = newTop;
		return;
	}
	node<card> *toAdd = new node<card>(newTop->nodeValue);
	toAdd->next = head;
	head = toAdd;
}

//Traverse function moves through the deck by a specified number of cards and
//returns a pointer to the card at that position.
node<card>* deck::traverse(int cardNumber)
{
	node<card> *currNode = this->head;
	for (int i=0; i<cardNumber; i++)
	{
		currNode = currNode->next;
	}
	return currNode;
}

//Overloaded operator << displays the values stored in a card.
ostream& operator<< (ostream& ostr, const deck& deck)
{
    int lineMarker = 0;
    node<card> cardNode = *deck.head;

    if (deck.head == NULL)
    {
        return ostr;
    }

    //while the list isn't empty
    do
    {
        //print the card
        ostr << cardNode.nodeValue << " ";

        //Move to the next node.
        cardNode = *cardNode.next;

        //if the line reaches the maximum number of cards add a newline
        if (++lineMarker == MAXLINEWIDTH)
        {
            ostr << endl;
            //reset counter
            lineMarker = 0;
        }
    }
    while (cardNode.next != NULL);

    //add to the output stream
    ostr << cardNode.nodeValue << endl;

    return ostr;
}//End of overloaded operator <<
