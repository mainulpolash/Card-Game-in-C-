#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>
#include "deck.h"

// Constructor.
// Initialize all the cards with different suit ans card value.
// And push them into the vector @cards_.
Deck::Deck()
{
  for (int suit = 0; suit < numberOfSuits; suit++) 
  {
    for (int value = 0; value < numberOfCards; value++) 
    {
        cards_.push_back(Card(value, suit));   
    }
  }
}
//
// Destructor.
// Destroy the vector @cards_ after execution.  
Deck::~Deck()
{
  cards_.clear();
}
//
// Deals M cards to each of N players from the current deck and print each hand in a separate row.
// @param[in1]	sets represents the number of players.
// @param[in2]	cards represents the number of cards each player will get.
void Deck::deal_hand(int sets, int cards)
{
  // Asserts halts the program when the function is told to deal more cards than the totalCards.
  assert(sets * cards >= 0 && sets * cards <= totalCards);
  for (int i = 0; i < sets; i++) 
  {
    for (int j = 0; j < cards; j++) 
    {
      // Coverting 2D into a 1D index as cards_ is 1-D vector.
      int index = i * cards + j;
      cards_[index].print();
    }
    cout << endl;
  }
}

//
// Print the deck which is stored in the vector @cards_.

void Deck::print_deck()
{
  for (int row = 0; row < numberOfSuits; row++) 
  {
    for (int card = 0; card < numberOfCards; card++) 
    {
      // Coverting 2D into a 1D index as cards_ is 1-D vector.
      cards_[row * numberOfCards + card].print();
    }
    cout << endl;
  }
}

//
// Shuffle the deck using random_shuffle.
// As nothing is mentioned about how to shuffle I decided to use random_shuffle as I can use many different type of shuffle algorithm. And also it is mentioned that I cna't use any built-in function. 

void Deck::shuffle(int seed)
{
  assert(seed >= 0); 
  // The srand() function seeds the pseudo random number generator used by the rand() function.
  srand(seed);
  random_shuffle(cards_.begin(), cards_.end());
}

//
// Sort the deck from lowest to highest by suit then by card face value.
// The suits are valued from highest to lowest: Spades, Hearts, Clubs, Diamonds.
// The cards are valued from highest to lowest: King,Queen,Jack,10,9,8,7,6,5,4,3,2,Ace.
// Insertion sort algorithm: 1) iterate through the first element to last.
              //2) Compare the current to it's predecessor.
              //3) If this is smaller, compare the previous elements with this and move the greater elements one position up to make the soace for the swapped element.
// O(n) = n^2 for this algorithm. 

void Deck::insertionSort() {
  Card key;
  int j;
  for(int i =0; i<cards_.size(); i++)
  {
    key = cards_[i];
    j = i - 1;
    while (j >= 0 &&  key < cards_[j] )
    {
      cards_[j+1] = cards_[j];
      j = j - 1;
    }
    cards_[j+1] = key;
  }
  
}
//
// QuickSort
// In this fucntion, I am going to find  pivot value starting from the middle of the bound.
// Sort the vector in such a way that the all the left values are less than the pivot and all the right values are greater than the pivot. 
// @param[in1] i denotes the lower bound.
// @param[in1] i denotes the lower bound.
// @return the index i which act as our new bounds variale for the the next iteration of our sort.

int Deck::divide(int i, int j)
{
  //int i = 0;
  //int j = cards_.size()-1;
  Card temp;
  Card pivotValue = cards_[i + (j - i) /2];
  while(i <= j)
  {
    while(cards_[i] < pivotValue)
    {
      i++;
    }
    while (cards_[j] > pivotValue)
    {
      j--;
    }
    if(i<=j)
    {
      temp = cards_[i];
      cards_[i] = cards_[j];
      cards_[j] = temp;
      i++;
      j--;
    }
  }
  return i;
}

//
// This function sort the vector @cards_ by recursive method.
// As long as our lower bound is smaller than the upper bound, we call the dividide function and cut the vector into two and sort the smaller vector.
// Then again call this function twice, once with left portion of the vector, another call occurs with the right portion.
// This is how we divide the vector into smaller vectors and each time sort the smallest vector. 
// When the lower bound intersect the higher bound then the fucntion terminates.
// This algorithm is much more efficient because O(n) = nlog(n).
void Deck::QuickSort(int lowerBound, int higherBound)
{
  int pivotIndex;
  if(lowerBound < higherBound)
  {
    pivotIndex = divide(lowerBound, higherBound);
    QuickSort(lowerBound, pivotIndex - 1);
    QuickSort(pivotIndex,higherBound);
  }

}

//
// Call the sorting function which is implemented avobe to sort @cards_ after shuffling. 
void Deck::sort()
{
  //std::sort(cards_.begin(), cards_.end(), [&](const Card& a, const Card& b) {
    //return (a <= b);
 // });
 // I have implemented two sorting algoritom: Insertion and quicksort. 
//insertionSort();
int lowerBound = 0;
int higherBound = cards_.size() - 1;
QuickSort(lowerBound, higherBound);
}
