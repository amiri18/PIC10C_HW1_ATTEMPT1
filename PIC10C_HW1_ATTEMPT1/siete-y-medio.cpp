#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include "cards.h"

using namespace std;

int main() {
    // seed the random function
    srand(static_cast<unsigned int>(time(NULL)));
    
    // initialize player
    Player player(100);
    
    // open gamelog.txt file to write down game records
    ofstream recordLog;
    recordLog.open("gamelog.txt");
  
    int gameCount = 0;
    
    // while the player has money (more than $0 and less than $1000) play the game
    while (player.getMoney() > 0 && player.getMoney() < 1000){
        ++gameCount; // counts number of games
        
        // record gamelog formating, game count, and player's money 
        recordLog << "-----------------------------------------------\n\n";
        recordLog << "Game number: " << gameCount << "\t\t Money left: $" << player.getMoney();
        
        cout << "You have $" << player.getMoney() << ". Enter bet: ";
        // take in the bet
        int bet = 0;
        cin >> bet;
        
        recordLog << "\nBet: " << bet << "\n\n"; // record player's bet in gamelog
        
        Hand playerHand; // store player's card
        Hand dealerHand; // store dealer's cards
        
        // give the player their first card and display it
        cout << "Your cards: \n";
        Card card1;
        playerHand.addCard(card1);
        playerHand.display();
        
        // record player's card in gamelog
        recordLog << "Your cards:\n";
        recordLog << "\t\t";
        string n = card1.getSpanishRank() + " de " + card1.getSpanishSuit();
        recordLog << setfill(' ') << setw(20) << left << n;
        recordLog << "(" << card1.getEnglishRank() << " of " << card1.getEnglishSuit() << ").\n";
     
        bool more = true;
        bool bust = false;
        while (more) { // while they want more cards or until they bust ...
            
            if (playerHand.total() > 7.5) { // if they bust
                cout << "Your total is " << playerHand.total() << ".\n"; // display total
                // end the loop
                bust = true;
                more = false;
            }
            else { // if they can still ask for more cards
                // ask if they want another one
                char yes;
                cout << "Your total is " << playerHand.total() << ". Do you want another card (y/n)? ";
                cin >> yes;
                if (yes == 'y') { // if yes
                    Card anotherCard;
                    playerHand.addCard(anotherCard); // give another card
                    cout << "New Card: \n";
                    anotherCard.display(); // display it
                    cout << "\nYour cards: \n";
                    playerHand.display(); // display all their cards
                    
                    // record player's additional cards in gamelog
                    recordLog << "\t\t";
                    string n = anotherCard.getSpanishRank() + " de " + anotherCard.getSpanishSuit();
                    recordLog << setfill(' ') << setw(20) << left << n;
                    recordLog << "(" << anotherCard.getEnglishRank() << " of " << anotherCard.getEnglishSuit() << ").\n";
                }
                else { // if they don't want another card
                    more = false; // end the loop
                }
            }
        } // record player's hand value in gamelog
        recordLog << "Your total is: " << playerHand.total() << ".\n\n";
        
        if (!bust){ // if they did not bust
            // give the dealer a card and display it to the player
            Card card2;
            dealerHand.addCard(card2);
            
            // record dealer's card in gamelog
            recordLog << "Dealer's cards:\n";
            recordLog << "\t\t";
            string n = card2.getSpanishRank() + " de " + card2.getSpanishSuit();
            recordLog << setfill(' ') << setw(20) << left << n;
            recordLog << "(" << card2.getEnglishRank() << " of " << card2.getEnglishSuit() << ").\n";
            
            cout << "Dealer's cards: \n";
            dealerHand.display();
            cout << "The dealer's total is " << dealerHand.total() << ".\n\n";
            
            more = true;
            while (more) { // while the dealer can take in more cards
                
                // if their total is less than 5 and less than the player's total
                // deal another card
                if (dealerHand.total() < 5 && dealerHand.total() <= playerHand.total()){
                    Card anotherOne;
                    dealerHand.addCard(anotherOne);
                    cout << "New Card: \n"; // display the dealer's cards and their total
                    dealerHand.display();
                    cout << endl << "The dealer's total is " << dealerHand.total() << ".\n\n";
                    
                    // record dealer's additional cards in gamelog
                    recordLog << "\t\t";
                    string n = anotherOne.getSpanishRank() + " de " + anotherOne.getSpanishSuit();
                    recordLog << setfill(' ') << setw(20) << left << n;
                    recordLog << "(" << anotherOne.getEnglishRank() << " of " << anotherOne.getEnglishSuit() << ").\n";
                }
                
                // if their total is less than the player's and between (5 - 5.5)
                // then 50% chance will pick another card
                else if (dealerHand.total() <= playerHand.total() && dealerHand.total() >= 5 && dealerHand.total() <= 5.5) {
                    // 50% chance it picks 1 or 2
                    int r = 1 + rand() % 2;
                    switch (r) {
                        case 1: {Card anotherOne; // picks another card
                            dealerHand.addCard(anotherOne);
                            cout << "New Card: \n";
                            dealerHand.display();
                            cout << endl << "The dealer's total is " << dealerHand.total() << ".\n\n";
                            
                            // record dealer's additional cards in gamelog
                            recordLog << "\t\t";
                            string n = anotherOne.getSpanishRank() + " de " + anotherOne.getSpanishSuit();
                            recordLog << setfill(' ') << setw(20) << left << n;
                            recordLog << "(" << anotherOne.getEnglishRank() << " of " << anotherOne.getEnglishSuit() << ").\n";
                            
                            break;
                        }
                        case 2: { more = false; // does not pick another card and ends the loop
                            break;
                        }
                    }
                }
                else { // if above the busted or is above the player
                    more = false; // ends the loop
                }
            } // record dealer's hand value in gamelog
            recordLog << "Dealer's total: " << dealerHand.total() << ".\n\n";
        }
        // if the player lost that round
        if (bust || (playerHand.total() < dealerHand.total() && dealerHand.total() <= 7.5)) {
            cout << "Too bad. You lose " << bet << ".\n\n";
            player.updateMoney(false, bet); // lost money
        }
        // if the player won that round
        else if (playerHand.total() > dealerHand.total() || dealerHand.total() > 7.5){
            cout << "You win " << bet << "\n\n";
            player.updateMoney(true, bet); // gained money
        }
        // if it was a tie that round (no money lost or gained)
        else {
            cout << "Nobody wins!\n\n";
        }
    }
    // record for gamelog formating
    recordLog << "-----------------------------------------------";
    
    if (player.getMoney() >= 1000) { // if the player won the whole game
        cout << "You win " << player.getMoney() << ".\n\n";
        cout << "Congratulations. You beat the casino!\n\n";
        cout << "Bye!\n";
    }
    else { // if they player bet all of their money
        cout << "You have $0. GAME OVER!\n\n";
        cout << "Come back when you have more money.\n\n";
        cout << "Bye!\n";
    }
    
    recordLog.close(); // close gamelog.txt file
    
    // pause
    cin.get();
    cin.get();
    
    return 0;
}
