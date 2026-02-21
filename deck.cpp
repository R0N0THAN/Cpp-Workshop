#include "deck.hpp"
#include "cards.hpp"
#include <algorithm>
#include <random>
#include <chrono>

Deck::Deck() {
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 0; rank < 13; ++rank) {
            cards.emplace_back(static_cast<Suit>(suit), static_cast<Rank>(rank));
        }
    }
}

void Deck::shuffle() {
    unsigned seed = static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(cards.begin(), cards.end(), default_random_engine(seed));  // std::shuffle is a C++11 algorithm that randomly shuffles the 
                                                                            // elements in the range [first, last) using a random number generator. 
                                                                            // The std::shuffle is used instead of just shuffle to avoid confusion 
                                                                            // with Deck::shuffle() method. The default_random_engine is a random 
                                                                            // number generator that produces pseudo-random numbers.
}

Card Deck::dealCard() {
    if (cards.empty()) {
        throw runtime_error("Cannot deal from an empty deck");
    }
    Card card = cards.back();
    cards.pop_back();
    return card;
}

bool Deck::isEmpty() const {
    return cards.empty();
}
