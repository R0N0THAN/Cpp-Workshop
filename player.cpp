#include "player.h"

using namespace std;

void Player::receiveCard(Card card) {
    hand.push_back(card);
    checkForPairs();
}

bool Player::requestCard(Player& otherPlayer, char rank) {
    for (size_t i = 0; i < otherPlayer.hand.size(); ++i) {
        if (rankToChar(otherPlayer.hand[i].rank) == rank) {
            receiveCard(otherPlayer.hand[i]);
            otherPlayer.hand.erase(otherPlayer.hand.begin() + static_cast<ptrdiff_t>(i));
            return true; // Only one card of the requested rank can be transferred at a time
        }
    }
    return false;
}

string Player::handToString() {
    string result;
    for (Card card : hand) {
        result += rankToChar(card.rank);
        result += card.suit;
        result += " ";
    }
    return result;
}

string Player::pairsToString() {
    string result;
    for (Pair pair : pairs) {
        result += rankToChar(pair.card1.rank);
        result += "'s: ";
        result += pair.card1.suit;
        result += " & ";
        result += pair.card2.suit;
        result += ", ";
    }

    result = result.empty() ? "No pairs" : result.substr(0, result.size() - 2); // Remove trailing comma and space
    return result;
}

void Player::checkForPairs() {
    for (size_t i = 0; i < hand.size(); ++i) {
        for (size_t j = i + 1; j < hand.size(); ++j) {
            if (hand[i].rank == hand[j].rank) {
                pairs.push_back({hand[i], hand[j]});
                hand.erase(hand.begin() + static_cast<ptrdiff_t>(j));
                hand.erase(hand.begin() + static_cast<ptrdiff_t>(i));
                return; // Check for one pair at a time as there can never be more than one pair of the same rank in a player's hand.
            }
        }
    }
}

int Player::getPairCount() {
    return static_cast<int>(pairs.size());
}

int Player::getHandSize() {
    return static_cast<int>(hand.size());
}

vector<char> Player::getHandRanks() {
    vector<char> ranks;
    for (Card card : hand) {
        ranks.push_back(rankToChar(card.rank));
    }
    return ranks;
}