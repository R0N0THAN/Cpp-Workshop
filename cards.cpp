#include "cards.hpp"
using namespace std;

Suit Card::getSuit() const {
    return suit;
}

Rank Card::getRank() const {
    return rank;
}

string Card::toString() const {
    string rankStr = rankToString(rank);

    string suitStr = suitToString(suit);

    return rankStr + " of " + suitStr;
}