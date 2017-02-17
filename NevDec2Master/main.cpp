//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file contains a simple main function which initializes a deck of cards
//from the deck class, prints it, shuffles it, then prints it again.

#include "card.h"//user defined card class
#include "deck.h"//user defined deck class
#include <iostream>//standard input and output

#define PILESIZE 24 //Define size of pile of cards chosen from deck

void playFlip();

int main()
{
	//Play game function
	playFlip();

	//debugging line
	cout<<"Back in the main function"<<endl;

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
void playFlip()
{
	deck playDeck;
	deck choosePile(false);

	for (int i=0; i<PILESIZE; i++)//Start at one because top card already passed
	{
		choosePile.replace(playDeck.deal());//Remove card from main deck
	}
	cout<<"Printing drawn pile"<<endl;
	cout<<choosePile<<endl;
}
