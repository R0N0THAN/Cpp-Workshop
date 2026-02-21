#include "cards.hpp"
#include "hand.hpp"

void Hand::addCard(const Card& card) {
    cards.push_back(card);
}

vector<Card> Hand::getCards() const {
    return cards;
}

string Hand::toString() const {
    string handStr;
    for (const auto& card : cards) {
        handStr += card.toString() + ", ";
    }
    if (!handStr.empty()) {
        handStr.pop_back(); // Remove last space
        handStr.pop_back(); // Remove last comma
    }
    return handStr;
}
