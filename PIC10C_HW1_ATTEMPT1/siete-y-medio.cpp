#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "cards.h"

using namespace std;

int main() {

    int bet = 0;
    cout << "You have $100. Enter bet: ";
    cin >> bet;
    Player player(100);
    Hand playerHand;
    Card card1;
    playerHand.addCard(card1);
    cout << "Your cards: \n";
    playerHand.display();
    char yes = 'y';
    cout << "Your total is " << playerHand.total() << ". Do you want another card (y/n)?";
    cin >> yes;
    while (yes) {
        Card anotherCard;
        playerHand.addCard(anotherCard);
        cout << "New Card: \n";
        anotherCard.display();
        cout << "\n Your cards: \n";
        playerHand.display();
        cout << "Your total is " << playerHand.total() << ". Do you want another card (y/n)?";
        cin >> yes;
    }
    Hand dealerHand;
    Card card2;
    dealerHand.addCard(card2);
    cout << "Dealer's cards: ";
    dealerHand.display();
    
    
    return 0;
}
