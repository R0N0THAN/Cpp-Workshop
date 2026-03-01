#include "player.h"
#include "deck.h"
#include <iostream> // For input/output operations

using namespace std;

bool playerTurn(Player& currentPlayer, Player& otherPlayer, Deck& deck, bool isBot);

int main() {
    Deck deck;
    deck.initialize();
    deck.shuffle();

    Player player1, player2;
    // Deal 7 cards to each player
    for (int i = 0; i < 7; i++) {
        player1.receiveCard(deck.dealCard());
        player2.receiveCard(deck.dealCard());
    }

    bool botTurn = false; // Player 1 starts first
    while (player1.getHandSize() > 0 && player2.getHandSize() > 0) {
        bool receivedCard;
        if (botTurn) {
            cout << endl << "-------- Bot's turn --------" << endl << endl;
            receivedCard = playerTurn(player2, player1, deck, true);
        } else {
            cout << endl << "-------- Your turn --------" << endl << endl;
            receivedCard = playerTurn(player1, player2, deck, false);
        }
        botTurn ^= !receivedCard; // Switch turns if no card was received
    }

    // Determine winner
    if (player1.getPairCount() > player2.getPairCount()) {
        cout << "Congratulations! You win with " << player1.getPairCount() << " pairs!" << endl;
    } else if (player2.getPairCount() > player1.getPairCount()) {
        cout << "Bot wins with " << player2.getPairCount() << " pairs. Better luck next time!" << endl;
    } else {
        cout << "It's a tie with both players having " << player1.getPairCount() << " pairs!" << endl;
    }

    return 0;
}

bool playerTurn(Player& currentPlayer, Player& otherPlayer, Deck& deck, bool isBot) {
    char requestedRank;

    if (isBot) {
        // Generate random rank to request
        vector<char> ranks = currentPlayer.getHandRanks();
        requestedRank = ranks[static_cast<size_t>(rand()) % ranks.size()];
    } else { // Human player turn
        cout << "Your hand: " << currentPlayer.handToString() << endl;
        cout << "Opponent's hand: " << otherPlayer.handToString() << endl; // for debugging purposes, can be removed in final version
        cout << "Your pairs: " << currentPlayer.pairsToString() << endl << endl;
        cout << "Opponent's pairs: " << otherPlayer.pairsToString() << endl << endl; 
        bool validInput = false;
        vector<char> ranks = currentPlayer.getHandRanks(); // Get ranks from player's hand to validate input
        do {
            cout << "Enter rank to request (A, 2-9, T, J, Q, K): ";
            cin >> requestedRank;

            // Validate input
            for (char rank : ranks) {
                if (requestedRank == rank) {
                    validInput = true;
                    break;
                }
            }
            if (!validInput) {
                cout << "Invalid rank. Please enter a rank from your hand." << endl;
            }
        } while (!validInput);  
    }
    
    bool success = currentPlayer.requestCard(otherPlayer, requestedRank);
    cout << "Player requests: " << requestedRank << endl;

    if (success) {
        cout << "You got a card!" << endl;
    } else {
        cout << "Go Fish!" << endl;
        if (!deck.isEmpty()) {
            Card receivedCard = deck.dealCard();
            currentPlayer.receiveCard(receivedCard);
            if (!isBot) {
                cout << "You drew: " << rankToChar(receivedCard.rank) << receivedCard.suit << endl;
            }
        } else {
            cout << "Deck is empty, no card drawn." << endl;
        }
    }
    return success;
}