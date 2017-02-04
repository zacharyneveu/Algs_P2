//includes
#include "card.h"
#include "d_node.h"
#include <vector>

using namespace std;

class deck {
private:
	node<card> *head;

	//the deconstructDeck function takes the linked list deck and converts it
	//into a vector for use by the shuffle function
	std::vector<node<card>> deconstructDeck();

	//The reconstructDeck function takes the vector of cards created by the
	//deconstructDeck function and re-assembles it into a linked list
	void reconstructDeck(vector<node<card>> cards);
public:
	deck();

	//The shuffle function uses the random_shuffle function from the
	//algorithms library to randomly re-order the deck of cards
	void shuffle();
	friend ostream& operator<< (ostream& ostr, const deck &deck);
};
