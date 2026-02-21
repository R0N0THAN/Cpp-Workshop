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

inline const char * rankToString(Rank rank) {
    switch (rank) {
        case Rank::Two: return "2";
        case Rank::Three: return "3";
        case Rank::Four: return "4";
        case Rank::Five: return "5";
        case Rank::Six: return "6";
        case Rank::Seven: return "7";
        case Rank::Eight: return "8";
        case Rank::Nine: return "9";
        case Rank::Ten: return "10";
        case Rank::Jack: return "J";
        case Rank::Queen: return "Q";
        case Rank::King: return "K";
        case Rank::Ace: return "A";
    }
    return "";
}

inline const char * suitToString(Suit suit) {
    switch (suit) {
        case Suit::Hearts: return "Hearts";
        case Suit::Diamonds: return "Diamonds";
        case Suit::Clubs: return "Clubs";
        case Suit::Spades: return "Spades";
    }
    return "";
}

class Card {
private:
    Suit suit;
    Rank rank;
public:
    Card(Suit s_suit, Rank s_rank) : suit(s_suit), rank(s_rank) {}
    Suit getSuit() const;
    Rank getRank() const;
    string toString() const;
};

#endif