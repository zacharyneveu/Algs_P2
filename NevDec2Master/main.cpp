//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file contains a simple main function which initializes a deck of cards
//from the deck class, prints it, shuffles it, then prints it again.

#include "card.h"//user defined card class
#include "deck.h"//user defined deck class
#include <iostream>//standard input and output

void playFlip(deck PassedDeck);

int main()
{
	//Initialize a deck to play with
	deck playDeck;

	//Play game function
	playFlip(playDeck);

    //add a system pause to keep the visual studio terminal open
    system("pause");
}//End of main function

//playFlip function implements a game of Flip reading from the user
//Steps:
//1. Cards are shuffled (three times... why?)
//2. Deal 24 cards (face down but read for testing)
//3. Player can either select a card to turn over or end the game.  points
//tally of points kept throughout.  Game should remember which cards have
//been flipped.
void playFlip(deck PassedDeck)
{
	PassedDeck.shuffle(); //Instructions said to shuffle three times?
	PassedDeck.shuffle(); //Deck in random order after once
	PassedDeck.shuffle();
	node<card> firstCard = PassedDeck.deal();
	deck choosePile(&firstCard);//create new "deck" to store pile of 24 cards.
	node<card> newCard(card((suit)1,(value)1), NULL);//Random values needed to construct
	for (int i=1; i<24; i++)//Start at one because top card already passed
	{
		newCard = PassedDeck.deal();//Remove card from main deck
		choosePile.addTop(&newCard);//add card to pile
	}
	cout<<"Printing drawn pile"<<endl;
	cout<<choosePile<<endl;
}
