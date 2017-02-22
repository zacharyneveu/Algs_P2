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

	//print out the deck
    cout << "Printing unshuffled deck" << endl;
    cout << playDeck << endl;

    playDeck.shuffle();
    playDeck.shuffle();
    playDeck.shuffle();

	//print shuffled deck
    cout << "Printing shuffled deck" << endl;
    cout << playDeck << endl;


    //Draw 24 cards from the top of the deck and place in choosePile
    for (int i = 0; i < PILESIZE; i++)
    {
        choosePile.replace(playDeck.deal());
    }

	//print out the drawn pile
    cout << "Printing drawn pile" << endl;
    cout << choosePile << endl;


    int input; //for user input
    int points = 0; // game score
    bool checked[PILESIZE]; //array to check for flips on same card

    //init array
    for (int i = 0; i < PILESIZE; i++)
    {
        checked[i] = false;
    }

    //main game loop
    do
    {
        cout << endl << "Current Points: " << points << endl;//print points
        cout << "Enter a number between 1 and " << PILESIZE <<
             "to flip that card, 0 to quit: ";
        cin >> input;//get desired card number to flip

        //if quit condition
        if (input <= 0)
        {
            printf("Game ending. Final score is: %d\n", points);
            return;
        }
        //if card is in range
        else if (input <= PILESIZE)

            //if the card has not been flipped
            if (!checked[input - 1])
            {
                //mark card as flipped
                checked[input - 1] = true;
                //get the card (node)
                node<card> *pointCard = choosePile.traverse(input - 1);
                //update points- pass by reference and change directly
                pointCard->nodeValue.getPoints(points);
            }
        //the card has already been flipeped
            else
            {
                cout << "You already flipped that card!." << endl;
            }
        //invalid integer input (out of range)
        else
        {
            cout << "That card number is invalid." << endl;
        }
    } 
	while (1);//loop until quit condition. 
}//end playFlip()
