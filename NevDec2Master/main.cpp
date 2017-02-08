//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file contains a simple main function which initializes a deck of cards
//from the deck class, prints it, shuffles it, then prints it again.

#include "card.h"//user defined card class
#include "deck.h"//user defined deck class
#include <iostream>//standard input and output

int main()
{
    //card newCard((enum suit)1, (value)2);
    //cout << "printing a card:" << endl;
    //cout << newCard << endl;

    //initialize a deck
    cout << "Initializing the deck" << endl;
    deck theDeck;

    //print the deck
    cout << "Printing the deck:\n";
    cout << theDeck << endl << endl;


    //Shuffle the deck
    theDeck.shuffle();

    //print the shuffled deck
    cout << "Printing the shuffled deck:" << endl;
    cout << theDeck << endl << endl;

    //add a system pause to keep the visual studio terminal open
    system("pause");
}//End of main function
