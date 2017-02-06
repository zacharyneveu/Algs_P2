//includes
#include "card.h"
#include "d_node.h"
#include <vector>

using namespace std;

class deck {
private:
	node<card> *head;

public:
	deck();

	//The shuffle function uses the random_shuffle function from the
	//algorithms library to randomly re-order the deck of cards
	void shuffle();
	friend ostream& operator<< (ostream& ostr, const deck &deck);
};
