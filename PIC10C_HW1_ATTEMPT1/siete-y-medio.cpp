#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "cards.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    int bet = 0;
    cout << "You have $100. Enter bet: ";
    cin >> bet;
    Player player(100);
    Hand playerHand;
    Card card1;
    playerHand.addCard(card1);
    cout << "Your cards: \n";
    playerHand.display();
    bool more = true;
    while (more) {
        char yes;
        cout << "Your total is " << playerHand.total() << ". Do you want another card (y/n)? ";
        cin >> yes;
        if (yes == 'y') {
            Card anotherCard;
            playerHand.addCard(anotherCard);
            cout << "New Card: \n";
            anotherCard.display();
            cout << "\nYour cards: \n";
            playerHand.display();
        }
        else {
            more = false;
        }
    }
    Hand dealerHand;
    Card card2;
    dealerHand.addCard(card2);
    cout << "Dealer's cards: \n";
    dealerHand.display();
    cout << "The dealer's total is " << dealerHand.total() << endl;
    more = true;
    while (more) {
        if (dealerHand.total() < 5 && dealerHand.total() <= playerHand.total()){
            Card anotherOne;
            dealerHand.addCard(anotherOne);
            cout << "New Card: \n";
            dealerHand.display();
            cout << "The dealer's total is " << dealerHand.total() << endl;
        }
        else if (dealerHand.total() <= playerHand.total() && dealerHand.total() >= 5 && dealerHand.total() <= 5.5) {
            int r = 1 + rand() % 2;
            switch (r) {
                case 1: {Card anotherOne;
                    dealerHand.addCard(anotherOne);
                    cout << "New Card: \n";
                    dealerHand.display();
                    cout << "The dealer's total is " << dealerHand.total() << endl;
                    break;}
                case 2: { more = false;
                    break;
                }
            }
        }
        else {
            more = false;
        }
    }
   
    return 0;
}
