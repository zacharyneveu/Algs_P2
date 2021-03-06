//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file contains a simple main function which initializes a deck of cards
//from the deck class, prints it, shuffles it, then prints it again.

#include "card.h"//user defined card class
#include "deck.h"//user defined deck class
#include <iostream>//standard input and output

#define PILESIZE 24 //Define size of pile of cards chosen from deck

void playFlip(deck PassedDeck);

int main()
{
	//Initialize a deck to play with
	deck playDeck;

	//Play game function
	playFlip(playDeck);

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
void playFlip(deck PassedDeck)
{
	PassedDeck.shuffle(); //Instructions said to shuffle three times?
	//PassedDeck.shuffle(); //Deck in random order after once
	//PassedDeck.shuffle();

	node<card> firstCard = PassedDeck.deal();
	deck choosePile(&firstCard);//create new "deck" to store pile of 24 cards.
	node<card> newCard(&firstCard.nodeValue);//Random values needed to construct
	for (int i=1; i<PILESIZE; i++)//Start at one because top card already passed
	{
		newCard = PassedDeck.deal();//Remove card from main deck
		choosePile.addTop(&newCard);//add card to pile
	}
	cout<<"Printing drawn pile"<<endl;
	cout<<choosePile<<endl;

	char playerStatus;//char used to quit if player enters q
	int points=0;//integer to store total points
	do
	{
		int cardNumber;//int to store desired card to flip
		cout<<"Enter a number between 1 and "<<PILESIZE<<"to flip that card: ";
		cin>>cardNumber;//get desired card number to flip
		if(cardNumber<=PILESIZE) //trigger if card is in range
		{
			//pointer to the desired card
			node<card> *pointCard = PassedDeck.traverse(cardNumber);
			//update points- pass by reference and change directly
			pointCard->nodeValue.getPoints(points);
			cout<<endl<<"Current Points: "<<points<<endl;//print points
		}
		else //triggger if card is out of range
		{
			cout<<"That card is out of range"<<endl;
		}
		cout<<"Press q to quit, or any other key to continue"<<endl;
		cin>>playerStatus;
	}
	while(playerStatus!='q');
}
