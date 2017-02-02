//includes
#include "card.h"
#include <vector>

using namespace std;

class deck {
private:
	card * head;

	std::vector<card> deconstructDeck();
	void reconstructDeck(vector<card> cards);
public:
	deck(card * card);
	void shuffle();
	friend ostream& operator<< (ostream& ostr, const deck &deck);
};