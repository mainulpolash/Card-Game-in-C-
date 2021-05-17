// deck.h
//
// @brief A class that represents a deck of playing cards
//
// @details
// This class is responsible for shuffling and dealing a deck of cards. The deck should
// contain 52 cards 2 - 10, Jack,Queen, King, Ace of four suits, but no jokers.
//

#include <string>
#include <iostream>
#include <vector>
#include "card.h"
using namespace std;

class Deck
{
  //vector which will have the cards after initialization
  vector<Card> cards_;
  int numberOfSuits = 4;
  int numberOfCards = 14; // As we assign value for Joker, I assume joker is a card of each suit and is the lower powerful card.
  int totalCards = 56; // Hence, total card is 56. 
public:

	Deck();

	~Deck();

	void deal_hand(int sets, int cards);

	void print_deck();

	void shuffle(int seed);

  void insertionSort(); 

  int divide(int i, int j);

  void QuickSort(int lowerBound, int higherBound);

	void sort();

};