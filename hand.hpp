#ifndef HAND_HPP
#define HAND_HPP

#include "cards.hpp"
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <stdio.h>
using namespace std;

struct Pair {
    Rank rank;
    Card card1;
    Card card2;
};

class Hand {
private:
    vector<Card> cards;
    vector<Pair> pairs; // To track pairs in the hand

    void checkForPairs();
public:
    Hand() = default;

    void addCard(const Card& card);

    void removeCard(const Card& card);

    int getHandSize() const;

    int getPairCount() const;
    
    vector<Card> getCards() const;

    vector<Pair> getPairs() const;

    string toString() const;

    string pairsToString() const;

};

#endif