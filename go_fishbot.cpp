#include "deck.hpp"
#include "hand.hpp"
#include "cards.hpp"
#include <iostream>
#include <vector>
#include <random>
using namespace std;

int main() {
    Deck deck;
    deck.shuffle();

    Hand playerHand;
    Hand opponentHand;

    // Deal 5 cards to each player
    for (int i = 0; i < 7; ++i) {
        playerHand.addCard(deck.dealCard());
        opponentHand.addCard(deck.dealCard());
    }

    cout << "Player's Hand: " << playerHand.toString() << endl;
    cout << "Player's Pairs: " << playerHand.pairsToString() << endl;

    // cout << "Opponent's Hand: " << opponentHand.toString() << endl; // to be hidden in actual game
    cout << "Opponent's Pairs: " << opponentHand.pairsToString() << endl;

    while (playerHand.getHandSize() > 0 && opponentHand.getHandSize() > 0) {
        bool playerTurn = true; // For simplicity, player always goes first
        while (playerTurn) {
            cout << "Player's turn to ask for a card..." << endl;
            cout << "What card would you like to ask for? (e.g., 'A', '2', 'K', etc.): ";
            bool validInput = false;
            string requestedRank;
            do {
                cin >> requestedRank;

                if (Rank::Two <= Rank::Ace) { // Validate input
                    for (int r = static_cast<int>(Rank::Two); r <= static_cast<int>(Rank::Ace); ++r) {
                        if (requestedRank == rankToString(static_cast<Rank>(r))) {
                            validInput = true;
                            break;
                        }
                    }
                    if (!validInput) {
                        cout << "Invalid rank. Please try again." << endl;
                        continue;
                    }
                } else {
                    cout << "Invalid rank. Please try again." << endl;
                    continue;
                }
            } while (!validInput);

            bool cardFound = false;
    
            for (const auto& card : opponentHand.getCards()) {
                if (card.toString().find(requestedRank) != string::npos) {
                    cout << "Opponent has the card: " << card.toString() << endl;
                    cardFound = true;
                    playerHand.addCard(card);
                    opponentHand.removeCard(card);
                }
            }
            if (!cardFound) {
                cout << "Go Fish! Drawing a card from the deck..." << endl;
                playerTurn = false; // End player's turn
                if (!deck.isEmpty()) {
                    playerHand.addCard(deck.dealCard());
                } else {
                    cout << "Deck is empty!" << endl;
                }
            }
            cout << "Player's Hand: " << playerHand.toString() << endl;
            cout << "Player's Pairs: " << playerHand.pairsToString() << endl;

            // cout << "Opponent's Hand: " << opponentHand.toString() << endl; // to be hidden in actual game
            cout << "Opponent's Pairs: " << opponentHand.pairsToString() << endl;
        }

        // Opponent's turn (simple random choice for demonstration)
        while (!playerTurn) {
            cout << "Opponent's turn to ask for a card..." << endl;
            if (opponentHand.getHandSize() > 0) {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> dis(0, playerHand.getHandSize() - 1);
                int randomIndex = dis(gen);
                Card requestedCard = opponentHand.getCards()[static_cast<size_t>(randomIndex)];
                string requestedRank = rankToString(requestedCard.getRank());

                cout << "Opponent asks for: " << requestedRank << endl;

                bool cardFound = false;
        
                for (const auto& card : playerHand.getCards()) {
                    if (card.toString().find(requestedRank) != string::npos) {
                        cout << "Player has the card: " << card.toString() << endl;
                        cardFound = true;
                        opponentHand.addCard(card);
                        playerHand.removeCard(card);
                    }
                }
                if (!cardFound) {
                    cout << "Opponent goes fishing..." << endl;
                    playerTurn = true; // End opponent's turn
                    if (!deck.isEmpty()) {
                        opponentHand.addCard(deck.dealCard());
                    } else {
                        cout << "Deck is empty!" << endl;
                    }
                }
            } else {
                cout << "Opponent has no cards left to ask with!" << endl;
            }
            cout << "Player's Hand: " << playerHand.toString() << endl;
            cout << "Player's Pairs: " << playerHand.pairsToString() << endl;

            //cout << "Opponent's Hand: " << opponentHand.toString() << endl; // to be hidden in actual game
            cout << "Opponent's Pairs: " << opponentHand.pairsToString() << endl;
        }
    }

    // Determine winner
    if (playerHand.getPairCount() > opponentHand.getPairCount()) {
        cout << "Player wins with " << playerHand.getPairCount() << " pairs!" << endl;
    } else if (opponentHand.getPairCount() > playerHand.getPairCount()) {
        cout << "Opponent wins with " << opponentHand.getPairCount() << " pairs!" << endl;
    } else {
        cout << "It's a tie with " << playerHand.getPairCount() << " pairs each!" << endl;
    }

    return 0;
}