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
    node<card> *head;

public:
    //default constructor for deck
    deck();

    //default destructor for deck
    ~deck();

    //The shuffle function picks a random card from the deck and places it on top.
    //This process is repeated 1000 times.
    void shuffle();

    //Overloaded << operator that prints a deck to the output stream
    friend ostream& operator<< (ostream& ostr, const deck &deck);
};
