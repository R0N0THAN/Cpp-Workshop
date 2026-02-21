#include "deck.hpp"

Deck::Deck() {
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 0; rank < 13; ++rank) {
            cards.emplace_back(static_cast<Suit>(suit), static_cast<Rank>(rank));
        }
    }
}

void Deck::shuffle() {
    random_shuffle(cards.begin(), cards.end());
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
