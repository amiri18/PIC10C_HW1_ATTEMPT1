#include "cards.h"
#include <cstdlib>
#include <iostream>

Card::Card(){ // construct a random card
    int r = 1 + rand() % 4;
    switch (r) {// pick random suit
        case 1: suit = OROS;
            break;
        case 2: suit = COPAS;
            break;
        case 3: suit = ESPADAS;
            break;
        case 4: suit = BASTOS;
            break;
        default: break;
    }
    r = 1 + rand() % 10;
    switch (r) { // pick random rank
        case 1: rank = AS;
            break;
        case 2: rank = DOS;
            break;
        case 3: rank = TRES;
            break;
        case 4: rank = CUATRO;
            break;
        case 5: rank = CINCO;
            break;
        case 6: rank = SEIS;
            break;
        case 7: rank = SIETE;
            break;
        case 8: rank = SOTA;
            break;
        case 9: rank = CABALLO;
            break;
        case 10: rank = REY;
            break;
        default: break;
    }
}

string Card::getSpanishSuit() const {
    string Suit;
    // return the card's suit in Spanish
    switch (suit) {
        case OROS: Suit = "oros";
            break;
        case COPAS: Suit = "copas";
            break;
        case ESPADAS: Suit = "espadas";
            break;
        case BASTOS: Suit = "bastos";
            break;
        default: break;
    }
    return Suit;
}

string Card::getSpanishRank() const {
    string Rank;
    // return the card's rank in Spanish
    switch (rank) {
        case AS: Rank = "As";
            break;
        case DOS: Rank = "Dos";
            break;
        case TRES: Rank = "Tres";
            break;
        case CUATRO: Rank = "Cuatro";
            break;
        case CINCO: Rank = "Cinco";
            break;
        case SEIS: Rank = "Seis";
            break;
        case SIETE: Rank = "Siete";
            break;
        case SOTA: Rank = "Sota";
            break;
        case CABALLO: Rank = "Caballo";
            break;
        case REY: Rank = "Rey";
            break;
        default: break;
    }
    return Rank;
}

string Card::getEnglishSuit() const {
    string Suit;
    switch (suit) { // returns the card's suit in English
        case OROS: Suit = "coins";
            break;
        case COPAS: Suit = "cups";
            break;
        case ESPADAS: Suit = "spades";
            break;
        case BASTOS: Suit = "clubs";
            break;
    }
    return Suit;
}

string Card::getEnglishRank() const {
    string Rank;
    switch (rank) { // returns the card's rank in English
        case AS: Rank = "Ace";
            break;
        case DOS: Rank = "Two";
            break;
        case TRES: Rank = "Three";
            break;
        case CUATRO: Rank = "Four";
            break;
        case CINCO: Rank = "Five";
            break;
        case SEIS: Rank = "Six";
            break;
        case SIETE: Rank = "Seven";
            break;
        case SOTA: Rank = "Jack";
            break;
        case CABALLO: Rank = "Knight";
            break;
        case REY: Rank = "King";
            break;
        default: break;
    }
    return Rank;
}

int Card::getRank() const {
    // returns the card's rank value
    // {AS = 1, DOS = 2, ... SOTA = 10, CABALLO = 11, REY = 12}
    return static_cast<int>(rank) + 1;
}

bool Card::operator < (const Card& card2) const{
    // compares the rank of cards 
    return rank < card2.rank;
}

Hand::Hand(): value(0) {} // constructor sets the hand's initial value at 0

void Hand::addCard(const Card& card) {
    // stores card in the vector
    hand.push_back(card);
    
    // updates hand's value
    if (card.getRank() <= 7){
        // if the card's rank is less than or equal to seven
        value += card.getRank();
    }
    else {
        // if the card's rank is 10, 11, or 12
        value += 0.5;
    }
}

float Hand::handTotal() const {
    // return the hand's value
    return value;
}
