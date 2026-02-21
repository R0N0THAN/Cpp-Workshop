#ifndef DECK_HPP
#define DECK_HPP

#include "cards.hpp"
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdexcept>
using namespace std;

class Deck {
private:
    vector<Card> cards;
public:
    Deck();
    
    void shuffle();
    
    Card dealCard();
    
    bool isEmpty() const;

};

#endif