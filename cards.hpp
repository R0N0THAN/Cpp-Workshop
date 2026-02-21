#ifndef CARDS_HPP
#define CARDS_HPP

#include <string>
using namespace std;

enum class Suit {
    Hearts,
    Diamonds,
    Clubs,
    Spades
};

enum class Rank {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

class Card {
private:
    Suit suit;
    Rank rank;
public:
    Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}
    Suit getSuit() const;
    Rank getRank() const;
    string toString() const;
};

#endif