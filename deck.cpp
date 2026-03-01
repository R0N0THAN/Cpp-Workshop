#include "deck.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <stdexcept>
using namespace std;

char rankToChar(int rank) {
    if (rank == 1) return 'A';
    if (rank == 10) return 'T';
    if (rank == 11) return 'J';
    if (rank == 12) return 'Q';
    if (rank == 13) return 'K';
    return static_cast<char>('0' + rank); // Convert 2-10 to characters
}

void Deck::initialize() {
    cards.clear();
    char suits[] = {'H', 'D', 'C', 'S'};
    for (char suit : suits) {
        for (int rank = 1; rank <= 13; rank++) {
            cards.push_back({rank, suit});
        }
    }
}

void Deck::shuffle() {
    unsigned int seed = static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(cards.begin(), cards.end(), default_random_engine(seed));

    // std::shuffle is a C++11 algorithm that randomly shuffles the 
    // elements in the range [first, last) using a random number generator. 
    // The std::shuffle is used instead of just shuffle to avoid confusion 
    // with Deck::shuffle() method. The default_random_engine is a random 
    // number generator that produces pseudo-random numbers.
}

Card Deck::dealCard() {
    if (cards.empty()) {
        throw runtime_error("No more cards to deal");
    }
    Card topCard = cards.back();
    cards.pop_back();
    return topCard;
}

bool Deck::isEmpty() {
    return cards.size() == 0;
}