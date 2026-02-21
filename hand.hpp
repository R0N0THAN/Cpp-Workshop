#ifndef HAND_HPP
#define HAND_HPP

#include "cards.hpp"
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <stdio.h>
using namespace std;

class Hand {
private:
    vector<Card> cards;
public:
    Hand() = default;

    void addCard(const Card& card);
    
    vector<Card> getCards() const;

    string toString() const;

};

#endif