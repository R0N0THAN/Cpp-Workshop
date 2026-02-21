#include "cards.hpp"
#include "hand.hpp"

void Hand::checkForPairs() {
    for (size_t i = 0; i < cards.size(); ++i) { //size_t to avoid signed/unsigned comparison
        for (size_t j = i + 1; j < cards.size(); ++j) {
            if (cards[i].getRank() == cards[j].getRank()) {
                Pair pair{cards[i].getRank(), cards[i], cards[j]};
                pairs.push_back(pair);

                cards.erase(cards.begin() + static_cast<int>(j)); // Remove second card of the pair // Cast to int since erase expects an int index
                cards.erase(cards.begin() + static_cast<int>(i)); // Remove first card of the pair
                i--; // Adjust index since we removed an element
            }
        }
    }
}

void Hand::addCard(const Card& card) {
    cards.push_back(card);
    checkForPairs();
}

void Hand::removeCard(const Card& card) {
    auto it = find_if(cards.begin(), cards.end(), [&card](const Card& c) {
        return c.getSuit() == card.getSuit() && c.getRank() == card.getRank();
    });
    if (it != cards.end()) {
        cards.erase(it);
    }
}

int Hand::getHandSize() const {
    return static_cast<int>(cards.size()); //need to cast to int since size() returns size_t
}

int Hand::getPairCount() const {
    return static_cast<int>(pairs.size());
}

vector<Card> Hand::getCards() const {
    return cards;
}

vector<Pair> Hand::getPairs() const {
    return pairs;
}

string Hand::pairsToString() const {
    string pairsStr;
    for (const auto& pair : pairs) {
        pairsStr += "Pair of ";
        pairsStr += rankToString(pair.rank);
        pairsStr += "s, ";
    }
    pairsStr = pairsStr.empty() ? "No pairs" : pairsStr.substr(0, pairsStr.size() - 2); // Remove last comma and space
    pairsStr += "\n";
    return pairsStr;
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
