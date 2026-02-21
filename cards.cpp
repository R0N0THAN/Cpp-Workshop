#include "cards.hpp"
using namespace std;

Suit Card::getSuit() const {
    return suit;
}

Rank Card::getRank() const {
    return rank;
}

string Card::toString() const {
    string rankStr;
    switch (rank) {
        case Rank::Two: rankStr = "2"; break;
        case Rank::Three: rankStr = "3"; break;
        case Rank::Four: rankStr = "4"; break;
        case Rank::Five: rankStr = "5"; break;
        case Rank::Six: rankStr = "6"; break;
        case Rank::Seven: rankStr = "7"; break;
        case Rank::Eight: rankStr = "8"; break;
        case Rank::Nine: rankStr = "9"; break;
        case Rank::Ten: rankStr = "10"; break;
        case Rank::Jack: rankStr = "J"; break;
        case Rank::Queen: rankStr = "Q"; break;
        case Rank::King: rankStr = "K"; break;
        case Rank::Ace: rankStr = "A"; break;
    }

    string suitStr;
    switch (suit) {
        case Suit::Hearts: suitStr = "Hearts"; break;
        case Suit::Diamonds: suitStr = "Diamonds"; break;
        case Suit::Clubs: suitStr = "Clubs"; break;
        case Suit::Spades: suitStr = "Spades"; break;
    }

    return rankStr + " of " + suitStr;
}