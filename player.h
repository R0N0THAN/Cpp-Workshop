#ifndef player_H
#define player_H

#include "deck.h"
#include <vector>
#include <string>
using namespace std;

struct Pair {
    Card card1;
    Card card2;
};

class Player {

private:

    vector<Card> hand;
    vector<Pair> pairs;

    void checkForPairs();

public:

    void receiveCard(Card card);
    bool requestCard(Player& otherPlayer, char rank);
    string handToString();
    string pairsToString();
    int getPairCount();
    int getHandSize();
    vector<char> getHandRanks();

    
};
#endif // player_H