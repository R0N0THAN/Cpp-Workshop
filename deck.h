#ifndef DECK_H
#define DECK_H
#define RANKS 13
#define SUITS 4
#include <vector>
#include <array>

enum class Suit {
    Hearts,
    Diamonds,
    Clubs,
    Spades
};

static constexpr std::array<Suit, SUITS> all_suits = {
    Suit::Hearts, Suit::Diamonds, Suit::Clubs, Suit::Spades 
};

struct Card {
    int rank; // 1-13 for Ace-King
    Suit suit;
};

char rankToChar(int rank);

char suitToChar(Suit suit);

class Deck {

private:
    std::vector<Card> cards;

public:
    Deck();
    void shuffle();
    Card dealCard();
    bool isEmpty();
};

#endif // DECK_H