#ifndef DECK_H
#define DECK_H
#include <vector>
using namespace std;

struct Card {
    int rank; // 1-13 for Ace-King
    char suit; // 'H', 'D', 'C', 'S' for Hearts, Diamonds, Clubs, Spades
};

char rankToChar(int rank);

struct Deck {
    vector<Card> cards;
    void initialize();
    void shuffle();
    Card dealCard();
    bool isEmpty();
};

#endif // DECK_H